#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "planet.hpp"

extern GLuint texturasPlanetas[8];
extern GLuint texturaSol;
extern GLuint texturaEstrelas;
extern GLuint texturaAnelJupiter;
extern GLuint texturaLua;

extern float cameraDistance;
extern float cameraAngleX;
extern float cameraAngleY;
extern bool mousePressed;
extern double lastMouseX, lastMouseY;
extern bool animacaoPausada;
extern bool modoVisualizacaoAlternado;
extern bool fundoEstreladoAtivo;
extern bool mostraOrbita;
extern int planetaSelecionado;

extern std::vector<std::vector<float>> angulosRotacaoLuas;

#endif