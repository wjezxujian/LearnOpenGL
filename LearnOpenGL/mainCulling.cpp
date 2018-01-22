//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <stb_image.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include "Shader.h"
//#include "Camera.h"
//#include "Model.h"
//
//#include <iostream>
//#include <map>
//
//
//void framebuffer_size_callback(GLFWwindow* window, int widht, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow* window);
//unsigned int loadTexture(const char* path);
//
////���ڴ�С
//const unsigned int SCR_WIDTH = 1280;
//const unsigned int SCR_HEIGHT = 720;
//
////�����
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = (float)SCR_WIDTH / 2.0f;
//float lastY = (float)SCR_HEIGHT / 2.0f;
//bool firstMode = true;
//
////ʱ��
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//#ifdef __APPLE__
//	glfwWindowHit(GLFW_OPENGL_FORWARD_COMPAR, GL_TRUE);
//#endif //__APPLE__
//
//	//��������
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr);
//	if (window == nullptr)
//	{
//		std::cout << "Failed to cteate GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	//�������
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	//glad:����OpenGL����ָ��
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	//����OpenGLȫ��״̬
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LESS);
//		
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	//glFrontFace(GL_CW);
//
//	//���ö������ݣ����ö�������
//	float cubeVertices[] = {
//		// Back face
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Bottom-left
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
//		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, // bottom-right         
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // bottom-left
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
//		// Front face
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
//		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, // top-left
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
//		// Left face
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
//		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-left
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
//		// Right face
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right         
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
//		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left     
//		// Bottom face
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
//		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, // top-left
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
//		// Top face
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right     
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
//		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f  // bottom-left        
//	};
//
//	float planeVertices[] = {
//		//λ��          //�������꣨�����������1�������µذ������ظ���
//		 5.0f, -0.5f,  5.0f,  16.0f,  0.0f,
//		-5.0f, -0.5f,  5.0f,   0.0f,  0.0f,
//		-5.0f, -0.5f, -5.0f,   0.0f, 16.0f,
//
//		 5.0f, -0.5f,  5.0f,  16.0f,  0.0f,
//		-5.0f, -0.5f, -5.0f,   0.0f, 16.0f,
//		 5.0f, -0.5f, -5.0f,  16.0f, 16.0f
//	};
//
//	//������VAO
//	unsigned cubeVAO, cubeVBO;
//	glGenVertexArrays(1, &cubeVAO);
//	glGenBuffers(1, &cubeVBO);
//	glBindVertexArray(cubeVAO);
//	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	glBindVertexArray(0);
//	//ƽ��VAO
//	unsigned planeVAO, planeVBO;
//	glGenVertexArrays(1, &planeVAO);
//	glGenBuffers(1, &planeVBO);
//	glBindVertexArray(planeVAO);
//	glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), &planeVertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	
//	//��������
//	unsigned int cubeTexture = loadTexture("source/image/marble.jpg");
//	unsigned int planeTexture = loadTexture("source/image/timg.jpg");
//	unsigned int grassTexture = loadTexture("source/image/grass.png");
//	unsigned int windowTexture = loadTexture("source/image/window.png");
//
//	//����Shaders
//	Shader shader("shaders/shader_blending.vs", "shaders/shader_blending.fs");
//	shader.use();
//	shader.setUniformValue("texturel", 0);
//
//	//ѭ��
//	while (!glfwWindowShouldClose(window))
//	{
//		//ÿ֡ʱ���߼�
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		//����
//		processInput(window);
//
//		//��Ⱦ
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		shader.use();
//		glm::mat4 model;
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.f);
//		shader.setMat4("view", view);
//		shader.setMat4("projection", projection);
//
//		//������
//		glBindVertexArray(cubeVAO);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, cubeTexture);
//		model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
//		shader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		model = glm::mat4();
//		model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
//		shader.setMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//		glBindVertexArray(planeVAO);
//		glBindTexture(GL_TEXTURE_2D, planeTexture);
//		shader.setMat4("model", glm::mat4());
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//		glBindVertexArray(0);
//
//		//��鲢�����¼�����������
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	//ɾ��
//	glDeleteVertexArrays(1, &cubeVAO);
//	glDeleteVertexArrays(1, &planeVAO);
//	glDeleteBuffers(1, &cubeVBO);
//	glDeleteBuffers(1, &planeVBO);
//
//	glfwTerminate();
//	return 0;
//}
//
////��������ص�
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		camera.ProcessKeyboard(FORWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		camera.ProcessKeyboard(BACKWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		camera.ProcessKeyboard(LEFT, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		camera.ProcessKeyboard(RIGHT, deltaTime);
//}
//
////�����ڳߴ緢���仯�������ӿڳߴ�
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
////����ƶ��ص�
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	if (firstMode)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMode = false;
//	}
//
//	float xoffset = xpos - lastX;
//	float yoffset = ypos - lastY;
//
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.ProcessMouseMovement(xoffset, yoffset);
//}
//
////�����ֻص�
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	camera.ProcessMouseScroll(yoffset);
//}
//
////����2D����
//unsigned int loadTexture(const char* path)
//{
//	unsigned int textureID;
//	glGenTextures(1, &textureID);
//
//	int width, height, nrComponents;
//	unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
//	if (data)
//	{
//		GLenum format;
//		if (nrComponents == 1)
//			format = GL_RED;
//		else if (nrComponents == 3)
//			format = GL_RGB;
//		else if (nrComponents == 4)
//			format = GL_RGBA;
//
//		glBindTexture(GL_TEXTURE_2D, textureID);
//		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//		stbi_image_free(data);
//	}
//	else
//	{
//		std::cout << "Texture failed to load at path: " << path << std::endl;
//		stbi_image_free(data);
//	}
//
//	return textureID;
//}