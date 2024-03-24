#pragma once

#include "Scene.h"

class StartScene : public Scene
{
	using Super = Scene;
public:
	StartScene();
	virtual ~StartScene() = default;
public:
	void Init()       override;
	void Update()     override;
	void LateUpdate() override;
	void Render()     override;
};

