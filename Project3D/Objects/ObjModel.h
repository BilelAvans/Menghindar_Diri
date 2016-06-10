#pragma once

#include <string>
#include <vector>
#include <list>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL\freeglut.h>
#endif

using namespace std;

class Vec3f
{
public:
	union
	{
		struct 
		{
			float x,y,z;
		};
		float v[3];
	};
	Vec3f();
	Vec3f(Vec3f &other);
	Vec3f(float x, float y, float z);
	float& operator [](int);
};

class Vec2f
{
public:
	union
	{
		struct 
		{
			float x,y;
		};
		float v[2];
	};
	Vec2f();
	Vec2f(float x, float y);
	Vec2f(Vec2f &other);
	float& operator [](int);
};


class ObjModel
{
	private:
		class Texture{
				GLuint index;
			public:
				Texture(const std::string &fileName);
				void bind();
		};

		class Vertex{
			public:
				int position;
				int normal;
				int texcoord;
		};

		class Face{
			public:
				list<Vertex> vertices;
		};

		class MaterialInfo{
			public:
				MaterialInfo();
				std::string name;
				bool hasTexture;
				Texture *texture;
		};

		class ObjGroup{
			public:
				std::string name;
				int materialIndex;
				list<Face> faces;
		};






	std::vector<Vec3f*>	vertices;
	std::vector<Vec3f*>	normals;
	std::vector<Vec2f*>	texcoords;
	std::vector<ObjGroup*> groups;
	std::vector<MaterialInfo*> materials;

	void loadMaterialFile(std::string fileName, std::string dirName);
public:
	ObjModel(std::string filename);
	~ObjModel(void);

	void draw();
};

