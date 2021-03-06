// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Slate/SceneViewport.h"
#include "SEditorViewport.h"
#include "SCommonEditorViewportToolbarBase.h"

#include "NiagaraBakerSettings.h"

class FNiagaraBakerViewModel;
class FNiagaraBakerViewportClient;

class SNiagaraBakerViewport : public SEditorViewport, public ICommonEditorViewportToolbarInfoProvider
{
public:
	SLATE_BEGIN_ARGS(SNiagaraBakerViewport) {}
		SLATE_ARGUMENT(TWeakPtr<FNiagaraBakerViewModel>, WeakViewModel)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	// SEditorViewport interface
	void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;
	TSharedPtr<SWidget> MakeViewportToolbar() override;
	// SEditorViewport interface

	// ICommonEditorViewportToolbarInfoProvider interface
	virtual TSharedRef<SEditorViewport> GetViewportWidget() override;
	virtual TSharedPtr<FExtender> GetExtenders() const override;
	virtual void OnFloatingButtonClicked() override;
	// ICommonEditorViewportToolbarInfoProvider interface

	void RefreshView(const float CurrentTime, const float DeltaTime);

	bool IsInfoTextEnabled() const;
	void SetInfoTextEnabled(bool bEnabled);

	bool IsPreviewViewEnabled() const;
	void SetPreviewViewEnabled(bool bEnabled);

	bool IsBakerViewEnabled() const;
	void SetBakerViewEnabled(bool bEnabled);

	ENiagaraBakerViewMode GetCameraMode() const;
	void SetCameraMode(ENiagaraBakerViewMode Mode);
	bool IsCameraMode(ENiagaraBakerViewMode Mode) const;

	FText GetCameraModeText(ENiagaraBakerViewMode Mode) const;
	FName GetCameraModeIconName(ENiagaraBakerViewMode Mode) const;

	FText GetActiveCameraModeText() const { return GetCameraModeText(GetCameraMode()); }
	const struct FSlateBrush* GetActiveCameraModeIcon() const;

private:
	TWeakPtr<FNiagaraBakerViewModel>			WeakViewModel;
	TSharedPtr<FNiagaraBakerViewportClient>	ViewportClient;
};
