#pragma once
#include <glad/glad.h>
#include <string>

class Shader
{
public:
	//��������ȡ��������ɫ��
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

	//ʹ��/�������
	void use();

	//uniform���ߺ���
	void setUniformValue(const std::string& name, bool value)const;
	void setUniformValue(const std::string& name, int value)const;
	void setUniformValue(const std::string& name, float value)const;

	unsigned getShaderID() { return m_ID; }

private:
	unsigned m_ID;
};
