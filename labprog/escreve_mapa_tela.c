#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leia_mapa.c"

void escreve_mapa_tela(mapStruct map){
    int i, j, OK, OK2;

    OK = OK2 = 1;

    printf("    ");
    
    for(i = 0; i < map.n; i++){
        printf("%d  ", i + 1 );
    }
    printf("\n");
    
    for(i = 0; i < map.m; i++){
        OK = 1;
        for(j = 0; j < map.n; j++){
            if(OK){
                if(i <= 8)
                    printf("%d   ", i + 1);
                else
                    printf("%d  ", i + 1);
                OK = 0;
            }
            /* i linha, j coluna*/
            if(map.map[i][j] == 'C' ||
               map.map[i][j] == 'H' ||
               map.map[i][j] == 'D' ||
               map.map[i][j] == 'P' ||
               map.map[i][j] == 'S' ||
               map.map[i][j] == ' '
               ){
                if(i <= 9 && j < 9)
                    printf("-  ");
                if(i > 9 && j < 9)
                    printf("-  ");
                if(i <= 9 && j >= 9)
                    printf("-   ");
                if(i > 9 && j >= 9)
                    printf("-   ");
            }
            else{
                if(i <= 9 && j < 9)
                    printf("%c  ", map.map[i][j]);
                if(i > 9 && j < 9)
                    printf("%c  ", map.map[i][j]);
                if(i <= 9 && j >= 9)
                    printf("%c   ", map.map[i][j]);
                if(i > 9 && j >= 9)
                    printf("%c   ", map.map[i][j]);
            }
        }
        printf("\n");
    }
}


int main(){
    mapStruct map;
    char localDoArquivo[MAX]; 

    scanf("%s", localDoArquivo);

    map = leia_mapa(localDoArquivo);

    escreve_mapa_tela(map);
    
    return 0;
}
