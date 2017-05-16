#include "stdafx.h"

#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace glm;
using namespace softlit;

Image::Image(const std::string & fileName)
{
	m_data = stbi_load(fileName.c_str(), &m_width, &m_height, &m_numChannels, 0);
}

Image::Image(uchar* data)
	: m_data(data)
{
}

Image::~Image()
{
	stbi_image_free(m_data);
	m_data = nullptr;
}

Texture::Texture(Image* image)
	: m_image(image)
{
}

Texture::~Texture()
{
}