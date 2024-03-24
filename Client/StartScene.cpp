#include "pch.h"
#include "StartScene.h"
#include "Player.h"
#include "Enermy.h"
#include "Terrain.h"

StartScene::StartScene()
{
}

void StartScene::Init()
{
	Add(makeSptr<Player>());
}

void StartScene::Update()
{
	for (auto gameObject : mGameObjects)
	{
		gameObject->Update();
	}
}

void StartScene::LateUpdate()
{
	for (auto gameObject : mGameObjects)
	{
		gameObject->LateUpdate();
	}
}

void StartScene::Render()
{

}
