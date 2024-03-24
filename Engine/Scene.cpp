#include "pch.h"
#include "Scene.h"

Scene::Scene()
{
}

void Scene::Init()
{
}

void Scene::Update()
{
}

void Scene::LateUpdate()
{
}

void Scene::Render()
{
}

void Scene::Add(sptr<IGameObject> gameObject)
{
	mGameObjects.insert(gameObject);

	if (gameObject->GetCamera() != nullptr)
	{
		mCameras.insert(gameObject);
	}
}

void Scene::Remove(sptr<IGameObject> gameObject)
{
	mGameObjects.erase(gameObject);
	mCameras.erase(gameObject);
	mLights.erase(gameObject);
}
