// Copyright 2024 Horizon Blockchain Games Inc. All rights reserved.

#include "Sequence/SequenceWalletBP.h"
#include "Sequence/SequenceAPI.h"

USequenceWalletBP::USequenceWalletBP()
{
}

void USequenceWalletBP::CallOnApiSignMessage(const FSequenceResponseStatus& Status, const FSeqSignMessageResponse_Response& SignedMessage) const
{
	if (this->OnApiSignMessage.IsBound())
		this->OnApiSignMessage.Broadcast(Status,SignedMessage);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnApiSignMessage]"));
}

void USequenceWalletBP::CallOnApiGetFilteredFeeOptions(const FSequenceResponseStatus& Status, const TArray<FFeeOption>& FeeOptions) const
{
	if (this->OnApiGetFilteredFeeOptions.IsBound())
		this->OnApiGetFilteredFeeOptions.Broadcast(Status,FeeOptions);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnApiGetFilteredFeeOptions]"));
}

void USequenceWalletBP::CallOnApiGetUnFilteredFeeOptions(const FSequenceResponseStatus& Status, const TArray<FFeeOption>& FeeOptions) const
{
	if (this->OnApiGetUnFilteredFeeOptions.IsBound())
		this->OnApiGetUnFilteredFeeOptions.Broadcast(Status,FeeOptions);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnApiGetUnFilteredFeeOptions]"));
}

void USequenceWalletBP::CallOnApiSendTransactionWithFee(const FSequenceResponseStatus& Status, const FSeqTransactionResponse_Data& Response) const
{
	if (this->OnApiSendTransactionWithFeeOption.IsBound())
		this->OnApiSendTransactionWithFeeOption.Broadcast(Status,Response);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnApiSendTransactionWithFeeOption]"));
}

void USequenceWalletBP::CallOnApiSendTransaction(const FSequenceResponseStatus& Status, const FSeqTransactionResponse_Data& Response) const
{
	if (this->OnApiSendTransaction.IsBound())
		this->OnApiSendTransaction.Broadcast(Status,Response);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnApiSendTransaction]"));
}

void USequenceWalletBP::CallOnApiListSessions(const FSequenceResponseStatus& Status, const TArray<FSeqListSessions_Session>& Sessions) const
{
	if (this->OnApiListSessions.IsBound())
		this->OnApiListSessions.Broadcast(Status,Sessions);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnApiListSessions]"));
}

void USequenceWalletBP::CallOnApiGetSupportedTransakCountries(const FSequenceResponseStatus& Status, const TArray<FSupportedCountry>& SupportedCountries) const
{
	if (this->OnApiGetSupportedTransakCountries.IsBound())
		this->OnApiGetSupportedTransakCountries.Broadcast(Status,SupportedCountries);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnApiGetSupportedTransakCountries]"));
}

void USequenceWalletBP::CallOnIndexerPing(const FSequenceResponseStatus& Status, bool PingResponse) const
{
	if (this->OnIndexerPing.IsBound())
		this->OnIndexerPing.Broadcast(Status,PingResponse);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnIndexerPing]"));
}

void USequenceWalletBP::CallOnIndexerVersion(const FSequenceResponseStatus& Status, const FSeqVersion& Version) const
{
	if (this->OnIndexerVersion.IsBound())
		this->OnIndexerVersion.Broadcast(Status,Version);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnIndexerVersion]"));
}

void USequenceWalletBP::CallOnIndexerRuntimeStatus(const FSequenceResponseStatus& Status, const FSeqRuntimeStatus& RuntimeStatus) const
{
	if (this->OnIndexerRuntimeStatus.IsBound())
		this->OnIndexerRuntimeStatus.Broadcast(Status,RuntimeStatus);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnIndexerRuntimeStatus]"));
}

void USequenceWalletBP::CallOnIndexerGetChainId(const FSequenceResponseStatus& Status, int64 ChainId) const
{
	if (this->OnIndexerGetChainId.IsBound())
		this->OnIndexerGetChainId.Broadcast(Status,ChainId);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnIndexerGetChainId]"));
}

