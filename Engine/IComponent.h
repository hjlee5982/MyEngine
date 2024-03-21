#pragma once

class IGameObject;

enum class ComponentType : u8
{
	TRANSFORM,
	MESHRENDERER,

	END,
};

class IComponent abstract
{
public:
	IComponent(ComponentType type);
	virtual ~IComponent() = default;
public:
	virtual void Awake() 	   = 0;
	virtual void Start()	   = 0;
	virtual void Update()	   = 0;
	virtual void LateUpdate()  = 0;
	virtual void FixedUpdate() = 0;
public:
	ComponentType GetType()
	{
		return mType;
	}
	sptr<IGameObject> GetGameObject()
	{
		return mGameObject.lock();
	}
private:
	friend class IGameObject;
	void SetGameObject(sptr<IGameObject> gameObject)
	{
		mGameObject = gameObject;
	}
protected:
	ComponentType    mType;
	wptr<IGameObject> mGameObject;
};

