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
	UEditableTextBox* MessageInput;

	UPROPERTY(meta = (BindWidget))
	UButton* SignMessageButton;

	UFUNCTION()
	void OnButtonClicked();

private:
	void UpdateAddress();
	void UpdateBalance();
};
