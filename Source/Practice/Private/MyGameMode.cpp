#include "MyGameMode.h"
#include "MyCharacter.h"
#include "MyPlayerController.h"
#include "MyGameState.h"

AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = AMyCharacter::StaticClass();  // Ŭ���� ������ �Ѱܼ� ��ȯ�� ���� StaticClass ���� ���
	PlayerControllerClass = AMyPlayerController::StaticClass();  // Question : ���⼭ PlayerControllerClass ��� ���� ��� �ƴ���?
	GameStateClass = AMyGameState::StaticClass();
}
