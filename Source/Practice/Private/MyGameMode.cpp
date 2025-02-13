#include "MyGameMode.h"
#include "MyCharacter.h"
#include "MyPlayerController.h"
#include "MyGameState.h"

AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = AMyCharacter::StaticClass();  // 클래스 정보를 넘겨서 반환할 때는 StaticClass 많이 사용
	PlayerControllerClass = AMyPlayerController::StaticClass();  // Question : 여기서 PlayerControllerClass 라는 것을 어떻게 아는지?
	GameStateClass = AMyGameState::StaticClass();
}
