/*
 *  Shader.h
 *  CS248-Final-Project
 *
 *  Created by Matthew Fichman on 1/25/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <string>
#include <vector>

class Shader {
public:
	/**
	 * Loads a vertex shader and fragment shader, compiles them, and links
	 * them into a single GPU program.  The vertex shader file should be 
	 * at <path>.frag.glsl, and the fragment shader file should be at
	 * <path>.vert.glsl.  If the program fails to compile, then the loaded()
	 * function will return false.
	 * @param path the path to the vertex/fragment shader files
	 */
	Shader(const std::string& path);
	
	/**
	 * This function deallocates the shader.
	 */
	~Shader();
	
	/**
	 * Returns the path used to load this shader (without the file extensions)
	 * @return the shader path
	 */
	const std::string& path() const;
	
	/**
	 * Returns the OpenGL handle for the GPU program.  You can use the handle
	 * with OpenGL like this: glUseProgram(shader->program());
	 * Calling glUseProgram() will replace OpenGL's fixed pipeline with your
	 * vertex/fragment shader.  You can also use the program handle to 
	 * get/set uniform values and attributes using glUniformLocation(),
	 * glUniform(), glAttributeLocation(), and glAttribute().
	 * @return OpenGL handle to the GPU program
	 */
	GLuint program() const;
	
	/**
	 * If the shader loaded successfully, then this function will return true.
	 * If the shader didn't load successfully, the error messages can be
	 * retrieved from the errors() function.
	 */
	bool loaded() const;
	
	/**
	 * Returns a string containing all the shader compile errors.
	 * @return shader compilation errors
	 */
	const std::string& errors() const;
	
private:
	std::vector<char> readSource(const std::string& path);
	
	std::string path_;
	std::string errors_;
	GLuint vertexShader_;
	GLuint fragmentShader_;
	GLuint program_;
	bool loaded_;
};