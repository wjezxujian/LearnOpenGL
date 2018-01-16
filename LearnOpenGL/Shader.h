#pragma once
#include <glad/glad.h>
#include <string>

class Shader
{
public:
	//构造器读取并构建着色器
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

	//使用/激活程序
	void use();

	//uniform工具函数
	void setUniformValue(const std::string& name, bool value)const;
	void setUniformValue(const std::string& name, int value)const;
	void setUniformValue(const std::string& name, float value)const;

	unsigned getShaderID() { return m_ID; }

private:
	unsigned m_ID;
};
