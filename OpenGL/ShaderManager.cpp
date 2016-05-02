#include "ShaderManager.h"

ShaderManager::ShaderManager()
{
	program = 0;
}


ShaderManager::~ShaderManager()
{
}

GLuint ShaderManager::GetProgram() const
{
	return program;
}

bool ShaderManager::loadShaders(const char * vertexFile, const char * fragmentFile)
{
	GLint programLinkCheck = 0;

	//Load the two shaders
	GLuint vShader = loadShader(vertexFile, GL_VERTEX_SHADER);
	GLuint fShader = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
	
	//Chcek to see if the shaders loaded properly
	if (!vShader || !fShader) return false;

	//Create a linked shader program
	program = glCreateProgram();

	//Attach the shaders
	glAttachShader(program, vShader);
	glAttachShader(program, fShader);

	//Link the program
	glLinkProgram(program);

	//Check the linking status of the program
	glGetProgramiv(program, GL_LINK_STATUS, &programLinkCheck);
	
	if (programLinkCheck == 0)
	{
		GLint logLength = 0;

		//Get the length of the log and output it to logLength
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);

		//Alocate that amount of an array on the heap
		GLchar *log = new char[logLength];

		//Get the log and send it to the array on the heap
		glGetProgramInfoLog(program, logLength, 0, log);

		//print out the log
		cout << log;

		delete[] log;

		//Delete the shader and exit the function
		glDeleteProgram(program);
		return false;
	}
	else
	{
		return true;
	}
}

GLuint ShaderManager::loadShader(const char * file, GLenum shaderType)
{
	char* shaderContents;
	GLuint shader = 0;
	GLint shaderCompileCheck = 0;
	ifstream shaderFile(file, std::ios::binary);
	if (shaderFile.is_open())
	{
		//Find the length of the file in binary
		shaderFile.seekg(0, std::ios::end);
		int length = shaderFile.tellg();

		//Return to the beginning of the file
		shaderFile.seekg(0, std::ios::beg);

		//Allocate enough space for storing the contents on the heap
		shaderContents = new char[length + 1];

		//Read in the contents to the heap and add a null terminator
		shaderFile.read(shaderContents, length);
		shaderContents[length] = '\0';

		shaderFile.close();

		//Create the shader and attempt to compile it
		shader = glCreateShader(shaderType);
		glShaderSource(shader, 1, &shaderContents, 0);
		glCompileShader(shader);

		//Check the compile status and output whether it worked or not to shaderCompileCheck
		glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderCompileCheck);
		
		if (shaderCompileCheck == 0) //Failure to compile
		{
			GLint logLength = 0;
			
			//Get the length of the log and output it to logLength
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

			//Alocate that amount of an array on the heap
			GLchar* log = new char[logLength];

			//Get the log and send it to the array on the heap
			glGetShaderInfoLog(shader, logLength, 0, log);

			//print out the log
			cout << log;

			delete[] log;

			//Delete the shader and exit the function
			glDeleteShader(shader);
			return 0;
		}
		return shader;

		delete[] shaderContents;
	}
	else
	{
		cout << "Something went wrong loading the shader -" << file << "- ";
		return 0;
	}
}
