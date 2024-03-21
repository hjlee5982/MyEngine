#pragma once

#include "IComponent.h"

class MeshRenderer final : public IComponent
{
	using Super = IComponent;
public:
	MeshRenderer();
	virtual ~MeshRenderer() = default;
public:
	void Awake()       override;
	void Start()       override;
	void Update()      override;
	void LateUpdate()  override;
	void FixedUpdate() override;
};

