#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, inf = 1, sup = 2, custo;
    int vetor[10001];

    vetor[0] = 0;
    scanf("%d", &N);

    for (int i = 0; i <=N; i++)
    {
      if (i == inf) {
        vetor[i]=1;
      } else if (i == sup){
        vetor[i]=1;
        inf = sup;
        sup *=2;
      } else {
        custo = (vetor[i-inf]<vetor[sup-i]) ? vetor[i-inf]:vetor[sup-i];
        vetor[i] = 1 + custo;
      }
    }
    
    printf("%d", vetor[N]);

    return 0;
}