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


	//����������
	//���ö������ݣ��ͻ������������ö�������
	float vertices[] = {
		//λ��				//��ɫ
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,		//����
		0.5f, -0.5f, 0.0f,	 1.0f, 0.0f, 0.0f,		//����
		0.0f,  0.5f, 0.0f,	 0.0f, 0.0f, 1.0f		//����
	};

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//���ö�������ָ��
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//ע����������ģ�����glVertexAttribPointer��VBOע��Ϊ�������Եİ󶨶��㻺������������֮�����ǿ��԰�ȫ�ؽ����
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//֮������Խ��VAO�İ󶨣�����������VAO���ò���������޸����VAO����������������ٷ����� 
	//�޸�������VAO��Ҫ����glBindVertexArray����������һ�㲻���ڲ�ֱ�ӱ�Ҫ������½����VAO������VBO����
	glBindVertexArray(0);

	//�����߿�ģʽ���ƶ����
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	Shader ourShader("shaders/shader.vs", "shaders/shader.fs");

	//renderLoop
	while (!glfwWindowShouldClose(window))
	{
		//����
		processInput(window);

		//��Ⱦָ��
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//�����ǵĵ�һ��������
		
		ourShader.use();
		//ourShader.setUniformValue("someUniform", 1.0f);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);


		//��鲢�����¼�����������
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

