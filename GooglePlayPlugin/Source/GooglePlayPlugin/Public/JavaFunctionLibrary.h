// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "CoreUObject/Public/UObject/Object.h"
#include "JavaFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GOOGLEPLAYPLUGIN_API UJavaFunctionLibrary : public UObject
{
	GENERATED_BODY()
public:

#if PLATFORM_ANDROID
	static void InitJavaFunctions();
#endif

	UFUNCTION(BlueprintCallable, Category="|GooglePlayGamesService|GooglePlay")
	static void TryLogin();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="|GooglePlayGamesService|GooglePlay")
	static FString GetGooglePGSPlayerId();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="|GooglePlayGamesService|GooglePlay")
	static FString GetGooglePGSDisplayName();
};