void USequenceWalletBP::CallOnIndexerGetEtherBalance(const FSequenceResponseStatus& Status, const FSeqEtherBalance& EtherBalance) const
{
	if (this->OnIndexerGetEtherBalance.IsBound())
		this->OnIndexerGetEtherBalance.Broadcast(Status,EtherBalance);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnIndexerGetEtherBalance]"));
}

void USequenceWalletBP::CallOnIndexerGetTokenBalances(const FSequenceResponseStatus& Status, const FSeqGetTokenBalancesReturn& TokenBalances) const
{
	if (this->OnIndexerGetTokenBalances.IsBound())
		this->OnIndexerGetTokenBalances.Broadcast(Status,TokenBalances);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnIndexerGetTokenBalances]"));
}

void USequenceWalletBP::CallOnIndexerGetTokenSupplies(const FSequenceResponseStatus& Status, const FSeqGetTokenSuppliesReturn& TokenSupplies) const
{
	if (this->OnIndexerGetTokenSupplies.IsBound())
		this->OnIndexerGetTokenSupplies.Broadcast(Status,TokenSupplies);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnIndexerGetTokenSupplies]"));
}

void USequenceWalletBP::CallOnIndexerGetTokenSuppliesMap(const FSequenceResponseStatus& Status, const FSeqGetTokenSuppliesMapReturn& TokenSuppliesMap) const
{
	if (this->OnIndexerGetTokenSuppliesMap.IsBound())
		this->OnIndexerGetTokenSuppliesMap.Broadcast(Status,TokenSuppliesMap);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnIndexerGetTokenSuppliesMap]"));
}

void USequenceWalletBP::CallOnIndexerGetBalanceUpdates(const FSequenceResponseStatus& Status, const FSeqGetBalanceUpdatesReturn& BalanceUpdates) const
{
	if (this->OnIndexerGetBalanceUpdates.IsBound())
		this->OnIndexerGetBalanceUpdates.Broadcast(Status,BalanceUpdates);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnIndexerGetBalanceUpdates]"));
}

void USequenceWalletBP::CallOnIndexerGetTransactionHistory(const FSequenceResponseStatus& Status, const FSeqGetTransactionHistoryReturn& TransactionHistory) const
{
	if (this->OnIndexerGetTransactionHistory.IsBound())
		this->OnIndexerGetTransactionHistory.Broadcast(Status,TransactionHistory);
	else
		UE_LOG(LogTemp, Error, TEXT("[Nothing bound to: OnIndexerGetTransactionHistory]"));
}

float USequenceWalletBP::GetUserReadableAmountIntDecimals(int64 Amount, int64 Decimals)
{
	return USequenceSupport::GetUserReadableAmount(Amount,Decimals);
}

int64 USequenceWalletBP::GetTransactionReadableAmountIntDecimals(float Amount, int64 Decimals)
{
	return USequenceSupport::GetSystemReadableAmount(Amount,Decimals);
}

int64 USequenceWalletBP::GetNetworkIdFromName(const FString& NetworkNameIn)
{
	return USequenceSupport::GetNetworkId(NetworkNameIn);
}

FString USequenceWalletBP::GetNetworkNameFromId(const int64 NetworkIdIn)
{
	return USequenceSupport::GetNetworkName(NetworkIdIn);
}

TArray<FIdNamePair> USequenceWalletBP::GetAllNetworks()
{
	return USequenceSupport::GetAllNetworks();
}

TArray<FString> USequenceWalletBP::GetAllNetworkNames()
{
	return USequenceSupport::GetAllNetworkNames();
}

TArray<int64> USequenceWalletBP::GetAllNetworkIds()
{
	return USequenceSupport::GetAllNetworkIds();
}

FString USequenceWalletBP::ApiGetWalletAddress()
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();
		return Wallet->GetWalletAddress();
	}
	return "";
}

int64 USequenceWalletBP::ApiGetNetworkId()
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();
		return Wallet->GetNetworkId();
	}
	return 0;
}

void USequenceWalletBP::ApiUpdateNetworkId(int64 NewNetworkId)
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		USequenceWallet * Wallet = WalletOptional.GetValue();
		Wallet->UpdateNetworkId(NewNetworkId);
	}
}

void USequenceWalletBP::ApiUpdateProviderUrl(const FString& NewProviderUrl)
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();
		Wallet->UpdateProviderURL(NewProviderUrl);
	}
}

