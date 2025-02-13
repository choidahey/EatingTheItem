#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MyGameState.generated.h"

UCLASS()
class PRACTICE_API AMyGameState : public AGameState
{
	GENERATED_BODY()

public:
	AMyGameState();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
	int32 Score;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 SpawnedCoinCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 CollectedCoinCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	float LevelDuration;

	// Level肺 包府
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	//int32 CurrentLevelIndex;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	//int32 MaxLevel;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	//TArray<FName> LevelMapNames;

	// Wave肺 包府
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 CurrentWaveIndex;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 MaxWave;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	TArray<int32> WaveSpawnItemCounts;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	TArray<AActor*> SpawnedItemList;

	FTimerHandle LevelTimerHandle;
	FTimerHandle HUDUpdateTimerHandle;
	

	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);
	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnGameOver();

	// Level肺 包府
	//void StartLevel();
	//void EndLevel();
	
	// Wave肺 包府
	void StartWave();
	void EndWave();
	
	void UpdateHUD();
	//void OnLevelTimeUp();
	void OnWaveTimeUp();
	void OnCoinCollected();
};
