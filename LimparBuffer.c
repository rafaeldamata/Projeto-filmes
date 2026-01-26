#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LimparBuffer.h"

void limpar_buffer() {
    int c;
    // Lê e descarta caracteres enquanto não for o final da linha ('\n')
    // ou o fim do arquivo (EOF).
    while ((c = getchar()) != '\n' && c != EOF) {
        // Não faz nada dentro do loop, apenas consome o caractere.
    }
}
