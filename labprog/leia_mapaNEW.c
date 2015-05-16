#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Structs.h"

#define MAX 10000

char **aloca_matriz (int m, int n){
    char **matriz;
    int ind;
    matriz = malloc(m * sizeof(char*));
    
    if(matriz == NULL){
        printf("Erro ao alocar matriz.\n");
    }
    
    for (ind = 0; ind < m; ind++){
        matriz[ind] = malloc(n * sizeof(char));
        if (matriz[ind] == NULL){
            printf("Erro ao alocar matriz.\n");
        }
    }
    return matriz;
}

mapStruct leia_mapa(char caminhoDoArquivo[]){
    mapStruct map;
    int i, j, lixo;
    char c, d;
    
    FILE *file = fopen(caminhoDoArquivo, "r");

    /* Tem um terceiro inteiro no cabecalho do mapa
       que ninguem sabe para que serve, chamei de lixo. 
    */
    
    fscanf(file, "%d %d %d", &map.m, &map.n, &lixo);
    
    map.map = aloca_matriz(map.m, map.n);

    c = fgetc(file); // se livrando dos lixos
    c = fgetc(file);

    for(i = 0; i < map.m; i++){
        for(j = 0; j < map.n; j++){
	  c = (int) fgetc(file);
            if(c != '|'){ 
                map.map[i][j] = c;
            }
	   
            else{
	      while(c != '\n') c = fgetc(file);
	      if(c == '\n'){
		c = fgetc(file);
		map.map[i][j] = c;
	      }
	    }
        }
    }    
    fclose(file);
    return map;
}

/* TEST CLIENT */
int main(){
    mapStruct map;
    char String[MAX];
    int i, j;

    // Local do arquivo
    scanf("%s", String);

    map = leia_mapa(String);

    for(i = 0; i < map.m; i++){
        for(j = 0; j < map.n; j++){
	  printf("%c", map.map[i][j]);
        }
	printf("\n");
    }
    return 0;
}

