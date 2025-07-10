#include <windows.h>
#include <GLFW/glfw3.h>
#include "input.hpp"
#include "globals.hpp"

void tecla_pressionada(GLFWwindow* janela, int tecla, int scancode, int acao, int mods) {
    if (acao == GLFW_PRESS) {
        if (tecla == GLFW_KEY_SPACE) {
            animacaoPausada = !animacaoPausada;
        }
        if (tecla == GLFW_KEY_F) {
            fundoEstreladoAtivo = !fundoEstreladoAtivo;
        }
        if (tecla >= GLFW_KEY_1 && tecla <= GLFW_KEY_8) {
            planetaSelecionado = tecla - GLFW_KEY_1;
        }
        if (tecla == GLFW_KEY_0) {
            planetaSelecionado = -1;
        }
        if (tecla == GLFW_KEY_O) {
            mostraOrbita = !mostraOrbita;
        }
    }
}
