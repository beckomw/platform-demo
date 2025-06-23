#ifndef SHADER_H
#define SHADER_H


#include <GL/glew.h> 
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp> 
#include <string> 
#include <fstream> 
#include <sstream> 
#include <iostream> 

class Shader {
	

	// shader program ID 
	unsigned int ID; 


	// Constructor reads and builds the shader 
	Shader(const char* vertexPATH, const char* fragmentPath); 

	// Destructor 
	~Shader(); 

	//Use/activate the shader 
	void use(); 

	// Utility uniform function 
	void setFloat(const std::string &name, float value) const; 
	void setInt(const std::string &name, int value) const; 
	void setVec3(const std::string &name, const glm::vec3 &value) const; 
	void setVec3(const Std::string &name, float x, float y, float z) const; 
	void setMat4(const std::string &name, const glm::mat4 &mat) const; 

private: 
	// Utility function for checking shader compliation/linking errors
	void checkComileErrors(unsigned int shader, std::string type); 

}; 

#endif 
