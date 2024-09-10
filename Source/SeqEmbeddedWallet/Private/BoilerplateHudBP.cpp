// Copyright 2024 Horizon Blockchain Games Inc. All rights reserved.

#include "BoilerplateHudBP.h"
#include "Sequence/SequenceAPI.h"

void UBoilerplateHudBP::NativeConstruct()
{
	Super::NativeConstruct();
	UpdateAddress();
	UpdateBalance();

	if (SignMessageButton)
	{
		SignMessageButton->OnClicked.AddDynamic(this, &UBoilerplateHudBP::OnSignMessageClicked);
	}

	if (SendTransactionButton)
	{
		SendTransactionButton->OnClicked.AddDynamic(this, &UBoilerplateHudBP::OnSendTransactionClicked);
	}
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
		if (this->SignedMessage)
		{
			this->SignedMessage->SetText(FText::FromString("Signed Message: " + SignedMessageText));
		}
			
		this->Log(FString::Printf(TEXT("SUCCESS: Signed message '%s': %s"), *MessageInputText, *SignedMessageText));
	},
	[this, &MessageInputText](const FSequenceError& Error)
	{
		this->Log(FString::Printf(TEXT("ERROR: While signing message '%s', error: %s"), *MessageInputText, *Error.Message));
	});
}

void UBoilerplateHudBP::OnSendTransactionClicked()
{
	if (!ToAddressInput || !TokenAddressInput || !TransactionValueInput)
	{
		this->Log("ERROR: ToAddressInput, TokenAddressInput or TransactionValueInput is undefined.");
		return;
	}
	
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
	
	Wallet->SendTransaction(Txn, [this](const FSeqTransactionResponse_Data Data)
	{
		this->Log(FString::Printf(TEXT("SUCCESS: Sending transaction: %s"), *Data.TxHash));
	},
	[this](const FSequenceError& Error)
	{
		this->Log(FString::Printf(TEXT("ERROR: Failed to send transaction %s"), *Error.Message));
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

	if (this->WalletAddress)
	{
		this->WalletAddress->SetText(FText::FromString("Wallet Address: " + Address));	
	}
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
		if (this->EtherBalance)
		{
			const FString BalanceText = FString::Printf(TEXT("%lld ETH"), Balance.balanceWei);
			this->EtherBalance->SetText(FText::FromString(BalanceText));
		}
	},
	[this, Address](const FSequenceError& Error)
	{
		this->Log(FString::Printf(TEXT("ERROR: While getting ether balance for address '%s, error: %s"), *Address, *Error.Message));
	});
}

// Let's print the log and display it to the user
void UBoilerplateHudBP::Log(const FString& Message)
{
	if (this->LogMessage)
	{
		this->LogMessage->SetText(FText::FromString(Message));
	}
	
	UE_LOG(LogTemp, Display, TEXT("%s"), *Message);
}

