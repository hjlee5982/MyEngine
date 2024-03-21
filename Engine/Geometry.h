#pragma once

template<typename T>
class Geometry
{
public:
	 Geometry() {}
	~Geometry() {}
public:
	u32 GetVertexCount() 
	{
		return static_cast<u32>(mVertices.size()); 
	}
	void* GetVertexData() 
	{
		return mVertices.data();
	}
	const vector<T>& GetVertices() 
	{
		return mVertices; 
	}
public:
	u32 GetIndexCount() 
	{
		return static_cast<u32>(mIndices.size());
	}
	void* GetIndexData() 
	{
		return mIndices.data(); 
	}
	const vector<u32>& GetIndices() 
	{
		return mIndices; 
	}
public:
	void AddVertex(const T& vertex) 
	{
		mVertices.push_back(vertex); 
	}
	void AddVertices(const vector<T>& vertices) 
	{
		mVertices.insert(mVertices.end(), vertices.begin(), vertices.end()); 
	}
	void SetVertices(const vector<T>& vertices) 
	{
		mVertices = vertices;
	}
public:
	void AddIndex(u32 index) 
	{
		mIndices.push_back(index); 
	}
	void AddIndices(const vector<u32>& indices) 
	{
		mIndices.insert(mIndices.end(), indices.begin(), indices.end()); 
	}
	void SetIndices(const vector<u32>& indices) 
	{
		mIndices = indices; 
	}
private:
	vector<T>   mVertices;
	vector<u32> mIndices;
};
