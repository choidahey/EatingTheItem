#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HPBarWidget.generated.h"

class UProgressBar;

UCLASS()
class PRACTICE_API UHPBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UProgressBar* HPProgressBar;
	virtual void NativeConstruct() override;
	
};
