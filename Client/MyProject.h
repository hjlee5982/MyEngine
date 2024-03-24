#pragma once

#include "IExecute.h"

class MyProject : public IExecute
{
public:
	virtual void Init()   override;
	virtual void Update() override;
	virtual void Render() override;
};

