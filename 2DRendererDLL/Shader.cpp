#include "Shader.h"

namespace Renderer {

	Shader::Shader() {

	}

	Shader::Shader(const char* vertexPath, const char* fragmentPath) {
		std::string vertexCode;
		std::string fragmentCode;

		std::ifstream vShaderFile;
		std::ifstream fShaderFile;

		//Ensure exceptions are thrown
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		//Try to open the file
		try {

			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);

			//String stream for reading the code in file
			std::stringstream vShaderStream, fShaderStream;
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();

			vShaderFile.close();
			fShaderFile.close();

			//Put the code into our string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		} catch (std::ifstream::failure& e) {
			std::cout << "ERROR::SHADER::COULDN'T_READ_FILE!\n";
		}

		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();

		//Compile shader
		unsigned int vertex, fragment;
		int success;
		char infoLog[1024];

		//Compile vertex shader and check for errors
		vertex = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);

		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			std::cout << "ERROR:SHADER:VERTEX::COMPILATION_FAILED!\n" << infoLog << "\n";
		}

		std::cout << "Compilation of vertex shader successfull!\n";

		//Compile fragment shader and check for errors
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragment, 1024, NULL, infoLog);
			std::cout << "ERROR:SHADER:FRAGMENT::COMPILATION_FAILED!\n" << infoLog << "\n";
		}

		std::cout << "Compilation of fragment shader successfull!\n";

		//Link shader and check for errors
		ID = glCreateProgram();

		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);

		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(ID, 1024, NULL, infoLog);
			std::cout << "ERROR:SHADER:LINKING::LINKING_FAILED!\n" << infoLog << "\n";
		}

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	void Shader::use() {
		glUseProgram(ID);
	}

	void Shader::SetBool(const std::string& name, bool value) const {
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}

	void Shader::SetInt(const std::string& name, int value) const {
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}

	void Shader::SetFloat(const std::string& name, float value) const {
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}

}