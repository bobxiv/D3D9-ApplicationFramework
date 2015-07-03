#include <App.h>

namespace GUI
{
	class GUIBasicEffect: public GUIMaterial
	{
		public:
		GUIBasicEffect()
		{
			LPVOID data;
			LPD3DXBUFFER pErrors;
			D3DXCreateEffectFromFile(App::GetSingleton().GetD3DDevice(), "Shaders\BasicEffect.fx",
				NULL, NULL, NULL, NULL, pEffect, pErrors);
		}
	}

	class GUIMaterial
	{
		LPD3DXEFFECT pEffect;
	}

	class GUIObject
	{
		

		public virtual Render();
		
		
	};


}

	