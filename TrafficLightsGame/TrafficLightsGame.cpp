#include <stdio.h>
#include <stdlib.h>

/*
Função responsável por definir a modalidade do jogo, sendo:

1 - Player vs Computador
2 - Player vs Player
*/
int SelecionarModoJogo() {
	int modo = 0;

	while (modo != 1 && modo != 2) {
		printf("Selecione o modo de jogo: \n\n 1 - Player vs Computador \n 2 - Player vs Player \n\n Opcao:");
		scanf("%d", &modo);
	}

	system("CLS");
	return modo;
}

// Função responsável por ler e validar a linha selecionada 
int SelecionarLinha() {
	int linha = 0;

	while (linha < 1 && linha > 3) {
		printf("Selecione a linha em que deseja jogar: ");
		scanf("%d", &linha);
	}

	return linha;
}

// Função responsável por ler e validar a coluna selecionada 
int SelecionarColuna() {
	int coluna = 0;

	while (coluna < 1 && coluna > 4) {
		printf("Selecione a coluna em que deseja jogar: ");
		scanf("%d", &coluna);
	}

	return coluna;
}

//Posiciona um valor no tabuleiro: vermelho, amarelo ou verde.
void RealizarJogada(char tabuleiro[3][4], int linha, int coluna) {
	switch (tabuleiro[linha][coluna]) {
		case ' ':
			tabuleiro[linha][coluna] = '-';
			break;

		case '-':
			tabuleiro[linha][coluna] = '+';
			break;

		case '+':
			tabuleiro[linha][coluna] = '#';
			break;
	}
}

/*Função para validar se a posição selecionada contém o valor "verde".
Caso valor da posição selecionada seja "verde", a jogada é invalidada.
*/
int ValidarPosicaoTabuleiro(char tabuleiro[3][4], int linha, int coluna) {
	if (tabuleiro[linha][coluna] == '#') {
		printf("Jogada inválida, por favor, jogue novamente. \n");
		return 0;
	}
		
	return 1;
}

//Função utilizada para mostrar o tabuleiro atualizado.
void MostrarTabuleiro(char tabuleiro[3][4]) {

	printf("    1    2    3    4 \n");

	for (int i = 0; i < 3; i++) {
		printf("%d [ %c ][ %c ][ %c ][ %c ] \n", i+1, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2], tabuleiro[i][3]);
	}
}

/*
Função para verificar se o jogo terminou.
Caso as condições para o termino do jogo sejam satisfeitas a função retorna 1,
caso contrario ela retorna 0, indicando que o jogo continua.
*/
int ValidarJogoTerminou(char tabuleiro[3][4]) {

	//Valida colunas
	for (int i = 0; i < 4; i++) {
		if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
			return 1;
	}

	//Valida linhas
	for (int i = 0; i < 3; i++) {
		if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2] && tabuleiro[i][0] !=  ' ' ||
			tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][1] == tabuleiro[i][3] && tabuleiro[i][1] != ' ')
			return 1;
	}

	//Valida diagonais
	if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2] && tabuleiro[0][0] != ' ' ||
		tabuleiro[0][1] == tabuleiro[1][2] && tabuleiro[0][1] == tabuleiro[2][3] && tabuleiro[0][1] != ' ' ||
		tabuleiro[0][3] == tabuleiro[1][2] && tabuleiro[0][3] == tabuleiro[2][1] && tabuleiro[0][3] != ' ' ||
		tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
			return 1;	

	return 0;
}



void PlayerVsPlayer() {
	char tabuleiro[3][4];
	int linha, coluna, jogadas = 0;

	InicializaTabuleiro(tabuleiro);

	while (ValidarJogoTerminou(tabuleiro) != 1) {
		MostrarTabuleiro(tabuleiro);

		
	}
}


void PlayerVsComputador() {

}

//Inicializa o tabuleiro, mudando os valores para vazio.
void InicializaTabuleiro(char tabuleiro[3][4]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			tabuleiro[i][j] = ' ';
		}
	}
}

//Função principal
void main()
{
	char tabuleiro[3][4];
	int linha, coluna;

	InicializaTabuleiro(tabuleiro);

	int modoJogo = SelecionarModoJogo();

	if (modoJogo == 1)
		PlayerVsComputador();
	else
		PlayerVsPlayer();
}

