#pragma once

enum class KEY_TYPE
{
	UP    = VK_UP,
	DOWN  = VK_DOWN,
	LEFT  = VK_LEFT,
	RIGHT = VK_RIGHT,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',

	KEY_1 = '1',
	KEY_2 = '2',
	KEY_3 = '3',
	KEY_4 = '4',

	LBUTTON = VK_LBUTTON,
	RBUTTON = VK_RBUTTON,
};

enum class KEY_STATE
{
	NONE,
	PRESS,
	DOWN,
	UP,
	END
};

enum class MOUSE_STATE
{
	X,
	Y,
	WHEEL,
	END
};

enum
{
	KEY_TYPE_COUNT    = static_cast<i32>(UINT8_MAX + 1),
	KEY_STATE_COUNT   = static_cast<i32>(KEY_STATE::END),
	MOUSE_STATE_COUNT = static_cast<i32>(MOUSE_STATE::END),
};

class InputManager
{
	DECLARE_SINGLETON(InputManager);
public:
	void Init(HWND hWnd, HINSTANCE hInst);
	void Update();
public:
	bool GetButtonUp(KEY_TYPE key)
	{
		return GetState(key) == KEY_STATE::UP; 
	}
	bool GetButtonDown(KEY_TYPE key) 
	{
		return GetState(key) == KEY_STATE::DOWN;
	}
	bool GetButtonPress(KEY_TYPE key) 
	{
		return GetState(key) == KEY_STATE::PRESS; 
	}
public:
	const POINT& GetMousePos() 
	{
		return mMousePos; 
	}
private:
	inline KEY_STATE GetState(KEY_TYPE key)
	{
		return mStates[static_cast<u8>(key)]; 
	}
private:
	vector<KEY_STATE> mStates;
private:
	POINT mMousePos = {};
	HWND  mhWnd;
public:
	i32 MouseMove(MOUSE_STATE mouseState)
	{
		return ((i32*)&mMouseState)[(i32)mouseState];
	}
private:
	IDirectInput8*       mInputSDK = nullptr;
	IDirectInputDevice8* mMouse    = nullptr;
	DIMOUSESTATE mMouseState;
};

