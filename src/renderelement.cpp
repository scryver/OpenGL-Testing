#include "./renderelement.hpp"

#include <cmath>
#include <iostream>
#include <GLFW/glfw3.h>


RenderElement::RenderElement(GLuint shader, DrawingMode drawMode) :
        _VBO(0), _EBO(0), _VAO(0), _shader(shader), _drawMode(drawMode)
{
    // Empty
}

RenderElement::~RenderElement()
{
    destroy();
}

void RenderElement::init(const std::vector<GLfloat>& vertices) {
    if (!_vertices.empty()) {
        std::cout << "RenderElement already initialized" << std::endl;
        return;
    }

    glGenBuffers(1, &_VBO);
    glGenVertexArrays(1, &_VAO);

    _vertices = vertices;

    bindBuffer();
}

void RenderElement::init(const std::vector<GLfloat>& vertices,
                         const std::vector<GLuint>& indices) {
    if (!_vertices.empty()) {
        std::cout << "RenderElement already initialized" << std::endl;
        return;
    }

    glGenBuffers(1, &_EBO);
    _indices = indices;

    init(vertices);
}

void RenderElement::draw() {
    glUseProgram(_shader);

    GLfloat timeValue = glfwGetTime();
    GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
    GLint vertexColorLocation = glGetUniformLocation(_shader, "ourColor");
    if (vertexColorLocation >= 0)
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

    if (_drawMode == DrawingMode::Dynamic || _drawMode == DrawingMode::Stream)
        bindBuffer();

    glBindVertexArray(_VAO);

    if (_indices.empty())
        glDrawArrays(GL_TRIANGLES, 0, 3);
    else
        glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glUseProgram(0);
}

void RenderElement::destroy() {
    if (!_vertices.empty()) {
        glDeleteVertexArrays(1, &_VAO);
        glDeleteBuffers(1, &_VBO);
        if (!_indices.empty()) {
            glDeleteBuffers(1, &_EBO);
        }
    }
    _vertices.clear();
    _indices.clear();
}

void RenderElement::bindBuffer() {
    // ..:: Initialization code (done once (unless your object frequently changes)) :: ..
    // 1. Bind Vertex Array Object
    glBindVertexArray(_VAO);
    {
        // 2. Copy our vertices array in a buffer for OpenGL to use
        glBindBuffer(GL_ARRAY_BUFFER, _VBO);

        if (_drawMode == DrawingMode::Static)
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _vertices.size(), &_vertices.front(), GL_STATIC_DRAW);
        else if (_drawMode == DrawingMode::Dynamic)
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _vertices.size(), &_vertices.front(), GL_DYNAMIC_DRAW);
        else if (_drawMode == DrawingMode::Stream)
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _vertices.size(), &_vertices.front(), GL_STREAM_DRAW);

        if (!_indices.empty()) {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);

            if (_drawMode == DrawingMode::Static)
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * _indices.size(), &_indices.front(), GL_STATIC_DRAW);
            else if (_drawMode == DrawingMode::Dynamic)
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * _indices.size(), &_indices.front(), GL_DYNAMIC_DRAW);
            else if (_drawMode == DrawingMode::Stream)
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * _indices.size(), &_indices.front(), GL_STREAM_DRAW);
        }

        // 3. Then set the vertex attributes pointers
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
    }
    // 4. Unbind VAO
    glBindVertexArray(0);
}
