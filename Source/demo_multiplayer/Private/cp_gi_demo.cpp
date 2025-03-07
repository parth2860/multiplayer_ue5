// Fill out your copyright notice in the Description page of Project Settings.


#include "cp_gi_demo.h"
#include "PlayfabGSDK.h"
#include "GSDKUtils.h"

DEFINE_LOG_CATEGORY(LogPlayFabGSDKGameInstance);

void Ucp_gi_demo::Init()
{
    
    if (IsDedicatedServerInstance() == true)
    {
        FOnGSDKShutdown_Dyn OnGSDKShutdown;
        OnGSDKShutdown.BindDynamic(this, &Ucp_gi_demo::OnGSDKShutdown);
        FOnGSDKHealthCheck_Dyn OnGSDKHealthCheck;
        OnGSDKHealthCheck.BindDynamic(this, &Ucp_gi_demo::OnGSDKHealthCheck);
        FOnGSDKServerActive_Dyn OnGSDKServerActive;
        OnGSDKServerActive.BindDynamic(this, &Ucp_gi_demo::OnGSDKServerActive);
        FOnGSDKReadyForPlayers_Dyn OnGSDKReadyForPlayers;
        OnGSDKReadyForPlayers.BindDynamic(this, &Ucp_gi_demo::OnGSDKReadyForPlayers);

       // UGSDKUtils::RegisterGSDKShutdownDelegate(OnGsdkShutdown);
       // UGSDKUtils::RegisterGSDKHealthCheckDelegate(OnGsdkHealthCheck);
        UGSDKUtils::RegisterGSDKServerActiveDelegate(OnGSDKServerActive);
        UGSDKUtils::RegisterGSDKReadyForPlayers(OnGSDKReadyForPlayers);
    }

#if UE_SERVER
    UGSDKUtils::SetDefaultServerHostPort();
#endif
}
void Ucp_gi_demo::OnStart()
{
    UE_LOG(LogPlayFabGSDKGameInstance, Warning, TEXT("Reached onStart!"));
    UGSDKUtils::ReadyForPlayers();
}

void Ucp_gi_demo::OnGSDKShutdown()
{
    UE_LOG(LogPlayFabGSDKGameInstance, Warning, TEXT("Shutdown!"));
    FPlatformMisc::RequestExit(false);
}

bool Ucp_gi_demo::OnGSDKHealthCheck()
{
    // Uncomment the next line if you want your server to log something at every heartbeat for sanity check.
    /* UE_LOG(LogPlayFabGSDKGameInstance, Warning, TEXT("Healthy!")); */
    return true;
}

void Ucp_gi_demo::OnGSDKServerActive()
{
    /**
     * Server is transitioning to an active state.
     * Optional: Add in the implementation any code that is needed for the game server when
     * this transition occurs.
     */
    UE_LOG(LogPlayFabGSDKGameInstance, Warning, TEXT("Active!"));
}

void Ucp_gi_demo::OnGSDKReadyForPlayers()
{
    /**
     * Server is transitioning to a StandBy state. Game initialization is complete and the game
     * is ready to accept players.
     * Optional: Add in the implementation any code that is needed for the game server before
     * initialization completes.
     */
    UE_LOG(LogPlayFabGSDKGameInstance, Warning, TEXT("Finished Initialization - Moving to StandBy!"));
}
