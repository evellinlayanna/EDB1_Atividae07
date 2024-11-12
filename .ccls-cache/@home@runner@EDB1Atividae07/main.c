#define TAMANHO_MAX 100

typedef struct {
  int dados[TAMANHO_MAX];
  int tamanho;
} Fila;

void inicializarFila(Fila *fila) { fila->tamanho = 0; }

int filaVazia(Fila *fila) { return fila->tamanho == 0; }

int FilaCheia(Fila *fila) { return fila->tamanho == TAMANHO_MAX; }

void inserirFila(Fila *fila, int valor) {
  if (FilaCheia(fila)) {
    printf("A fila está cheia");
  } else {
    fila->dados[fila->tamanho] = valor;
    fila->tamanho++;
  }
}

int removerFila(Fila *fila) {
  if (filaVazia(fila)) {
    printf("A fila está vazia");
    return -1;
  } else {
    int valor = fila->dados[0];

    for (int i = 1; i < fila->tamanho; i++) {
      fila->dados[i - 1] = fila->dados[i];
    }
    fila->tamanho--;
    return valor;
  }
}

int consultarPrimeiro(Fila *fila) {
  if (filaVazia(fila)) {
    printf("A fila está vazia");
  } else {
    return fila->dados[0];
  }
}

void exibirFila(Fila *fila) {
  if (filaVazia(fila)) {
    printf("A fila está vazia");
  } else {
    printf("Fila: ");
    for (int i = 0; i < fila->tamanho; i++) {
      printf("%d ", fila->dados[i]);
    }
    pritnf("\n");
  }
}

int main() {
  Fila fila;
  inicializarFila(&fila);

  inserirFila(&fila, 10);
  inserirFila(&fila, 20);
  inserirFila(&fila, 30);

  exibirFila(&fila);

  printf("Primeiro elemento: %d\n", consultarPrimeiro(&fila));

  printf("Removendo elemento: %d\n", removerFila(&fila));

  printf("Primeiro elemento após remoção: %d\n", consultarPrimeiro(&fila));

  exibirFila(&fila);

  return 0;
}