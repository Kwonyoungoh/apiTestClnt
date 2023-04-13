// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemSteam.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "UlocalSteamUser.h"
#include "serverApiTestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SERVERAPITEST_API AserverApiTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	// 멤버 변수로 LocalSteamUser 추가
	UPROPERTY(BlueprintReadWrite, Category = "Steam")
	UUlocalSteamUser* LocalSteamUser;

	UPROPERTY(BlueprintReadWrite, Category = "Steam")
	bool bIsSteamConnected;

	UFUNCTION(BlueprintCallable, Category = "UI")
	void CreateAndShowUI();

};
