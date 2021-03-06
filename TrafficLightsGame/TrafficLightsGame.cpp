#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
Fun��o respons�vel por definir a modalidade do jogo, sendo:

1 - Player vs Computador
2 - Player vs Player
*/
int SelecionarModoJogo() {
	int modo = 0;

	while (modo != 1 && modo != 2) {
		printf("Selecione o modo de jogo: \n\n 1 - Player vs Computador \n 2 - Player vs Player \n\n Opcao:");
		scanf("%d", &modo);
	}

	system("cls");
	return modo;
}

// Fun��o respons�vel por ler e validar a linha selecionada 
int SelecionarLinha() {
	int linha = 0;

	while (linha < 1 || linha > 3) {
		printf("Selecione a linha em que deseja jogar: ");
		scanf("%d", &linha);
	}

	return linha;
}

// Fun��o respons�vel por ler e validar a coluna selecionada 
int SelecionarColuna() {
	int coluna = 0;

	while (coluna < 1 || coluna > 4) {
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

/*Fun��o para validar se a posi��o selecionada cont�m o valor "verde".
Caso valor da posi��o selecionada seja "verde", a jogada � invalidada.
*/
int ValidarPosicaoTabuleiro(char tabuleiro[3][4], int linha, int coluna) {
	if (tabuleiro[linha][coluna] == '#')
		return 0;	
		
	return 1;
}

//Fun��o utilizada para mostrar a tela do jogo.
void MostrarTelaJogo(char tabuleiro[3][4], int jogadas, int jogadaValida, int jogoAcabou) {
	int jogador = (jogadas - jogoAcabou) % 2;

	system("cls");
	printf("    1    2    3    4 \n");

	for (int i = 0; i < 3; i++) {
		printf("%d [ %c ][ %c ][ %c ][ %c ] \n", i+1, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2], tabuleiro[i][3]);
	}	

	if (jogadaValida == 0)
		printf("Jogada realizada foi inv�lida, por favor jogue novamente. \n");

	if (jogoAcabou == 0)
		printf("Turno do jogador %d. \n", jogador + 1);
	else 
		printf("Jogador %d venceu!. \n", jogador + 1);
}

/*
Fun��o para verificar se o jogo terminou.
Caso as condi��es para o termino do jogo sejam satisfeitas a fun��o retorna 1,
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

//Inicializa o tabuleiro, mudando os valores para vazio.
void InicializaTabuleiro(char tabuleiro[3][4]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			tabuleiro[i][j] = ' ';
		}
	}
}

int ValidarJogadaComputadorVencer(char tabuleiro[3][4]) {
	char aux = ' ';

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
		{
			aux = tabuleiro[i][j];
			RealizarJogada(tabuleiro, i, j);
			if (ValidarJogoTerminou(tabuleiro) == 1)
				return 1;
			else
				tabuleiro[i][j] = aux;
		}
	}

	return 0;
}

int RealizarJogadaComputador(char tabuleiro[3][4]) {
	char aux = ' ';

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
		{
			if (tabuleiro[i][j] != '#') {
				aux = tabuleiro[i][j];
				RealizarJogada(tabuleiro, i, j);
				if (ValidarJogadaComputadorVencer(tabuleiro) == 1)
					tabuleiro[i][j] = aux;
				else
					return 1;
			}
		}
	}

	return 0;
}

//Fun��o principal
void main()
{	
	char tabuleiro[3][4];
	int linha, coluna, jogadas = 0, jogadaValida = 1, jogoAcabou = 0;

	int modoJogo = SelecionarModoJogo();

	InicializaTabuleiro(tabuleiro);

	while (jogoAcabou == 0) {
		
		if ((modoJogo == 2) || (modoJogo == 1 && jogadas % 2 == 0)) {
			MostrarTelaJogo(tabuleiro, jogadas, jogadaValida, 0);

			linha = SelecionarLinha() - 1;
			coluna = SelecionarColuna() - 1;

			jogadaValida = ValidarPosicaoTabuleiro(tabuleiro, linha, coluna);

			if (jogadaValida == 1) {
				RealizarJogada(tabuleiro, linha, coluna);
				jogadas++;
			}

			jogoAcabou = ValidarJogoTerminou(tabuleiro);
		}
		else {
			jogadas++;
			if (ValidarJogadaComputadorVencer(tabuleiro) == 0) {
				if (RealizarJogadaComputador(tabuleiro) == 0) {
					jogoAcabou == 1;
					jogadas--;
				}
			}
			else
				jogoAcabou = ValidarJogoTerminou(tabuleiro);
		}
	}

	MostrarTelaJogo(tabuleiro, jogadas, jogadaValida, jogoAcabou);
	getch();
}
	

