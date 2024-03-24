#pragma once

#include "IComponent.h"

enum class ProjectionType
{
	PERSPECTIVE,
	ORTHOGRAPHIC
};

class Camera : public IComponent
{
	using Super = IComponent;
public:
	Camera(f32 Near, f32 Far, f32 Fov);
	virtual ~Camera() = default;
public:
	virtual void Update() override;
private:
	void UpdateMatrix();
private:
	ProjectionType mProjectionType;
private:
	matx mViewMatrix = matx::Identity;
	matx mProjMatrix = matx::Identity;
private:
	f32 mNear   = 0.f;
	f32 mFar    = 0.f;
	f32 mFov    = 0.f;
	f32 mWidth  = 0.f;
	f32 mHeight = 0.f;
public:
	static matx sViewMatrix;
	static matx sProjMatrix;
};

