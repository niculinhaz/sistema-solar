#include <windows.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <locale>
#include "planet.hpp"
#include "globals.hpp"
#include "render.hpp"
#include "input.hpp"
#include "camera.hpp"
#include "texture.hpp"
#include "utils.hpp"

int main() {
    if (!glfwInit()) return -1;
    
    GLFWwindow* window = glfwCreateWindow(1980, 1080, "Sistema Solar 3D", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetCursorPosCallback(window, movimento_cursor);
    glfwSetMouseButtonCallback(window, botao_mouse);
    glfwSetScrollCallback(window, rolagem_mouse);
    glfwSetKeyCallback(window, tecla_pressionada);
    
    configurarCena();
    
    texturaSol = carregarTextura("../texturas/sol.jpg");
    texturaEstrelas = carregarTextura("../texturas/fundo_estrelado.jpg");
    
    const char* arquivosTexturas[8] = {
        "../texturas/mercurio.jpg",
        "../texturas/venus.jpg",
        "../texturas/terra.jpg",
        "../texturas/marte.jpg",
        "../texturas/jupiter.jpg",
        "../texturas/saturno.jpg",
        "../texturas/urano.jpg",
        "../texturas/netuno.jpg"
    };

    angulosRotacaoLuas.resize(8);
    for (int i = 0; i < 8; ++i) {
        angulosRotacaoLuas[i].resize(planetas[i].numLuas, 0.0f);
    }
    
    for (int i = 0; i < 8; i++) {
        texturasPlanetas[i] = carregarTextura(arquivosTexturas[i]);
    }
    
    texturaAnelJupiter = carregarTextura("../texturas/aneis_saturno.jpg");
    texturaLua = carregarTextura("../texturas/lua.jpg");

    printMenu();

    PlaySound(TEXT("../sound/trilha.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    double ultimoTempo = glfwGetTime();
    while (!glfwWindowShouldClose(window)) {
        double tempoAtual = glfwGetTime();
        float deltaTime = float(tempoAtual - ultimoTempo);
        ultimoTempo = tempoAtual;

        if (!animacaoPausada) {
            for (auto& p : planetas) {
                p.anguloOrbita += p.velocidadeOrbita * deltaTime * 20.0f;
                p.rotacaoEixo += p.velocidadeRotacao * deltaTime * 20.0f;
                if (p.numLuas > 0)
                    p.anguloLua += 6.0f * deltaTime * 20.0f;
            }
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < planetas[i].numLuas; ++j) {
                    angulosRotacaoLuas[i][j] += 30.0f * deltaTime * 20.0f;
                    if (angulosRotacaoLuas[i][j] > 360.0f)
                        angulosRotacaoLuas[i][j] -= 360.0f;
                }
            }
        }

        desenharCena();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}