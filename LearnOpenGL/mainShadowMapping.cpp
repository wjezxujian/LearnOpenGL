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
//void RenderScene(Shader& shader);
//void RenderQuad();
//void RenderCube();
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
//unsigned planeVAO;
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
//	float planeVertices[] = {
//		   // positions            // normals      // texcoords
//		 25.0f, -0.5f,  25.0f,  0.0f, 1.0f, 0.0f,  25.0f,  0.0f,
//		-25.0f, -0.5f,  25.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
//		-25.0f, -0.5f, -25.0f,  0.0f, 1.0f, 0.0f,   0.0f, 25.0f,
//
//		 25.0f, -0.5f,  25.0f,  0.0f, 1.0f, 0.0f,  25.0f,  0.0f,
//		-25.0f, -0.5f, -25.0f,  0.0f, 1.0f, 0.0f,   0.0f, 25.0f,
//		 25.0f, -0.5f, -25.0f,  0.0f, 1.0f, 0.0f,  25.0f, 10.0f
//	};
//
//	//平面VAO
//	unsigned planeVBO;
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
//	GLuint woodTexture = loadTexture("source/image/wood.png");
//
//	//编译Shaders
//	Shader simpleDepthShader("shaders/shader_shadow_mapping_depth.vs", "shaders/shader_shadow_mapping_depth.fs");
//	//simpleDepthShader.use();
//	//simpleDepthShader.setBlock("Matrices", 0);
//
//	Shader debugDepthQuad("shaders/shader_debug_quad.vs", "shaders/shader_debug_quad.fs");
//	debugDepthQuad.use();
//	debugDepthQuad.setUniformValue("depthMap", 0);
//
//	Shader shader("shaders/shader_shadow_mapping.vs", "shaders/shader_shadow_mapping.fs");
//	shader.use();
//	shader.setBlock("Matrices", 0);
//	shader.setUniformValue("diffuseTexture", 0);
//	shader.setUniformValue("shadowMap", 1);
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
//	//配置深度映射FBO
//	const unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
//	unsigned int depthMapFBO;
//	glGenFramebuffers(1, &depthMapFBO);
//	//创建深度纹理
//	unsigned int depthMap;
//	glGenTextures(1, &depthMap);
//	glBindTexture(GL_TEXTURE_2D, depthMap);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
//	float borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
//	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
//
//
//	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
//	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
//	glDrawBuffer(GL_NONE);
//	glReadBuffer(GL_NONE);
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//
//	//灯光位置
//	glm::vec3 lightPos(-2.0f, 4.0f, -1.0f);
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
//		//渲染
//		//glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
//		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		
//		//1. render depth of scene to texture (from light's perspective)
//		glm::mat4 lightProjection, lightView;
//		glm::mat4 lightSpaceMatrix;
//		float near_plane = 1.0f, far_plane = 7.5f;
//		lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
//		lightView = glm::lookAt(lightPos, glm::vec3(0.0f), glm::vec3(0.0, 1.0, 0.0));
//		lightSpaceMatrix = lightProjection * lightView;
//		simpleDepthShader.use();
//		simpleDepthShader.setMat4("lightSpaceMatrix", lightSpaceMatrix);
//
//		glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
//		glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
//		glClear(GL_DEPTH_BUFFER_BIT);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, woodTexture);
//		RenderScene(simpleDepthShader);
//		glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//		//2.
//		glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		shader.use();
//		glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
//		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 1000.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(projection));
//		glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(view));
//		glBindBuffer(GL_UNIFORM_BUFFER, 0);
//		// set light uniforms
//		shader.setVec3("viewPos", camera.Position);
//		shader.setVec3("lightPos", lightPos);
//		shader.setMat4("lightSpaceMatrix", lightSpaceMatrix);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, woodTexture);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, depthMap);
//		RenderScene(shader);
//
//		// render Depth map to quad for visual debugging
//		// ---------------------------------------------
//		debugDepthQuad.use();
//		debugDepthQuad.setUniformValue("near_plane", near_plane);
//		debugDepthQuad.setUniformValue("far_plane", far_plane);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, depthMap);
//		//RenderQuad();
//
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
//
//void RenderScene(Shader & shader)
//{
//	//Floor
//	glm::mat4 model;
//	shader.setMat4("model", model);
//	glBindVertexArray(planeVAO);
//	glDrawArrays(GL_TRIANGLES, 0, 6);
//	glBindVertexArray(0);
//
//	//立方体
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(0.0f, 1.5f, 0.0f));
//	shader.setMat4("model", model);
//	RenderCube();
//
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(2.0f, 0.0f, 1.0f));
//	shader.setMat4("model", model);
//	RenderCube();
//
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(-1.0f, 0.0f, 2.0f));
//	model = glm::rotate(model, glm::radians(60.0f), glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f)));
//	model = glm::scale(model, glm::vec3(0.25));
//	shader.setMat4("model", model);
//	RenderCube();
//}
//
//
//GLuint quadVAO = 0;
//GLuint quadVBO;
//void RenderQuad()
//{
//	if (quadVAO == 0)
//	{
//		GLfloat quadVertices[] = {
//			//Positions		//Texture Coords
//			-1.0f,  1.0f,  0.0f,  0.0f, 1.0f,
//			-1.0f, -1.0f,  0.0f,  0.0f, 0.0f,
//			 1.0f,  1.0f,  0.0f,  1.0f, 1.0f,
//			 1.0f, -1.0f,  0.0f,  1.0f, 0.0f
//		};
//		//Setup plane VAO
//		glGenVertexArrays(1, &quadVAO);
//		glGenBuffers(1, &quadVBO);
//		glBindVertexArray(quadVAO);
//		glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*)0);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
//		glEnableVertexAttribArray(1);
//	}
//
//	glBindVertexArray(quadVAO);
//	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//	glBindVertexArray(0);
//}
//
//GLuint cubeVAO = 0;
//GLuint cubeVBO;
//void RenderCube()
//{
//	//Initialize (if necessary)
//	if (cubeVAO == 0)
//	{
//		GLfloat vertices[] = {
//            // Back face
//            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, // Bottom-left
//             0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f, // top-right
//             0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, // bottom-right         
//             0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,  // top-right
//            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,  // bottom-left
//            -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,// top-left
//            // Front face
//            -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom-left
//             0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,  // bottom-right
//             0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,  // top-right
//             0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // top-right
//            -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,  // top-left
//            -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom-left
//            // Left face
//            -0.5f,  0.5f,  0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top-right
//            -0.5f,  0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top-left
//            -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,  // bottom-left
//            -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom-left
//            -0.5f, -0.5f,  0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // bottom-right
//            -0.5f,  0.5f,  0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top-right
//            // Right face
//             0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top-left
//             0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom-right
//             0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top-right         
//             0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,  // bottom-right
//             0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // top-left
//             0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom-left     
//            // Bottom face
//            -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, // top-right
//             0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f, // top-left
//             0.5f, -0.5f,  0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,// bottom-left
//             0.5f, -0.5f,  0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, // bottom-left
//            -0.5f, -0.5f,  0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, // bottom-right
//            -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, // top-right
//            // Top face
//            -0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,// top-left
//             0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom-right
//             0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // top-right     
//             0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom-right
//            -0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,// top-left
//            -0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f // bottom-left        
//        };
//		glGenVertexArrays(1, &cubeVAO);
//		glGenBuffers(1, &cubeVBO);
//		glBindVertexArray(cubeVAO);
//		//fill buffer
//		glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//		glEnableVertexAttribArray(1);
//		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//		glEnableVertexAttribArray(2);
//		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//		glBindBuffer(GL_ARRAY_BUFFER, 0);
//		glBindVertexArray(0);
//	}
//	// render Cube
//	glBindVertexArray(cubeVAO);
//	glDrawArrays(GL_TRIANGLES, 0, 36);
//	glBindVertexArray(0);
//}