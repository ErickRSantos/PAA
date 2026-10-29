#include <stdio.h>
#include <stdlib.h>

#define MAX_OPERACOES 1000005

typedef struct
{
  int senha;
  int valor;
} Comprador;

typedef struct
{
  Comprador *data;
  int tam; 
  int i;   
} FilaCompra;

Comprador novoComprador(int senha, int val)
{
  Comprador novo;
  novo.senha = senha;
  novo.valor = val;
  return novo;
}

FilaCompra *novaFila(int capacidade)
{
  FilaCompra *novo = (FilaCompra *)malloc(sizeof(FilaCompra));
  if (novo == NULL)
    return NULL;

  novo->data = (Comprador *)malloc(sizeof(Comprador) * capacidade);
  if (novo->data == NULL)
  {
    free(novo);
    return NULL;
  }

  novo->i = 0;
  novo->tam = capacidade;
  return novo;
}

void troca(Comprador *a, Comprador *b)
{
  Comprador temp = *b;
  *b = *a;
  *a = temp;
}


static inline int temPrioridade(Comprador a, Comprador b)
{
  if (a.valor != b.valor)
    return a.valor > b.valor; 
  return a.senha < b.senha;  
}

void subirMaior(Comprador *data, int i)
{
  while (i > 0)
  {
    int prox = (i - 1) / 2;
    if (temPrioridade(data[i], data[prox]))
    {
      troca(&data[i], &data[prox]);
      i = prox;
    }
    else
    {
      break;
    }
  }
}

void maxHeapfy(Comprador *data, int i, int tam)
{
  while (1)
  {
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i;

    if (left <= tam && temPrioridade(data[left], data[largest]))
    {
      largest = left;
    }
    if (right <= tam && temPrioridade(data[right], data[largest]))
    {
      largest = right;
    }

    if (largest != i)
    {
      troca(&data[largest], &data[i]);
      i = largest;
    }
    else
    {
      break;
    }
  }
}

void inserirFila(FilaCompra *fila, Comprador novo)
{
  fila->data[fila->i] = novo;
  subirMaior(fila->data, fila->i);
  fila->i++;
}

int main()
{
  int senha_atual = 1;
  int val;
  char oper;
  FilaCompra *fila = novaFila(MAX_OPERACOES);

  if (fila == NULL)
  {
    return 1;
  }

  while (scanf(" %c", &oper) != EOF)
  {
    if (oper == 'c')
    {
      scanf("%d", &val);
      Comprador temp = novoComprador(senha_atual, val);
      inserirFila(fila, temp);
      senha_atual++;
    }
    else if (oper == 'v')
    {
      if (fila->i > 0)
      {
        Comprador atendido = fila->data[0];
        troca(&fila->data[0], &fila->data[fila->i - 1]);
        fila->i--;
        if (fila->i > 0)
        {
          maxHeapfy(fila->data, 0, fila->i - 1);
        }
        printf("%d\n", atendido.senha);
      }
      else
      {
        // Fila vazia: imprime 0
        printf("0\n");
      }
    }
    else if (oper == 'f')
    {
      break;
    }
  }

  free(fila->data);
  free(fila);

  return 0;
}