#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "escreve_mapa_tela.c"

int posiciona_barco(mapStruct map, int B){
    if(map.map[0][B] == ' '){
        map.map[0][B] = 'B';
        return 1;
    }
    return 0;
}

/* TEST CLIENT */
int main(){
    mapStruct map;
    char localDoArquivo[MAX]; 
    int B, OK;


    int i, j;
    
    scanf("%s %d", localDoArquivo, &B);

    map = leia_mapa(localDoArquivo);
    
    OK = posiciona_barco(map, B);
    
    while(!OK){
        printf("Posição inválida, entre com outra coluna.\n");
        scanf("%d", &B);
        OK = posiciona_barco(map, B);
    }

    escreve_mapa_tela(map);
    
    return 0;
}
