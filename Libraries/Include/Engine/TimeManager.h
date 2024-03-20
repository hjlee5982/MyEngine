#pragma once

class TimeManager
{
	DECLARE_SINGLETON(TimeManager);
public:
	void Init();
public:
	u32 GetFPS() 
	{
		return mInFPS;
	}
//***************************************//
public:
	void InternalUpdate();
public:
	f32 GetInternalDeltaTime()
	{
		return mInDeltaTime; 
	}
private:
	f32 mInDeltaTime = 0.f;
	u64	mInFrequency = 0;
	u64	mInPrevCount = 0;
private:
	f32 mInFrameTime = 0.f;
	u32	mInFrameCount = 0;
	u32	mInFPS = 0;
//***************************************//
public:
	void ExternalUpdate();
public:
	f32 GetExternalDeltaTime()
	{
		return mExDeltaTime;
	}
private:
	f32 mExDeltaTime = 0.f;
	u64	mExFrequency = 0;
	u64	mExPrevCount = 0;
private:
	f32 mExFrameTime = 0.f;
	u32	mExFrameCount = 0;
	u32	mExFPS = 0;
};

