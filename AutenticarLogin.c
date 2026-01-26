#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Site.h"

#include "AutenticarLogin.h"


int Autenticar_Login(FILE *arq, Login *reg){
	Exibir_Titulo_Site();
	char nome[20];
	char senha[10];
	arq = fopen("Usuarios.dat","rb");
	printf("                                 				-- L O G I N --\n");
    printf("                                 				--------------- \n\n");
	printf("                              				>>> Insira o Nome: ");
	fgets(nome,sizeof(nome),stdin);
	printf("\n                              				>>> Insira a Senha: ");
	fgets(senha,sizeof(senha),stdin);
	for(;;){
		fread(reg,sizeof(Login),1,arq);
		if (feof(arq)) break;
		if ((strcmp(nome,reg->nome) == 0) && (strcmp(senha,reg->senha) == 0)){
			printf("\n                                 		    	Usuario Encontrado!\n");
			printf("\n                                 		    	Redirecionando para Tela de Avaliacao...\n\n");
			printf("                                              ");
        	system("pause");
        	fclose(arq);
        	return 1;
		}
	}
	printf("\n                                 		    	Usuario nao Cadastrado! Cadastre o seu Login.\n");
	printf("                                                      ");
    system("pause");
    fclose(arq);
    return -1;
}
