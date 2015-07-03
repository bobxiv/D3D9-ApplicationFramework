#pragma once

#include "stdafx.h"
#include "MyGUI.h"

#include "MyApp.h"

#include "FrameworkBase\\Header\\GUI\\Controls.h"

#include <ctime>

namespace GUIFramework
{

	#pragma region EventHandlers Forward Declarations
	
	#pragma endregion

		//Singleton Variable Initialization
	MyGUI* MyGUI::Singleton = NULL;

	MyGUI* MyGUI::GetSingleton()
		{
		if( !Singleton )
			Singleton = new MyGUI();

		return Singleton;	
		}

	//YOUR CODE HERE

	/*void MyGUI::ResolveEvents()
		{
		return;
		}*/

	void MyGUI::Load()
		{
			//Initialize you controls, and hang then from the GUI Tree
		}

	void MyGUI::UnLoad()
		{
			//Make any nessesary unitialization

		return;
		}

	void MyGUI::RenderGUI(const double elapsedTime)
		{
			//Our GUI will need alpha blending
			pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
			pDevice->SetRenderState(D3DRS_SRCBLEND , D3DBLEND_SRCALPHA);
			pDevice->SetRenderState(D3DRS_DESTBLEND , D3DBLEND_INVSRCALPHA);

			//Makes the rendering and the presentation of the backbuffer
			GUI::RenderGUI(elapsedTime);
			return;
		}

	#pragma region EventHandlers Section

	#pragma endregion

}