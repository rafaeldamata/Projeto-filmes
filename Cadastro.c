#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Site.h"
#include "Cadastro.h"


void Cadastrar_Usuario(Login *reg){
	Exibir_Titulo_Site();
	FILE *arq = fopen("Usuarios.dat","ab");
	printf("                                 				-- C A D A S T R O --\n");
    printf("                                 				--------------------- \n\n");
    printf("                              				>>> Insira o Nome do Usuario: ");
    fgets(reg->nome,sizeof(reg->nome),stdin);
    printf("\n                              				>>> Insira a Senha do Usuario: ");
    fgets(reg->senha,sizeof(reg->senha),stdin);
    if(arq){
    	fwrite(reg,sizeof(Login),1,arq);
    	fclose(arq);
    	 printf("\n                              				 Login do Usuario Cadastrado com Sucesso!\n\n");
    	 printf("								");
    	 system("pause");
	}
}
