#include "stdafx.h"
#include "Keyboard.h"

KeyboardMG::~KeyboardMG(void)
	{
	if( pDInputKeyboard )
		{
		pDInputKeyboard->Unacquire();
		pDInputKeyboard->Release();
		}
	}

bool KeyboardMG::Initialize(const LPDIRECTINPUT pDInput, const HWND hWnd)
	{
	hr = pDInput->CreateDevice(GUID_SysKeyboard , &pDInputKeyboard, NULL);
	if( FAILED(hr) )
		return false;

	hr = pDInputKeyboard->SetDataFormat( &c_dfDIKeyboard );
	if( FAILED(hr) )
		return false;

	hr = pDInputKeyboard->SetCooperativeLevel(hWnd, DISCL_FOREGROUND|DISCL_NONEXCLUSIVE);
	if( FAILED(hr) )
		return false;

	hr = pDInputKeyboard->Acquire();
	if( FAILED(hr) )
		return false;
	return true;
	}

bool KeyboardMG::UpdateState()
	{
	hr = pDInputKeyboard->GetDeviceState(sizeof(KeyBuffer) ,KeyBuffer);
	while( hr == DIERR_INPUTLOST ) 
		hr = pDInputKeyboard->Acquire();
	if( FAILED(hr) )
		return false;
	return true;
	}

bool KeyboardMG::Pressed(int DIK)
	{
	return (KeyBuffer[DIK] & 0x80);//Mask: 10000000
	}