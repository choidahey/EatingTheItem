// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Item.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PRACTICE_Item_generated_h
#error "Item.generated.h already included, missing '#pragma once' in Item.h"
#endif
#define PRACTICE_Item_generated_h

#define FID_Practice_Source_Practice_Public_Item_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetRotationSpeed); \
	DECLARE_FUNCTION(execResetActorPosition);


#define FID_Practice_Source_Practice_Public_Item_h_11_CALLBACK_WRAPPERS
#define FID_Practice_Source_Practice_Public_Item_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAItem(); \
	friend struct Z_Construct_UClass_AItem_Statics; \
public: \
	DECLARE_CLASS(AItem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Practice"), NO_API) \
	DECLARE_SERIALIZER(AItem)


#define FID_Practice_Source_Practice_Public_Item_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AItem(AItem&&); \
	AItem(const AItem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AItem) \
	NO_API virtual ~AItem();


#define FID_Practice_Source_Practice_Public_Item_h_8_PROLOG
#define FID_Practice_Source_Practice_Public_Item_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Practice_Source_Practice_Public_Item_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Practice_Source_Practice_Public_Item_h_11_CALLBACK_WRAPPERS \
	FID_Practice_Source_Practice_Public_Item_h_11_INCLASS_NO_PURE_DECLS \
	FID_Practice_Source_Practice_Public_Item_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PRACTICE_API UClass* StaticClass<class AItem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Practice_Source_Practice_Public_Item_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
