#pragma once

class Skybox
{
	public:
	void loadskybox();
	GLuint loadCubemap(std::vector<const char*>);
		GLuint getcubemapTexture()
		{
			return cubemapTexture;
		}
		Skybox();
private:
	GLuint cubemapTexture;

};
