# Simulador 3D de Sistema Solar

Este é um projeto de simulador 3D de Sistema Solar utilizando as bibliotecas OpenGL e GLFW. O projeto foi 
desenvolvido em C++ pelos alunos:

- Larissa Lumy Higue - SP3122778
- Maria Luisa de Aquino Vicente - SP3124444
- Nicholas Ferraz Pinheiro - SP3121101

## Estrutura

O projeto foi desenvolvido utilizando CMake, o que facilitou nas configurações e desenvolvimento. Foi estruturado
da seguinte forma:

#### /src

O código fonte do projeto. Inclui os arquivos fonte que são compilados para o funcionamento da aplicação.

#### /include

Os cabeçalhos desenvolvidos para o projeto.

#### /assets

Os arquivos externos utilizados para ajudar na renderização e customização de texturas, sons e imagens.


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
debug/atividade1.exe```