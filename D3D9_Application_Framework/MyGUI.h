////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////					GUI							  //////////////////////////////////////
///////////////////////////////////					Manager						  //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameworkBase\\Header\\GUI\\GUI.h"

namespace GUIFramework
{

	//Singleton Class
	//The App GUI inside DirectX, this is where you have to put your code for the GUI.
	//This clase derives from the base GUI class. The responsibility
	//from the base App is to create/initialize GUI controls, GUI events, etc
	//
	//The specifics of your App GUI are responsibility from this clase
	//
	//IMPORTANT: this class links with the App once the App has created a DirectX Device
	//and this GUI will render by default
	class MyGUI: public GUI
		{
		private:
				//Singleton Variable
			static MyGUI* Singleton;


			//-----------------------
			//	Your States
			//-----------------------

				//YOUR CODE HERE
				//THIS IS AN EXAMPLE
			//GUIFramework::Sprite mySprite;
			GUIFramework::Button mButton;
			GUIFramework::Slider mSlider;

			std::vector<Button*> mlButtonDial;
			//1;
			//2;
			//3;

			//4;
			//5;
			//6;

			//7;
			//8;
			//9;

			//Asterisc;
			//0;
			//Numeral;

			Button mAnalizePulses;

			//-----------------------

				//Private contructors
			MyGUI(){}

			MyGUI(const MyGUI&){}

			MyGUI& operator= (const MyGUI& ){}

		public:

				//Public destructor
			~MyGUI(){}
			
				//Gets the unique instance of GUI
			static MyGUI* GetSingleton();


			//-----------------------
			//	Your Methods
			//-----------------------

			//virtual void ResolveEvents();

			virtual void Load();

			virtual void UnLoad();

			virtual void RenderGUI(const double elapsedTime);

			
		};


}