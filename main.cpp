#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// readgust window viewport to window size when user resizes
void framebuffer_size_callback(GLFWwindow *windown, int width, int height)
{
    glViewport(0, 0, width, height);
}

void proccessInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void drawShaders()
{
}

int main()
{

    // initialize and configure hints
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create window
    GLFWwindow *window = glfwCreateWindow(800, 600, "Testis", NULL, NULL);
    if (window == NULL) // terminate if window is not created
    {
        std::printf("failed to create window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // make sure all GLAD pointers are loaded
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("failed to initialize GLAD\n");
        return -1;
    }

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        proccessInput(window); // process input keys

        // render new colloer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window); // swap buffers
        glfwPollEvents();        // IO events ex. key press/release
    }

    glfwTerminate(); // terminate and clear allocated resources

    return 0;
}