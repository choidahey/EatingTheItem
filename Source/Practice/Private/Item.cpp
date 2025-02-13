#include "Item.h"


AItem::AItem()
{
	// �� ������Ʈ�� ��Ʈ�� �����ϴ� ����
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_C.SM_Star_C"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Power_Sphere_Inst.M_Power_Sphere_Inst"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;

	RotationSpeed = 90.0f;
	SpeedZ = 200.0f;
	TimeAccumulator = 0.0f;
	ChangeScaleTime = 2.0f;
	MaxScale = 5.0f;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	//SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
	//SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));  // FRoatator�� ���� - pitch(y��), yaw(z��), roll(x��) ��
	//SetActorScale3D(FVector(2.0f));

	FVector NewLocation(300.0f, 200.0f, 100.0f);
	FRotator NewRotation(0.0f, 90.0f, 0.0f);
	FVector NewScale(2.0f);

	InitialScale = NewScale;

	FTransform NewTransform(NewRotation, NewLocation, NewScale);

	SetActorTransform(NewTransform);

	OnItemPickedUp();

	

}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �ε��Ҽ����� ������ ������ ũ�� ������ ���ʿ��� 0.00000001������ ȸ���� �Ѵ�.
	// �׷��� �𸮾󿡼� �����ϴ� FMath�� 0�� �������� ����ϴ� �Լ��� ������ش�.
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
	AddActorLocalOffset(FVector(0.0f, 0.0f, SpeedZ * DeltaTime));
	TimeAccumulator += DeltaTime;

	if (TimeAccumulator > ChangeScaleTime)
		TimeAccumulator -= ChangeScaleTime;

	float ScaleFactor = InitialScale.X + MaxScale * FMath::Sin((2 * PI / ChangeScaleTime) * TimeAccumulator);

	SetActorScale3D(FVector(ScaleFactor, ScaleFactor, ScaleFactor));
		
}

void AItem::ResetActorPosition()
{
	SetActorLocation(FVector::ZeroVector);
}

float AItem::GetRotationSpeed() const
{
	return RotationSpeed;
}




