#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
  int senha;
  int valor;
} Comprador;

typedef struct 
{
  Comprador** data;
  int tam;
  int i;
} FilaCompra;


Comprador* novoComprador(int i, int val) {
  Comprador* novo = (Comprador*) malloc(sizeof(Comprador));
  novo->senha = i;
  novo->valor = val;
  return novo;
}

FilaCompra* novaFila(int i) {
  FilaCompra* novo = (FilaCompra*)malloc(sizeof(FilaCompra));
  novo->data = (Comprador**)malloc(sizeof(Comprador*)*i);
  novo->i=0;
  novo->tam=i;
  return novo;
}

int filaCheia(FilaCompra* fila){
  if (fila->i = fila->tam) return 1;
  return 0;  
}

void aumentarFila(FilaCompra* fila){
  fila->tam*=2;
  fila->data=realloc(fila, fila->tam);
}

void merge(Comprador** data, int p, int q, int r) {
  int q = (p+r)/2;
  int tamL = q-p+1;
  int tamR = r-q;
  Comprador** tempL = (Comprador**)malloc(sizeof(Comprador*)*tamL);
  Comprador** tempR = (Comprador**)malloc(sizeof(Comprador*)*tamR);
}

void mergeCompradores(FilaCompra* fila, int p, int r) {

}

void inserirFila(FilaCompra* fila , Comprador* novo){
  if (filaCheia(fila) == 1)
  {
    aumentarFila(fila);
  }
  fila->data[fila->tam] = novo;
  mergeCompradores(fila, 0, fila->i-1);
}

int main(){
  int i,val;
  Comprador* temp = NULL;
  char oper[8];
 
    i = 1;
  
    while(scanf("%s",oper)!=EOF){
        if(strcmp(oper,"c")==0){
        //operacao de compra
            scanf("%d\n",&val);
            temp = novoComprador(i, val);

            i++;
        }
        else if(strcmp(oper,"v")==0){
        //operacao de venda
        }
        else if(strcmp(oper,"f")==0) break; //finalizar
        else printf("Read operation %s\n",oper);
    }
    return 0;
}