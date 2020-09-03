//***************************************************************************************
// d3dUtil.h by Frank Luna (C) 2011 All Rights Reserved.
//***************************************************************************************
#pragma once

#if defined(DEBUD) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#pragma comment(lib,"d3d11.lib")

#include "d3dx11effect.h"
#include "dxerr.h"
#include "DDSTextureLoader.h"
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <d3dcompiler.h>

//---------------------------------------------------------------------------------------
// Simple d3d error checker for book demos.
//---------------------------------------------------------------------------------------
#if defined(DEBUG) || defined(_DEBUG)
	#ifndef HR
	#define HR(x)												\
	{															\
		HRESULT hr = (x);										\
		if (FAILED(hr))											\
		{														\
			DXTrace(__FILEW__, (DWORD)__LINE__, hr, L#x, true);	\
		}														\
	}
	#endif
#else
	#ifndef HR
	#define HR(x) (x)
	#endif
#endif

//---------------------------------------------------------------------------------------
// Convenience macro for releasing COM objects.
//---------------------------------------------------------------------------------------

#define ReleaseCOM(x) { if(x){ x->Release(); x = 0; } }

//---------------------------------------------------------------------------------------
// Convenience macro for deleting objects.
//---------------------------------------------------------------------------------------

#define SafeDelete(x) { delete x; x = 0; }

//---------------------------------------------------------------------------------------
// Utility classes.
//---------------------------------------------------------------------------------------

class d3dHelper
{
public:
	///<summary>
	/// 
	/// Does not work with compressed formats.
	///</summary>

	static ID3D11ShaderResourceView* CreateRandomTexture1DSRV(ID3D11Device* device);
};

namespace Colors
{
	XMGLOBALCONST DirectX::XMFLOAT4 White = { 1.0f, 1.0f, 1.0f, 1.0f };
	XMGLOBALCONST DirectX::XMFLOAT4 Black = { 0.0f, 0.0f, 0.0f, 1.0f };
	XMGLOBALCONST DirectX::XMFLOAT4 Red = { 1.0f, 0.0f, 0.0f, 1.0f };
	XMGLOBALCONST DirectX::XMFLOAT4 Green = { 0.0f, 1.0f, 0.0f, 1.0f };
	XMGLOBALCONST DirectX::XMFLOAT4 Blue = { 0.0f, 0.0f, 1.0f, 1.0f };
	XMGLOBALCONST DirectX::XMFLOAT4 Yellow = { 1.0f, 1.0f, 0.0f, 1.0f };
	XMGLOBALCONST DirectX::XMFLOAT4 Cyan = { 0.0f, 1.0f, 1.0f, 1.0f };
	XMGLOBALCONST DirectX::XMFLOAT4 Magenta = { 1.0f, 0.0f, 1.0f, 1.0f };

	XMGLOBALCONST DirectX::XMFLOAT4 Silver = { 0.75f, 0.75f, 0.75f, 1.0f };
	XMGLOBALCONST DirectX::XMFLOAT4 LightSteelBlue = { 0.69f, 0.77f, 0.87f, 1.0f };
}