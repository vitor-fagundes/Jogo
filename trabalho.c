#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int x = 0, y = 0, vitoria = 0;

//int tabuleiro[4][4] = {8, 11,  1, 7,
//                     12,  5,  2, 6,
//                      10,  9,  4, 15,
//                       3, 13, 14, 0};

int tabuleiro[4][4] = {1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 0,
                       13, 14, 15, 12};                       

void jogo() {
    show();
    while(!GetAsyncKeyState(VK_ESCAPE) && vitoria == 0)	{          //Movimenta as chaves
		if(GetAsyncKeyState(VK_LEFT) != 0 && x > 0){ 
            x--; 
            show(); 
        }
		if(GetAsyncKeyState(VK_RIGHT)!= 0 && x < 3){ 
            x++; 
            show();
        }
		if(GetAsyncKeyState(VK_DOWN) != 0 && y < 3){ 
            y++; 
            show(); 
        }
		if(GetAsyncKeyState(VK_UP)   != 0 && y > 0){ 
            y--; 
            show(); 
        }
		        //Troca as peças
		if(GetAsyncKeyState(VK_SPACE)!= 0){
			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 4; j ++){
					if(x == j && y == i){
						if(j > 0 && tabuleiro[i][j-1] == 0){ 
                            tabuleiro[i][j-1] = tabuleiro[i][j]; 
                            tabuleiro[i][j] = 0;
                        }
						if(j < 3 && tabuleiro[i][j+1] == 0){ 
                            tabuleiro[i][j+1] = tabuleiro[i][j]; 
                            tabuleiro[i][j] = 0; 
                        }
						if(i < 3 && tabuleiro[i+1][j] == 0){ 
                            tabuleiro[i+1][j] = tabuleiro[i][j]; 
                            tabuleiro[i][j] = 0; 
                        }
						if(i > 0 && tabuleiro[i-1][j] == 0){ 
                            tabuleiro[i-1][j] = tabuleiro[i][j]; 
                            tabuleiro[i][j] = 0; 
                        }
					}
				}
			}
			//printf("%c",7);
            show();
		}
        if(tabuleiro[0][0] == 1 && tabuleiro[0][1] == 2 && tabuleiro[0][2] == 3 && tabuleiro[0][3] == 4 &&
               tabuleiro[1][0] == 5 && tabuleiro[1][1] == 6 && tabuleiro[1][2] == 7 && tabuleiro[1][3] == 8 && 
               tabuleiro[2][0] == 9 && tabuleiro[2][1] == 10 && tabuleiro[2][2] == 11 && tabuleiro[2][3] == 12 &&
               tabuleiro[3][0] == 13 && tabuleiro[3][1] == 14 && tabuleiro[3][2] == 15 && tabuleiro[3][3] == 0){
                vitoria = 1;
                printf("\n\n Parabens! Jogo finalizado. "); 
                Sleep(2000); 
                
        }                     
	}
}

void show(){
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
	printf("    ________________________\n");
	Sleep(100);

}

void telaCadastro() {
    char nome[30];
    printf("\n\nDigite seu nome: ");
    gets(nome);
    
    printf("Seu nome eh: %s", nome);
    Sleep(500);
    system("cls");
}

int main() {
    printf("Seja bem vindo ao Jogo do 15\n\nPressione Enter para continuar...");
    getchar();
    system("cls");

    telaCadastro();
    jogo();
    
    
    printf("fim");

    return 0;
}