#pragma once

#include "stdafx.h"
#include "..\\..\\Header\\GUI\\GUIMaterial.h"

#include "..\\..\\..\\MyApp.h"

namespace GUIFramework
{

	GUIMaterial::~GUIMaterial()
	{
		//if( pEffect )
			//pEffect->Release();
	}

	GUIBasicEffect::GUIBasicEffect()
	{
		pEffect = NULL;
	}

	GUIBasicEffect::~GUIBasicEffect()
	{
	}

	void GUIBasicEffect::Initialize()
	{
		LPD3DXBUFFER pErrors = NULL;
		HRESULT hr = D3DXCreateEffectFromFile(MyApp::GetSingleton()->GetD3DDevice(), L"Content\\Effects\\GUI\\BasicEffect.fx",
			NULL, NULL, NULL, NULL, &pEffect, &pErrors);

		#if defined( _DEBUG )
			if ( FAILED( hr ) && pErrors != NULL && pErrors->GetBufferPointer() != NULL )
				MyApp::GetSingleton()->Error(strcat("Effect Compilation Error: ", (char *)pErrors->GetBufferPointer()));
		#endif 
		if( pErrors != NULL )
			pErrors->Release();

		return;
	}

}