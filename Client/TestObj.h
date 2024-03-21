#pragma once

#include "IGameObject.h"

class TestObj final : public IGameObject
{
public:
	TestObj();
	virtual ~TestObj() = default;
public:
	void Awake()       override;
	void Start()       override;
	void Update()      override;
	void LateUpdate()  override;
	void FixedUpdate() override;

};

