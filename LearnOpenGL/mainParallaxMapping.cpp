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
//void RenderCube();
//void RenderQuad();
//
//
////���ڴ�С
//const unsigned int SCR_WIDTH = 1280;
//const unsigned int SCR_HEIGHT = 720;
//bool shadows = true;
//bool shadowKeyPressed = false;
//
////�����
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = (float)SCR_WIDTH / 2.0f;
//float lastY = (float)SCR_HEIGHT / 2.0f;
//bool firstMode = true;
//float heightScale = 0.1;
//
////ʱ��
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
////�Ƿ���Blinn-Phong
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
//	//glEnable(GL_MULTISAMPLE);
//
//	/*glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);*/
//	//glFrontFace(GL_CW);
//
//
//	//��������
//	GLuint diffuseMap = loadTexture("source/image/bricks2.jpg");
//	GLuint normalMap = loadTexture("source/image/bricks2_normal.jpg");
//	GLuint heightMap = loadTexture("source/image/bricks2_disp.jpg");
//
//	//����Shaders
//	//Shader shader("shaders/5_advanced_lighting/5_1_parallax_mapping/parallax_mapping.vs", "shaders/5_advanced_lighting/5_1_parallax_mapping/parallax_mapping.fs");
//	//Shader shader("shaders/5_advanced_lighting/5_2_parallax_mapping/parallax_mapping.vs", "shaders/5_advanced_lighting/5_2_parallax_mapping/parallax_mapping.fs");
//	Shader shader("shaders/5_advanced_lighting/5_3_parallax_occlusion_mapping/parallax_mapping.vs", "shaders/5_advanced_lighting/5_3_parallax_occlusion_mapping/parallax_mapping.fs");
//	shader.use();
//	shader.setBlock("Matrices", 0);
//	shader.setUniformValue("diffuseMap", 0);
//	shader.setUniformValue("normalMap", 1);
//	shader.setUniformValue("depthMap", 2);
//
//	//unsigned int uboMatrices;
//	//glGenBuffers(1, &uboMatrices);
//	//glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
//	//glBufferData(GL_UNIFORM_BUFFER, 152, nullptr, GL_STATIC_DRAW);	//����152�ֽڵ��ڴ�
//	//glBindBuffer(GL_UNIFORM_BUFFER, 0);
//	//glBindBufferRange(GL_UNIFORM_BUFFER, 0, uboMatrices, 0, 2 * sizeof(glm::mat4));
//
//	//glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
//	//glm::mat4 projection = glm::perspective(90.0f, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//	//glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(projection));
//	//glBindBuffer(GL_UNIFORM_BUFFER, 0);
//
//	////�������ӳ��FBO
//	//const unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
//	//unsigned int depthMapFBO;
//	//glGenFramebuffers(1, &depthMapFBO);
//	////�����������
//	//unsigned int depthCubemap;
//	//glGenTextures(1, &depthCubemap);
//	//glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubemap);
//	//for (unsigned int i = 0; i < 6; ++i)
//	//	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
//	////glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
//	//glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	//glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	//glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	//glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	//glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
//	////float borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
//	////glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
//
//
//	//glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
//	//glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthCubemap, 0);
//	//glDrawBuffer(GL_NONE);
//	//glReadBuffer(GL_NONE);
//	//glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//
//	//�ƹ�λ��
//	glm::vec3 lightPos(0.5f, 1.0f, 0.3f);
//
//	//Model planetModel("objects/planet/planet.obj");
//
//	//�����߿�ģʽ���ƶ����
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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
//		// move light position over time
//		//lightPos.z = sin(glfwGetTime() * 0.5) * 3.0;
//
//		//��Ⱦ
//		//glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		// configure view/projection matrices
//		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		shader.use();
//		shader.setMat4("projection", projection);
//		shader.setMat4("view", view);
//		// render normal-mapped quad
//		glm::mat4 model;
//		model = glm::rotate(model, glm::radians((float)glfwGetTime() * -10.0f), glm::normalize(glm::vec3(1.0, 0.0, 1.0))); // rotate the quad to show normal mapping from multiple directions
//		shader.setMat4("model", model);
//		shader.setVec3("viewPos", camera.Position);
//		shader.setVec3("lightPos", lightPos);
//		shader.setUniformValue("heightScale", heightScale);
//		//std::cout << heightScale << std::endl;
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, diffuseMap);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, normalMap);
//		glActiveTexture(GL_TEXTURE2);
//		glBindTexture(GL_TEXTURE_2D, heightMap);
//		RenderQuad();
//		
//		// render light source (simple re-renders a smaller plane at the light's position for debugging/visualization)
//		model = glm::mat4();
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.1f));
//		shader.setMat4("model", model);
//		RenderQuad();
//
//		//��鲢�����¼�����������
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
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
//	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
//		isPressB = true;
//	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_RELEASE && isPressB)
//	{
//		blinn = !blinn;
//		isPressB = false;
//	}
//	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
//	{
//		if (heightScale > 0.0f)
//			heightScale -= 0.0005f;
//		else
//			heightScale = 0.0f;
//	}
//	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
//	{
//		if (heightScale < 1.0f)
//			heightScale += 0.0005f;
//		else
//			heightScale = 1.0f;
//	}
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
//	//����ö��
//	GLenum attachment_type;
//	if (!depth && !stencil)
//		attachment_type = GL_RGB;
//	else if (depth && !stencil)
//		attachment_type = GL_DEPTH_COMPONENT;
//	else if (!depth && stencil)
//		attachment_type = GL_STENCIL_INDEX;
//
//	//��������ID�ͼ�����������
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
//	model = glm::scale(model, glm::vec3(5.0f));
//	shader.setMat4("model", model);
//	glDisable(GL_CULL_FACE); // note that we disable culling here since we render 'inside' the cube instead of the usual 'outside' which throws off the normal culling methods.
//	shader.setUniformValue("reverse_normals", 1); // A small little hack to invert normals when drawing cube from the inside so lighting 
//	RenderCube();
//	shader.setUniformValue("reverse_normals", 0); // and of course disable it
//	glEnable(GL_CULL_FACE);
//
//	//������
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(4.0f, -3.5f, 0.0));
//	model = glm::scale(model, glm::vec3(0.5f));
//	shader.setMat4("model", model);
//	RenderCube();
//
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(2.0f, 3.0f, 1.0));
//	model = glm::scale(model, glm::vec3(0.75f));
//	shader.setMat4("model", model);
//	RenderCube();
//
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(-3.0f, -1.0f, 0.0));
//	model = glm::scale(model, glm::vec3(0.5f));
//	shader.setMat4("model", model);
//	RenderCube();
//
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(-1.5f, 1.0f, 1.5));
//	model = glm::scale(model, glm::vec3(0.5f));
//	shader.setMat4("model", model);
//	RenderCube();
//
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(-1.5f, 2.0f, -3.0));
//	model = glm::rotate(model, glm::radians(60.0f), glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f)));
//	model = glm::scale(model, glm::vec3(0.75));
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
//		// positions
//		glm::vec3 pos1(-1.0f,  1.0f, 0.0f);
//		glm::vec3 pos2(-1.0f, -1.0f, 0.0f);
//		glm::vec3 pos3( 1.0f, -1.0f, 0.0f);
//		glm::vec3 pos4( 1.0f,  1.0f, 0.0f);
//		// texture coordinates
//		glm::vec2 uv1(0.0f, 1.0f);
//		glm::vec2 uv2(0.0f, 0.0f);
//		glm::vec2 uv3(1.0f, 0.0f);
//		glm::vec2 uv4(1.0f, 1.0f);
//		// normal vector
//		glm::vec3 nm(0.0f, 0.0f, 1.0f);
//
//		//calculate tangetn/bitangent vectors of both triangles
//		glm::vec3 tangent1, bitangent1;
//		glm::vec3 tangent2, bitangent2;
//		// triangle 1
//		// ------------
//		glm::vec3 edge1 = pos2 - pos1;
//		glm::vec3 edge2 = pos3 - pos1;
//		glm::vec2 deltaUV1 = uv2 - uv1;
//		glm::vec2 deltaUV2 = uv3 - uv1;
//
//		GLfloat f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
//
//		tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
//		tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
//		tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
//		tangent1 = glm::normalize(tangent1);
//
//		bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
//		bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
//		bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
//		bitangent1 = glm::normalize(bitangent1);
//
//		// triangle 2
//		// ----------
//		edge1 = pos3 - pos1;
//		edge2 = pos4 - pos1;
//		deltaUV1 = uv3 - uv1;
//		deltaUV2 = uv4 - uv1;
//
//		f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
//
//		tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
//		tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
//		tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
//		tangent2 = glm::normalize(tangent2);
//
//		bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
//		bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
//		bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
//		bitangent2 = glm::normalize(bitangent2);
//
//		float quadVertices[] = {
//			// positions            // normal         // texcoords  // tangent                          // bitangent
//			pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//			pos2.x, pos2.y, pos2.z, nm.x, nm.y, nm.z, uv2.x, uv2.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//			pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//
//			pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
//			pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
//			pos4.x, pos4.y, pos4.z, nm.x, nm.y, nm.z, uv4.x, uv4.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z
//		};
//
//		// configure plane VAO
//		glGenVertexArrays(1, &quadVAO);
//		glGenBuffers(1, &quadVBO);
//		glBindVertexArray(quadVAO);
//		glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)0);
//		glEnableVertexAttribArray(1);
//		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(3 * sizeof(float)));
//		glEnableVertexAttribArray(2);
//		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(6 * sizeof(float)));
//		glEnableVertexAttribArray(3);
//		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(8 * sizeof(float)));
//		glEnableVertexAttribArray(4);
//		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(11 * sizeof(float)));
//
//	}
//
//	glBindVertexArray(quadVAO);
//	glDrawArrays(GL_TRIANGLES, 0, 6);
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
//		float vertices[] = {
//            // back face
//            -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
//             1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // top-right
//             1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f, // bottom-right         
//             1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // top-right
//            -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
//            -1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f, // top-left
//            // front face
//            -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
//             1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f, // bottom-right
//             1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // top-right
//             1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // top-right
//            -1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f, // top-left
//            -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
//            // left face
//            -1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-right
//            -1.0f,  1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // top-left
//            -1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-left
//            -1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-left
//            -1.0f, -1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-right
//            -1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-right
//            // right face
//             1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-left
//             1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-right
//             1.0f,  1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // top-right         
//             1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-right
//             1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-left
//             1.0f, -1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-left     
//            // bottom face
//            -1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
//             1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f, // top-left
//             1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
//             1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
//            -1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f, // bottom-right
//            -1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
//            // top face
//            -1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
//             1.0f,  1.0f , 1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
//             1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f, // top-right     
//             1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
//            -1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
//            -1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f  // bottom-left        
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
