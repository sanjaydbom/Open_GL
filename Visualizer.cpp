#define _USE_MATH_DEFINES
#include "Visualizer.h"
#include <stdexcept>
#include <cmath>
#include <numbers>

Visualizer::Visualizer(int width, int height, float* bgColor, float* oColor)
{
    //Initialize glfw
    glfwInit();

    //tells us which version of glfw we are working with: 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //create window
    window = glfwCreateWindow(width, height, "My OpenGL Window", NULL, NULL);
    //make sure window is created
    if(window == NULL){
        glfwTerminate();
        std::cout << "COOKED";
        //throw std::system_error("Error initializing window. Check system configurations and libraries");
    }

    //idk just make the context current to make sure glfw operates on this window?
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Cooked";
        //throw std::system_error("Error initializing GLAD. Check system configurations and libraries");
    }


    //Set up VAO
    //VAO is configuration data
    //Since we only use one configuration, we only generate 1 VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //VBO is where the actual data is stored
    //we only have one location for the data, vertices, so we only generate on VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //store the data-Static Draw is a way to draw the object, there are other ways depending on if it changes a lot or not
    glBufferData(GL_ARRAY_BUFFER, 3 * (precision + 1) * sizeof(float), nullptr, GL_DYNAMIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * (precision) * sizeof(int), nullptr, GL_DYNAMIC_DRAW);


    //we tell OpenGL how to interpret the data
    //First value is location of the vertex attributes. IDK what this means
    //Second value is number of components per vertex. 3 because (x,y,z) even though z = 0 for all points
    //Third value is type of the data
    //Ignore 4th argument-always false
    //Fifth value is stride length for each vertex. Because each vertex has 3 components, and each component is the size of a float, the stride length is 3 * sizeof(float)
    //Sixth value is offset of the first component.
    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    //Unbind VAO and VBO to prevent accidental changes
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

    std::string fss = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(" + 
    std::to_string(oColor[0]) + "f, " +
    std::to_string(oColor[1]) + "f, " +
    std::to_string(oColor[2]) + "f, " +
    std::to_string(oColor[3]) + "f);\n" +
    "}\n\0";

    const char *fragmentShaderSource = fss.c_str();

    //create shaders
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //link shaders
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    //set background color
    backgroundColor = bgColor;

}

bool Visualizer::render(const float* center)
{
    //std::cout << "Working\n";
    //check if window should be closed
    if(glfwWindowShouldClose(window))
    {
        glfwTerminate();
        return false;
    }
    //if window isn't going to close, render the window
    glfwPollEvents();

    //set background
    glClearColor(backgroundColor[0],backgroundColor[1],backgroundColor[2],backgroundColor[3]);//R,G,B,Alpha-how transparent it is
    glClear(GL_COLOR_BUFFER_BIT);

    float vertices[3 * (1 + precision)];
    int order[3 * precision];

    make_circle(center, vertices, order);

    /*for(int i = 0; i < 3 * (precision); i++)
    {
        if((i+1) % 3 == 0)
            std::cout << order[i] << "\n";
        else std::cout << order[i] << " ";
    }*/

    //std::cout << vertices[12] << " " << vertices[13] << " " << vertices[14] << "\n";

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(order), order);
    //draw triangle
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 3 * precision, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    //swap buffers
    glfwSwapBuffers(window);
    return true;
}

void Visualizer::make_circle(const float* center, float* vertices, int* order)
{
    vertices[0] = center[0];
    vertices[1] = center[1];
    vertices[2] = 0.0f;
    float pi_val = 3.15159276;
    for(int i = 0; i < precision; i++)
    {
        float angle = i * 2.0 * pi_val / precision;
        vertices[3 * (i + 1) + 0] = center[0] + radius * std::cos(angle);
        vertices[3 * (i + 1) + 1] = center[1] + radius * std::sin(angle);
        vertices[3 * (i + 1) + 2] = 0.0f;
    }
    
    for(int i = 0; i < precision; i++)
    {
        order[3 * i + 0] = 0;
        order[3 * i + 1] = i + 1;
        order[3 * i + 2] = (i + 1) % precision + 1;
    }
}