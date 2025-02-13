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

	UFUNCTION(BlueprintPure, Category = "Health")  // BlueprintPure�� Get �Լ��鿡�� ����
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
	void Move(const FInputActionValue& value);  // ������ �������� ���� : ����ü�� ��û ū �������̱� ������ ����, ���� ����� ũ��. �׷��� ������ ������
	UFUNCTION()
	void StartJump(const FInputActionValue& value);  // Trigger�� �޴� �ֵ��� ���۰� ���� �����ִ� ���� ����(EnhancedInputSystem�� �����͵� ����)
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
	float SprintSpeedMultiplier;  // �� �� �����ٰ���
	float SprintSpeed;


};
