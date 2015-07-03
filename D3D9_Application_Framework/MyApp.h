////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////					   User App			    	  //////////////////////////////////////
///////////////////////////////////					Derived from App		      //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameworkBase\\Header\\App.h"

#include "FrameworkBase\\Header\\ProPrimitives\\Quad.h"
#include "MyGUI.h"

//Singleton Class
//The user App, this is where you have to put your code.
//This clase derives from the base App class. The responsibility
//from the base App is to initialize input devices, graphic devices,
//manage the camera, the console, the initial specification panel, etc
//
//The specifics of your App are responsibility from this clase
//
//IMPORTANT: the only overhead of this framework is the virtuals calls
//			 that the base class makes from this class
class MyApp: public App
{
	private:
			//Singleton Variable
		static MyApp* Singleton;

			//To catch error results
		HRESULT hr;

		//-----------------------
		//	Your States
		//-----------------------

			//YOUR CODE HERE
			//THIS IS AN EXAMPLE
		LPDIRECT3DVERTEXDECLARATION9 pQuadDeclaration;

		//-----------------------

	protected:

		MyApp(void): App(){}

		MyApp(const MyApp&){}

		MyApp& operator= (const MyApp&){}

	public:
			//The singleton getter
		static MyApp* GetSingleton();

			//-----------------------
			//	Virtual Functions
			//-----------------------

		//Execute after getting the window and the devices,
		//makes the user app initializations
		virtual void Initialize();

		//Execute after Initialize, loads all the nesesary 
		//DirectX and user resources
		virtual void LoadContent();

		//Execute before quitting the app, it just unloads
		//the resources loaded in LoadContent(NO OTHER)
		virtual void UnloadContent();

		//Execute 1 time per loop, it updates all
		//
		//- elapsedTime the elapsed time between this frame and the previous
		virtual void Update(const double elapsedTime);

		//Execute 1 time per loop, it renders the scene
		//
		//- elapsedTime the elapsed time between this frame and the previous
		virtual void Render(const double elapsedTime);

		//-----------------------
		//	Your Methods
		//-----------------------

			//YOUR CODE HERE
	
};