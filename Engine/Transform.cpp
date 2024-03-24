#include "pch.h"
#include "Transform.h"

Transform::Transform()
	: Super(ComponentType::TRANSFORM)
{
}

vec3 Transform::ToEulerAngles(quat q)
{
	vec3 angles;

	double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
	double cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
	angles.x = std::atan2(sinr_cosp, cosr_cosp);

	double sinp = std::sqrt(1 + 2 * (q.w * q.y - q.x * q.z));
	double cosp = std::sqrt(1 - 2 * (q.w * q.y - q.x * q.z));
	angles.y = 2 * std::atan2(sinp, cosp) - 3.14159f / 2;

	double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
	double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
	angles.z = std::atan2(siny_cosp, cosy_cosp);

	return angles;
}

void Transform::UpdateTransform()
{
	matx scale       = matx::CreateScale(mLocalScale);
	matx rotationX   = matx::CreateRotationX(mLocalRotation.x);
	matx rotationY   = matx::CreateRotationX(mLocalRotation.y);
	matx rotationZ   = matx::CreateRotationX(mLocalRotation.z);
	matx translation = matx::CreateTranslation(mLocalPosition);

	mLocalMatrix = scale * rotationX * rotationY * rotationZ * translation;

	if (false != HasParent())
	{
		mWorldMatrix = mLocalMatrix * mParent->GetWorldMatrix();
	}
	else
	{
		mWorldMatrix = mLocalMatrix;
	}

	quat q;
	mWorldMatrix.Decompose(mScale, q, mPosition);
	mRotation = ToEulerAngles(q);

	for (const sptr<Transform>& children : mChildren)
	{
		children->UpdateTransform();
	}
}

void Transform::SetScale(const vec3& worldScale)
{
	if (false != HasParent())
	{
		vec3 parentScale = mParent->GetScale();
		vec3 scale = worldScale;

		scale.x /= parentScale.x;
		scale.y /= parentScale.y;
		scale.z /= parentScale.z;

		SetLocalScale(scale);
	}
	else
	{
		SetLocalScale(worldScale);
	}
}

void Transform::SetRotation(const vec3& worldRotation)
{
	if (false != HasParent())
	{
		matx worldToParentLocalMatrix = mParent->GetWorldMatrix().Invert();

		vec3 rotation = vec3::TransformNormal(worldRotation, worldToParentLocalMatrix);

		SetLocalRotation(rotation);
	}
	else
	{
		SetLocalRotation(worldRotation);
	}
}

void Transform::SetPosition(const vec3& worldPosition)
{
	if (false != HasParent())
	{
		matx worldToParentLocalMatrix = mParent->GetWorldMatrix().Invert();

		vec3 position = vec3::TransformCoord(worldPosition, worldToParentLocalMatrix);

		SetLocalPosition(position);
	}
	else
	{
		SetLocalPosition(worldPosition);
	}
}
