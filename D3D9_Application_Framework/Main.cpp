#include "stdafx.h"
#include "MyApp.h"

#include <rmxftmpl.h>

using namespace ProPrimitive;

extern MyApp* pMyApp;//YOUR APP(ALREADY DECLEARE AND DEFINE IN App.cpp)

//Matrices de Transformacion
D3DXMATRIXA16 View;
D3DXMATRIXA16 Proyection;

//Important: if want to use PIX with this .exe then define PIX_ENABLE in the proyect
//or put the next commented line in "stdafx.h"
//#define PIX_ENABLE

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
	{

	//App::GetSingleton() GETS THE UNIQUE INSTANCE OF YOUR APP, BUT pMyApp ALREADY HAVE IT

		//Set the state of the app, if desired, before calling the main loop
	//Example: MyApp->SetWindowStyle(CS_HREDRAW|CS_VREDRAW,WS_OVERLAPPED,NULL); This is the default

		//Set the creation setup of the Application
	pMyApp->CreationSetup.HasDirectSoundManager = true;
		
	pMyApp->ToggleConsole();
		
	pMyApp->Run(hInstance,nCmdShow,(App::InputDevice)(App::InputDevice::KeyboardInput|App::InputDevice::MouseInput));//ENTERS THE MAIN LOOP
	
	delete pMyApp;//FREE YOUR APP
	return 0;
	}


	//APP BEHAVE FUNCTIONS

void MyApp::Initialize()
	{
	//INITIALIZE YOUR APPLICATION(here you already have all the devices initialized)
	Camera.SetProjection(D3DX_PI/4,0.001f,100.0f);
	Camera.Position(*(new D3DXVECTOR3(0,0,0)));
	Camera.Upper(*(new D3DXVECTOR3(0,1,0)));
	Camera.LookAt(*(new D3DXVECTOR3(0,0,1)) );

	pD3dDev->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	pD3dDev->SetRenderState(D3DRS_LIGHTING, false);
	pD3dDev->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(255,255,255));
	pD3dDev->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	pD3dDev->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
	pD3dDev->SetSamplerState(0, D3DSAMP_ADDRESSW, D3DTADDRESS_WRAP);
	pD3dDev->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	pD3dDev->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	pD3dDev->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
	
	//mxArray* pSequencia;
	//mxArray* pArchivo;
	//mxArray* pPloted;
	//size_t strlen = 30;
	//pArchivo = mxCreateCharArray(1,&strlen);
	//char archivo[30] = { "telefono" };
	//mxSetData(pArchivo, archivo);
	//pPloted = mxCreateCellMatrix(1,1);
	//bool graficar = 0;
	//mxSetData(pArchivo, &graficar);

	// The MatLab Application Initialization(MatLab RunTime Libraries Load)
	//if( !mclInitializeApplication(NULL,0) )
	//{
	//	MyApp::Fatal(std::string("The MatLab Library could not initialize"),0);
	//}

	//// The .m function Initialization(The .m DLL load)
	//if( !AnalizePulsesInitialize() )
	//{
	//	MyApp::Fatal(std::string("The m-file DLL code could not initialize"),0);
	//}
		//std::string nombreArchivo("telefono");
		//char* pNombreArchivo = new char[30];
		//strcpy(pNombreArchivo , "telefono");
	//mwArray Archivo("telefono\0");//nombreArchivo.c_str());
	//mxLogical plot = false;
	//mwArray Ploted(plot);
		//char tmp[100];
		//for( int i=1; i <= strlen("telefono"); ++i)
		//	tmp[i-1] = Archivo(i);
	//mwArray* Sequencia = new mwArray();//(10,10,mxINT32_CLASS);
		//mwArray Sequencia();

	//mwArray* Sequencia =NULL;
	/*
	try
	{
	AnalizarPulsos(1,*Sequencia,Archivo,Ploted);
	}catch( mwException e )
	{
		MyApp::Fatal(e.what(),0);
	}


	int seq[7];
	for( int i=1; i <= 7; ++i)
		seq[i-1] = (*Sequencia)(i);
	*/

	//pD3dDev->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	//pD3dDev->SetRenderState(D3DRS_SRCBLEND , D3DBLEND_SRCALPHA);
	//pD3dDev->SetRenderState(D3DRS_DESTBLEND , D3DBLEND_INVSRCALPHA);
	
	return;
	}

