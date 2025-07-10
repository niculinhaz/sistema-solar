#include <windows.h>
#include <GLFW/glfw3.h>
#include "camera.hpp"
#include "globals.hpp"

void movimento_cursor(GLFWwindow* janela, double xpos, double ypos) {
    if (mousePressed) {
        float deltaX = xpos - lastMouseX;
        float deltaY = ypos - lastMouseY;
        
        cameraAngleY += deltaX * 0.3f;
        cameraAngleX += deltaY * 0.3f;
        
        if (cameraAngleX > 89.0f) cameraAngleX = 89.0f;
        if (cameraAngleX < -89.0f) cameraAngleX = -89.0f;
    }
    lastMouseX = xpos;
    lastMouseY = ypos;
}

void botao_mouse(GLFWwindow* janela, int botao, int acao, int mods) {
    if (botao == GLFW_MOUSE_BUTTON_LEFT) {
        mousePressed = (acao == GLFW_PRESS);
    }
}

void rolagem_mouse(GLFWwindow* janela, double xoffset, double yoffset) {
    cameraDistance -= yoffset;
    if (cameraDistance < 3.0f) cameraDistance = 3.0f;
    if (cameraDistance > 100.0f) cameraDistance = 100.0f;
}
