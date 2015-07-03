////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////				Sound Primitive Manager			  //////////////////////////////////////
///////////////////////////////////			Uses DirectSound(deprecated but		  //////////////////////////////////////
///////////////////////////////////			absolutely low level interfaze)		  //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

class SoundBuffersMG
	{
	private:
		HRESULT hr;
	public:
		SoundBuffersMG(): pDSound(NULL){}
		~SoundBuffersMG(void);

			//Variables, not protected because dont want to impose 
			//the way to work

		//Main Sound device
		LPDIRECTSOUND pDSound;
		//Normal Output Buffers
		std::vector<LPDIRECTSOUNDBUFFER> OutputBuffers;

			//Basic Functionality, it is in the user to respect 
			//encapsulation or not

		//Initialize the Direct Sound, before this 
		//the Manager is unusable
		bool Initialize(const LPDIRECTSOUND pDS, HWND hWnd);

		//Update the keybuffer state with the current one,
		//and re-acquire the device if needed
		bool UpdateState();

		//Says if DIK was currently pressed
		bool Pressed(int DIK);

		//Says if DIK was release pressed
		bool Release(int DIK);
	};

