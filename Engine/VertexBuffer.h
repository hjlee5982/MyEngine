#pragma once

class VertexBuffer
{
public:
	 VertexBuffer();
	~VertexBuffer();
public:
	ComPtr<ID3D11Buffer> GetComPtr() 
	{
		return mVertexBuffer; 
	}
public:
	u32 GetStride() 
	{
		return mStride; 
	}
	u32 GetOffset() 
	{
		return mOffset; 
	}
	u32 GetCount() 
	{
		return mCount; 
	}
	u32 GetSlot()
	{
		return mSlot; 
	}
public:
	template<typename T>
	void Create(const vector<T>& vertices, u32 slot = 0, bool cpuWrite = false, bool gpuWrite = false)
	{
		mStride = sizeof(T);
		mCount  = static_cast<u32>(vertices.size());

		mSlot     = slot;
		mCPUWrite = cpuWrite;
		mGPUWrite = gpuWrite;

		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(desc));
		//desc.Usage = D3D11_USAGE_IMMUTABLE;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		desc.ByteWidth = (u32)(mStride * mCount);

		if (mCPUWrite == false && mGPUWrite == false)
		{
			// CPU Read, GPU Read
			desc.Usage = D3D11_USAGE_IMMUTABLE; 
		}
		else if (mCPUWrite == true && mGPUWrite == false)
		{
			// CPU Write, GPU Read
			desc.Usage          = D3D11_USAGE_DYNAMIC; 
			desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		}
		else if (mCPUWrite == false && mGPUWrite == true)
		{
			// CPU Read, GPU Write
			desc.Usage = D3D11_USAGE_DEFAULT; 
		}
		else
		{
			desc.Usage          = D3D11_USAGE_STAGING;
			desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE;
		}

		D3D11_SUBRESOURCE_DATA data;
		ZeroMemory(&data, sizeof(data));
		data.pSysMem = vertices.data();

		HRESULT hr = DEVICE->CreateBuffer(&desc, &data, mVertexBuffer.GetAddressOf());
		CHECK(hr);
	}
	void PushData()
	{
		CONTEXT->IASetVertexBuffers(mSlot, 1, mVertexBuffer.GetAddressOf(), &mStride, &mOffset);
	}
private:
	ComPtr<ID3D11Buffer> mVertexBuffer;
private:
	u32 mStride = 0;
	u32 mOffset = 0;
	u32 mCount  = 0;
private:
	u32  mSlot     = 0;
	bool mCPUWrite = false;
	bool mGPUWrite = false;
};
