#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int vet[]);
void QuickSort(int vet[], int p, int u);
int particao(int vet[], int p, int u);
void troca(int vet[], int i, int j);
#define TAMANHOVETOR 10000

int main() {
	int vet[TAMANHOVETOR] = {0};
	srand(time(NULL)); // gera a semente aleatória

	// inserção de dados
	for (int i = 0; i < TAMANHOVETOR; i++) {
		vet[i] = rand() % 10000; // gera os valores aleatórios
	}
		
	printf("Vetor não ordenado: \n");
	for (int i = 0; i < TAMANHOVETOR; i++) {
		printf("%d\n", vet[i]);
	}

	BubbleSort(vet);
	//QuickSort(vet, 0, TAMANHOVETOR - 1);

	printf("Vetor ordenado: \n");
	for (int i = 0; i < TAMANHOVETOR; i++) {
		printf("%d\n", vet[i]);
	}

	system("pause");
	return 0;
}

void BubbleSort(int vet[]) {
	int aux;
	for (int n = 1; n <= TAMANHOVETOR; n++) {
		for (int i = 0; i < (TAMANHOVETOR - 1); i++) {
			if (vet[i] > vet[i + 1]){// crescente
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
			/* --- decrescente
			if (vet[i] < vet[i + 1]){ 
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
			*/
			}
		}
	}
}

void QuickSort(int vet[], int p, int u) {
	int m;
	if (p < u) {
		m = particao(vet, p, u);
		QuickSort(vet, p, m); // esquerdo
		QuickSort(vet, m + 1, u); // direito
	}

}

int particao(int vet[], int p, int u) {
	int pivo, pivo_pos, i, j;

	pivo_pos = (p + u) / 2;
	pivo = vet[pivo_pos];

	i = p - 1;
	j = u + 1;

	while (i < j) {
		do // testa lado direito
		{
			j--;
		} while (vet[j] > pivo);
		do // testa lado esquerdo
		{
			i++;
		} while (vet[i] < pivo);
		if (i < j) {
			troca(vet, i, j);
		}
	}
	return j;
}

void troca(int vet[], int i, int j) {
	int aux;
	aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;

}