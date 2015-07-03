////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////					Input Manager				  //////////////////////////////////////
///////////////////////////////////					for Keyboard				  //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once


class KeyboardMG
	{
	private:
		HRESULT hr;
	public:
		KeyboardMG(): pDInputKeyboard(NULL){}
		~KeyboardMG(void);

			//Variables, not protected because dont want to impose 
			//the way to work

		//Keyboard device
		LPDIRECTINPUTDEVICE pDInputKeyboard;
		//Key Buffer
		char KeyBuffer[256];

			//Basic Functionality, it is in the user to respect 
			//encapsulation or not

		//Initialize the Direct Input Device, before this 
		//the Manager is unusable
		bool Initialize(const LPDIRECTINPUT pDInput, HWND hWnd);

		//Update the keybuffer state with the current one,
		//and re-acquire the device if needed
		bool UpdateState();

		//Says if DIK is currently pressed
		bool Pressed(int DIK);
	};

