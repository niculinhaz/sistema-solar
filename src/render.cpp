#include <windows.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include "render.hpp"
#include "texture.hpp"
#include "planet.hpp"
#include <vector>
#include <string>
#include "../stb_easy_font.h"
#include "globals.hpp"

#define STB_EASY_FONT_IMPLEMENTATION
#include "../stb_easy_font.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void desenhaEsfera(float raio, GLuint textura) {
    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    if (textura != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textura);
    } else {
        glDisable(GL_TEXTURE_2D);
    }
    gluSphere(quad, raio, 40, 40);
    if (textura != 0) glDisable(GL_TEXTURE_2D);
    gluDeleteQuadric(quad);
}

void desenharOrbita(float raio) {
    glDisable(GL_LIGHTING);
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; ++i) {
        float ang = 2 * M_PI * i / 100;
        float x = cos(ang) * raio;
        float z = sin(ang) * raio;
        glVertex3f(x, 0.0f, z);
    }
    glEnd();
    glEnable(GL_LIGHTING);
}

void desenharAnelUrano(float raioInicial, float raioFinal) {
    int numAneis = 6;
    float espessura = 0.02f;
    float espacamento = (raioFinal - raioInicial - espessura * numAneis) / (numAneis - 1);

    for (int i = 0; i < numAneis; ++i) {
        float intensidade = 1.0f - i * 0.08f;
        if (intensidade < 0.4f) intensidade = 0.4f;
        glColor3f(intensidade, intensidade, intensidade);

        float raio = raioInicial + i * (espessura + espacamento);
        float raioInterno = raio;
        float raioExterno = raio + espessura;

        glBegin(GL_LINE_LOOP);
        for (int j = 0; j < 100; ++j) {
            float ang = 2 * M_PI * j / 100;
            float x = cos(ang);
            float z = sin(ang);
            glVertex3f(x * raioInterno, 0.0f, z * raioInterno);
        }
        glEnd();

        glBegin(GL_LINE_LOOP);
        for (int j = 0; j < 100; ++j) {
            float ang = 2 * M_PI * j / 100;
            float x = cos(ang);
            float z = sin(ang);
            glVertex3f(x * raioExterno, 0.0f, z * raioExterno);
        }
        glEnd();

        espessura *= 0.7f;
    }
}

void desenharAneis(float raioInterno, float raioExterno) {
    const int segmentos = 200;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaAnelJupiter);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= segmentos; ++i) {
        float ang = 2.0f * M_PI * i / segmentos;
        float x = cos(ang);
        float z = sin(ang);
        float u = float(i) / segmentos;

        glTexCoord2f(0.0f, u);
        glVertex3f(x * raioInterno, 0.0f, z * raioInterno);

        glTexCoord2f(1.0f, u);
        glVertex3f(x * raioExterno, 0.0f, z * raioExterno);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void desenharFundoEstrelado() {
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaEstrelas);
    glColor3f(1.0f, 1.0f, 1.0f);

    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    glScalef(-1, 1, 1);
    gluSphere(quad, 50.0f, 50, 50);
    gluDeleteQuadric(quad);

    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void desenharTexto(float x, float y, const char* texto) {
    char buffer[99999];
    int num_quads;

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 600, 0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    glColor3f(1.0f, 1.0f, 1.0f);

    num_quads = stb_easy_font_print(x, y, (char*)texto, NULL, buffer, sizeof(buffer));

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 16, buffer);
    glDrawArrays(GL_QUADS, 0, num_quads * 4);
    glDisableClientState(GL_VERTEX_ARRAY);

    glEnable(GL_LIGHTING);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void configurarCena() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 800.0 / 600.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat luz_posicao[] = { 0.0f, 10.0f, 10.0f, 1.0f };
    GLfloat luz_ambiente[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat luz_difusa[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat luz_especular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, luz_posicao);
    glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);
}

