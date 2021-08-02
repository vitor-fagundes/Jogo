#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int x = 0;
int y = 0;
int vitoria = 0;

int tabuleiro[4][4] = {1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 0,
                       13, 14, 15, 12};                       

int jogo(contador) {
    mostrarTabuleiro(contador);
    while(!GetAsyncKeyState(VK_ESCAPE) && vitoria == 0)	{          //Movimenta as chaves
		if(GetAsyncKeyState(VK_LEFT) != 0 && x > 0){ 
            x--; 
            mostrarTabuleiro(contador); 
        }
		if(GetAsyncKeyState(VK_RIGHT)!= 0 && x < 3){ 
            x++; 
            mostrarTabuleiro(contador);
        }
		if(GetAsyncKeyState(VK_DOWN) != 0 && y < 3){ 
            y++; 
            mostrarTabuleiro(contador); 
        }
		if(GetAsyncKeyState(VK_UP)   != 0 && y > 0){ 
            y--; 
            mostrarTabuleiro(contador); 
        }
		        //Troca as peças
		if(GetAsyncKeyState(VK_SPACE)!= 0){
			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 4; j ++){
					if(x == j && y == i){
						if(j > 0 && tabuleiro[i][j-1] == 0){ 
                            tabuleiro[i][j-1] = tabuleiro[i][j]; 
                            tabuleiro[i][j] = 0;
                            contador++;
                        }
						if(j < 3 && tabuleiro[i][j+1] == 0){ 
                            tabuleiro[i][j+1] = tabuleiro[i][j]; 
                            tabuleiro[i][j] = 0;
                            contador++; 
                        }
						if(i < 3 && tabuleiro[i+1][j] == 0){ 
                            tabuleiro[i+1][j] = tabuleiro[i][j]; 
                            tabuleiro[i][j] = 0;
                            contador++; 
                        }
						if(i > 0 && tabuleiro[i-1][j] == 0){ 
                            tabuleiro[i-1][j] = tabuleiro[i][j]; 
                            tabuleiro[i][j] = 0;
                            contador++; 
                        }
					}
				}
			}
            mostrarTabuleiro(contador);
		}
        if(tabuleiro[0][0] == 1 && tabuleiro[0][1] == 2 && tabuleiro[0][2] == 3 && tabuleiro[0][3] == 4 &&
               tabuleiro[1][0] == 5 && tabuleiro[1][1] == 6 && tabuleiro[1][2] == 7 && tabuleiro[1][3] == 8 && 
               tabuleiro[2][0] == 9 && tabuleiro[2][1] == 10 && tabuleiro[2][2] == 11 && tabuleiro[2][3] == 12 &&
               tabuleiro[3][0] == 13 && tabuleiro[3][1] == 14 && tabuleiro[3][2] == 15 && tabuleiro[3][3] == 0){
                vitoria = 1;
                printf("\n\n Parabens! Jogo finalizado. "); 
                printf("Numero de jogadas: %d", contador);
                Sleep(2000); 
                
        }                     
	}
    return contador;
}

void mostrarTabuleiro(contador){
	system("cls");       
	printf("    ________________________\n\n");

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if (j == x && i == y){
                if (tabuleiro[i][j]==0){
                    printf("    [ ]");
                } else {
                    printf("    [%d]", tabuleiro[i][j]);
                }
			}else{
				if (tabuleiro[i][j]==0){
                    printf("       ");
                } else {
                    printf("     %d ", tabuleiro[i][j]);
                }
			}
		}
		printf("\n\n");
	}
	printf("    ________________________\n Numero de jogadas: %d", contador);
	Sleep(100);

}

int main() {
    int aux;
    int opcao = 0;
    char Linha[100];
    char *result;
    int i;
    int op;

    FILE *pont_arq;

    struct jogador{
        char nome[30];
        int contador;
    };

    struct jogador jogador;

    jogador.contador = 0;

    printf("Seja bem vindo ao Jogo do 15\n\nUtilize as setas para movimentar as chaves e espaco para movimentar as pecas para o espaco em branco.\n\nPressione Enter para continuar...");
    getchar();
    system("cls");    
    printf("\nDigite seu nome: ");
    gets(jogador.nome);
    printf("Seu nome eh: %s", jogador.nome);
    Sleep(500);
    system("cls");

    aux = jogo(jogador.contador);

    pont_arq = fopen("ranking.txt", "a");
            
    if(pont_arq == NULL) {
        printf("Erro na abertura do arquivo!");
        return 1;
    }else{
        fprintf(pont_arq, "Nome: %s - Numero de jogadas: %d\n", jogador.nome, aux);
        fclose(pont_arq);
        printf("\n\nDados gravados com sucesso!\n\n");
        Sleep(2000);
        system("cls");
    }

    pont_arq = fopen("ranking.txt", "rt");

    if(pont_arq == NULL) {
        printf("Erro na abertura do arquivo!");
        return 1;
    }else{
        i=1;
        while (!feof(pont_arq)){
            result = fgets(Linha, 100, pont_arq);
            if(result) {
                printf("Posicao %d : %s",i,Linha);
            }    
            i++;
        }

        fclose(pont_arq);
    }        
    
    printf("Encerrando o jogo...");
    Sleep(5000);
    system("cls");
    return 0;

}