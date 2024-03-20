#pragma once

// Headers **********************************************

#include "Types.h"
#include "Define.h"


// STL **************************************************

#include <string>
#include <memory>
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;


// Win **************************************************

#include <windows.h>
#include <assert.h>
#include <optional>
#include <comdef.h>

// DirecX ***********************************************

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <d3d11shader.h>
#include <d3d11.h>
#include <wrl.h>
#include <DirectXMath.h>
#include <DirectXTex/DirectXTex.h>
#include <DirectXTex/DirectXTex.inl>
#include <FX11/d3dx11effect.h>
#include <DirectXColors.h>
using namespace DirectX;
using namespace Microsoft::WRL;


// ImGui ************************************************
#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"


// Libs *************************************************
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#ifdef _DEBUG
#pragma comment(lib, "DirectXTex/DirectXTex_debug.lib")
#pragma comment(lib, "FX11/Effects11d.lib")
#else
#pragma comment(lib, "DirectXTex/DirectXTex.lib")
#pragma comment(lib, "FX11/Effects11.lib")
#endif


// Utils *************************************************
#include "Log.h"
#include "Exception.h"


// Engine ************************************************
#include "Window.h"
#include "DirectX11.h"

#include "ImGuiManager.h"
#include "InputManager.h"
#include "TimeManager.h"