// Copyright 2024 Horizon Blockchain Games Inc. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "SeqRuntimeChecks.generated.h"

USTRUCT(BlueprintType)
struct SEQUENCEPLUGIN_API FSeqRuntimeChecks
{
    GENERATED_USTRUCT_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
        bool running = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
        FString syncMode = "";
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
        int64 lastBlockNum = -1;
};