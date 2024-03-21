#include "pch.h"
#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
{

}

IndexBuffer::~IndexBuffer()
{

}

void IndexBuffer::Create(const vector<u32>& indices)
{
	mStride = sizeof(u32);
	mCount  = static_cast<u32>(indices.size());

	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	{
		desc.Usage     = D3D11_USAGE_IMMUTABLE;
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		desc.ByteWidth = (u32)(mStride * mCount);
	}

	D3D11_SUBRESOURCE_DATA data;
	ZeroMemory(&data, sizeof(data));
	data.pSysMem = indices.data();

	HRESULT hr = DEVICE->CreateBuffer(&desc, &data, mIndexBuffer.GetAddressOf());
	CHECK(hr);
}
