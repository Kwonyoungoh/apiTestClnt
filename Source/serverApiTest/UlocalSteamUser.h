#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemTypes.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "UlocalSteamUser.generated.h"

UCLASS()
class SERVERAPITEST_API UUlocalSteamUser : public UObject
{
	GENERATED_BODY()

public:

	// 맴버 변수 선언
	UPROPERTY(BlueprintReadWrite, Category = "Steam")
	FUniqueNetIdRepl SteamID;

	UPROPERTY(BlueprintReadWrite, Category = "Steam")
	FString AuthToken;

	UPROPERTY(BlueprintReadWrite, Category = "Steam")
	bool bIsAuth;

	UUlocalSteamUser();
};
