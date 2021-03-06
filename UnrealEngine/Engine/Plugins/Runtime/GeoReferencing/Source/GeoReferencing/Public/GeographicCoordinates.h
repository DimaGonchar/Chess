// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "GeographicCoordinates.generated.h"

USTRUCT(BlueprintType)
struct GEOREFERENCING_API FGeographicCoordinates
{
	GENERATED_USTRUCT_BODY()

public:

	FGeographicCoordinates();
	FGeographicCoordinates(double InLongitude, double InLatitude, double InAltitude);

	double Longitude;
	double Latitude;
	double Altitude;

	FText ToFullText(int32 IntegralDigitsLatLon = 8, int32 IntegralDigitsAlti = 2, bool bAsDMS = false);
	FText ToCompactText(int32 IntegralDigitsLatLon = 8, int32 IntegralDigitsAlti = 2, bool bAsDMS = false);
	void ToSeparateTexts(FText& OutLatitude, FText& OutLongitude, FText& OutAltitude, int32 IntegralDigitsLatLon = 8, int32 IntegralDigitsAlti = 2, bool bAsDMS = false);

private:
	static FText AsAngle(double Val, const FNumberFormattingOptions* const Options = NULL, bool bAsDMS = false);
};

UCLASS()
class GEOREFERENCING_API UGeographicCoordinatesFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/**
	 * Converts a GeographicCoordinates value to localized formatted text, in the form 'X= Y= Z='
	 **/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToFullText", AdvancedDisplay = "1", BlueprintAutocast), Category = "GeoReferencing")
	static FORCEINLINE FText ToFullText(UPARAM(ref) FGeographicCoordinates& GeographicCoordinates, int32 IntegralDigitsLatLon = 8, int32 IntegralDigitsAlti = 2, bool bAsDMS = false)
	{
		return GeographicCoordinates.ToFullText(IntegralDigitsLatLon, IntegralDigitsAlti, bAsDMS);
	}

	/**
	 * Converts a GeographicCoordinates value to formatted text, in the form '(X, Y, Z)'
	 **/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToCompactText", AdvancedDisplay = "1", BlueprintAutocast), Category = "GeoReferencing")
	static FORCEINLINE FText ToCompactText(UPARAM(ref) FGeographicCoordinates& GeographicCoordinates, int32 IntegralDigitsLatLon = 8, int32 IntegralDigitsAlti = 2, bool bAsDMS = false)
	{
		return GeographicCoordinates.ToCompactText(IntegralDigitsLatLon, IntegralDigitsAlti, bAsDMS);
	}

	/**
	 * Converts a GeographicCoordinates value to 3 separate text values
	 **/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToSeparateTexts", AdvancedDisplay = "4", BlueprintAutocast), Category = "GeoReferencing")
	static void ToSeparateTexts(UPARAM(ref) FGeographicCoordinates& GeographicCoordinates, FText& OutLatitude, FText& OutLongitude, FText& OutAltitude, int32 IntegralDigitsLatLon = 8, int32 IntegralDigitsAlti = 2, bool bAsDMS = false)
	{
		GeographicCoordinates.ToSeparateTexts(OutLatitude, OutLongitude, OutAltitude, IntegralDigitsLatLon, IntegralDigitsAlti, bAsDMS);
	}

	/**
	 * Get the Coordinates as a float approximation.
	 * USE WISELY as we can't guarantee there will no be rounding due to IEEE754 float encoding !
	 **/
	UFUNCTION(BlueprintPure, Category = "GeoReferencing")
	static void ToFloatApproximation(UPARAM(ref) FGeographicCoordinates& GeographicCoordinates, float& OutLatitude, float& OutLongitude, float& OutAltitude)
	{
		OutLatitude  = static_cast<float>(GeographicCoordinates.Latitude);
		OutLongitude = static_cast<float>(GeographicCoordinates.Longitude);
		OutAltitude  = static_cast<float>(GeographicCoordinates.Altitude);
	}

	/**
	 * Set the Coordinates from float approximation.
	 * USE WISELY as we can't guarantee there will no be rounding due to IEEE754 float encoding !
	 **/
	UFUNCTION(BlueprintPure, Category = "GeoReferencing|Coordinates")
	static FGeographicCoordinates MakeGeographicCoordinatesApproximation(const float& InLatitude, const float& InLongitude, const float& InAltitude)
	{
		return FGeographicCoordinates(static_cast<double>(InLongitude), static_cast<double>(InLatitude), static_cast<double>(InAltitude));
	}
};
