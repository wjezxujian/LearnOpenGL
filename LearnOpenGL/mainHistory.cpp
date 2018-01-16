//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
////settings
//const uint32_t SCR_WIDHT = 800;
//const uint32_t SCR_HEIGHT = 600;
//
//const char* vertexShaderSource = "#version 330 core\n"
//	"layout (location = 0) in vec3 aPos; //位置变量的属性位置值为0\n"
//	"layout (location = 1) in vec3 aColor; //颜色变量的属性位置值为1 \n"
//	"//out vec4 vertexColor;//为片段着色器指定一个颜色输出\n"
//	"out vec3 ourColor; \n"
//	"void main() \n"
//	"{\n"
//	"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//	"	//vertexColor = vec4(0.5, 0.0, 0.0, 1.0); //把输出变量设置为暗红色\n"
//	"	ourColor = aColor; \n"
//	"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//	"out vec4 FragColor;\n"
//	"//in vec4 vertexColor; //从顶点着色器传来的输入变量（名称相同、类型相同）\n"
//	"//uniform vec4 ourColor; //在OpenGL程序代码中设定这个变量\n"
//	"in vec3 ourColor; \n"
//	"void main()\n"
//	"{\n"
//	"	FragColor = vec4(ourColor, 1.0);\n"
//	"}\n\0";
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
//	//编译着色器
//	//顶点着色器
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
//	glCompileShader(vertexShader);
//	//检查着色器编译错误
//	int sucess;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &sucess);
//	if (!sucess)
//	{
//		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
//		std::cout << "ERROR:SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	//片源着色器
//	unsigned int  fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
//	glCompileShader(fragmentShader);
//	//检查着色器编译错误
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &sucess);
//	if (!sucess)
//	{
//		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
//		std::cout << "ERROR:SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//
//	//链接Shaders
//	int shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	//检测链接错误
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &sucess);
//	if (!sucess)
//	{
//		glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	//绘制三角形
//	//设置顶点数据（和缓冲区）并配置顶点属性
//	float vertices[] = {
//			//位置				//颜色
//		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,		//左下
//		 0.5f, -0.5f, 0.0f,	 1.0f, 0.0f, 0.0f,		//右下
//		 0.0f,  0.5f, 0.0f,	 0.0f, 0.0f, 1.0f		//顶部
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
//	//绘制矩形
//	//float vertices[] = {
//	//	 0.5f,  0.5f, 0.0f,	//top right
//	//	 0.5f, -0.5f, 0.0f,	//bottom right
//	//	-0.5f, -0.5f, 0.0f, //botto left
//	//	-0.5f,  0.5f, 0.0f, //top left
//	//};
//
//	//unsigned int indices[] = {
//	//	0, 1, 3,			//first Triangle
//	//	1, 2, 3				//second Triangle
//	//};
//
//	//unsigned int VAO;
//	//glGenVertexArrays(1, &VAO);
//	//glBindVertexArray(VAO);
//
//	//unsigned int VBO;
//	//glGenBuffers(1, &VBO);
//	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//unsigned int EBO;
//	//glGenBuffers(1, &EBO);
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	//glEnableVertexAttribArray(0);
//
//	//glBindBuffer(GL_ARRAY_BUFFER, 0);
//	//glBindVertexArray(0);
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//
//
//	//调用线框模式绘制多边形
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	//renderLoop
//	while (!glfwWindowShouldClose(window))
//	{
//		//输入
//		processInput(window);
//
//		//渲染指令
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		//画我们的第一个三角形
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		//画矩形
//		/*glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);*/
//
//		//Shaders（uniform颜色全局变量）
//		//glUseProgram(shaderProgram);
//		////更新Uniform颜色
//		//float timeValue = glfwGetTime();
//		//float greenValue = sin(timeValue) / 2.0f + 0.5f;
//		//int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//		////绘制三角形
//		//glBindVertexArray(VAO);
//		//glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		//检查并调用事件，交换缓冲
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//