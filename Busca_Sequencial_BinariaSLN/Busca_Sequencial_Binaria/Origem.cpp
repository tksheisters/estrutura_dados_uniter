#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHOVETOR 100

int BuscaSequencial(int vet[], int buscado);

int main() {
	int vet[TAMANHOVETOR] = { 0 };
	srand(time(NULL));
	int buscado, achou;

	for (int i = 0; i < TAMANHOVETOR; i++) {
		vet[i] = rand() % 1000;
	}

	printf("Vetor gerado: \n");
	for (int i = 0; i < TAMANHOVETOR; i++) {
		printf("%d\n", vet[i]);
	}

	printf("Selecione um valor para buscar: \n");
	scanf_s("%d", &buscado);

	achou = BuscaSequencial(vet, buscado);

	if (achou == -1) {
		printf("Valor não encontrado...");
	}
	else {
		printf("Valor encontrado na posição %d. \n", achou);
	}

	system("pause");
	return 0;
}

int BuscaSequencial(int vet[], int buscado) {
	int achou, i;
	achou = 0;
	i = 0;

	while ((i <= TAMANHOVETOR) && (achou == 0)) {
		if (vet[i] == buscado) {
			achou = 1;
		}
		else {
			i++;
		}
	}

	if (achou == 0) {
		return -1;
	}
	else {
		return i + 1;
	}
}