// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePractice_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Practice;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Practice()
	{
		if (!Z_Registration_Info_UPackage__Script_Practice.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Practice",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xED090E7D,
				0xED1B8491,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Practice.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Practice.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Practice(Z_Construct_UPackage__Script_Practice, TEXT("/Script/Practice"), Z_Registration_Info_UPackage__Script_Practice, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xED090E7D, 0xED1B8491));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
