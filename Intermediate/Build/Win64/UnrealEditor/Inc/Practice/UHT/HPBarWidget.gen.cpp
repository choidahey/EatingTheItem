// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Practice/Public/HPBarWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHPBarWidget() {}

// Begin Cross Module References
PRACTICE_API UClass* Z_Construct_UClass_UHPBarWidget();
PRACTICE_API UClass* Z_Construct_UClass_UHPBarWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Practice();
// End Cross Module References

// Begin Class UHPBarWidget
void UHPBarWidget::StaticRegisterNativesUHPBarWidget()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHPBarWidget);
UClass* Z_Construct_UClass_UHPBarWidget_NoRegister()
{
	return UHPBarWidget::StaticClass();
}
struct Z_Construct_UClass_UHPBarWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "HPBarWidget.h" },
		{ "ModuleRelativePath", "Public/HPBarWidget.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHPBarWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UHPBarWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Practice,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHPBarWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHPBarWidget_Statics::ClassParams = {
	&UHPBarWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHPBarWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UHPBarWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UHPBarWidget()
{
	if (!Z_Registration_Info_UClass_UHPBarWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHPBarWidget.OuterSingleton, Z_Construct_UClass_UHPBarWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHPBarWidget.OuterSingleton;
}
template<> PRACTICE_API UClass* StaticClass<UHPBarWidget>()
{
	return UHPBarWidget::StaticClass();
}
UHPBarWidget::UHPBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UHPBarWidget);
UHPBarWidget::~UHPBarWidget() {}
// End Class UHPBarWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_Practice_Source_Practice_Public_HPBarWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHPBarWidget, UHPBarWidget::StaticClass, TEXT("UHPBarWidget"), &Z_Registration_Info_UClass_UHPBarWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHPBarWidget), 3632051003U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Practice_Source_Practice_Public_HPBarWidget_h_3611347200(TEXT("/Script/Practice"),
	Z_CompiledInDeferFile_FID_Practice_Source_Practice_Public_HPBarWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Practice_Source_Practice_Public_HPBarWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
