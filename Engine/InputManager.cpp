#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hWnd, HINSTANCE hInst)
{
	mhWnd = hWnd;
	mStates.resize(KEY_TYPE_COUNT, KEY_STATE::NONE);

	HRESULT hr;

	hr = DirectInput8Create(hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&mInputSDK, nullptr);
	CHECK(hr);

	hr = mInputSDK->CreateDevice(GUID_SysMouse, &mMouse, nullptr);
	CHECK(hr);

	hr = mMouse->SetDataFormat(&c_dfDIMouse);
	CHECK(hr);

	hr = mMouse->SetCooperativeLevel(hWnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	CHECK(hr);

	hr = mMouse->Acquire();
	CHECK(hr);
}

void InputManager::Update()
{
	HWND hwnd = ::GetActiveWindow();

	if (mhWnd != hwnd)
	{
		for (u32 key = 0; key < KEY_TYPE_COUNT; key++)
		{
			mStates[key] = KEY_STATE::NONE;
		}

		return;
	}

	BYTE asciiKeys[KEY_TYPE_COUNT] = {};

	if (::GetKeyboardState(asciiKeys) == false)
	{
		return;
	}

	for (u32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// 키가 눌려 있으면 true
		if (asciiKeys[key] & 0x80)
		{
			KEY_STATE& state = mStates[key];

			// 이전 프레임에 키를 누른 상태라면 PRESS
			if (state == KEY_STATE::PRESS || state == KEY_STATE::DOWN)
			{
				state = KEY_STATE::PRESS;
			}
			else
			{
				state = KEY_STATE::DOWN;
			}
		}
		else
		{
			KEY_STATE& state = mStates[key];

			// 이전 프레임에 키를 누른 상태라면 UP
			if (state == KEY_STATE::PRESS || state == KEY_STATE::DOWN)
			{
				state = KEY_STATE::UP;
			}
			else
			{
				state = KEY_STATE::NONE;
			}
		}
	}

	mMouse->GetDeviceState(sizeof(mMouseState), &mMouseState);

	::GetCursorPos(&mMousePos);
	::ScreenToClient(mhWnd, &mMousePos);
}