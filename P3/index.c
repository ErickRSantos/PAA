#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int data[15];
  int insert;
}Seq;

Seq* gerarSubseq(Seq S, int i){
  Seq *resul;
  int max;
  if(i >= S.insert) return NULL;
  int L[15];
  for (int m = 0; m < 15; m++)
  {
    L[m]=0;
  }
  for (int j = 0; j < i; j++)
  {
    L[j] = S.data[j]; 
  }
  for (int j = 0; j < S.insert-i; j++)
  {
    
  }

  resul = (Seq*)malloc(sizeof(Seq));
}


int main() {
    // seu código aqui
    return 0;
}