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