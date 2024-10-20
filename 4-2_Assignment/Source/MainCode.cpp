// MainCode.cpp - Main application logic for 3D scene

#include "viewmanager.h"
#include "camera.h"

int main()
{
    // Initialize OpenGL, create a window, and setup necessary callbacks
    GLFWwindow* window = viewManager.CreateDisplayWindow("3D Scene with Camera Control");

    // Set mouse callbacks for position and scroll events
    glfwSetCursorPosCallback(window, ViewManager::Mouse_Position_Callback);
    glfwSetScrollCallback(window, ViewManager::Mouse_Scroll_Callback);

    // Enable mouse capture (disable cursor in window)
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Main render loop
    while (!glfwWindowShouldClose(window))
    {
        // Process keyboard input
        viewManager.ProcessKeyboardEvents(window);

        // Render scene here
        viewManager.PrepareSceneView();
        glfwSwapBuffers(window);
        glfwPollEvents(); // Poll for user input
    }

    // Clean up resources
    glfwTerminate();
    return 0;
}
