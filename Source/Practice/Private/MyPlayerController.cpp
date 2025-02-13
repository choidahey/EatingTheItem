#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Blueprint/UserWidget.h"
#include "MyGameState.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

AMyPlayerController::AMyPlayerController()
	:InputMappingContext(nullptr),
	 MoveAction(nullptr),
	 JumpAction(nullptr),
	 LookAction(nullptr),
	 SprintAction(nullptr),
	 HUDWidgetClass(nullptr),
	 HUDWidgetInstance(nullptr),
	 MainMenuWidgetClass(nullptr),
	 MainMenuWidgetInstance(nullptr)
{
	
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())  // LocalPlayer - �÷��̾��� �Է��̳� ȭ�� �� ���� �����ϴ� ��ü
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())  // EnhancedInputSystem�� �����ϴ� Subsystem ��������
		{
			if (InputMappingContext)  // IMC ���� Ȯ��
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);  // IMC �Ҵ�
			}
		}
	}

	FString CurrentMapName = GetWorld()->GetMapName();
	if (CurrentMapName.Contains("MenuLevel"))
	{
		ShowMainMenu(false);
	}
}

UUserWidget* AMyPlayerController::GetHUDWidget() const
{
	return HUDWidgetInstance;
}

// ������ HUD ǥ��
void AMyPlayerController::ShowGameHUD()
{
	// HUD ���������� ����
	if (HUDWidgetInstance)
	{
		HUDWidgetInstance->RemoveFromParent();
		HUDWidgetInstance = nullptr;
	}

	// �̹� �޴� �������� ����
	if (MainMenuWidgetInstance)
	{
		MainMenuWidgetInstance->RemoveFromParent();
		MainMenuWidgetInstance = nullptr;
	}

	if (HUDWidgetClass)
	{
		HUDWidgetInstance = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidgetInstance)
		{
			HUDWidgetInstance->AddToViewport();

			bShowMouseCursor = true;
			SetInputMode(FInputModeGameOnly());

			AMyGameState* MyGameState = GetWorld() ? GetWorld()->GetGameState<AMyGameState>() : nullptr;
			if (MyGameState)
			{
				MyGameState->UpdateHUD();
			}
		}
	}
}

void AMyPlayerController::ShowMainMenu(bool bIsRestart)
{
	// HUD ���� ������ ����
	if (HUDWidgetInstance)
	{
		HUDWidgetInstance->RemoveFromParent();
		HUDWidgetInstance = nullptr;
	}

	// �̹� �޴��� ���������� �ٽ� �ݾ���
	if (MainMenuWidgetInstance)
	{
		MainMenuWidgetInstance->RemoveFromParent();
		MainMenuWidgetInstance = nullptr;
	}

	// ���� �޴� UI ����
	if (MainMenuWidgetClass)
	{
		MainMenuWidgetInstance = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
		if (MainMenuWidgetInstance)
		{
			MainMenuWidgetInstance->AddToViewport();

			bShowMouseCursor = true;
			SetInputMode(FInputModeUIOnly());
		}
		/*if (UTextBlock* ButtonText = Cast<UTextBlock>(MainMenuWidgetInstance->GetWidgetFromName(TEXT("StartButtonText"))))
		{
			if (bIsRestart)
			{
				ButtonText->SetText(FText::FromString(TEXT("Restart")));
			}
			else
			{
				ButtonText->SetText(FText::FromString(TEXT("Start")));
			}
		}*/

		UTextBlock* ButtonText = Cast<UTextBlock>(MainMenuWidgetInstance->GetWidgetFromName(TEXT("StartButtonText")));
		UTextBlock* StartText = Cast<UTextBlock>(MainMenuWidgetInstance->GetWidgetFromName("StartNoticeText"));
		UFunction* PlayAnimFunc = MainMenuWidgetInstance->FindFunction(FName("PlayGameOverAnim"));
		//UFunction* StartAnimFuc = MainMenuWidgetInstance->FindFunction(FName("PlayStartNoticeAnim"));
		UButton* HomeButton = Cast<UButton>(MainMenuWidgetInstance->GetWidgetFromName(TEXT("HomeButton")));
		


		// GameOver �Ǿ��� ��
		if (bIsRestart)
		{
			ButtonText->SetText(FText::FromString(TEXT("Restart")));
			StartText->SetVisibility(ESlateVisibility::Hidden);
			// TODO : Ȩ��ư ���̰� �߰�
            //HomeButton->SetVisibility(ESlateVisibility::Visible);

			if (PlayAnimFunc)
			{
				MainMenuWidgetInstance->ProcessEvent(PlayAnimFunc, nullptr);
			}
			if (UTextBlock* TotalScoreText = Cast<UTextBlock>(MainMenuWidgetInstance->GetWidgetFromName("TotalScoreText")))
			{
				if (UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance (this)))
				{
					TotalScoreText->SetText(FText::FromString(FString::Printf(TEXT("Total Score : %d"), MyGameInstance->TotalScore)));
				}
			}
		}
		else
		{
			ButtonText->SetText(FText::FromString(TEXT("Start")));
			StartText->SetVisibility(ESlateVisibility::Visible);
			// TODO : Ȩ��ư ����� �߰�
		}
	}
}

// ���� ������ �� - Basic Level�� �����ϰ� GameInstance ������ ��������
void AMyPlayerController::StartGame()
{
	if (UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(this)))
	{
		MyGameInstance->CurrentLevelIndex = 0;
		MyGameInstance->TotalScore = 0;
	}

	UGameplayStatics::OpenLevel(GetWorld(), FName("BasicLevel"));
	SetPause(false);
}

//// WorldContextObejct - �Լ��� ����� ���� ������ ����(�Ϲ������� GetWorld()����Ѵٰ� ��)
//// SpecificPlayer - ������ �÷��̾� ��Ʈ�ѷ��� ������ �� ���
//// QuitPreference - ���� �������� �Ǵ� ��׶���� ��ȯ���� ����
//// bIgnorePlatformRestrictions - 'true' : �÷��� ������ ����, ���� �������� / 'false' : �÷��� ������ ������ �Ϲ����� ���� ���� ����
//void UKismetSystemLibrary::QuitGame(
//	const UObject* WorldContextObject,
//	class APlayerController* SpecificPlayer,
//	TEnumAsByte<EQuitPreference::Type> QuitPreference,
//	bool bIgnorePlatformRestrictions)
//{
//	APlayerController* TargetPC = SpecificPlayer ? SpecificPlayer : UGameplayStatics::GetPlayerController(WorldContextObject, 0);
//	if (TargetPC)
//	{
//		if (QuitPreference == EQuitPreference::Background)
//		{
//			TargetPC->ConsoleCommand("quit background");
//		}
//		else
//		{
//			if (bIgnorePlatformRestrictions)
//			{
//				TargetPC->ConsoleCommand("quit force");
//			}
//			else
//			{
//				TargetPC->ConsoleCommand("quit");
//			}
//		}
//	}
//}
