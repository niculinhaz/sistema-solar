#ifndef RENDER_HPP
#define RENDER_HPP

#include <windows.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>

void desenhaEsfera(float raio, GLuint textura = 0);

void desenharOrbita(float raio);

void desenharAneis(float raioInterno, float raioExterno);

void desenharAnelUrano(float raioInicial, float raioFinal);

void desenharFundoEstrelado();

void desenharCena();

void desenharSistemaSolar();

void desenharTexto(float x, float y, const char* texto);

void configurarCena();

#endif
