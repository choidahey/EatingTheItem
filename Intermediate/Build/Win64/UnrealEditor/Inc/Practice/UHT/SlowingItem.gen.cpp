// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Practice/Public/SlowingItem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSlowingItem() {}

// Begin Cross Module References
PRACTICE_API UClass* Z_Construct_UClass_ABaseItem();
PRACTICE_API UClass* Z_Construct_UClass_ASlowingItem();
PRACTICE_API UClass* Z_Construct_UClass_ASlowingItem_NoRegister();
UPackage* Z_Construct_UPackage__Script_Practice();
// End Cross Module References

// Begin Class ASlowingItem
void ASlowingItem::StaticRegisterNativesASlowingItem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASlowingItem);
UClass* Z_Construct_UClass_ASlowingItem_NoRegister()
{
	return ASlowingItem::StaticClass();
}
struct Z_Construct_UClass_ASlowingItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SlowingItem.h" },
		{ "ModuleRelativePath", "Public/SlowingItem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASlowingItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ASlowingItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseItem,
	(UObject* (*)())Z_Construct_UPackage__Script_Practice,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASlowingItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASlowingItem_Statics::ClassParams = {
	&ASlowingItem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASlowingItem_Statics::Class_MetaDataParams), Z_Construct_UClass_ASlowingItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASlowingItem()
{
	if (!Z_Registration_Info_UClass_ASlowingItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASlowingItem.OuterSingleton, Z_Construct_UClass_ASlowingItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASlowingItem.OuterSingleton;
}
template<> PRACTICE_API UClass* StaticClass<ASlowingItem>()
{
	return ASlowingItem::StaticClass();
}
ASlowingItem::ASlowingItem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASlowingItem);
ASlowingItem::~ASlowingItem() {}
// End Class ASlowingItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Practice_Source_Practice_Public_SlowingItem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASlowingItem, ASlowingItem::StaticClass, TEXT("ASlowingItem"), &Z_Registration_Info_UClass_ASlowingItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASlowingItem), 1403539328U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Practice_Source_Practice_Public_SlowingItem_h_292134203(TEXT("/Script/Practice"),
	Z_CompiledInDeferFile_FID_Practice_Source_Practice_Public_SlowingItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Practice_Source_Practice_Public_SlowingItem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
