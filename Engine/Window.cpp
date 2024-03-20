#include "pch.h"
#include "Window.h"
#include "IExecute.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void Window::Update()
{
	TIME->InternalUpdate();
	INPUT->Update();

	//u32 fps = GET_SINGLETON(TimeManager)->GetFPS();

	DX->RenderBegin();
	
	GUI->Update();

	mDesc.app->Update();
	mDesc.app->Render();

	GUI->Render();
	
	DX->RenderEnd();
}

void Window::ShowFPS()
{
	u32 fps = GET_SINGLETON(TimeManager)->GetFPS();

	WCHAR text[100] = L"";
	::wsprintf(text, L"FPS : %d", fps);

	::SetWindowText(mDesc.hWnd, text);
}

WPARAM Window::Run(WindowDesc& desc)
{
	mDesc = desc;

	MyRegisterClass();

	if (!InitInstance(SW_SHOWNORMAL))
	{
		return FALSE;
	}

	// SINGLETON INIT
	{
		LOG->Init();
		DX->Init(mDesc);
		GUI->Init();
		INPUT->Init(mDesc.hWnd, mDesc.hInstance);
		TIME->Init();
	}

	mDesc.app->Init();

	MSG msg = { 0 };

	f32 timeAcc = 0.0f;

	while (msg.message != WM_QUIT)
	{
		if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}

		Update();
	}

	// RELEASE
	{
		spdlog::shutdown();
	}

	return msg.wParam;
}

ATOM Window::MyRegisterClass()
{
	WNDCLASSEXW wcex;
	{
		wcex.cbSize        = sizeof(WNDCLASSEX);
		wcex.style         = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc   = WndProc;
		wcex.cbClsExtra    = 0;
		wcex.cbWndExtra    = 0;
		wcex.hInstance     = mDesc.hInstance = GetModuleHandle(NULL);
		wcex.hIcon         = ::LoadIcon(NULL, IDI_WINLOGO);
		wcex.hCursor       = ::LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName  = NULL;
		wcex.lpszClassName = mDesc.appName.c_str();
		wcex.hIconSm       = wcex.hIcon;
	}

	return RegisterClassExW(&wcex);
}

BOOL Window::InitInstance(i32 cmdShow)
{
	RECT windowRect = { 0, 0, mDesc.width, mDesc.height };
	::AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, false);

	mDesc.hWnd = CreateWindowW
	(
		mDesc.appName.c_str(),
		mDesc.appName.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top,
		nullptr,
		nullptr,
		mDesc.hInstance,
		nullptr
	);

	if (!mDesc.hWnd)
	{
		return FALSE;
	}
	
	::ShowWindow(mDesc.hWnd, cmdShow);
	::UpdateWindow(mDesc.hWnd);
	
	return TRUE;
}

LRESULT CALLBACK Window::WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(handle, message, wParam, lParam))
	{
		return true;
	}

	switch (message)
	{
	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:

			DestroyWindow(handle);
			break;
		}

		break;
	case WM_SIZE:
		break;
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return ::DefWindowProc(handle, message, wParam, lParam);
}
