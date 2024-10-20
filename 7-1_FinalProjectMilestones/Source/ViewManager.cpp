///////////////////////////////////////////////////////////////////////////////
// viewmanager.cpp
// ===============
// Handle user interaction for the 3D scene with keyboard and mouse controls
///////////////////////////////////////////////////////////////////////////////

#include "viewmanager.h"
#include "camera.h"

// Initialize Camera object
Camera g_pCamera(glm::vec3(0.0f, 0.0f, 3.0f)); // Default camera position
bool isPerspective = true; // Toggle for projection mode

// Mouse input variables
static bool firstMouse = true;
static float lastX = 400, lastY = 300; // Default mouse positions
static float deltaTime = 0.0f; // Time between frames
static float lastFrame = 0.0f; // Time of last frame

// Constructor
ViewManager::ViewManager(ShaderManager* pShaderManager) : m_pShaderManager(pShaderManager) {}

// Destructor
ViewManager::~ViewManager() {}

// Mouse movement callback to adjust the camera orientation
void ViewManager::Mouse_Position_Callback(GLFWwindow* window, double xMousePos, double yMousePos)
{
    if (firstMouse)
    {
        lastX = xMousePos;
        lastY = yMousePos;
        firstMouse = false;
    }

    float xOffset = xMousePos - lastX;
    float yOffset = lastY - yMousePos; // Reversed since y-coordinates go from bottom to top

    lastX = xMousePos;
    lastY = yMousePos;

    g_pCamera.ProcessMouseMovement(xOffset, yOffset);
}

// Mouse scroll callback to adjust the camera movement speed
void ViewManager::Mouse_Scroll_Callback(GLFWwindow* window, double xOffset, double yOffset)
{
    g_pCamera.ProcessMouseScroll(yOffset);
}

// Handle keyboard input for panning, zooming, and moving up and down
void ViewManager::ProcessKeyboardEvents(GLFWwindow* window)
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    float cameraSpeed = 2.5f * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) // Move forward (zoom in)
        g_pCamera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) // Move backward (zoom out)
        g_pCamera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) // Pan left
        g_pCamera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) // Pan right
        g_pCamera.ProcessKeyboard(RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) // Move up
        g_pCamera.ProcessKeyboard(UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) // Move down
        g_pCamera.ProcessKeyboard(DOWN, deltaTime);
}

// Handle toggling between perspective and orthographic view modes
void ViewManager::ProcessProjectionSwitch(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && !isPerspective)
    {
        // Switch to perspective view
        g_pCamera.SwitchToPerspective();
        isPerspective = true;
    }
    else if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS && isPerspective)
    {
        // Switch to orthographic view
        g_pCamera.SwitchToOrthographic();
        isPerspective = false;
    }
}

// Other methods remain unchanged...
