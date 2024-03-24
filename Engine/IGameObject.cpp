#include "pch.h"
#include "IGameObject.h"
#include "Transform.h"
#include "Camera.h"
#include "MeshRenderer.h"

IGameObject::IGameObject()
{
}

void IGameObject::Awake()
{
}

void IGameObject::Start()
{
}

void IGameObject::Update()
{
}

void IGameObject::LateUpdate()
{
}

void IGameObject::FixedUpdate()
{
}

void IGameObject::AddComponent(ComponentType type, sptr<IComponent> component)
{
	if (mComponents.end() != mComponents.find(type))
	{
		return;
	}

	component->SetGameObject(shared_from_this());

	mComponents.emplace(type, component);
}

sptr<IComponent> IGameObject::GetComponent(ComponentType type)
{
	auto pair = mComponents.find(type);

	if (mComponents.end() == pair)
	{
		return nullptr;
	}

	return pair->second;
}

sptr<Transform> IGameObject::GetTransform()
{
	auto component = GetComponent(ComponentType::TRANSFORM);

	return static_pointer_cast<Transform>(component);
}

sptr<Camera> IGameObject::GetCamera()
{
	auto component = GetComponent(ComponentType::CAMERA);

	return static_pointer_cast<Camera>(component);
}

sptr<MeshRenderer> IGameObject::GetMeshRenderer()
{
	auto component = GetComponent(ComponentType::MESHRENDERER);

	return static_pointer_cast<MeshRenderer>(component);
}
