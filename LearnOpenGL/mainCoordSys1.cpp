//#include "Shader.h"
//#include "stb_image.h"
//
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
////settings
//const uint32_t SCR_WIDHT = 800;
//const uint32_t SCR_HEIGHT = 600;
//float _visiavle = 0.2f;
//
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDHT, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == nullptr)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//	}
//
//
//	//����������
//	//���ö������ݣ��ͻ������������ö�������
//	float vertices[] = {
//		//---- λ�� ----     --��������--
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//
//	glm::vec3 cubePositions[] = {
//		glm::vec3(0.0f,  0.0f,  0.0f),
//		glm::vec3(2.0f,  5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f,  3.0f, -7.5f),
//		glm::vec3(1.3f, -2.0f, -2.5f),
//		glm::vec3(1.5f,  2.0f, -2.5f),
//		glm::vec3(1.5f,  0.2f, -1.5f),
//		glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//	unsigned int VAO;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	unsigned int VBO;
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	/*unsigned int EBO;
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/
//
//	//���ö�������ָ��
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	//ע����������ģ�����glVertexAttribPointer��VBOע��Ϊ�������Եİ󶨶��㻺������������֮�����ǿ��԰�ȫ�ؽ����
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	//֮������Խ��VAO�İ󶨣�����������VAO���ò���������޸����VAO����������������ٷ����� 
//	//�޸�������VAO��Ҫ����glBindVertexArray����������һ�㲻���ڲ�ֱ�ӱ�Ҫ������½����VAO������VBO����
//	glBindVertexArray(0);
//
//	//������
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	//Ϊ��ǰ�������û���
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//���ز���������
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load("source/image/wall.jpg", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//
//	//�󶨵ڶ�������
//	unsigned int texture2;
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	//Ϊ��ǰ�������û���
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//���ز���������
//	stbi_set_flip_vertically_on_load(true);
//	data = stbi_load("source/image/awesomeface.png", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture2" << std::endl;
//	}
//	stbi_image_free(data);
//
//	Shader ourShader("shaders/shader_coordsys.vs", "shaders/shader_coordsys.fs");
//	ourShader.use();
//	ourShader.setUniformValue("ourTexture", 0);
//	glUniform1i(glGetUniformLocation(ourShader.getShaderID(), "ourTexture2"), 1);
//	ourShader.setUniformValue("visiable", _visiavle);
//
//	//ģ�;���
//	/*glm::mat4 model;
//	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));*/
//	//��ͼ����ע�⣬���ǽ�����������Ҫ�����ƶ������ķ������ƶ�
//	glm::mat4 view;
//	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//	//ͶӰ����
//	glm::mat4 projection;
//	projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDHT / ((float)SCR_HEIGHT), 0.1f, 100.0f);
//
//	//������Ȼ���
//	glEnable(GL_DEPTH_TEST);
//
//	//�����߿�ģʽ���ƶ����
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	//renderLoop
//	while (!glfwWindowShouldClose(window))
//	{
//		//����
//		processInput(window);
//
//		//��Ⱦָ��
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//���ƾ���
//		ourShader.setUniformValue("visiable", _visiavle);
//		//������󵥸���ת
//		/*double time = glfwGetTime();
//		float _rotate = glm::radians(50.0f * time);
//		glm::mat4 model;
//		model = glm::rotate(model, _rotate, glm::vec3(0.5f, 1.0f, 0.0f));
//		int modelLoc = glGetUniformLocation(ourShader.getShaderID(), "model");
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));*/
//
//		int viewLoc = glGetUniformLocation(ourShader.getShaderID(), "view");
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		int perspectivelLoc = glGetUniformLocation(ourShader.getShaderID(), "projection");
//		glUniformMatrix4fv(perspectivelLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glBindVertexArray(VAO);
//
//		for (int i = 0;  i< sizeof(cubePositions) / sizeof(cubePositions[0]); ++i)
//		{
//			glm::mat4 model;
//			model = glm::translate(model, cubePositions[i]);
//			float angle = 20.0f * i;// +20 * glfwGetTime();
//			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//			int modelLoc = glGetUniformLocation(ourShader.getShaderID(), "model");
//			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//		//glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//		//��鲢�����¼�����������
//		ourShader.use();
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//	return 0;
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//	else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//	{
//		_visiavle -= 0.005;
//		_visiavle = _visiavle < 0.0f ? 0.0f : _visiavle;
//	}
//	else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//	{
//		_visiavle += 0.005;
//		_visiavle = _visiavle > 1.0f ? 1.0f : _visiavle;
//	}
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
