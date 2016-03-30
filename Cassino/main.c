//
//  main.c
//  Cassino
//
//  Created by Lucas Rocali on 4/15/15.
//  Copyright (c) 2015 Lucas Rocali. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int fichasIniciais = 1024;
    int jogadasMax = 12000;
    int janelasMax = 100;
    int diasMax = 300;
    
    int fichas = fichasIniciais;
    int aposta = 0;
    int j = 0;
    int maxfichas = 0;
    int flagFail = 1;
    srand(time(NULL));
    int flafFailNum = 0;
    int caixa = 0;
    int mediaLucro = 0;
    for (int dias = 0; dias<diasMax; dias++) {

    for (int janelas = 0; janelas<janelasMax;janelas++)
    {
        flafFailNum+=flagFail;
        if (flagFail == 0) {
            caixa = caixa - fichas;
        }
        else {
            caixa = caixa + fichas-fichasIniciais;
        }
        //printf("Dia: %d Max: %d FlagFail: %d\n",janelas+1,maxfichas,flagFail);
        aposta = 0;
        maxfichas = 0;
        fichas = fichasIniciais;
        flagFail = 1;
        for (j = 0; j <= jogadasMax; j++) {
            if (fichas<=0) {
                //printf("FUDEU NEGAO %d MAXIMO %d",j,maxfichas);
                flagFail = 0;
                break;
            }
            fichas = fichas - pow(2,aposta);
        
            int sorted = rand()%37;
        
            //printf("Sorted: %d\t Fichas: %d \tAposta: %d\n",sorted,fichas,aposta);
        
            if (sorted%2 == 1) { //IMPAR GANHA
                if (fichas > maxfichas) {
                    maxfichas = fichas;
                }
                
                fichas = fichas + 2*pow(2,aposta);
                aposta = 0;
            }
        
            else {
                aposta++;
            }
        }
    }
        int investido = fichasIniciais*janelasMax;
        float port = 0;
        port = ((float)caixa/(float)investido)*100;
        mediaLucro += port;
        printf("V:%d Cx: %d Inv: %d PL: %.2f\n",flafFailNum,caixa,investido,port);
        caixa = 0;
    }
    printf("Media lucro: %d",mediaLucro/diasMax);
    
    
    return 0;
}
