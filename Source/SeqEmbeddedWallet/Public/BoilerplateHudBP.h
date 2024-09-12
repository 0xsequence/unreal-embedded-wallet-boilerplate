// Copyright 2024 Horizon Blockchain Games Inc. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "BoilerplateHudBP.generated.h"

UCLASS(Blueprintable)
class SEQEMBEDDEDWALLET_API UBoilerplateHudBP : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* WalletAddress;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* EtherBalance;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* SignedMessage;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* LogMessage;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* MessageInput;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* ToAddressInput;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* TokenAddressInput;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* TransactionValueInput;

	UPROPERTY(meta = (BindWidget))
	UButton* SignMessageButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SendTransactionButton;

	UFUNCTION()
	void OnSignMessageClicked();

	UFUNCTION()
	void OnSendTransactionClicked();

private:
	void UpdateAddress();
	void UpdateBalance();
	void Log(const FString& Message) const;
};
