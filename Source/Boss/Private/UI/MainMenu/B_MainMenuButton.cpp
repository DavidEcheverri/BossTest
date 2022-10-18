// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenu/B_MainMenuButton.h"


UB_MainMenuButton::UB_MainMenuButton()
{
	CheckFocusRate = 0.1f;
}


void UB_MainMenuButton::Start()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandler_CheckFocus, this, &UB_MainMenuButton::CheckFocus, CheckFocusRate, true);
}

void UB_MainMenuButton::CheckFocus()
{
	if (IsHovered()) 
	{
		SetKeyboardFocus();
		SetButtonStyle(EB_ButtonStyleType::ButtonStyleType_Mouse);
	}
	else 
	{
		EB_ButtonStyleType StyleTypeSelected = HasKeyboardFocus() ? EB_ButtonStyleType::ButtonStyleType_KeySelected : EB_ButtonStyleType::ButtonStyleType_KeyNotSelected;
		SetButtonStyle(StyleTypeSelected);
	}
}

void UB_MainMenuButton::SetButtonStyle(EB_ButtonStyleType NewStyleType)
{
	BP_SetButtonStyle(NewStyleType);
}