void MyApp::LoadContent()
	{
	//LOAD YOUR CONTENT
		/*hr = D3DXCreateTextureFromFile(pD3dDev, L"Content\\Images\\destroyer.png", &pTexture);
		if( FAILED(hr) )
		{
			if(hasConsole)
				std::cerr<<"Texture Imposible to load\n";
			exit(0);
		}*/

		
		hr = pD3dDev->CreateVertexDeclaration((D3DVERTEXELEMENT9*)ProPrimitive::QuadVertexElement, &pQuadDeclaration);
		if( FAILED(hr) )
		{
			if(hasConsole)
				std::cerr<<"Texture Imposible to load\n";
			exit(0);
		}

		//Loads the Phone Pulses, and adds them to the SoundDictionary of the SoundBuffersMG class
		//This don't have to be release in the unload because this is manage by SoundBuffersMG class

		SoundCue* pPulse1 = new SoundCue(pSoundBuffers->pDSound);
		SoundCue* pPulse2 = new SoundCue(pSoundBuffers->pDSound);
		SoundCue* pPulse3 = new SoundCue(pSoundBuffers->pDSound);

		SoundCue* pPulse4 = new SoundCue(pSoundBuffers->pDSound);
		SoundCue* pPulse5 = new SoundCue(pSoundBuffers->pDSound);
		SoundCue* pPulse6 = new SoundCue(pSoundBuffers->pDSound);

		SoundCue* pPulse7 = new SoundCue(pSoundBuffers->pDSound);
		SoundCue* pPulse8 = new SoundCue(pSoundBuffers->pDSound);
		SoundCue* pPulse9 = new SoundCue(pSoundBuffers->pDSound);

		SoundCue* pPulseAsterisk = new SoundCue(pSoundBuffers->pDSound);
		SoundCue* pPulse0		 = new SoundCue(pSoundBuffers->pDSound);
		SoundCue* pPulseNumeral  = new SoundCue(pSoundBuffers->pDSound);

		if( !pPulse1->Open(L"Content\\Sound\\Pulse1.wav") )
			Fatal("No se pudo cargar el pulso del numero 1", 0);
		if( !pPulse2->Open(L"Content\\Sound\\Pulse2.wav") )
			Fatal("No se pudo cargar el pulso del numero 2", 0);
		if( !pPulse3->Open(L"Content\\Sound\\Pulse3.wav") )
			Fatal("No se pudo cargar el pulso del numero 3", 0);

		if( !pPulse4->Open(L"Content\\Sound\\Pulse4.wav") )
			Fatal("No se pudo cargar el pulso del numero 4", 0);
		if( !pPulse5->Open(L"Content\\Sound\\Pulse5.wav") )
			Fatal("No se pudo cargar el pulso del numero 5", 0);
		if( !pPulse6->Open(L"Content\\Sound\\Pulse6.wav") )
			Fatal("No se pudo cargar el pulso del numero 6", 0);

		if( !pPulse7->Open(L"Content\\Sound\\Pulse7.wav") )
			Fatal("No se pudo cargar el pulso del numero 7", 0);
		if( !pPulse8->Open(L"Content\\Sound\\Pulse8.wav") )
			Fatal("No se pudo cargar el pulso del numero 8", 0);
		if( !pPulse9->Open(L"Content\\Sound\\Pulse9.wav") )
			Fatal("No se pudo cargar el pulso del numero 9", 0);

		if( !pPulseAsterisk->Open(L"Content\\Sound\\PulseAsterisk.wav") )
			Fatal("No se pudo cargar el pulso del asterisco", 0);
		if( !pPulse0->Open		(L"Content\\Sound\\Pulse0.wav") )
			Fatal("No se pudo cargar el pulso del numero 0", 0);
		if( !pPulseNumeral->Open (L"Content\\Sound\\PulseNumeral.wav") )
			Fatal("No se pudo cargar el pulso del numeral", 0);

		pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue*>("Pulse1",pPulse1));
		pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue*>("Pulse2",pPulse2));
		pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue*>("Pulse3",pPulse3));

		pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue*>("Pulse4",pPulse4));
		pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue*>("Pulse5",pPulse5));
		pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue*>("Pulse6",pPulse6));

		pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue*>("Pulse7",pPulse7));
		pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue*>("Pulse8",pPulse8));
		pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue*>("Pulse9",pPulse9));

		pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue*>("PulseAsterisk",pPulseAsterisk));
		pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue*>("Pulse0",pPulse0));
		pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue*>("PulseNumeral",pPulseNumeral));
		//pSoundBuffers->SoundDictionary.insert(std::pair<std::string,SoundCue>("5",*(new SoundCue(pSoundBuffers->pDSound))));
		
	return;
	}

