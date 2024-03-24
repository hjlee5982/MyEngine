#pragma once

#include "IComponent.h"

class Transform final : public IComponent
{
	using Super = IComponent;
public:
	Transform();
	virtual ~Transform() = default;
public:
	static vec3 ToEulerAngles(quat q);
private:
	void UpdateTransform();
public:
	vec3 GetLocalScale()
	{
		return mLocalScale; 
	}
	vec3 GetLocalRotation() 
	{
		return mLocalRotation; 
	}
	vec3 GetLocalPosition() 
	{
		return mLocalPosition; 
	}
	void SetLocalScale(const vec3& localScale)
	{
		mLocalScale = localScale; UpdateTransform();
	}
	void SetLocalRotation(const vec3& localRotation) 
	{
		mLocalRotation = localRotation; UpdateTransform(); 
	}
	void SetLocalPosition(const vec3& localPosition)
	{
		mLocalPosition = localPosition; UpdateTransform(); 
	}
public:
	vec3 GetScale() 
	{
		return mScale; 
	}
	vec3 GetRotation() 
	{
		return mRotation;
	}
	vec3 GetPosition() 
	{
		return mPosition; 
	}
	void SetScale(const vec3& worldScale);
	void SetRotation(const vec3& worldRotation);
	void SetPosition(const vec3& worldPosition);
public:
	matx GetWorldMatrix()
	{
		return mWorldMatrix;
	}
	vec3 GetRight()
	{
		return mWorldMatrix.Right(); 
	}
	vec3 GetUp() 
	{
		return mWorldMatrix.Up(); 
	}
	vec3 GetLook()
	{
		return mWorldMatrix.Look(); 
	}
public:
	bool HasParent()
	{
		return mParent != nullptr; 
	}
public:
	sptr<Transform> GetParent() 
	{
		return mParent;
	}
	void SetParent(sptr<Transform> parent)
	{
		mParent = parent; 
	}
public:
	const vector<sptr<Transform>>& GetChildren()
	{
		return mChildren; 
	}
	void AddChildren(sptr<Transform> child) 
	{
		mChildren.push_back(child);
	}
private:
	matx mLocalMatrix = matx::Identity;
	matx mWorldMatrix = matx::Identity;
private:
	vec3 mLocalScale    = { 1.f, 1.f, 1.f };
	vec3 mLocalRotation = { 0.f, 0.f, 0.f };
	vec3 mLocalPosition = { 0.f, 0.f, 0.f };
private:
	vec3 mScale;
	vec3 mRotation;
	vec3 mPosition;
private:
	sptr<Transform>         mParent;
	vector<sptr<Transform>> mChildren;
;};

