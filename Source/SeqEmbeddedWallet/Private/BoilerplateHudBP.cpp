// Copyright 2024 Horizon Blockchain Games Inc. All rights reserved.

#include "BoilerplateHudBP.h"
#include "Sequence/SequenceAPI.h"

void UBoilerplateHudBP::NativeConstruct()
{
	Super::NativeConstruct();
	UpdateAddress();
	UpdateBalance();

	SignMessageButton->OnClicked.AddDynamic(this, &UBoilerplateHudBP::OnSignMessageClicked);
	SendTransactionButton->OnClicked.AddDynamic(this, &UBoilerplateHudBP::OnSendTransactionClicked);
}

void UBoilerplateHudBP::OnSignMessageClicked()
{
	if (!this->MessageInput)
	{
		this->Log("ERROR: BoilerplateHud.MessageInput is undefined.");
		return;
	}

	const FString& MessageInputText = this->MessageInput->GetText().ToString();
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();

	if (!WalletOptional.IsSet())
	{
		this->Log("ERROR: Failed to get stored wallet.");
		return;
	}

	const USequenceWallet* Wallet = WalletOptional.GetValue();
	Wallet->SignMessage(MessageInputText, [this, MessageInputText](const FSeqSignMessageResponse_Response& Response)
	{
		const FString& SignedMessageText = *Response.Data.Message;
		this->SignedMessage->SetText(FText::FromString("Signed Message: " + SignedMessageText));
		this->Log(FString::Printf(TEXT("SUCCESS: Signed message '%s': %s"), *MessageInputText, *SignedMessageText));
	},
	[this, &MessageInputText](const FSequenceError& Error)
	{
		this->Log(FString::Printf(TEXT("ERROR: While signing message '%s', error: %s"), *MessageInputText, *Error.Message));
	});
}

void UBoilerplateHudBP::OnSendTransactionClicked()
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();
	if (!WalletOptional.IsSet())
	{
		this->Log("ERROR: Failed to get stored wallet.");
		return;
	}

	const USequenceWallet* Wallet = WalletOptional.GetValue();
	const FString ToAddress = ToAddressInput->GetText().ToString();
	const FString TokenAddress = TokenAddressInput->GetText().ToString();
	const FString TransactionValue = TransactionValueInput->GetText().ToString();

	TArray<TUnion<FRawTransaction, FERC20Transaction, FERC721Transaction, FERC1155Transaction, FDelayedTransaction>> Txn;

	FERC20Transaction T20;
	T20.to = ToAddress;
	T20.tokenAddress = TokenAddress;
	T20.value = TransactionValue;
 
	Txn.Push(TUnion<FRawTransaction, FERC20Transaction, FERC721Transaction, FERC1155Transaction, FDelayedTransaction>(T20));

	Wallet->GetFeeOptions(Txn, [this, Txn, Wallet](const TArray<FFeeOption>& Response)
	{
		if (Response.Num() == 0)
		{
			this->Log(FString::Printf(TEXT("ERROR: Test failed no fee options in response")));
			return;
		}

		const FFeeOption SelectedFeeOption = Response[0];
		this->Log(FString::Printf(TEXT("Using FeeOption value: %s"), *SelectedFeeOption.Value));
		 
		Wallet->SendTransactionWithFeeOption(Txn, SelectedFeeOption, [=](const FSeqTransactionResponse_Data& Transaction)
		{
			this->Log(FString::Printf(TEXT("SUCCESS: Transaction sent, hash: %s"), *Transaction.TxHash));
		},
		[this](const FSequenceError& Error)
		{
			this->Log(FString::Printf(TEXT("ERROR: Failed to send transaction %s"), *Error.Message));
		});
	},
	[this](const FSequenceError& Error)
	{
		this->Log(FString::Printf(TEXT("ERROR: Get Fee Option Response failure %s"), *Error.Message));
	});
}


void UBoilerplateHudBP::UpdateAddress()
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();
	if (!WalletOptional.IsSet())
	{
		this->Log("ERROR: Failed to get stored wallet.");
		return;
	}

	const USequenceWallet* Wallet = WalletOptional.GetValue();
	const FString Address = Wallet->GetWalletAddress();
	this->WalletAddress->SetText(FText::FromString("Wallet Address: " + Address));
}

void UBoilerplateHudBP::UpdateBalance()
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();
	if (!WalletOptional.IsSet())
	{
		this->Log("ERROR: Failed to get stored wallet.");
		return;
	}
	
	const USequenceWallet* Wallet = WalletOptional.GetValue();
	const FString Address = Wallet->GetWalletAddress();

	Wallet->GetEtherBalance(Address, [this](const FSeqEtherBalance& Balance)
	{
		const FString BalanceText = FString::Printf(TEXT("Balance: %lld"), Balance.balanceWei);
		this->EtherBalance->SetText(FText::FromString(BalanceText));
	},
	[this, Address](const FSequenceError& Error)
	{
		this->Log(FString::Printf(TEXT("ERROR: While getting ether balance for address '%s, error: %s"), *Address, *Error.Message));
	});
}

// Let's print the log and display it to the user
void UBoilerplateHudBP::Log(const FString& Message) const
{
	this->LogMessage->SetText(FText::FromString(Message));
	UE_LOG(LogTemp, Display, TEXT("%s"), *Message);
}

