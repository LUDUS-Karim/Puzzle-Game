// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */

class UUserWidget;
class UMenuWidget;

UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance,public IMenuInterface
{
	GENERATED_BODY()

public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init();

	UFUNCTION(BlueprintCallable)//call by blueprint
	void LoadMenu();

	UFUNCTION(BlueprintCallable)//call by blueprint
	void InGameLoadMenu();
	
	UFUNCTION(Exec)//call by console
	void Host() override;

	UFUNCTION(Exec)
	void Join(const FString& Address)override;

	virtual void LoadMainMenu() override;


private :
	TSubclassOf<UUserWidget> MenuClass;

	TSubclassOf<UUserWidget> InGameMenuClass;


	UMenuWidget *Menu;


	
};
