#pragma once

struct WindowDesc
{
	sptr<class IExecute> app = nullptr;

	wstring   appName;
	HINSTANCE hInstance;
	HWND      hWnd;
	f32       width;
	f32       height;
	bool      vsync;
	bool      windowed;
	Color     clearColor;
};

class Window
{
	DECLARE_SINGLETON(Window);
public:
	WPARAM Run(WindowDesc& desc);
private:
	void Update();
	void ShowFPS();
private:
	ATOM MyRegisterClass();
	BOOL InitInstance(i32 cmdShow);
public:
	WindowDesc& GetGameDesc()
	{ 
		return mDesc; 
	}
private:
	WindowDesc mDesc;
public:
	static LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);
};

