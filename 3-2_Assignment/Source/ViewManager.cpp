
#include "ViewManager.h"

ViewManager::ViewManager() {}

ViewManager::~ViewManager() {}

void ViewManager::PrepareSceneView() {
    // Set up a basic static view (no camera movement)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); // Basic orthographic projection for simplicity
    glMatrixMode(GL_MODELVIEW);
}
