#include "MyGameState.h"
#include "MyGameInstance.h"
#include "MyPlayerController.h"
#include "SpawnVolume.h"
#include "CoinItem.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"

AMyGameState::AMyGameState()
{
	Score = 0;
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;
	/*LevelDuration = 30.0f;*/
	LevelDuration = 10.0f;
	/*CurrentLevelIndex = 0;
	MaxLevel = 3;*/
	CurrentWaveIndex = 0;
	MaxWave = 3;
	WaveSpawnItemCounts = { 40, 50, 60 };  // TODO : 지금은 3개의 Wave에 맞게 직접 입력했지만 Wave 많아지면 풀링으로 아이템 스폰 관리해도 될 듯
} 

void AMyGameState::BeginPlay()
{
	Super::BeginPlay();

	//StartLevel();
	StartWave();

	// 타이머 돌아가기 시작
	GetWorldTimerManager().SetTimer(
		HUDUpdateTimerHandle,
		this,
		&AMyGameState::UpdateHUD,
		0.1f,
		true
	);
}

int32 AMyGameState::GetScore() const
{
	return Score;
}

void AMyGameState::AddScore(int32 Amount)
{
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
		if (MyGameInstance)
		{
			MyGameInstance->AddToScore(Amount);
		}
	}
}

//void AMyGameState::StartLevel()
//{
//	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
//	{
//		if (AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController))
//		{
//			MyPlayerController->ShowGameHUD();
//		}
//	}
//
//	if (UGameInstance* GameInstance = GetGameInstance())
//	{
//		UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
//		if (MyGameInstance)
//		{
//			CurrentLevelIndex = MyGameInstance->CurrentLevelIndex;
//		}
//	}
//
//	SpawnedCoinCount = 0;
//	CollectedCoinCount = 0;
//
//	TArray<AActor*> FoundVolumes;
//	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);
//
//	const int32 ItemToSpawn = 40;
//
//	if (FoundVolumes.Num() > 0)
//	{
//		ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
//		if (SpawnVolume)
//		{
//			for (int32 i = 0; i < ItemToSpawn; i++)
//			{
//				AActor* SpawnedActor = SpawnVolume->SpawnRandomItem();
//				if (SpawnedActor && SpawnedActor->IsA(ACoinItem::StaticClass()))
//				{
//					SpawnedCoinCount++;
//				}
//			}
//		}
//	}
//
//	// 타이머를 LevelDuration으로 초기세팅
//	GetWorldTimerManager().SetTimer(
//		LevelTimerHandle,
//		this,
//		&AMyGameState::OnLevelTimeUp,
//		LevelDuration,
//		false
//	);
//
//	UpdateHUD();
//
//	UE_LOG(LogTemp, Warning, TEXT("Level %d Start!, Spawned %d coin"),
//		CurrentLevelIndex + 1,
//		SpawnedCoinCount);
//}

//void AMyGameState::EndLevel()
//{
//	GetWorldTimerManager().ClearTimer(LevelTimerHandle);
//
//	if (UGameInstance* GameInstance = GetGameInstance())
//	{
//		UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
//		if (MyGameInstance)
//		{
//			AddScore(Score);
//			CurrentLevelIndex++;
//			MyGameInstance->CurrentLevelIndex = CurrentLevelIndex;
//
//			if (CurrentLevelIndex >= MaxLevel)
//			{
//				OnGameOver();
//				return;
//			}
//
//			if (LevelMapNames.IsValidIndex(CurrentLevelIndex))
//			{
//				UGameplayStatics::OpenLevel(GetWorld(), LevelMapNames[CurrentLevelIndex]);
//			}
//			else
//			{
//				OnGameOver();
//			}
//		}
//	}
//}


