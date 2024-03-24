#include "pch.h"
#include "SceneManager.h"

void SceneManager::Update()
{
	if (nullptr == mCurrentScene)
	{
		return;
	}

	mCurrentScene->Update();

	mCurrentScene->LateUpdate();
}

void SceneManager::Render()
{
	if (nullptr == mCurrentScene)
	{
		return;
	}

	mCurrentScene->Render();
}

void SceneManager::ChangeScene(sptr<Scene> scene)
{
	mCurrentScene = scene;

	mCurrentScene->Init();
}
