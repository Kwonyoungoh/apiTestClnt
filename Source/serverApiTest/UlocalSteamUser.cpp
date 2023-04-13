#include "UlocalSteamUser.h"

// 기본값 설정
UUlocalSteamUser::UUlocalSteamUser()
{
	SteamID = FUniqueNetIdRepl();
	AuthToken = FString();
	bIsAuth = false;
}
