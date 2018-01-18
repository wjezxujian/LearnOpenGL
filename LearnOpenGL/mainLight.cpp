//#include "Shader.h"
//#include "Camera.h"
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
//void mouseCallback(GLFWwindow* window, double xpos, double ypos);
//void scrollBack(GLFWwindow* window, double xoffset, double yoffset);
//
////设置
//const uint32_t SCR_WIDHT = 800;
//const uint32_t SCR_HEIGHT = 600;
//
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = SCR_WIDHT / 2.0;
//float lastY = SCR_HEIGHT / 2.0;
//bool isFirstMouse = true;
//
//float deltaTime = 0.0f; //当前帧与上一帧的时间差
//float lastFrame = 0.0f;	//上一帧的事件
//
//// 灯光位置
//glm::vec3 lightPos(1.2f, 0.5f, 2.0f);
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
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	glfwSetCursorPosCallback(window, mouseCallback);
//	glfwSetScrollCallback(window, scrollBack);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//	}
//
//
//	//绘制三角形
//	//设置顶点数据（和缓冲区）并配置顶点属性
//	float vertices[] = {
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
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
//	//设置顶点属性指针
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	//注意这是允许的，调用glVertexAttribPointer将VBO注册为顶点属性的绑定顶点缓冲区对象，所以之后我们可以安全地解除绑定
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	//之后你可以解除VAO的绑定，这样其他的VAO调用不会意外地修改这个VAO，但是这种情况很少发生。 
//	//修改其他的VAO需要调用glBindVertexArray，所以我们一般不会在不直接必要的情况下解除绑定VAO（不是VBO）。
//	glBindVertexArray(0);
//
//	//设置灯光数据
//	unsigned int lightVAO;
//	glGenVertexArrays(1, &lightVAO);
//	glBindVertexArray(lightVAO);
//	//只需要绑定VBO不用再次设置VBO的数据，因为箱子的VBO数据中已经包含了正确的立方体顶点数据
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//设置灯立方体的顶点属性（对我们的灯来说仅仅只有位置数据）
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	
//
//
//	//绑定纹理
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	//为当前纹理设置环绕
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//加载并生成纹理
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
//	//绑定第二个纹理
//	unsigned int texture2;
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	//为当前纹理设置环境
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//加载并生成纹理
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
//	Shader lightingShader("shaders/shader_light.vs", "shaders/shader_light.fs");
//	lightingShader.use();
//	glUniform3f(glGetUniformLocation(lightingShader.getShaderID(), "objectColor"), 1.0f, 0.5f, 0.31f);
//	glUniform3f(glGetUniformLocation(lightingShader.getShaderID(), "lightColor"), 1.0f, 1.0f, 1.0f);
//	glUniform3f(glGetUniformLocation(lightingShader.getShaderID(), "lightPos"), lightPos.x, lightPos.y, lightPos.z);
//	//lightingShader.setUniformValue("ambientStrength", 0.1f);
//
//	Shader lampShader("shaders/shader_lamp.vs", "shaders/shader_lamp.fs");
//	lampShader.use();
//
//	//开启深度缓冲
//	glEnable(GL_DEPTH_TEST);
//
//	//调用线框模式绘制多边形
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	//renderLoop
//	while (!glfwWindowShouldClose(window))
//	{
//		//每一帧时间逻辑
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		//输入
//		processInput(window);
//
//		//渲染指令
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//绘制盒子
//		lightingShader.use();
//		glm::mat4 view = camera.GetViewMatrix();
//		glUniformMatrix4fv(glGetUniformLocation(lightingShader.getShaderID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
//		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDHT / (float)SCR_HEIGHT, 0.1f, 100.0f);
//		glUniformMatrix4fv(glGetUniformLocation(lightingShader.getShaderID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//		glUniform3f(glGetUniformLocation(lightingShader.getShaderID(), "viewPos"), camera.Position.x, camera.Position.y, camera.Position.z);
//
//		/*glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);*/
//
//		glm::mat4 model;
//		/*model = glm::translate(model, cubePositions[i]);
//		float angle = 20 * glfwGetTime();
//		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));*/
//		glUniformMatrix4fv(glGetUniformLocation(lightingShader.getShaderID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		//绘制灯光
//		lampShader.use();
//		glUniformMatrix4fv(glGetUniformLocation(lampShader.getShaderID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(glGetUniformLocation(lampShader.getShaderID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//		model = glm::mat4();
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f)); // 缩放
//		glUniformMatrix4fv(glGetUniformLocation(lampShader.getShaderID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
//
//		glBindVertexArray(lightVAO);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		//检查并调用事件，交换缓冲
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteVertexArrays(1, &lightVAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//	return 0;
//}
//
//void processInput(GLFWwindow* window)
//{
//	float cameraSpeed = 2.5f * deltaTime;	//adjust accordingly
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, true);
//	}
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//	{
//		camera.ProcessKeyboard(FORWARD, deltaTime);
//	}
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//	{
//		camera.ProcessKeyboard(BACKWARD, deltaTime);
//	}
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//	{
//		camera.ProcessKeyboard(LEFT, deltaTime);
//	}
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//	{
//		camera.ProcessKeyboard(RIGHT, deltaTime);
//	}
//}
//
//void mouseCallback(GLFWwindow * window, double xpos, double ypos)
//{
//	if (isFirstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		isFirstMouse = false;
//	}
//
//	float xOffset = xpos - lastX;
//	float yOffset = lastY - ypos;
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.ProcessMouseMovement(xOffset, yOffset);
//}
//
//void scrollBack(GLFWwindow * window, double xoffset, double yoffset)
//{
//	camera.ProcessMouseScroll(yoffset);
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
