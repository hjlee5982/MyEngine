#include "pch.h"
#include "MyProject.h"
#include "StartScene.h"

void MyProject::Init()
{
	SCENE->ChangeScene(makeSptr<StartScene>());
}

void MyProject::Update()
{
	SCENE->Update();
}

void MyProject::Render()
{
	SCENE->Render();
}
