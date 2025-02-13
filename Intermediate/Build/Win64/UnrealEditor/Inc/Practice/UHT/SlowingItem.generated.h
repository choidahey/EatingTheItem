// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SlowingItem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PRACTICE_SlowingItem_generated_h
#error "SlowingItem.generated.h already included, missing '#pragma once' in SlowingItem.h"
#endif
#define PRACTICE_SlowingItem_generated_h

#define FID_Practice_Source_Practice_Public_SlowingItem_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASlowingItem(); \
	friend struct Z_Construct_UClass_ASlowingItem_Statics; \
public: \
	DECLARE_CLASS(ASlowingItem, ABaseItem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Practice"), NO_API) \
	DECLARE_SERIALIZER(ASlowingItem)


#define FID_Practice_Source_Practice_Public_SlowingItem_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASlowingItem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ASlowingItem(ASlowingItem&&); \
	ASlowingItem(const ASlowingItem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASlowingItem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASlowingItem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASlowingItem) \
	NO_API virtual ~ASlowingItem();


#define FID_Practice_Source_Practice_Public_SlowingItem_h_7_PROLOG
#define FID_Practice_Source_Practice_Public_SlowingItem_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Practice_Source_Practice_Public_SlowingItem_h_10_INCLASS_NO_PURE_DECLS \
	FID_Practice_Source_Practice_Public_SlowingItem_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PRACTICE_API UClass* StaticClass<class ASlowingItem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Practice_Source_Practice_Public_SlowingItem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
