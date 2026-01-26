#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FuncaoEnter.h"

void Funcao_Enter(){
	printf("\n\n                             			   [Pressione **ENTER** para continuar]");
            while (getchar() != '\n');
            getchar();
            return;
}

