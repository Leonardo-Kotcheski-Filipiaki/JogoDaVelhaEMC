#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
const int TAMANHO_LINHA = 3;
const int TAMANHO_COLUNA = 3;
int campoDeJogo[3][3];
int ganhador = 0;
int terminarJogo = 0;
char nomeJogadorUm[30], nomeJogadorDois[30] = "";
int jogadaPlayers = 0;
// for(int i = 0; i < 3; i++){
//     for(int j = 0; j < 3; j++){

//     }
// }

void exibirCampoNaTela(){
    for(int i = 0; i < 3; i++){
        printf("\n| ");
        for(int j = 0; j < 3; j++){
            if(campoDeJogo[i][j] == 120 || campoDeJogo[i][j] == 111){
                char jogada = campoDeJogo[i][j];
                printf("%c |", jogada);
            }else{
                if(j == 1 || j == 2){
                    printf(" %d |", campoDeJogo[i][j]);
                }else{
                    printf("%d |", campoDeJogo[i][j]);

                }
            }
        }
    }
}

int registraJogada(int posicaoI, int posicaoJ, int jogada){
    campoDeJogo[posicaoI][posicaoJ] = jogada;
    int linha = 0;
    int coluna = 0;
    int d = 0;
    for(int i = 0; i < TAMANHO_LINHA; i++){
        linha = 0;
        for (int j = 0; j < TAMANHO_COLUNA; j++){
            if(campoDeJogo[i][j] == jogada)
                linha++;
            if(i == j && campoDeJogo[i][j] == jogada){
                d++;
            }
        }
    }
    for(int j = 0; j < TAMANHO_COLUNA; j++){
        coluna = 0;
        for (int i = 0; i < TAMANHO_LINHA; i++){
            if(campoDeJogo[i][j] == jogada)
                coluna++;
        }
    }
    
    if(campoDeJogo[2][0] == jogada && campoDeJogo[1][1] == jogada && campoDeJogo[0][2] == jogada){
        return 1;
    }else if(linha == 3 || d == 3 || coluna == 3){
        return 1;
    }
    return 0;
}

int procuraPosicao(int valor, int playerMark){
    int achei = 0;
    int i = 0;
    int j = 0;
    int ganhou = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(campoDeJogo[i][j] == valor){
                achei = 1;
                ganhou = registraJogada(i, j, playerMark);
            }
        }
    }
    if(achei == 1){
        if(ganhou == 1){
            return 2; //Jogador ganhou.
        }
        return 1; //Registra jogada.
    }
    return 0; //Jogada não registrada.
}

void inicializaCampo(){
    int cont = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            campoDeJogo[i][j] = cont++;
        }
    }
}


//JOGADOR CONTRA JOGADOR
void jogadorXJogador(){
    setbuf(stdin, NULL);
    printf("JOGO DA VELHA\nDigite um nome para o jogador 1: ");
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
    int jogaPrimeiro = (rand()%100)%2==0;
    int turno = 0;
    while(terminarJogo != 1){
        if(jogaPrimeiro == 0){
            if(turno == 0){
                int result = 0;
                while(result == 0){
                    exibirCampoNaTela();
                    printf("\nVez do %s jogar, escolha um posicao: ", nomeJogadorUm);
                    printf("\n");
                    scanf("%d", &jogadaPlayers);
                    result = procuraPosicao(jogadaPlayers, 120);
                    if(result == 0)
                        printf("\nJogada invalida, jogue novamente.");
                    if(result == 2){
                        printf("\nParabens! %s ganhou!", nomeJogadorUm);
                        terminarJogo = 1;
                    }
                }
                ++turno;
            }else{
                int result = 0;
                while(result == 0){
                    exibirCampoNaTela();
                    printf("\nVez do %s jogar, escolha um posicao: ", nomeJogadorDois);
                    printf("\n");
                    scanf("%d", &jogadaPlayers);
                    result = procuraPosicao(jogadaPlayers, 111);
                    if(result == 0)
                        printf("\nJogada invalida, jogue novamente.");
                    if(result == 2){
                        printf("\nParabens! %s ganhou!", nomeJogadorDois);
                        terminarJogo = 1;
                    }
                }
                --turno;
            }
        
        }else{
            if(turno == 0){
                int result = 0;
                while(result == 0){
                    exibirCampoNaTela();
                    printf("\nVez do %s jogar, escolha um posicao: ", nomeJogadorDois);
                    printf("\n");
                    scanf("%d", &jogadaPlayers);
                    result = procuraPosicao(jogadaPlayers, 120);
                    if(result == 0)
                        printf("\nJogada invalida, jogue novamente.");
                    if(result == 2)
                        printf("\nParabens! %s ganhou!", nomeJogadorDois);
                        terminarJogo = 1;
                    
                }
                ++turno;
            }else{
                int result = 0;
                while(result == 0){
                    exibirCampoNaTela();
                    printf("\nVez do %s jogar, escolha um posicao: ", nomeJogadorUm);
                    printf("\n");
                    scanf("%d", &jogadaPlayers);
                    result = procuraPosicao(jogadaPlayers, 111);
                    if(result == 0)
                        printf("\nJogada invalida, jogue novamente.");
                    if(result == 2){
                        printf("\nParabens! %s ganhou!", nomeJogadorUm);
                        terminarJogo = 1;
                    }
                }
                --turno;
            }
        }
    }   
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    SetConsoleOutputCP(65001);
    srand(time(NULL));
    inicializaCampo(); //Faz o que o nome diz
    int opcao = 0;
    while(opcao != 1 && opcao != 2){
        printf("Deseja jogar contra o robo (1) ou contra outro jogador(2)? ");
        scanf("%d", &opcao);
        if(opcao != 1 && opcao != 2){
            printf("\nEscolha invalida, por favor realize uma escolha correta!\n");
        }
    }

    if(opcao == 2){
        jogadorXJogador();
    }
    
    exibirCampoNaTela();
    return 0;
}