// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Practice/Public/HealingItem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHealingItem() {}

// Begin Cross Module References
PRACTICE_API UClass* Z_Construct_UClass_ABaseItem();
PRACTICE_API UClass* Z_Construct_UClass_AHealingItem();
PRACTICE_API UClass* Z_Construct_UClass_AHealingItem_NoRegister();
UPackage* Z_Construct_UPackage__Script_Practice();
// End Cross Module References

// Begin Class AHealingItem
void AHealingItem::StaticRegisterNativesAHealingItem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHealingItem);
UClass* Z_Construct_UClass_AHealingItem_NoRegister()
{
	return AHealingItem::StaticClass();
}
struct Z_Construct_UClass_AHealingItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "HealingItem.h" },
		{ "ModuleRelativePath", "Public/HealingItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealAmout_MetaData[] = {
		{ "Category", "Item" },
		{ "ModuleRelativePath", "Public/HealingItem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_HealAmout;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHealingItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AHealingItem_Statics::NewProp_HealAmout = { "HealAmout", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealingItem, HealAmout), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealAmout_MetaData), NewProp_HealAmout_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHealingItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealingItem_Statics::NewProp_HealAmout,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHealingItem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AHealingItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABaseItem,
	(UObject* (*)())Z_Construct_UPackage__Script_Practice,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHealingItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AHealingItem_Statics::ClassParams = {
	&AHealingItem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AHealingItem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AHealingItem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealingItem_Statics::Class_MetaDataParams), Z_Construct_UClass_AHealingItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AHealingItem()
{
	if (!Z_Registration_Info_UClass_AHealingItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHealingItem.OuterSingleton, Z_Construct_UClass_AHealingItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AHealingItem.OuterSingleton;
}
template<> PRACTICE_API UClass* StaticClass<AHealingItem>()
{
	return AHealingItem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AHealingItem);
AHealingItem::~AHealingItem() {}
// End Class AHealingItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Practice_Source_Practice_Public_HealingItem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AHealingItem, AHealingItem::StaticClass, TEXT("AHealingItem"), &Z_Registration_Info_UClass_AHealingItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHealingItem), 2686772598U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Practice_Source_Practice_Public_HealingItem_h_3369968501(TEXT("/Script/Practice"),
	Z_CompiledInDeferFile_FID_Practice_Source_Practice_Public_HealingItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Practice_Source_Practice_Public_HealingItem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
