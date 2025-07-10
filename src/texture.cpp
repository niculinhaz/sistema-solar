#include <windows.h>
#include <GLFW/glfw3.h>
#include "../stb_image.h"
#include <cstdio>
#include "texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"

GLuint carregarTextura(const char* caminhoArquivo) {
    int largura, altura, canais;
    unsigned char* dados = stbi_load(caminhoArquivo, &largura, &altura, &canais, 0);
    if (!dados) {
        printf("Falha ao carregar textura %s\n", caminhoArquivo);
        return 0;
    }
    
    GLuint texturaID;
    glGenTextures(1, &texturaID);
    glBindTexture(GL_TEXTURE_2D, texturaID);
    
    GLenum formato = (canais == 4) ? GL_RGBA : GL_RGB;
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, formato, largura, altura, 0, formato, GL_UNSIGNED_BYTE, dados);
    
    stbi_image_free(dados);
    return texturaID;
}
