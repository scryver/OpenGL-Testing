#ifndef RenderElement_HPP
#define RenderElement_HPP

#include <vector>
#include <GL/glew.h>

#include "./shader.hpp"


class RenderElement
{
public:
    enum class DrawingMode {
        Static,
        Dynamic,
        Stream
    };

    explicit RenderElement(Shader* shader = nullptr,
                           DrawingMode drawMode = DrawingMode::Static);
    ~RenderElement();

    const Shader& shader() const { return *_shader; }
    // Set the shader of this element
    void setShader(Shader* shader) { _shader = shader; }

    // Init a render element with data, indices are optional but highly recommended
    void init(const std::vector<GLfloat>& vertices);
    void init(const std::vector<GLfloat>& vertices,
              const std::vector<GLfloat>& colors);

    void initIdx(const std::vector<GLfloat>& vertices,
                 const std::vector<GLuint>& indices);
    void initIdx(const std::vector<GLfloat>& vertices,
                 const std::vector<GLfloat>& colors,
                 const std::vector<GLuint>& indices);

    // Draw the element to the screen
    void draw();

    // Free the buffers and clear the vertices/indices
    void destroy();

private:
    // Vertex Buffer
    GLuint _VBO;
    // Element Buffer
    GLuint _EBO;
    // Vertex attributes
    GLuint _VAO;

    bool _withColor;

    // Shader program id
    Shader* _shader;

    // Vertices as set by init function
    std::vector<GLfloat>   _vertices;
    // Optional indices for element buffering
    std::vector<GLuint>    _indices;

    // Drawing mode, in static and stream mode the bindBuffer is called every
    // frame to update data
    DrawingMode             _drawMode;

    // Bind the vertices and indices data to the graphics card
    void bindBuffer();
};

#endif  // RenderElement_HPP
