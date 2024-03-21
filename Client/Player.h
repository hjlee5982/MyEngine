#pragma once

#include "IGameObject.h"

class Player : public IGameObject
{
public:
	Player();
	virtual ~Player() = default;
public:
	void Awake()       override;
	void Start()       override;
	void Update()      override;
	void LateUpdate()  override;
	void FixedUpdate() override;

};

