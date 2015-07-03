#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' "\
	"version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <cmath>
#include <utility>
#include <iostream>

// DX Libraries
#pragma comment(lib, "d3d9.lib")
#include <d3d9.h>
#pragma comment(lib, "d3dx9d.lib")
#include <d3dx9.h>
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dinput8.lib")
#include <dinput.h>

//if want DirectSound
#pragma comment(lib, "Winmm.lib")
#include <mmsystem.h>//already inside windows.h
#pragma comment(lib, "dsound.lib")
#include <dsound.h>

// C++ STD libraries
#include <string>
#include <list>
#include <vector>
#include <map>

#include <commctrl.h>

#define ARRAY_ACCESS_INLINING
#include <matrix.h>

//use PIX 
#define PIX_ENABLE