// 한 레벨 안에 최소 3개의 웨이브 추가
void AMyGameState::StartWave()
{
	// 현재 웨이브 인덱스를 기반으로 스폰할 아이템 갯수 결정
	int32 ItemToSpawn = 0;

	if (WaveSpawnItemCounts.IsValidIndex(CurrentWaveIndex))
	{
		ItemToSpawn = WaveSpawnItemCounts[CurrentWaveIndex];
	}
	else
	{
		ItemToSpawn = WaveSpawnItemCounts[0];
	}

	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController))
		{
			MyPlayerController->ShowGameHUD();
		}
	}

	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;

	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);


	if (FoundVolumes.Num() > 0)
	{
		ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
		if (SpawnVolume)
		{
			for (int32 i = 0; i < ItemToSpawn; i++)
			{
				AActor* SpawnedActor = SpawnVolume->SpawnRandomItem();
				/*if (SpawnedActor && SpawnedActor->IsA(ACoinItem::StaticClass()))*/
				if (SpawnedActor)
				{
					SpawnedItemList.Add(SpawnedActor);

					if (SpawnedActor->IsA(ACoinItem::StaticClass()))
						SpawnedCoinCount++;
				}
			}
		}
	}

	// 타이머를 LevelDuration으로 초기세팅
	GetWorldTimerManager().SetTimer(
		LevelTimerHandle,
		this,
		&AMyGameState::OnWaveTimeUp,
		LevelDuration,
		false
	);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%d Wave begins!"), CurrentWaveIndex + 1));
	UpdateHUD();
}

void AMyGameState::EndWave()
{
	GetWorldTimerManager().ClearTimer(LevelTimerHandle);

	for (AActor* Item : SpawnedItemList)
	{
		if (Item)
		{
			Item->Destroy();
		}
	}
	SpawnedItemList.Empty();

    // 웨이브 종료 후 처리 (예: 점수 업데이트)
    if (UGameInstance* GameInstance = GetGameInstance())
    {
         UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
         if (MyGameInstance)
         {
             AddScore(Score);
         }
    }

    // 다음 웨이브 진행
    CurrentWaveIndex++;
    if (CurrentWaveIndex < MaxWave)
    {
         StartWave();
    }
    else
    {
         // 모든 웨이브가 끝났으므로 레벨 종료 처리
         OnGameOver();
		 return;
    }
}


//void AMyGameState::OnLevelTimeUp()
//{
//	EndLevel();
//}

void AMyGameState::OnWaveTimeUp()
{
	EndWave();
}


void AMyGameState::OnCoinCollected()
{
	CollectedCoinCount++;

	UE_LOG(LogTemp, Warning, TEXT("Coin Collected: %d / %d"),
		CollectedCoinCount,
		SpawnedCoinCount)

		if (SpawnedCoinCount > 0 && CollectedCoinCount >= SpawnedCoinCount)
		{
			//EndLevel();
			EndWave();
		}
}

void AMyGameState::OnGameOver()
{
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController))
		{
			MyPlayerController->SetPause(true);
			MyPlayerController->ShowMainMenu(true);
		}
	}
}

void AMyGameState::UpdateHUD()
{
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController);
		{
			if (UUserWidget* HUDWidget = MyPlayerController->GetHUDWidget())
			{
				if (UTextBlock* TimeText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Time"))))
				{
					float RemainingTime = GetWorldTimerManager().GetTimerRemaining(LevelTimerHandle);
					TimeText->SetText(FText::FromString(FString::Printf(TEXT("Time : %.1f"), RemainingTime)));
				}

				if (UTextBlock* ScoreText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Score"))))
				{
					if (UGameInstance* GameInstance = GetGameInstance())
					{
						UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
						if (MyGameInstance)
						{
							ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score : %d"), MyGameInstance->TotalScore)));
						}
					}
				}

				if (UTextBlock* LevelIndexText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Level"))))
				{
					/*LevelIndexText->SetText(FText::FromString(FString::Printf(TEXT("Level : %d"), CurrentLevelIndex + 1)));*/
					LevelIndexText->SetText(FText::FromString(FString::Printf(TEXT("%d Wave"), CurrentWaveIndex + 1)));
				}
			}
		}
	}
}