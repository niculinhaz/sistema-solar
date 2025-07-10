#include <iostream>
#include <locale>
#include <windows.h>

void printMenu () {
    setlocale(LC_ALL, ".UTF8");
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Bem-vindo ao projeto 3D de Sistema Solar!" << std::endl;
    std::cout << "\nCaso deseje ver informações detalhadas ou seguir um planeta, digite:" << std::endl;
    std::cout << "\n1 - Mercúrio" << std::endl;
    std::cout << "\n2 - Vênus" << std::endl;
    std::cout << "\n3 - Terra" << std::endl;
    std::cout << "\n4 - Marte" << std::endl;
    std::cout << "\n5 - Júpiter" << std::endl;
    std::cout << "\n6 - Saturno" << std::endl;
    std::cout << "\n7 - Urano"<< std::endl;
    std::cout << "\n8 - Netuno"<< std::endl;
    std::cout << "\n0 para voltar à visualização normal"<< std::endl;
    std::cout << "\nAperte O para apagar/exibir as órbitas"<< std::endl;
    std::cout << "\nAperte Espaço para pausar o movimento"<< std::endl;
    std::cout << "\nAperte F para remover as estrelas"<< std::endl;
}
