// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyPawn.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PRACTICE_MyPawn_generated_h
#error "MyPawn.generated.h already included, missing '#pragma once' in MyPawn.h"
#endif
#define PRACTICE_MyPawn_generated_h

#define FID_Practice_Source_Practice_Public_MyPawn_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyPawn(); \
	friend struct Z_Construct_UClass_AMyPawn_Statics; \
public: \
	DECLARE_CLASS(AMyPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Practice"), NO_API) \
	DECLARE_SERIALIZER(AMyPawn)


#define FID_Practice_Source_Practice_Public_MyPawn_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMyPawn(AMyPawn&&); \
	AMyPawn(const AMyPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyPawn) \
	NO_API virtual ~AMyPawn();


#define FID_Practice_Source_Practice_Public_MyPawn_h_8_PROLOG
#define FID_Practice_Source_Practice_Public_MyPawn_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Practice_Source_Practice_Public_MyPawn_h_11_INCLASS_NO_PURE_DECLS \
	FID_Practice_Source_Practice_Public_MyPawn_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PRACTICE_API UClass* StaticClass<class AMyPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Practice_Source_Practice_Public_MyPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
