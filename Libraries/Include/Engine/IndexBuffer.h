#pragma once

class IndexBuffer
{
public:
	 IndexBuffer();
	~IndexBuffer();
public:
	ComPtr<ID3D11Buffer> GetComPtr() 
	{
		return mIndexBuffer;
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
public:
	void Create(const vector<u32>& indices);
public:
	void PushData()
	{
		CONTEXT->IASetIndexBuffer(mIndexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);
	}
private:
	ComPtr<ID3D11Buffer> mIndexBuffer;
private:
	u32 mStride = 0;
	u32 mOffset = 0;
	u32 mCount  = 0;
};

