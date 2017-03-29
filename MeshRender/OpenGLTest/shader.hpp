
#pragma once
#ifndef SHADER_HPP
#define SHADER_HPP
#include <GL/freeglut.h>
GLuint LoadShaders(const char * vertex_file_path, const char* fragment_file_path);
GLuint LoadVertexShader(const char * vertex_file_path);
#endif
