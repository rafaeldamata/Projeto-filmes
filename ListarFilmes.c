#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Site.h"
#include "Pause.h"
#include "ListarFilmes.h"

void Listar_Filmes(Filme *f){
	FILE *ftp = fopen("Catalogo.dat","r+b");
	if(ftp == NULL) exit(1);
	Exibir_Titulo_Site();
	printf("                                 			-- C A T A L O G O  /  P A G I N A  1 --\n");
    printf("                                 			---------------------------------------- \n\n");
    for(;;){
    	fread(f,sizeof(Filme),1,ftp);
    	if (feof(ftp)) break;
    	if(ftell(ftp) == 11 * sizeof(Filme)) break;
    	printf("                                 				>> %s\n",f->titulo);
	}
	Funcao_Pause();
	system("cls");
	fseek(ftp, 10 * sizeof(Filme),SEEK_SET);

	Exibir_Titulo_Site();
	printf("                                 			-- C A T A L O G O  /  P A G I N A  2 --\n");
    printf("                                 			---------------------------------------- \n\n");
	 for(;;){
	 	fread(f,sizeof(Filme),1,ftp);
	 	if(feof(ftp)) break;
	 	if(ftell(ftp) == 21 * sizeof(Filme)) break;
          printf("                                 				>> %s\n",f->titulo);

	 }
	Funcao_Pause();
	fclose(ftp);
	return;
}

