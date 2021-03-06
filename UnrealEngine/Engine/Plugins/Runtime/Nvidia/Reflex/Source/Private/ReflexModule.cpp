// Copyright Epic Games, Inc. All Rights Reserved.

#include "ReflexModule.h"

#include "Modules/ModuleManager.h"

IMPLEMENT_MODULE(FReflexModule, Reflex);

void FReflexModule::StartupModule()
{
	ReflexMaxTickRateHandler = MakeUnique<FReflexMaxTickRateHandler>();
	if (ReflexMaxTickRateHandler.IsValid())
	{
		ReflexMaxTickRateHandler->Initialize();
		IModularFeatures::Get().RegisterModularFeature(ReflexMaxTickRateHandler->GetModularFeatureName(), ReflexMaxTickRateHandler.Get());
	}

	ReflexLatencyMarker = MakeUnique<FReflexLatencyMarkers>();
	if (ReflexLatencyMarker.IsValid())
	{
		ReflexLatencyMarker->Initialize();
		IModularFeatures::Get().RegisterModularFeature(ReflexLatencyMarker->GetModularFeatureName(), ReflexLatencyMarker.Get());
	}
}

void FReflexModule::ShutdownModule()
{
	if (ReflexMaxTickRateHandler.IsValid())
	{
		IModularFeatures::Get().UnregisterModularFeature(ReflexMaxTickRateHandler->GetModularFeatureName(), ReflexMaxTickRateHandler.Get());
	}

	if (ReflexLatencyMarker.IsValid())
	{
		IModularFeatures::Get().UnregisterModularFeature(ReflexLatencyMarker->GetModularFeatureName(), ReflexLatencyMarker.Get());
	}
}