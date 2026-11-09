#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int data[15];
  int insert;
} Seq;

typedef struct 
{
  Seq* solucao;
  int tam;
  int insert;
} Storage;

void iniciarStorage(Storage *storage){
  storage->solucao = (Seq*) calloc(10, sizeof(Seq));
  storage->insert = 0;
  storage->tam = 0;
}

void adicionarStorage (Storage *storage, Seq S){
  if (storage->tam == storage->insert)
  {
    storage->tam += 10;
    storage->solucao = realloc(storage->solucao, sizeof(Seq) * storage->tam);
  }
  storage->solucao[storage->insert++] = S;
}

Seq gerarSubseq(Seq S, int i)
{
  Seq resul;
  int max, esq, dir, soma = 0;
  int L[15];
  for (int m = 0; m < 15; m++)
  {
    L[m] = 0;
  }
  for (int j = 0; j < i; j++)
  {
    L[j] = S.data[j];
  }
  max = (i > S.insert - i) ? i : S.insert-i;
  esq = i - 1;
  dir = i;
  for (int j = max-1; j >= 0; j--)
  {
    if (esq >= 0)
      soma += L[esq--];
    if (dir < S.insert)
      soma += S.data[dir++];
    resul.data[j] = soma;
    soma = 0;
  }
  resul.insert = max;
  return resul;
}
void backtrack (Seq S, int n, Storage* storage){
  int max;  
  if (n == S.insert){
    adicionarStorage(storage, S);
  } else {
    for (int i = 1; i < S.insert ; i++)
    {
      max = (i > S.insert - i) ? i : S.insert-i;
      if (max >=n)
      {
        Seq novo = gerarSubseq(S, i);
        if(S.insert>1) backtrack(novo, n, storage);
      }        
    }
  }
}

int comparar(Seq S1, Seq S2){
  int r=1;
  if (S1.insert == S2.insert)
  {
    for (int i = 0; i < S1.insert && r == 1; i++)
    {
      if(S1.data[i]!=S2.data[i]) r = 0;
    }
    if (r==1) {
      return 1;
    } else {
      r = 1;
    }
    S1 = gerarSubseq(S1, 0);
    for (int i = 0; i < S1.insert && r == 1; i++)
    {
      if(S1.data[i]!=S2.data[i]) r = 0;
    }
    return r;     
  } else {
    return 0;
  }  
}

int main()
{
  Seq S, Sl;
  Storage storage;
  int soma1 = 0, soma2 = 0;

  scanf("%d", &S.insert);
  for (int i = 0; i < S.insert; i++)
  {
    scanf("%d", &S.data[i]);
    soma1 += S.data[i];
  }
  scanf("%d", &Sl.insert);
  for (int i = 0; i < Sl.insert; i++)
  {
    scanf("%d", &Sl.data[i]);
    soma2 += Sl.data[i];
  }
  if (soma1 != soma2) {
    printf("N");
  } else {
    iniciarStorage(&storage);
    backtrack(S, Sl.insert, &storage);
    for (int i = 0; i < storage.insert; i++)
    {
      if(comparar(storage.solucao[i], Sl)){
        printf("S");
        return 0;
      }
    }
    printf("N");
  }
  return 0;
}