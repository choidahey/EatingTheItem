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
	WaveSpawnItemCounts = { 40, 50, 60 };  // TODO : ������ 3���� Wave�� �°� ���� �Է������� Wave �������� Ǯ������ ������ ���� �����ص� �� ��
} 

void AMyGameState::BeginPlay()
{
	Super::BeginPlay();

	//StartLevel();
	StartWave();

	// Ÿ�̸� ���ư��� ����
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
//	// Ÿ�̸Ӹ� LevelDuration���� �ʱ⼼��
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


// �� ���� �ȿ� �ּ� 3���� ���̺� �߰�
void AMyGameState::StartWave()
{
	// ���� ���̺� �ε����� ������� ������ ������ ���� ����
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

	// Ÿ�̸Ӹ� LevelDuration���� �ʱ⼼��
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

    // ���̺� ���� �� ó�� (��: ���� ������Ʈ)
    if (UGameInstance* GameInstance = GetGameInstance())
    {
         UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
         if (MyGameInstance)
         {
             AddScore(Score);
         }
    }

    // ���� ���̺� ����
    CurrentWaveIndex++;
    if (CurrentWaveIndex < MaxWave)
    {
         StartWave();
    }
    else
    {
         // ��� ���̺갡 �������Ƿ� ���� ���� ó��
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