// Copyright Epic Games, Inc. All Rights Reserved.


#include "serverApiTestGameModeBase.h"

void AserverApiTestGameModeBase::CreateAndShowUI()
{
	// UI 생성
	// UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
	// Widget->AddToViewport();
}

void AserverApiTestGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// 스팀 유저정보 초기화
	LocalSteamUser = NewObject<UUlocalSteamUser>();

	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get(FName("Steam"));
	if (OnlineSub)
	{
		IOnlineIdentityPtr Identity = OnlineSub->GetIdentityInterface();
		if (Identity.IsValid())
		{
			FUniqueNetIdRepl UniqueId = Identity->GetUniquePlayerId(0);
			FString AuthToken = Identity->GetAuthToken(0);

			if (!AuthToken.IsEmpty())
			{
				UE_LOG(LogTemp, Warning, TEXT("Auth Token: %s"), *AuthToken);
				LocalSteamUser->AuthToken = AuthToken;
			}
			else
			{
				UE_LOG(LogTemp,Warning,TEXT("AuthToken is Empty."));
			}
			if (UniqueId.IsValid())
			{
				UE_LOG(LogTemp, Warning, TEXT("Unique ID: %s"), *UniqueId->ToString());
				LocalSteamUser->SteamID = UniqueId;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Unique ID is not valid"));
			}

		}
		else 
		{
			UE_LOG(LogTemp, Warning, TEXT("GetIdentityInterface() is faild"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Online Subsystem not found"));
	}

}
