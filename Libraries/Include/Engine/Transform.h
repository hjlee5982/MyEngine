#pragma once

#include "IComponent.h"

class Transform final : public IComponent
{
	using Super = IComponent;
public:
	Transform();
	virtual ~Transform() = default;
public:
	void Awake()       override;
	void Start()       override;
	void Update()      override;
	void LateUpdate()  override;
	void FixedUpdate() override;
};

