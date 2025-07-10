#ifndef CAMERA_HPP
#define CAMERA_HPP

extern float cameraDistance;
extern float cameraAngleX;
extern float cameraAngleY;
extern bool mousePressed;
extern double lastMouseX, lastMouseY;

void movimento_cursor(GLFWwindow* janela, double xpos, double ypos);
void botao_mouse(GLFWwindow* janela, int botao, int acao, int mods);
void rolagem_mouse(GLFWwindow* janela, double xoffset, double yoffset);

#endif
