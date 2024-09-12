/******************************************************************************

Autores: 
    Bruno Friedrich Raquel (NUSP: 13672450)
    Pedro Henrique Resnitzky Barbedo (NUSP: 14657691)    
    Gabriel Amorim Noronha (NUSP: 13727151)
    
*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>

void printPilha (int tamanho, int * pilha){
    int i;
    for (i = 1; i<tamanho; i++){
        if (i == tamanho-1){
            printf("%i\n", pilha[i]);
        }
        else{
            printf("%i ", pilha[i]);
        }
    }
}

void flip(int indice, int* pilha, int tamanho){
    int i;
    int j;
    int temp;
    
    for(i = indice, j = tamanho-1; i < j; i++, j--){
      temp = pilha[i];
      pilha[i] = pilha[j];
      pilha[j] = temp;
    }
    printf("por favor, fala q chegou");
}

int buscaMaior(int inicio, int tamanho, int* pilha){
  
  int i;
  int maior = 0;
  int indice;
  for(i = inicio; i < tamanho; i++){
    
    if(pilha[i] > maior){
      maior = pilha[i];
      indice = i;
    }
  }
  return indice;
}

int ordenado(int tamanho, int * pilha){
  int i;
  for(i = 2; i < tamanho; i++){
    if(pilha[i] > pilha[i-1] ){
      return 0;
    }
  }
  return 1;
}

void solve(int inicio, int tamanho, int * pilha){
    printf("a");
  if(ordenado(tamanho, pilha)){
    printf("0\n");
    return;
  }
  printf("aa");
  int indice = buscaMaior(inicio, tamanho, pilha);
  printf("%d ", (tamanho - indice + 1));
  flip((tamanho - indice + 1), pilha, tamanho);
  solve(inicio+1, tamanho, pilha);
}

int main()
{
    int tamanho;
    char fds;
    int n;
    int arr[31];
    int flag = 0;
    
    while(1){
        tamanho = 1;
        if(flag){
            return 0;
        }
        while(1){
            if(scanf("%i%c", &arr[tamanho], &fds) == EOF){
                flag = 1;
                break;
            }
            
            tamanho++;    
                
            if (fds == '\n')
                break;
        }
        printPilha(tamanho, arr);
        flip(1, arr, tamanho);
        printf("Z");
        solve(1, tamanho, arr);
    }
    return 0;
}