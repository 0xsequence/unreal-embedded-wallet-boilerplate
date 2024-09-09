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
		SignMessageButton->OnClicked.AddDynamic(this, &UBoilerplateHudBP::OnButtonClicked);
	}
}

void UBoilerplateHudBP::OnButtonClicked()
{
	if (!this->MessageInput)
	{
		UE_LOG(LogTemp, Display, TEXT("BoilerplateHud.MessageInput is undefined."));
		return;
	}

	const FString MessageInputText = this->MessageInput->GetText().ToString();
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();
	
	if (WalletOptional.IsSet())
	{
		const USequenceWallet* Wallet = WalletOptional.GetValue();
		Wallet->SignMessage(MessageInputText, [this, &MessageInputText](const FSeqSignMessageResponse_Response& Response)
		{
			const FString& SignedMessageText = *Response.Data.Message;
			if (this->SignedMessage)
			{
				this->SignedMessage->SetText(FText::FromString("Signed Message: " + SignedMessageText));
			}
			
			UE_LOG(LogTemp, Display, TEXT("Successfully signed message '%s': %s"), *MessageInputText, *SignedMessageText);
		},
		[this, &MessageInputText](const FSequenceError& Error)
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to sign message '%s', error: %s"), *MessageInputText, *Error.Message);
		});
	}
}

void UBoilerplateHudBP::UpdateAddress()
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();
	if (!WalletOptional.IsSet())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get stored wallet."));
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
		UE_LOG(LogTemp, Error, TEXT("Failed to get stored wallet."));
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
	[Address](const FSequenceError& Error)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get ether balance for address '%s', error: %s"), *Address, *Error.Message);
	});
}
