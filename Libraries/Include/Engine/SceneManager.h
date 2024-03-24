#pragma once

#include "Scene.h"

class SceneManager
{
	DECLARE_SINGLETON(SceneManager)
public:
	void Update();
	void Render();
public:
	void ChangeScene(sptr<Scene> scene);
private:
	sptr<Scene> mCurrentScene;
};

