
#include "SceneManager.h"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {}

// Prepare scene with basic objects
void SceneManager::PrepareScene() {
    // Placeholder for scene preparation (loading models, setting up objects)
}

// Render scene (currently renders a simple triangle)
void SceneManager::RenderScene() {
    // Render a simple object like a triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}