void USequenceWalletBP::ApiOpenTransakUrl(const FTransakSettings& Settings)
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		USequenceWallet * Wallet = WalletOptional.GetValue();
		Wallet->OpenTransakLink(Settings.FiatCurrency,Settings.FiatAmount,Settings.CryptoCurrency,Settings.Networks,Settings.DisableWalletAddressForm);
	}
}

void USequenceWalletBP::ApiSignOut()
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();
		Wallet->SignOut();
	}
}

void USequenceWalletBP::ApiSignMessage(const FString& Message)
{
	const TFunction<void (FSeqSignMessageResponse_Response)> OnSuccess = [this](const FSeqSignMessageResponse_Response& SignedMessage)
	{
		this->CallOnApiSignMessage(FSequenceResponseStatus(true, SignMessageTrt), SignedMessage);
	};

	const TFunction<void (FSequenceError)> OnFailure = [this](const FSequenceError& Err)
	{
		this->CallOnApiSignMessage(FSequenceResponseStatus(false, Err.Message,SignMessageTrt), FSeqSignMessageResponse_Response());
	};
	
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();
		Wallet->SignMessage(Message, OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::ApiGetFilteredFeeOptions(UTransactions * Transactions)
{
	const TFunction<void (TArray<FFeeOption>)> OnSuccess = [this](const TArray<FFeeOption>& FeeOptions)
	{
		this->CallOnApiGetFilteredFeeOptions(FSequenceResponseStatus(true, GetFilteredFeeTrt), FeeOptions);
	};

	const TFunction<void (FSequenceError)> OnFailure = [this](const FSequenceError& Err)
	{
		this->CallOnApiGetFilteredFeeOptions(FSequenceResponseStatus(false, Err.Message, GetFilteredFeeTrt),{});
	};
	
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();
		Wallet->GetFeeOptions(Transactions->GetTransactions(), OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::ApiGetUnfilteredFeeOptions(UTransactions * Transactions)
{
	const TFunction<void (TArray<FFeeOption>)> OnSuccess = [this](const TArray<FFeeOption>& FeeOptions)
	{
		this->CallOnApiGetUnFilteredFeeOptions(FSequenceResponseStatus(true, GetUnFilteredFeeOptionsTrt), FeeOptions);
	};

	const TFunction<void (FSequenceError)> OnFailure = [this](const FSequenceError& Err)
	{
		this->CallOnApiGetUnFilteredFeeOptions(FSequenceResponseStatus(false, Err.Message, GetUnFilteredFeeOptionsTrt), {});
	};
	
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();
		Wallet->GetUnfilteredFeeOptions(Transactions->GetTransactions(), OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::ApiSendTransactionWithFee(UTransactions * Transactions)
{
	const TFunction<void (FSeqTransactionResponse_Data)> OnSuccess = [this](const FSeqTransactionResponse_Data& Response)
	{
		this->CallOnApiSendTransactionWithFee(FSequenceResponseStatus(true, SendTransactionWithFeeTrt), Response);
	};

	const TFunction<void (FSequenceError)> OnFailure = [this](const FSequenceError& Err)
	{
		this->CallOnApiSendTransactionWithFee(FSequenceResponseStatus(false, Err.Message, SendTransactionWithFeeTrt), FSeqTransactionResponse_Data());
	};
	
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();
		if (Transactions->IsFeeSet())
		{
			Wallet->SendTransactionWithFeeOption(Transactions->GetTransactions(), Transactions->GetFee(), OnSuccess, OnFailure);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No Fee was set for a transaction being sent with a Fee!"));
		}
	}
}

void USequenceWalletBP::ApiSendTransaction(UTransactions * Transactions)
{
	const TFunction<void (FSeqTransactionResponse_Data)> OnSuccess = [this](const FSeqTransactionResponse_Data& Response)
	{
		this->CallOnApiSendTransaction(FSequenceResponseStatus(true, SendTransactionTrt), Response);
	};

	const TFunction<void (FSequenceError)> OnFailure = [this](const FSequenceError& Err)
	{
		this->CallOnApiSendTransaction(FSequenceResponseStatus(false, Err.Message, SendTransactionTrt), FSeqTransactionResponse_Data());
	};
	
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();
		Wallet->SendTransaction(Transactions->GetTransactions(), OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::ApiListSessions()
{
	const TFunction<void (TArray<FSeqListSessions_Session>)> OnSuccess = [this](const TArray<FSeqListSessions_Session>& Sessions)
	{
		this->CallOnApiListSessions(FSequenceResponseStatus(true, ListSessionsTrt), Sessions);
	};

	const TFunction<void (FSequenceError)> OnFailure = [this](const FSequenceError& Err)
	{
		this->CallOnApiListSessions(FSequenceResponseStatus(false, Err.Message, ListSessionsTrt), {});
	};
	
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();
		Wallet->ListSessions(OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::ApiGetSupportedTransakCountries()
{
	const TFunction<void (TArray<FSupportedCountry>)> OnSuccess = [this](const TArray<FSupportedCountry>& SupportedCountries)
	{
		this->CallOnApiGetSupportedTransakCountries(FSequenceResponseStatus(true, GetSupportedTransakCountriesTrt), SupportedCountries);
	};

	const TFunction<void (FSequenceError)> OnFailure = [this](const FSequenceError& Err)
	{
		this->CallOnApiGetSupportedTransakCountries(FSequenceResponseStatus(false, Err.Message, GetSupportedTransakCountriesTrt), {});
	};
	
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		USequenceWallet * Wallet = WalletOptional.GetValue();
		Wallet->GetSupportedTransakCountries(OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::IndexerPing()
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();

		const TSuccessCallback<bool> OnSuccess = [this](const bool bSuccess)
		{
			this->CallOnIndexerPing(FSequenceResponseStatus(true, PingTrt), bSuccess);
		};

		const FFailureCallback OnFailure = [this](const FSequenceError& Error)
		{
			this->CallOnIndexerPing(FSequenceResponseStatus(false,Error.Message, PingTrt),false);
		};
		
		Wallet->Ping(OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::IndexerVersion()
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();

		const TSuccessCallback<FSeqVersion> OnSuccess = [this](const FSeqVersion& Version)
		{
			this->CallOnIndexerVersion(FSequenceResponseStatus(true, VersionTrt), Version);
		};

		const FFailureCallback OnFailure = [this](const FSequenceError& Error)
		{
			this->CallOnIndexerVersion(FSequenceResponseStatus(false, Error.Message, VersionTrt), FSeqVersion());
		};
		
		Wallet->Version(OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::IndexerRuntimeStatus()
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();

		const TSuccessCallback<FSeqRuntimeStatus> OnSuccess = [this](const FSeqRuntimeStatus& RuntimeStatus)
		{
			this->CallOnIndexerRuntimeStatus(FSequenceResponseStatus(true, RuntimeStatusTrt), RuntimeStatus);
		};

		const FFailureCallback OnFailure = [this](const FSequenceError& Error)
		{
			this->CallOnIndexerRuntimeStatus(FSequenceResponseStatus(false, Error.Message, RuntimeStatusTrt), FSeqRuntimeStatus());
		};
		
		Wallet->RunTimeStatus(OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::IndexerGetChainId()
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();

		const TSuccessCallback<int64> OnSuccess = [this](const int64& ChainId)
		{
			this->CallOnIndexerGetChainId(FSequenceResponseStatus(true, GetChainIdTrt), ChainId);
		};

		const FFailureCallback OnFailure = [this](const FSequenceError& Error)
		{
			this->CallOnIndexerGetChainId(FSequenceResponseStatus(false, Error.Message, GetChainIdTrt),-1);
		};
		
		Wallet->GetChainID(OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::IndexerGetEtherBalance(const FString& WalletAddress)
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();

		const TSuccessCallback<FSeqEtherBalance> OnSuccess = [this](const FSeqEtherBalance& EtherBalance)
		{
			this->CallOnIndexerGetEtherBalance(FSequenceResponseStatus(true, GetEtherBalanceTrt), EtherBalance);
		};

		const FFailureCallback OnFailure = [this](const FSequenceError& Error)
		{
			this->CallOnIndexerGetEtherBalance(FSequenceResponseStatus(false, Error.Message, GetEtherBalanceTrt), FSeqEtherBalance());
		};
		
		Wallet->GetEtherBalance(WalletAddress, OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::IndexerGetTokenBalances(const FSeqGetTokenBalancesArgs& Args)
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();

		const TSuccessCallback<FSeqGetTokenBalancesReturn> OnSuccess = [this](const FSeqGetTokenBalancesReturn& TokenBalances)
		{
			this->CallOnIndexerGetTokenBalances(FSequenceResponseStatus(true, GetTokenBalancesTrt),TokenBalances);
		};

		const FFailureCallback OnFailure = [this](const FSequenceError& Error)
		{
			this->CallOnIndexerGetTokenBalances(FSequenceResponseStatus(false, Error.Message, GetTokenBalancesTrt),FSeqGetTokenBalancesReturn());
		};
		
		Wallet->GetTokenBalances(Args, OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::IndexerGetTokenSupplies(const FSeqGetTokenSuppliesArgs& Args)
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();

		const TSuccessCallback<FSeqGetTokenSuppliesReturn> OnSuccess = [this](const FSeqGetTokenSuppliesReturn& TokenSupplies)
		{
			this->CallOnIndexerGetTokenSupplies(FSequenceResponseStatus(true, GetTokenSuppliesTrt),TokenSupplies);
		};

		const FFailureCallback OnFailure = [this](const FSequenceError& Error)
		{
			this->CallOnIndexerGetTokenSupplies(FSequenceResponseStatus(false, Error.Message, GetTokenSuppliesTrt), FSeqGetTokenSuppliesReturn());
		};
		
		Wallet->GetTokenSupplies(Args, OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::IndexerGetTokenSuppliesMap(const FSeqGetTokenSuppliesMapArgs& Args)
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();

		const TSuccessCallback<FSeqGetTokenSuppliesMapReturn> OnSuccess = [this](const FSeqGetTokenSuppliesMapReturn& TokenSuppliesMap)
		{
			this->CallOnIndexerGetTokenSuppliesMap(FSequenceResponseStatus(true, GetTokenSuppliesMapTrt), TokenSuppliesMap);
		};

		const FFailureCallback OnFailure = [this](const FSequenceError& Error)
		{
			this->CallOnIndexerGetTokenSuppliesMap(FSequenceResponseStatus(false, Error.Message, GetTokenSuppliesMapTrt),FSeqGetTokenSuppliesMapReturn());
		};
		
		Wallet->GetTokenSuppliesMap(Args, OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::IndexerGetBalanceUpdates(const FSeqGetBalanceUpdatesArgs& Args)
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();

		const TSuccessCallback<FSeqGetBalanceUpdatesReturn> OnSuccess = [this](const FSeqGetBalanceUpdatesReturn& BalanceUpdates)
		{
			this->CallOnIndexerGetBalanceUpdates(FSequenceResponseStatus(true, GetBalanceUpdatesTrt), BalanceUpdates);
		};

		const FFailureCallback OnFailure = [this](const FSequenceError& Error)
		{
			this->CallOnIndexerGetBalanceUpdates(FSequenceResponseStatus(false, Error.Message, GetBalanceUpdatesTrt), FSeqGetBalanceUpdatesReturn());
		};
		
		Wallet->GetBalanceUpdates(Args, OnSuccess, OnFailure);
	}
}

void USequenceWalletBP::IndexerGetTransactionHistory(const FSeqGetTransactionHistoryArgs& Args)
{
	const TOptional<USequenceWallet*> WalletOptional = USequenceWallet::Get();	
	if (WalletOptional.IsSet() && WalletOptional.GetValue())
	{
		const USequenceWallet * Wallet = WalletOptional.GetValue();

		const TSuccessCallback<FSeqGetTransactionHistoryReturn> OnSuccess = [this](const FSeqGetTransactionHistoryReturn& TransactionHistory)
		{
			this->CallOnIndexerGetTransactionHistory(FSequenceResponseStatus(true, GetTransactionHistoryTrt), TransactionHistory);
		};

		const FFailureCallback OnFailure = [this](const FSequenceError& Error)
		{
			this->CallOnIndexerGetTransactionHistory(FSequenceResponseStatus(false, Error.Message, GetTransactionHistoryTrt), FSeqGetTransactionHistoryReturn());
		};
		
		Wallet->GetTransactionHistory(Args, OnSuccess, OnFailure);
	}
}