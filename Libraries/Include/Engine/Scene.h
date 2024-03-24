#pragma once

class Scene abstract
{
public:
	Scene();
	virtual ~Scene() = default;
public:
	virtual void Init()	      = 0;
	virtual void Update()	  = 0;
	virtual void LateUpdate() = 0;
	virtual void Render()	  = 0;
public:
	virtual void Add(sptr<IGameObject>    gameObject);
	virtual void Remove(sptr<IGameObject> gameObject);
protected:
	Hashset<sptr<IGameObject>> mGameObjects;
	Hashset<sptr<IGameObject>> mCameras;
	Hashset<sptr<IGameObject>> mLights;
};