void MyApp::UnloadContent()
	{
	//FREE HERE THE RESOURCES LOADED IN LoadContent
		//pTexture->Release();
		pQuadDeclaration->Release();
	return;
	}

void MyApp::Update(const double elapsedTime)
	{
	//PUT HERE YOUR LOOPs UPDATE CODE
	Keyboard.UpdateState();
	Mouse.UpdateState();
	
		//Move Forward
	if( Keyboard.Pressed(DIK_W) )
	{
		D3DXVECTOR3* vec;
		Camera.GetPosition(&vec);
		vec->z += 1*elapsedTime;
		Camera.GetTarget(&vec);
		vec->z += 1*elapsedTime;
	}

		//Move Backward
	if( Keyboard.Pressed(DIK_S) )
	{
		D3DXVECTOR3* vec;
		Camera.GetPosition(&vec);
		vec->z -= 1*elapsedTime;
		Camera.GetTarget(&vec);
		vec->z -= 1*elapsedTime;
	}

	Camera.UpdateView();
	return;
	}

void MyApp::Render(const double elapsedTime)
	{
	//PUT HERE YOUR LOOPs RENDER CODE
		pD3dDev->Clear(0,0,D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER,D3DCOLOR_XRGB(0,150,255),1.0f,1.0f);

	//LPD3DXSPRITE sprite;
	//D3DXCreateSprite(pD3dDev, &sprite);
	//pSprite->Draw()
	
	/*D3DXMATRIX world; 
	D3DXMatrixIdentity(&world);
	pD3dDev->SetTransform(D3DTS_WORLD, &world);
	pD3dDev->SetTransform(D3DTS_PROJECTION, &world);
	pD3dDev->SetTransform(D3DTS_VIEW, &world);*/

	pD3dDev->SetVertexDeclaration(pQuadDeclaration);
	
	pD3dDev->BeginScene();

		//Quad rect(-1.0f/2,1.0f/2,1.0f/2,-1.0f/2,pD3dDev);

		//sprite.SetTexture(pTexture);
		
		//sprite.Draw();
	
		//pD3dDev->SetTexture(0, tex);
		
		D3DXMATRIX mx;
		Camera.GetTotalTransformation(mx);
		D3DXMatrixIdentity(&mx);
		//rect.Draw(pD3dDev, pTexture);
					
			//sprite->Begin(D3DXSPRITE_OBJECTSPACE |
			//				D3DXSPRITE_DONOTMODIFY_RENDERSTATE);
			////sprite->SetTransform(&world);
			//sprite->Draw(tex, NULL, new D3DXVECTOR3(0.5,0.5,0), new D3DXVECTOR3(-0.5,-0.5,0),
			//	D3DCOLOR_XRGB(255, 255, 255));
			//sprite->End();

	pD3dDev->EndScene();

	//pD3dDev->Present(NULL,NULL,NULL,NULL);
	
	return;
	}