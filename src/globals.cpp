#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include "globals.hpp"

GLuint texturasPlanetas[8];
GLuint texturaSol;
GLuint texturaEstrelas;
GLuint texturaAnelJupiter;
GLuint texturaLua;

float cameraDistance = 25.0f;
float cameraAngleX = 20.0f;
float cameraAngleY = 0.0f;
bool mousePressed = false;
double lastMouseX, lastMouseY;
bool animacaoPausada = false;
bool modoVisualizacaoAlternado = false;
bool fundoEstreladoAtivo = true;
bool mostraOrbita = true;
int planetaSelecionado = -1;

std::vector<std::vector<float>> angulosRotacaoLuas;