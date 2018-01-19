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
//unsigned int loadTexture(char const* path);
//
////����
//const uint32_t SCR_WIDHT = 800;
//const uint32_t SCR_HEIGHT = 600;
//
//Camera camera(glm::vec3(-1.5f, 0.0f, 3.0f));
//float lastX = SCR_WIDHT / 2.0;
//float lastY = SCR_HEIGHT / 2.0;
//bool isFirstMouse = true;
//
//float deltaTime = 0.0f; //��ǰ֡����һ֡��ʱ���
//float lastFrame = 0.0f;	//��һ֡���¼�
//
//						// �ƹ�λ��
//glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
//glm::vec3 direction(-0.2f, -1.0f, -3.0f);
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
//	//����������
//	//���ö������ݣ��ͻ������������ö�������
//	float vertices[] = {
//		//λ��				   //����	   //��������
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
//		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
//		0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//
//		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
//	};
//
//	// positions all containers
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
//	// positions of the point lights
//	glm::vec3 pointLightPositions[] = {
//		glm::vec3(0.7f,  0.2f,  2.0f),
//		glm::vec3(2.3f, -3.3f, -4.0f),
//		glm::vec3(-4.0f,  2.0f, -12.0f),
//		glm::vec3(0.0f,  0.0f, -3.0f)
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
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	//ע����������ģ�����glVertexAttribPointer��VBOע��Ϊ�������Եİ󶨶��㻺������������֮�����ǿ��԰�ȫ�ؽ����
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	//֮������Խ��VAO�İ󶨣�����������VAO���ò���������޸����VAO����������������ٷ����� 
//	//�޸�������VAO��Ҫ����glBindVertexArray����������һ�㲻���ڲ�ֱ�ӱ�Ҫ������½����VAO������VBO����
//	glBindVertexArray(0);
//
//	//���õƹ�����
//	unsigned int lightVAO;
//	glGenVertexArrays(1, &lightVAO);
//	glBindVertexArray(lightVAO);
//	//ֻ��Ҫ��VBO�����ٴ�����VBO�����ݣ���Ϊ���ӵ�VBO�������Ѿ���������ȷ�������嶥������
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//���õ�������Ķ������ԣ������ǵĵ���˵����ֻ��λ�����ݣ�
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//
//	//����������
//	unsigned int texture = loadTexture("source/image/container2.png");
//	//�߹�����
//	unsigned int texture2 = loadTexture("source/image/container2_specular.png");
//	//�Է�������
//	unsigned int texture3 = loadTexture("source/image/matrix.jpg");
//
//	Shader lightingShader("shaders/shader_lightmultiple.vs", "shaders/shader_lightmultiple.fs");
//	lightingShader.use();
//	lightingShader.setUniformValue("material.diffuse", 0);
//	lightingShader.setUniformValue("material.specular", 1);
//	lightingShader.setUniformValue("material.shininess", 32.0f);
//
//	Shader lampShader("shaders/shader_lamp.vs", "shaders/shader_lamp.fs");
//	lampShader.use();
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
//		//ÿһ֡ʱ���߼�
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		//����
//		processInput(window);
//
//		//��Ⱦָ��
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//���ƺ���
//		lightingShader.use();
//		lightingShader.setVec3("viewPos", camera.Position);
//		glm::mat4 view = camera.GetViewMatrix();
//		lightingShader.setMat4( "view",view);
//		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDHT / (float)SCR_HEIGHT, 0.1f, 100.0f);
//		lightingShader.setMat4("projection", projection);
//	
//
//		glm::vec3 lightColor;
//		lightColor.r = sin(glfwGetTime() * 2.0f);
//		lightColor.g = sin(glfwGetTime() * 0.7f);
//		lightColor.b = sin(glfwGetTime() * 1.3f);
//
//		// directional light
//		lightingShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
//		lightingShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
//		lightingShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
//		// point light 1
//		lightingShader.setVec3("pointLights[0].position", pointLightPositions[0]);
//		lightingShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
//		lightingShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.setUniformValue("pointLights[0].constant", 1.0f);
//		lightingShader.setUniformValue("pointLights[0].linear", 0.09f);
//		lightingShader.setUniformValue("pointLights[0].quadratic", 0.032f);
//		// point light 2
//		lightingShader.setVec3("pointLights[1].position", pointLightPositions[1]);
//		lightingShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
//		lightingShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.setUniformValue("pointLights[1].constant", 1.0f);
//		lightingShader.setUniformValue("pointLights[1].linear", 0.09f);
//		lightingShader.setUniformValue("pointLights[1].quadratic", 0.032f);
//		// point light 3
//		lightingShader.setVec3("pointLights[2].position", pointLightPositions[2]);
//		lightingShader.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
//		lightingShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.setUniformValue("pointLights[2].constant", 1.0f);
//		lightingShader.setUniformValue("pointLights[2].linear", 0.09f);
//		lightingShader.setUniformValue("pointLights[2].quadratic", 0.032f);
//		// point light 4
//		lightingShader.setVec3("pointLights[3].position", pointLightPositions[3]);
//		lightingShader.setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
//		lightingShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.setUniformValue("pointLights[3].constant", 1.0f);
//		lightingShader.setUniformValue("pointLights[3].linear", 0.09f);
//		lightingShader.setUniformValue("pointLights[3].quadratic", 0.032f);
//		// spotLight
//		lightingShader.setVec3("spotLight.position", camera.Position);
//		lightingShader.setVec3("spotLight.direction", camera.Front);
//		lightingShader.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
//		lightingShader.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
//		lightingShader.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.setUniformValue("spotLight.constant", 1.0f);
//		lightingShader.setUniformValue("spotLight.linear", 0.09f);
//		lightingShader.setUniformValue("spotLight.quadratic", 0.032f);
//		lightingShader.setUniformValue("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
//		lightingShader.setUniformValue("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//		glActiveTexture(GL_TEXTURE2);
//		glBindTexture(GL_TEXTURE_2D, texture3);
//
//		glBindVertexArray(VAO);
//		//glm::mat4 model;
//		///*model = glm::translate(model, cubePositions[i]);
//		//float angle = 20 * glfwGetTime();
//		//model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));*/
//		//glUniformMatrix4fv(glGetUniformLocation(lightingShader.getShaderID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
//		//glDrawArrays(GL_TRIANGLES, 0, 36);
//		for (unsigned int i = 0; i < 10; ++i)
//		{
//			glm::mat4 model;
//			model = glm::translate(model, cubePositions[i]);
//			float angle = 20 * i;  //glfwGetTime();
//			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//			glUniformMatrix4fv(glGetUniformLocation(lightingShader.getShaderID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//		//���Ƶƹ�
//		lampShader.use();
//		lightingShader.setMat4("view", view);
//		lightingShader.setMat4("projection", projection);
//		glBindVertexArray(lightVAO);
//		for (unsigned i = 0; i < 4; ++i)
//		{
//			glm::mat4 model;
//			model = glm::mat4();
//			model = glm::translate(model, pointLightPositions[i]);
//			model = glm::scale(model, glm::vec3(0.2f)); // ����
//			lightingShader.setMat4("model", model);
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//		
//		//��鲢�����¼�����������
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
//unsigned int loadTexture(char const * path)
//{
//	//������
//	unsigned int textureID;
//	glGenTextures(1, &textureID);
//
//
//	//���ز���������
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		GLenum format;
//		if (nrChannels == 1)
//			format = GL_RED;
//		else if (nrChannels == 3)
//			format = GL_RGB;
//		else if (nrChannels == 4)
//			format = GL_RGBA;
//
//
//		glBindTexture(GL_TEXTURE_2D, textureID);
//		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//
//		//Ϊ��ǰ�������û���
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//		stbi_image_free(data);
//	}
//	else
//	{
//		textureID = 0;
//		std::cout << "Failed to load texture" << std::endl;
//	}
//
//	return textureID;
//}