#include <GL/freeglut.h>
#include <windows.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glew.h>
#include "SOIL.h"
#include <vector>
#include "Skybox.h"


void Skybox::loadskybox()
{
	std::vector<const char*> faces;
	faces.push_back("Images/Skybox/right.jpg");
	faces.push_back("Images/Skybox/left.jpg");
	faces.push_back("Images/Skybox/	top.jpg");
	faces.push_back("Images/Skybox/bottom.jpg");
	faces.push_back("Images/Skybox/back.jpg");
	faces.push_back("Images/Skybox/front.jpg");
	cubemapTexture = loadCubemap(faces);
}

GLuint Skybox::loadCubemap(std::vector<const char*> faces)
{
	GLuint textureID;
	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE0);

	int width, height;
	unsigned char* image;

	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	for (GLuint i = 0; i < faces.size(); i++)
	{
		image = SOIL_load_image(faces[i], &width, &height, 0, SOIL_LOAD_RGB);
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0,
			GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image
			);
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	return textureID;
}
