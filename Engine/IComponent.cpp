#include "pch.h"
#include "IComponent.h"

IComponent::IComponent(ComponentType type)
	: mType(type)
{
}

void IComponent::Awake()
{
}

void IComponent::Start()
{
}

void IComponent::Update()
{
}

void IComponent::LateUpdate()
{
}

void IComponent::FixedUpdate()
{
}

sptr<IGameObject> IComponent::GetGameObject()
{
	return mGameObject.lock();
}

sptr<Transform> IComponent::GetTransform()
{
	return mGameObject.lock()->GetTransform();
}
