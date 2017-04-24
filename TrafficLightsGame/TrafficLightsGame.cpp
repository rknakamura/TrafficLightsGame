#include <stdio.h>
#include <stdlib.h>

char tabuleiro[4][3];
char vermelho = '-', amarelo = '+', verde = '#';
int linha, coluna;


int SelecionarModoJogo() {
	int modo = 0;

	printf("---------------------- \n");
	printf("|[ - ][   ][ # ][ + ]| \n");
	printf("|[ - ][   ][ # ][ + ]| \n");
	printf("|[ - ][   ][ # ][ + ]| \n");
	printf("|[ - ][   ][ # ][ + ]| \n");

	while (modo != 1 && modo != 2) {
		printf("Selecione o modo de jogo: \n\n 1 - Player vs Computador \n 2 - Player vs Player \n\n Opcao:");
		scanf("%d", &modo);
	}

	system("CLS");
	return modo;
}

void PlayerVsPlayer() {

}

void PlayerVsComputador() {
	
}

void SelecionarLinha() {
	while (linha < 1 && linha > 3) {
		printf("Selecione a linha em que deseja jogar: ");
		scanf("%d", &linha);
	}
}

void SelecionarColuna() {
	while (linha < 1 && linha > 4) {
		printf("Selecione a coluna em que deseja jogar: ");
		scanf("%d", &linha);
	}
}

void MostrarTabuleiro() {
	for (int i = 0; i < 3; i++) {
		printf("|[ %c ][ %c  ][ %c ][ %c ]| \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2], tabuleiro[i][3]);
	}
}

void main()
{
	int modoJogo = SelecionarModoJogo();

	if (modoJogo == 1)
		PlayerVsComputador();
	else
		PlayerVsPlayer();
}

