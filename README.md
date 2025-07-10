# Simulador 3D de Sistema Solar

Este é um projeto de simulador 3D de Sistema Solar utilizando as bibliotecas OpenGL e GLFW. O projeto foi 
desenvolvido em C++ pelos alunos:

- Larissa Lumy Higue - SP3122778
- Maria Luisa de Aquino Vicente - SP3124444
- Nicholas Ferraz Pinheiro - SP3121101

## Estrutura

O projeto foi desenvolvido utilizando CMake, o que facilitou nas configurações e desenvolvimento. Foi estruturado
da seguinte forma:
```
Sistema_Solar
|
|_assets/
|   |_ textures/
|   |   |_ aneis_jupiter.jpg # Textura dos anéis de Júpiter
|   |   |_ jupiter.jpg # Textura de Júpiter
|   |   |_ marte.jpg # Textura de Marte
|   |   |_ mercurio.jpg # Textura de Mercúrio
|   |   |_ netuno.jpg # Textura de Netuno
|   |   |_ saturno.jpg # Textura de Saturno
|   |   |_ sol.jpg   # Textura do Sol
|   |   |_ terra.jpg # Textura da Terra
|   |   |_ urano.jpg # Textura de Urano
|   |   |_ venus.jpg # Textura de Vênus
|   |_ sound/
|       |_ trilha.wav  # Trilha sonora
|
|
|_ include
|   |_ camera.hpp # Funções para movimentação de câmera
|   |_ globals.hpp # Variáveis globais
|   |_ input.hpp # Funções para lidar com inputs de usuário
|   |_ planet.hpp # Estruturas para os planetas
|   |_ render.hpp # Funções para renderização
|   |_ texture.hpp # Funções para texturização
|   |_ utils.hpp # Funções auxiliares
|   
|
|_ src
    |_ camera.cpp # Implementação das funções de câmera
    |_ globals.cpp # Definição das variáveis
    |_ input.cpp # Implementação das funções de input
    |_ main.cpp # Função principal
    |_ planet.cpp # Definição dos dados dos planetas
    |_ render.cpp # Implementação das funções de renderização
    |_ texture.cpp # Implementação das funções de texturização
    |_ utils.cpp # Implementação das funções auxiliares

```



## Como rodar:

Certifique-se de ter instalado, em seu computador, as ferramentas:
- CMake, GLUT e GLFW.

Após isso, no CmakeLists.txt, certifique-se de que o diretório da GLFW está corretamente incluído nas funções
include_directories e link_directories (nesta, de acordo com seu compilador). Após isso, compile e execute o projeto
usando os comandos:

```mkdir build
cd build
cmake ..

cmake --build .
debug/sistema_solar.exe
```



## Controles:

#### Comandos de mouse

Use o mouse para movimentar a câmera ao clicar e arrastar. Com o scroll é possível aumentar ou diminuir o zoom.

#### Comandos de teclado

| First Header  | Second Header |
| :-------------: | :-------------: |
| 1-8 | Selecionar um planeta  |
| 0  | Voltar para visualização geral  |
| O | Exibir/Ocultar as órbitas |
| F | Exibir/Ocultar o fundo |
| Espaço | Pausar/Retomar a movimentação |

Para facilitar, os controles serão sempre exibidos no terminal e também na janela.

## Funcionalidades

### Sistema de texturas
- Carregamento: Utiliza biblioteca STB para suporte a JPG/PNG
- Mapeamento: Coordenadas UV calculadas nas esferas e nos anéis

### Física
 - Rotação e Translação: Movimentos baseados nos movimentos reais dos planetas
 - Inclinação: Eixo dos planetas com inclinações realistas
