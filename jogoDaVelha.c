#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
int ganhador = 0;
int terminarJogo = 0;
char nomeJogadorUm[30], nomeJogadorDois[30] = "";
int jogadaPlayers = 0;
// for(int i = 0; i < 3; i++){
//     for(int j = 0; j < 3; j++){

//     }
// }

void exibirCampoNaTela(int campo[3][3]){
    for(int i = 0; i < 3; i++){
        printf("\n| ");
        for(int j = 0; j < 3; j++){
            if(campo[i][j] == 120 || campo[i][j] == 111){
                char jogada = campo[i][j];
                printf("%c |", jogada);
            }else{
                printf("%d |", campo[i][j]);
            }
        }
    }
}

void registraJogada(int campo[3][3], int posicaoI, int posicaoJ, int jogada){
    campo[posicaoI][posicaoJ] = jogada;
}

void inicializaCampo(int campo[3][3]){
    int cont = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            campo[i][j] = cont++;
        }
    }
}

int main(){
    setlocale(LC_ALL, "");

    int campoDeJogo[3][3];

    inicializaCampo(campoDeJogo);

    exibirCampoNaTela(campoDeJogo);

    printf("Digite um nome para o jogador 1: ");
    gets(nomeJogadorUm);
    if(nomeJogadorUm[0] == '\0'){
        strcpy(nomeJogadorUm, "Jogador 1");
    }
    printf("Digite um nome para o jogador 2: ");
    gets(nomeJogadorDois);
    if(nomeJogadorDois[0] == '\0'){
        strcpy(nomeJogadorDois, "Jogador 2");
    }
    printf("\n");
    while(terminarJogo != 1){
        int turno = 0;
        if(turno == 0){
            printf("Vez do %s jogar, escolha um posicao: ", nomeJogadorUm);
            exibirCampoNaTela(campoDeJogo);
            scanf("%d", &jogadaPlayers);
        }
        terminarJogo = 1;
    }

    printf("\n%d",jogadaPlayers);
    

}