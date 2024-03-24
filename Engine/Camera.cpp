#include "pch.h"
#include "Camera.h"
#include "Viewport.h"

matx Camera::sViewMatrix = matx::Identity;
matx Camera::sProjMatrix = matx::Identity;

Camera::Camera(f32 Near, f32 Far, f32 Fov)
	: IComponent(ComponentType::CAMERA),
	mNear(Near), mFar(Far), mFov(Fov)
{
	mWidth  = DX->GetViewport().GetWidth();
	mHeight = DX->GetViewport().GetHeight();
}

void Camera::Update()
{
	UpdateMatrix();
}

void Camera::UpdateMatrix()
{
	mWidth  = DX->GetViewport().GetWidth();
	mHeight = DX->GetViewport().GetHeight();

	vec3 eyePosition   = GetTransform()->GetPosition();
	vec3 focusPosition = eyePosition + GetTransform()->GetLook();
	vec3 upDirection   = GetTransform()->GetUp();

	mViewMatrix = ::XMMatrixLookAtLH(eyePosition, focusPosition, upDirection);

	if (mProjectionType == ProjectionType::PERSPECTIVE)
	{
		mProjMatrix = ::XMMatrixPerspectiveFovLH(mFov, mWidth / mHeight, mNear, mFar);
	}
	else
	{
		mProjMatrix = ::XMMatrixOrthographicLH(mWidth, mHeight, mNear, mFar);
	}
}
