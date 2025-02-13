#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"


UCLASS()
class PRACTICE_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")  // �������� �ý��ۿ� ���
	USceneComponent* SceneRoot;  // ������ Ÿ���� �������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Properties")
	float RotationSpeed;
	float SpeedZ;
	float TimeAccumulator;
	float ChangeScaleTime;
	float MaxScale;
	FVector InitialScale;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category="Item|Actions")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category="Item|Properties")
	float GetRotationSpeed() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	void OnItemPickedUp();


};
