#include "Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

//settings
const uint32_t SCR_WIDHT = 800;
const uint32_t SCR_HEIGHT = 600;


int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDHT, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}


	//绘制三角形
	//设置顶点数据（和缓冲区）并配置顶点属性
	float vertices[] = {
		//位置				//颜色
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,		//左下
		0.5f, -0.5f, 0.0f,	 1.0f, 0.0f, 0.0f,		//右下
		0.0f,  0.5f, 0.0f,	 0.0f, 0.0f, 1.0f		//顶部
	};

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//注意这是允许的，调用glVertexAttribPointer将VBO注册为顶点属性的绑定顶点缓冲区对象，所以之后我们可以安全地解除绑定
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//之后你可以解除VAO的绑定，这样其他的VAO调用不会意外地修改这个VAO，但是这种情况很少发生。 
	//修改其他的VAO需要调用glBindVertexArray，所以我们一般不会在不直接必要的情况下解除绑定VAO（不是VBO）。
	glBindVertexArray(0);

	//调用线框模式绘制多边形
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	Shader ourShader("shaders/shader.vs", "shaders/shader.fs");

	//renderLoop
	while (!glfwWindowShouldClose(window))
	{
		//输入
		processInput(window);

		//渲染指令
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//画我们的第一个三角形
		
		ourShader.use();
		//ourShader.setUniformValue("someUniform", 1.0f);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);


		//检查并调用事件，交换缓冲
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

