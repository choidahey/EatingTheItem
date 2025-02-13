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

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())  // LocalPlayer - 플레이어의 입력이나 화면 뷰 등을 관리하는 객체
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())  // EnhancedInputSystem을 관리하는 Subsystem 가져오기
		{
			if (InputMappingContext)  // IMC 존재 확인
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);  // IMC 할당
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

// 게임의 HUD 표시
void AMyPlayerController::ShowGameHUD()
{
	// HUD 켜져있으면 닫음
	if (HUDWidgetInstance)
	{
		HUDWidgetInstance->RemoveFromParent();
		HUDWidgetInstance = nullptr;
	}

	// 이미 메뉴 떠있으면 닫음
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
	// HUD 켜져 있으면 닫음
	if (HUDWidgetInstance)
	{
		HUDWidgetInstance->RemoveFromParent();
		HUDWidgetInstance = nullptr;
	}

	// 이미 메뉴가 켜져있으면 다시 닫아줌
	if (MainMenuWidgetInstance)
	{
		MainMenuWidgetInstance->RemoveFromParent();
		MainMenuWidgetInstance = nullptr;
	}

	// 메인 메뉴 UI 생성
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
		


		// GameOver 되었을 때
		if (bIsRestart)
		{
			ButtonText->SetText(FText::FromString(TEXT("Restart")));
			StartText->SetVisibility(ESlateVisibility::Hidden);
			// TODO : 홈버튼 보이게 추가
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
			// TODO : 홈버튼 숨기기 추가
		}
	}
}

// 게임 시작할 때 - Basic Level로 오픈하고 GameInstance 데이터 리셋해줌
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

//// WorldContextObejct - 함수가 실행될 월드 정보를 제공(일반적으로 GetWorld()사용한다고 함)
//// SpecificPlayer - 종료할 플레이어 컨트롤러를 지정할 때 사용
//// QuitPreference - 게임 종료할지 또는 백그라운드로 전환할지 결정
//// bIgnorePlatformRestrictions - 'true' : 플랫폼 제약을 무시, 게임 강제종료 / 'false' : 플랫폼 제약을 따르고 일반적인 종료 절차 수행
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
