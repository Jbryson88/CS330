///////////////////////////////////////////////////////////////////////////////
// scenemanager.cpp
// ===============
// Manages the scene creation, including setting up a base plane
///////////////////////////////////////////////////////////////////////////////

#include "scenemanager.h"
#include "shader.h"

// Create the 3D plane to act as a ground or table surface
void SceneManager::CreatePlane()
{
    // Plane vertices (for simplicity, centered at origin)
    float planeVertices[] = {
        // Positions          // Normals         // Texture Coords
         5.0f,  0.0f,  5.0f,   0.0f, 1.0f, 0.0f,  0.0f, 1.0f,  // Top right
        -5.0f,  0.0f,  5.0f,   0.0f, 1.0f, 0.0f,  1.0f, 1.0f,  // Top left
        -5.0f,  0.0f, -5.0f,   0.0f, 1.0f, 0.0f,  1.0f, 0.0f,  // Bottom left
         5.0f,  0.0f, -5.0f,   0.0f, 1.0f, 0.0f,  0.0f, 0.0f   // Bottom right
    };

    // Plane indices
    unsigned int planeIndices[] = {
        0, 1, 2,
        0, 2, 3
    };

    // Generate the plane
    unsigned int planeVAO, planeVBO, planeEBO;
    glGenVertexArrays(1, &planeVAO);
    glGenBuffers(1, &planeVBO);
    glGenBuffers(1, &planeEBO);

    glBindVertexArray(planeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), &planeVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, planeEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(planeIndices), &planeIndices, GL_STATIC_DRAW);

    // Positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Normals
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // Texture Coords
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Unbind VAO
    glBindVertexArray(0);
}

