// SoC Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<stb_image.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 600;
const unsigned int SCR_HEIGHT = 600;
const GLchar* vertexShaderSource = "#version 410 core\n"
"layout ( location = 0 ) in vec3 position;\n"
"out vec3 aColor;\n"
"void main ( )\n"
"{\n"
"gl_Position = vec4( position.x, position.y, 0.0, 1.0 );\n"
"}\0";
const GLchar* fragmentShaderSource = "#version 410 core\n"
"out vec4 fragColor;\n"
"void main ( )\n "
"{\n"
"fragColor = vec4 (0.5, 0.3, 0.2, 1.0);\n"
"}\0";
const GLchar* fragmentShaderSourcex = "#version 410 core\n"
"out vec4 color;\n"
"uniform vec4 changeColor;\n"
"void main()\n"
"{\n"
"color = changeColor;\n"
"}\0";


int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Allahu Akbar", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glewExperimental = GL_TRUE;
    glewInit();
    
    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    int fragmentShaderx = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderx, 1, &fragmentShaderSourcex, NULL);
    glCompileShader(fragmentShaderx);

    // link shaders
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShaderx );        //simply make this fragmentshaderx
    glLinkProgram(shaderProgram);                          //for time varying color 
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    int shaderProgramx = glCreateProgram();
    glAttachShader(shaderProgramx, vertexShader);
    glAttachShader(shaderProgramx, fragmentShaderx);
    glLinkProgram(shaderProgramx);
    // check for linking errors
    glGetProgramiv(shaderProgramx, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgramx, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }


    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(fragmentShaderx);
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    GLfloat vertices[200], k=-1.0, m=1.0;
         for (int i = 0; i < 160; i = i + 18)
         {
             std::cout<< (vertices[i] = k);
             std::cout << (vertices[i + 1] = m);
             std::cout << (vertices[i + 2] = k + 1.0 / 4);
             std::cout << (vertices[i + 3] = m);
             std::cout << (vertices[i + 4] = k + 2 * 1.0 / 4);
             std::cout << (vertices[i + 5] = m);
             std::cout << (vertices[i + 6] = k + 3 * 1.0 / 4);
             std::cout << (vertices[i + 7] = m);
             std::cout << (vertices[i + 8] = k + 4 * 1.0 / 4);
             std::cout << (vertices[i + 9] = m);
             std::cout << (vertices[i + 10] = k + 5 * 1.0 /4);
             std::cout << (vertices[i + 11] = m);
             std::cout << (vertices[i + 12] = k + 6 * 1.0 /4);
             std::cout << (vertices[i + 13] = m);
             std::cout << (vertices[i + 14] = k + 7 * 1.0 /4);
             std::cout << (vertices[i + 15] = m);
             std::cout << (vertices[i + 16] = k + 8 * 1.0 /4);
             std::cout << (vertices[i + 17] = m)<<"\n";
             m = m - 1.0 / 4;
         }
    
        
    
         unsigned int indices1[1000], t=0,n=0;
         for (int k = 0; k < 71; k = k + 9)
         {
             if (n % 2 == 0)
             {
                 int m = k;
                 while (m < k + 8)
                 {
                     indices1[t] = m;
                     indices1[t + 1] = m + 1;
                     indices1[t + 2] = m + 9;
                     indices1[t + 3] = m;
                     indices1[t + 4] = m + 1;
                     indices1[t + 5] = m + 10;
                     indices1[t + 6] = m;
                     indices1[t + 7] = m + 9;
                     indices1[t + 8] = m + 10;
                     std::cout << indices1[t] << " " << indices1[t + 1] << " " << indices1[t + 2] << " " << indices1[t + 3] << "\n";
                     t = t + 9;
                     m = m + 2;

                 }
                 n++;
             }
             else {
                 int m = k + 1;
                 while (m < k + 8)
                 {
                     indices1[t] = m;
                     indices1[t + 1] = m + 1;
                     indices1[t + 2] = m + 9;
                     indices1[t + 3] = m;
                     indices1[t + 4] = m + 1;
                     indices1[t + 5] = m + 10;
                     indices1[t + 6] = m;
                     indices1[t + 7] = m + 9;
                     indices1[t + 8] = m + 10;
                     std::cout << indices1[t] << " " << indices1[t + 1] << " " << indices1[t + 2] << " " << indices1[t + 3] << "\n";
                     t = t + 9;
                     m = m + 2;
                 }
                 n++;
             }
         }
    GLuint VBO[2], VAO[2], EBO[2];
    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);
    glGenBuffers(2, EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    

    

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

     
    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        
        
         // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        
        

       
        float time = glfwGetTime();
        float green = sin(time) / 2.0 + 0.5;
        float red = cos(time) / 2.0 + 0.5;
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "changeColor");
        glUseProgram(shaderProgram);
        glUniform4f(vertexColorLocation, red, green, 0.0, 1.0);
        //glBindTexture(GL_TEXTURE_2D, texture);
        glBindVertexArray(VAO[0]);
        glDrawElements(GL_TRIANGLES, sizeof(indices1), GL_UNSIGNED_INT, 0);
       
        glBindVertexArray(0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO[2]);
    glDeleteBuffers(1, &VBO[2]);
    glDeleteBuffers(1, &EBO[2]);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
