#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "VerificarFilme.h"

int Verificar_Filme(FILE *ptr, Filme *f, char *titulo){
    ptr = fopen("Catalogo.dat","rb");
    for(;;){
        fread(f,sizeof(Filme),1,ptr);
        if(feof(ptr)) break;
        if (strcmp(titulo,f->titulo) == 0){
            fclose(ptr);
            return 1;
        }
    }
    fclose(ptr);
    return -1;
}

