#pragma once

#include "IComponent.h"

class Transform;
class MeshRenderer;

class IGameObject abstract : public enable_shared_from_this<IGameObject>
{
public:
	IGameObject();
	virtual ~IGameObject() = default;
public:
	virtual void Awake()       = 0;
	virtual void Start()       = 0;
	virtual void Update()      = 0;
	virtual void LateUpdate()  = 0;
	virtual void FixedUpdate() = 0;
public:
	void AddComponent(ComponentType type, sptr<IComponent> component);
private:
	sptr<IComponent> GetComponent(ComponentType type);
public:
	sptr<Transform>    GetTransform();
	sptr<MeshRenderer> GetMeshRenderer();
private:
	Dictionary<ComponentType, sptr<IComponent>> mComponents;
};

