#pragma once

class IExecute abstract
{
public:
	virtual void Init()   abstract;
	virtual void Update() abstract;
	virtual void Render() abstract;
};

