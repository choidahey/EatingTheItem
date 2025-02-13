#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UWidgetComponent;
struct FInputActionValue;

UCLASS()
class PRACTICE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyCharacter();

	UFUNCTION(BlueprintPure, Category = "Health")  // BlueprintPure는 Get 함수들에게 써줌
	float GetHealth() const;
	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float Amount);

protected:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

	float MaxHealth;
	float Health;

	/*UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	UWidgetComponent* OverHeadWidget;*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	UWidgetComponent* HpBarWidget;

	virtual void OnDeath();
	virtual float TakeDamage(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		AController* EventInstigator,
		AActor* DamageCauser) override;

	//void UpdateOverHeadHP();
	void UpdateHpBar();

	UFUNCTION()
	void Move(const FInputActionValue& value);  // 참조로 가져오는 이유 : 구조체는 엄청 큰 사이즈이기 때문에 성능, 복사 비용이 크다. 그래서 참조로 가져옴
	UFUNCTION()
	void StartJump(const FInputActionValue& value);  // Trigger로 받는 애들은 시작과 끝을 나눠주는 것이 좋음(EnhancedInputSystem의 취지와도 맞음)
	UFUNCTION()
	void StopJump(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);
	UFUNCTION()
	void StartSprint(const FInputActionValue& value);
	UFUNCTION()
	void StopSprint(const FInputActionValue& value);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	float NormalSpeed;
	float SprintSpeedMultiplier;  // 몇 배 곱해줄건지
	float SprintSpeed;


};
