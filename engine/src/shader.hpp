#ifndef Shader_HPP
#define Shader_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

namespace GampyCPP {

class Shader
{
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);

    const GLuint program() const { return _program; }

    void use() { glUseProgram(_program); }
private:
    GLuint _program;
};

} // namespace GampyCPP

#endif  // Shader_HPP
