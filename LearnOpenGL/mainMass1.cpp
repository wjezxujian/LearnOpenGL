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
//
////窗口大小
//const unsigned int SCR_WIDTH = 1280;
//const unsigned int SCR_HEIGHT = 720;
//
////摄像机
//Camera camera(glm::vec3(1.0f, 0.0f, 3.0f));
//float lastX = (float)SCR_WIDTH / 2.0f;
//float lastY = (float)SCR_HEIGHT / 2.0f;
//bool firstMode = true;
//
////时间
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
//	glfwWindowHint(GLFW_SAMPLES, 4);
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
//	glEnable(GL_MULTISAMPLE);
//
//	/*glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);*/
//	//glFrontFace(GL_CW);
//
//	//设置顶点数据，配置顶点属性
//	GLfloat cubeVertices[] = {
//		// Positions       
//		-0.5f, -0.5f, -0.5f,
//		0.5f, -0.5f, -0.5f,
//		0.5f,  0.5f, -0.5f,
//		0.5f,  0.5f, -0.5f,
//		-0.5f,  0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//
//		-0.5f, -0.5f,  0.5f,
//		0.5f, -0.5f,  0.5f,
//		0.5f,  0.5f,  0.5f,
//		0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f,  0.5f,
//		-0.5f, -0.5f,  0.5f,
//
//		-0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//		-0.5f, -0.5f,  0.5f,
//		-0.5f,  0.5f,  0.5f,
//
//		0.5f,  0.5f,  0.5f,
//		0.5f,  0.5f, -0.5f,
//		0.5f, -0.5f, -0.5f,
//		0.5f, -0.5f, -0.5f,
//		0.5f, -0.5f,  0.5f,
//		0.5f,  0.5f,  0.5f,
//
//		-0.5f, -0.5f, -0.5f,
//		0.5f, -0.5f, -0.5f,
//		0.5f, -0.5f,  0.5f,
//		0.5f, -0.5f,  0.5f,
//		-0.5f, -0.5f,  0.5f,
//		-0.5f, -0.5f, -0.5f,
//
//		-0.5f,  0.5f, -0.5f,
//		0.5f,  0.5f, -0.5f,
//		0.5f,  0.5f,  0.5f,
//		0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f, -0.5f
//	};
//
//	//小行星位置
//	unsigned int amount = 100000;
//	glm::mat4* modelMatrices;
//	modelMatrices = new glm::mat4[amount];
//	srand(glfwGetTime()); //初始化随机种子
//	float radius = 150.0;
//	float offset = 25.0f;
//	for (unsigned int i = 0; i < amount; i++)
//	{
//		glm::mat4 model;
//		// 1. 位移：分布在半径为 'radius' 的圆形上，偏移的范围是 [-offset, offset]
//		float angle = (float)i / (float)amount * 360.0f;
//		float displacement = (rand() % (int)(2 * offset * 100)) / 100.0f - offset;
//		float x = sin(angle) * radius + displacement;
//		displacement = (rand() % (int)(2 * offset * 100)) / 100.0f - offset;
//		float y = displacement * 0.4f; // 让行星带的高度比x和z的宽度要小
//		displacement = (rand() % (int)(2 * offset * 100)) / 100.0f - offset;
//		float z = cos(angle) * radius + displacement;
//		model = glm::translate(model, glm::vec3(x, y, z));
//
//		// 2. 缩放：在 0.05 和 0.25f 之间缩放
//		float scale = (rand() % 20) / 100.0f + 0.05;
//		model = glm::scale(model, glm::vec3(scale));
//
//		// 3. 旋转：绕着一个（半）随机选择的旋转轴向量进行随机的旋转
//		float rotAngle = (rand() % 360);
//		model = glm::rotate(model, rotAngle, glm::vec3(0.4f, 0.6f, 0.8f));
//
//		// 4. 添加到矩阵的数组中
//		modelMatrices[i] = model;
//	}
//
//
//	//立方体VAO
//	unsigned cubeVAO, cubeVBO;
//	glGenVertexArrays(1, &cubeVAO);
//	glGenBuffers(1, &cubeVBO);
//	glBindVertexArray(cubeVAO);
//	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	/*glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
//	glEnableVertexAttribArray(1);*/
//
//	//实例VBO
//	/*unsigned int instanceVBO;
//	glGenBuffers(1, &instanceVBO);
//	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * 100, &translations[0], GL_STATIC_DRAW);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(2);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glVertexAttribDivisor(2, 1);*/
//
//	glBindVertexArray(0);
//
//	//加载纹理
//	//unsigned int frontTexture = loadTexture("source/image/marble.jpg");
//	//unsigned int backTexture = loadTexture("source/image/container.jpg");
//
//	//编译Shaders
//	/*Shader shader("shaders/shader_advancehlsl.vs", "shaders/shader_advancehlsl.fs");
//	shader.use();
//	shader.setUniformValue("frontTexture", 0);
//	shader.setUniformValue("backTexture", 1);*/
//
//	Shader shader("shaders/shader_mass1.vs", "shaders/shader_mass1.fs");
//	shader.use();
//	shader.setBlock("Matrices", 0);
//
//	/*for (unsigned int i = 0; i < 100; ++i)
//	{
//	shader.setVec2(("offsets[" + std::to_string(i) + "]").c_str(), translations[i]);
//	}*/
//
//	/*Shader normalDisplayShader("shaders/shader_geometry3.vs", "shaders/shader_geometry3.fs", "shaders/shader_geometry3.gs");
//	normalDisplayShader.use();
//	normalDisplayShader.setBlock("Matrices", 0);*/
//
//	unsigned int uboMatrices;
//	glGenBuffers(1, &uboMatrices);
//	glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
//	glBufferData(GL_UNIFORM_BUFFER, 152, nullptr, GL_STATIC_DRAW);	//分配152字节的内存
//	glBindBuffer(GL_UNIFORM_BUFFER, 0);
//
//	glBindBufferRange(GL_UNIFORM_BUFFER, 0, uboMatrices, 0, 2 * sizeof(glm::mat4));
//
//	glm::mat4 projection = glm::perspective(45.0f, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 1000.0f);
//	glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
//	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(projection));
//	glBindBuffer(GL_UNIFORM_BUFFER, 0);
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
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glm::mat4 view = camera.GetViewMatrix();
//		glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
//		glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(view));
//		glBindBuffer(GL_UNIFORM_BUFFER, 0);
//
//		//绘制
//		shader.use();
//		shader.setMat4("model", glm::mat4());
//		glBindVertexArray(cubeVAO);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//
//		//检查并调用事件，交换缓冲
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	//删除
//	glDeleteVertexArrays(1, &cubeVAO);
//	glDeleteBuffers(1, &cubeVBO);
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