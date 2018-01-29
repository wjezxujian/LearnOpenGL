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
//unsigned int loadCubemap(std::vector<std::string> faces);
//GLuint generateMultiSampleTexture(GLuint samples);
//GLuint generateAttachmentTexture(GLboolean depth, GLboolean stencil);
//
//
////窗口大小
//const unsigned int SCR_WIDTH = 1280;
//const unsigned int SCR_HEIGHT = 720;
//
////摄像机
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = (float)SCR_WIDTH / 2.0f;
//float lastY = (float)SCR_HEIGHT / 2.0f;
//bool firstMode = true;
//
////时间
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
////是否开启Blinn-Phong
//GLboolean blinn = false;
//GLboolean isPressB = false;
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	//glfwWindowHint(GLFW_SAMPLES, 4);
//#ifdef __APPLE__
//	glfwWindowHit(GLFW_OPENGL_FORWARD_COMPAR, GL_TRUE);
//#endif //__APPLE__
//
//	//创建窗口
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
//	//隐藏鼠标
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	//glad:加载OpenGL函数指针
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	//配置OpenGL全局状态
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LESS);
//	//glEnable(GL_MULTISAMPLE);
//
//	/*glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);*/
//	//glFrontFace(GL_CW);
//
//	//设置顶点数据，配置顶点属性
//	GLfloat planeVertices[] = {
//		// Positions          // Normals         // Texture Coords
//		8.0f, -0.5f,  8.0f,  0.0f, 1.0f, 0.0f,  5.0f, 0.0f,
//		-8.0f, -0.5f,  8.0f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
//		-8.0f, -0.5f, -8.0f,  0.0f, 1.0f, 0.0f,  0.0f, 5.0f,
//
//		8.0f, -0.5f,  8.0f,  0.0f, 1.0f, 0.0f,  5.0f, 0.0f,
//		-8.0f, -0.5f, -8.0f,  0.0f, 1.0f, 0.0f,  0.0f, 5.0f,
//		8.0f, -0.5f, -8.0f,  0.0f, 1.0f, 0.0f,  5.0f, 5.0f
//	};
//
//	//平面VAO
//	unsigned planeVAO, planeVBO;
//	glGenVertexArrays(1, &planeVAO);
//	glGenBuffers(1, &planeVBO);
//	glBindVertexArray(planeVAO);
//	glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), &planeVertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	glBindVertexArray(0);
//
//	//加载纹理
//	GLuint floorTexture = loadTexture("source/image/wood.png");
//
//	//编译Shaders
//	Shader shader("shaders/shader_advanced_lighting.vs", "shaders/shader_advanced_lighting.fs");
//	shader.use();
//	shader.setBlock("Matrices", 0);
//
//
//	unsigned int uboMatrices;
//	glGenBuffers(1, &uboMatrices);
//	glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
//	glBufferData(GL_UNIFORM_BUFFER, 152, nullptr, GL_STATIC_DRAW);	//分配152字节的内存
//	glBindBuffer(GL_UNIFORM_BUFFER, 0);
//	glBindBufferRange(GL_UNIFORM_BUFFER, 0, uboMatrices, 0, 2 * sizeof(glm::mat4));
//
//	//glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
//	glm::mat4 projection = glm::perspective(45.0f, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 1000.0f);
//	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(projection));
//	glBindBuffer(GL_UNIFORM_BUFFER, 0);
//
//	//灯光位置
//	glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
//
//	//Model planetModel("objects/planet/planet.obj");
//
//	//调用线框模式绘制多边形
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	//循环
//	while (!glfwWindowShouldClose(window))
//	{
//		//每帧时间逻辑
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		//输入
//		processInput(window);
//
//		/*glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
//		glEnable(GL_DEPTH_TEST);*/
//
//		//渲染
//		//glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glEnable(GL_DEPTH_TEST);
//
//
//		glm::mat4 view = camera.GetViewMatrix();
//		glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
//		glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(view));
//		glBindBuffer(GL_UNIFORM_BUFFER, 0);
//
//		//绘制
//		shader.use();
//		shader.setMat4("model", glm::mat4());
//		shader.setVec3("lightPos", lightPos);
//		shader.setVec3("viewPos", camera.Position);
//		shader.setUniformValue("blinn", blinn);
//
//		glBindVertexArray(planeVAO);
//		glBindTexture(GL_TEXTURE_2D, floorTexture);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//		std::cout << (blinn ? "true" : "false") << std::endl;
//
//		//检查并调用事件，交换缓冲
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	//删除
//	glDeleteVertexArrays(1, &planeVAO);
//	glDeleteBuffers(1, &planeVBO);
//
//	glfwTerminate();
//	return 0;
//}
//
////键盘输入回调
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
//	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
//		isPressB = true;
//	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_RELEASE && isPressB)
//	{
//		blinn = !blinn;
//		isPressB = false;
//	}
//}
//
////当窗口尺寸发生变化，更改视口尺寸
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
////鼠标移动回调
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
////鼠标滚轮回调
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	camera.ProcessMouseScroll(yoffset);
//}
//
////加载2D纹理
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
//
//unsigned int loadCubemap(std::vector<std::string> faces)
//{
//	unsigned int textureID;
//	glGenTextures(1, &textureID);
//	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
//
//	int width, height, nrChannels;
//	for (unsigned int i = 0; i < faces.size(); ++i)
//	{
//		unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
//		if (data)
//		{
//			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//			stbi_image_free(data);
//		}
//		else
//		{
//			std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
//			stbi_image_free(data);
//		}
//	}
//
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
//
//	return textureID;
//}
//
//GLuint generateMultiSampleTexture(GLuint samples)
//{
//	GLuint texture;
//	glGenTextures(1, &texture);
//
//	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, texture);
//	glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, samples, GL_RGB, SCR_WIDTH, SCR_HEIGHT, GL_TRUE);
//	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
//
//	return texture;
//}
//
//GLuint generateAttachmentTexture(GLboolean depth, GLboolean stencil)
//{
//	//定义枚举
//	GLenum attachment_type;
//	if (!depth && !stencil)
//		attachment_type = GL_RGB;
//	else if (depth && !stencil)
//		attachment_type = GL_DEPTH_COMPONENT;
//	else if (!depth && stencil)
//		attachment_type = GL_STENCIL_INDEX;
//
//	//生成纹理ID和加载纹理数据
//	GLuint textureID;
//	glGenTextures(1, &textureID);
//	glBindTexture(GL_TEXTURE_2D, textureID);
//	if (!depth && !stencil)
//		glTexImage2D(GL_TEXTURE_2D, 0, attachment_type, SCR_WIDTH, SCR_HEIGHT, 0, attachment_type, GL_UNSIGNED_BYTE, nullptr);
//	else
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, SCR_WIDTH, SCR_HEIGHT, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, nullptr);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	return textureID;
//}