void desenharSistemaSolar() {
    glPushMatrix();
    GLfloat emissivoSol[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_EMISSION, emissivoSol);
    desenhaEsfera(1.2f, texturaSol);
    GLfloat semEmissao[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_EMISSION, semEmissao);
    glPopMatrix();
    
    for (int i = 0; i < 8; i++) {
        auto& p = planetas[i];
        if (mostraOrbita)
            desenharOrbita(p.distancia);
        
        glPushMatrix();
        glRotatef(p.anguloOrbita, 0, 1, 0);
        glTranslatef(p.distancia, 0, 0);
        glRotatef(p.inclinacaoEixo, 0, 0, 1);
        glRotatef(p.rotacaoEixo, 0, 1, 0);
        desenhaEsfera(p.raio, texturasPlanetas[i]);

        if (p.nome == "Urano") {
            glPushMatrix();
            glColor3f(0.7f, 0.7f, 0.4f);
            glRotatef(90.0f, 1, 0, 0);
            desenharAnelUrano(p.raio + 0.1f, p.raio + 0.25f);
            glPopMatrix();
        }
        
        if (p.nome == "Saturno") {
            glPushMatrix();
            glColor3f(0.7f, 0.7f, 0.4f);
            glRotatef(p.anguloAnel, 0, 1, 0);
            glRotatef(90.0f, 1, 0, 0);
            desenharAneis(p.raio + 0.1f, p.raio + 0.5f);
            glPopMatrix();
        }
        
        const int luasPorCamada = 10;
        float alturaEntreCamadas = 0.08f;

        if (p.numLuas > 0) {
            for (int l = 0; l < p.numLuas; ++l) {
                glPushMatrix();
                int camada = l / luasPorCamada;
                float alturaCamada = camada * alturaEntreCamadas;
                int indiceNaCamada = l % luasPorCamada;
                float anguloLuaAtual = p.anguloLua + (360.0f / luasPorCamada) * indiceNaCamada;

                glRotatef(anguloLuaAtual, 0, 1, 0);
                float distanciaLua = p.raio + 0.3f + 0.05f * camada;
                glTranslatef(distanciaLua, alturaCamada, 0);
                glRotatef(angulosRotacaoLuas[i][l], 0, 1, 0);

                GLfloat material_lua_ambient[] = { 0.05f, 0.05f, 0.05f, 1.0f };
                GLfloat material_lua_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };

                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_lua_ambient);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_lua_diffuse);
                glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, semEmissao);

                desenhaEsfera(0.03f, texturaLua);
                glPopMatrix();
            }
        }
        
        glPopMatrix();
    }
}

void desenharCena() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    if (planetaSelecionado >= 0 && planetaSelecionado <= 8) {
        auto& p = planetas[planetaSelecionado];
        float ang = p.anguloOrbita * M_PI / 180.0f;
        float px = cos(ang) * p.distancia;
        float py = 0.0f;
        float pz = -sin(ang) * p.distancia;
        
        float camX = px + 1.5f;
        float camY = py + 1.0f;
        float camZ = pz + 1.5f;
        
        gluLookAt(camX, camY, camZ, px, py, pz, 0, 1, 0);

        DadosReais& dr = dadosReaisPlanetas[planetaSelecionado];
        char info[512];
        const char* sentidoRotacao = (dr.rotacao_retrogada) ? "Retrograda" : "Direta";
        snprintf(info, sizeof(info),
                 "Planeta: %s | Raio: %.1f km | Distancia do Sol: %.1f x10^6 km | Inclinacao: %.1f graus | Rotacao: %.2f horas (%s)",
                 p.nome.c_str(),
                 dr.raio_km,
                 dr.distancia_10e6_km,
                 dr.inclinacao_axial_graus,
                 std::abs(dr.periodo_rotacao_horas),
                 sentidoRotacao);

        desenharTexto(10, 500, info);

    } else {
        desenharTexto(10, 500, "Pressione 1 a 8 para visitar um planeta, 0 para voltar à visao livre.");

        float camX = cameraDistance * cosf(cameraAngleX * M_PI / 180.0f) * sinf(cameraAngleY * M_PI / 180.0f);
        float camY = cameraDistance * sinf(cameraAngleX * M_PI / 180.0f);
        float camZ = cameraDistance * cosf(cameraAngleX * M_PI / 180.0f) * cosf(cameraAngleY * M_PI / 180.0f);
        
        if (!modoVisualizacaoAlternado)
        gluLookAt(camX, camY, camZ, 0, 0, 0, 0, 1, 0);
        else
        gluLookAt(0, cameraDistance, 0, 0, 0, 0, 0, 0, -1);
    }
    
    desenharTexto(10, 580, "Espaco: Pausar/Retomar");
    desenharTexto(10, 560, "F: Alternar fundo estrelado");
    desenharTexto(10, 540, "Mouse: Girar camera | Scroll: Zoom");
    desenharTexto(10, 520, "O: Apagar/exibir as orbitas");
    
    GLfloat luz_posicao[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, luz_posicao);
    
    if (fundoEstreladoAtivo) {
        desenharFundoEstrelado();
    }
    desenharSistemaSolar();
}