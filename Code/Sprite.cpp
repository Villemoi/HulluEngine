#include "../Headers/Sprite.h"

Sprite::Sprite() {
    // Define a standard 1x1 unit square centered at 0,0 or starting at 0,0
    float vertices[] = {
        1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top right
        1.0f, 1.0f, 0.0f, 1.0f, 1.0f, // bottom right
        0.0f, 1.0f, 0.0f, 0.0f, 1.0f, // bottom left
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f  // top left
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

Sprite::~Sprite() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Sprite::Draw() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}