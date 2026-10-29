#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Comprador novoComprador(int i, int val)
{
  Comprador novo;
  novo.senha = i;
  novo.valor = val;
  return novo;
}

FilaCompra *novaFila(int i)
{
  FilaCompra *novo = (FilaCompra *)malloc(sizeof(FilaCompra));
  if (novo == NULL)
  {
    return NULL;
  }

  novo->data = (Comprador *)malloc(sizeof(Comprador) * i);
  if (novo->data == NULL)
  {
    free(novo);
    return NULL;
  }

  novo->i = 0;
  novo->tam = i;
  return novo;
}

int filaCheia(FilaCompra *fila)
{
  return (fila->i == fila->tam);
}

void aumentarFila(FilaCompra *fila)
{
  fila->tam = fila->tam * 2;
  fila->data = (Comprador *)realloc(fila->data, sizeof(Comprador) * fila->tam);
}

void troca(Comprador *a, Comprador *b)
{
  Comprador temp = *b;
  *b = *a;
  *a = temp;
}

void subirMaior(Comprador *data, int i)
{
  while (i > 0)
  {
    int prox = (i - 1) / 2;
    if (data[i].valor > data[prox].valor ||
        (data[i].valor == data[prox].valor && data[i].senha < data[prox].senha))
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
  int left = i * 2 + 1;
  int right = i * 2 + 2;
  int largest = i;

  if (left <= tam && (data[left].valor > data[largest].valor ||
                      (data[left].valor == data[largest].valor && data[left].senha < data[largest].senha)))
  {
    largest = left;
  }
  if (right <= tam && (data[right].valor > data[largest].valor ||
                       (data[right].valor == data[largest].valor && data[right].senha < data[largest].senha)))
  {
    largest = right;
  }
  if (largest != i)
  {
    troca(&data[largest], &data[i]);
    maxHeapfy(data, largest, tam);
  }
}

void inserirFila(FilaCompra *fila, Comprador novo)
{
  if (filaCheia(fila))
  {
    aumentarFila(fila);
  }
  fila->data[fila->i] = novo;
  subirMaior(fila->data, fila->i);
  fila->i++;
}

int main()
{
  int i, val, r = 0;
  Comprador temp;
  FilaCompra *fila = NULL;
  char oper[8];

  fila = novaFila(10);
  if (fila == NULL)
  {
    return 1;
  }

  i = 1;

  while (scanf("%s", oper) != EOF)
  {
    if (strcmp(oper, "c") == 0)
    {
      scanf("%d", &val);
      temp = novoComprador(i, val);
      inserirFila(fila, temp);
      i++;
    }
    else if (strcmp(oper, "v") == 0)
    {
      if (fila->i > 0)
      {
        temp = fila->data[0];
        troca(&fila->data[0], &fila->data[fila->i - 1]);
        fila->i--;
        if (fila->i > 0)
        {
          maxHeapfy(fila->data, 0, fila->i - 1);
        }
  
        printf("%d\n", temp.senha);
    
      }
      else
      {
        printf("0\n");
      }
    }
    else if (strcmp(oper, "f") == 0)
    {
      break;
    }
    else
    {
      printf("Read operation %s\n", oper);
    }
  }

  free(fila->data);
  free(fila);

  return 0;
}
