#ifndef PLANET_HPP
#define PLANET_HPP

#include <string>

struct Lua {
    float distancia;
    float raio;
    float anguloOrbita;
    float velocidadeOrbita;
    float inclinacao;
};

struct Planeta {
    std::string nome;
    float raio;
    float distancia;
    float anguloOrbita;
    float velocidadeOrbita;
    int numLuas;
    float anguloLua;
    float rotacaoEixo;
    float velocidadeRotacao;
    float inclinacaoEixo;
    float anguloAnel = 0.0f;
    float velocidadeAnel = 1.0f;
};

struct DadosReais {
    float raio_km;
    float distancia_10e6_km;
    float inclinacao_axial_graus;
    float periodo_rotacao_horas;
    bool rotacao_retrogada;
};

extern Planeta planetas[8];
extern DadosReais dadosReaisPlanetas[8];

#endif
