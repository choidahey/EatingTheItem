// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ItemInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef PRACTICE_ItemInterface_generated_h
#error "ItemInterface.generated.h already included, missing '#pragma once' in ItemInterface.h"
#endif
#define PRACTICE_ItemInterface_generated_h

#define FID_Practice_Source_Practice_Public_ItemInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnItemEndOverlap); \
	DECLARE_FUNCTION(execOnItemOverlap);


#define FID_Practice_Source_Practice_Public_ItemInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PRACTICE_API UItemInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UItemInterface(UItemInterface&&); \
	UItemInterface(const UItemInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PRACTICE_API, UItemInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UItemInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UItemInterface) \
	PRACTICE_API virtual ~UItemInterface();


#define FID_Practice_Source_Practice_Public_ItemInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUItemInterface(); \
	friend struct Z_Construct_UClass_UItemInterface_Statics; \
public: \
	DECLARE_CLASS(UItemInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/Practice"), PRACTICE_API) \
	DECLARE_SERIALIZER(UItemInterface)


#define FID_Practice_Source_Practice_Public_ItemInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Practice_Source_Practice_Public_ItemInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Practice_Source_Practice_Public_ItemInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Practice_Source_Practice_Public_ItemInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IItemInterface() {} \
public: \
	typedef UItemInterface UClassType; \
	typedef IItemInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Practice_Source_Practice_Public_ItemInterface_h_10_PROLOG
#define FID_Practice_Source_Practice_Public_ItemInterface_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Practice_Source_Practice_Public_ItemInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Practice_Source_Practice_Public_ItemInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PRACTICE_API UClass* StaticClass<class UItemInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Practice_Source_Practice_Public_ItemInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
