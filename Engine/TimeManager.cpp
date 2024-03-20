#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&mInFrequency));
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&mExFrequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&mInPrevCount));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&mExPrevCount));
}

void TimeManager::InternalUpdate()
{
	u64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	mInDeltaTime = (currentCount - mInPrevCount) / static_cast<float>(mInFrequency);
	mInPrevCount = currentCount;

	mInFrameCount++;
	mInFrameTime += mInDeltaTime;

	if (mInFrameTime > 1.f)
	{
		mInFPS = static_cast<u32>(mInFrameCount / mInFrameTime);

		mInFrameTime  = 0.f;
		mInFrameCount = 0;
	}
}

void TimeManager::ExternalUpdate()
{
	u64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	mExDeltaTime = (currentCount - mInPrevCount) / static_cast<float>(mExFrequency);
	mExPrevCount = currentCount;

	mExFrameCount++;
	mExFrameTime += mExDeltaTime;

	if (mExFrameTime > 1.f)
	{
		mExFPS = static_cast<u32>(mExFrameCount / mExFrameTime);

		mExFrameTime = 0.f;
		mExFrameCount = 0;
	}
}
