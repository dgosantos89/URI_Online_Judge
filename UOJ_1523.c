#include <stdio.h>
#include <string.h>
#define MAX_PILHA 1001
#define max(A,B) ((A>B) ? (A):(B))

int chegada[100001], saida[100001];
int k;
  
typedef struct pilha {
    int dados[MAX_PILHA];
    int topo;    
} t_pilha;
  
void inicia_pilha(t_pilha *);
void empilha(int, t_pilha *);
void desempilha(t_pilha *);
int pilha_vazia(t_pilha);
int pilha_cheia(t_pilha);
int tamanho(t_pilha);
void mostra_pilha(t_pilha, char *);
  
int main() {
  t_pilha pilha;
  inicia_pilha(&pilha);
  int n, c, s, deu_ruim;
    
  while(1) {
    // lendo
    scanf("%d %d", &n, &k);
    if(!n) break;
      
    // limpando
    memset(chegada, 0, sizeof(chegada));
    memset(saida, 0, sizeof(saida));
    deu_ruim = 0;

    // lendo
    int ultimo_tempo = 0;
    int i;
    for(i=1; i<=n; i++) {
      scanf("%d %d", &c, &s);
      if(c>s)
        deu_ruim = 1;
      chegada[c] = i;
      saida[s] = i;
      ultimo_tempo = max(ultimo_tempo, s+1);
    }
      
    // limpando
    while(!pilha_vazia(pilha)) desempilha(&pilha);
      
  
//processando
int j;
for(j=1;j<ultimo_tempo;j++){
 
  //saida
  if(saida[j]){
    if(pilha_vazia(pilha) || top(pilha) != saida[j]){
      break;
    }
    else{
      desempilha(&pilha);
      //mostra_pilha(pilha, "Saiu");
    }
  }
  
  // chegada
      if(chegada[j]){
        if(tamanho(pilha) < k){
          empilha(chegada[j], &pilha);
          //mostra_pilha(pilha, "Entrou");
        }
        else{
          break;
        }
      }
    }
    if(deu_ruim == 1 || j != ultimo_tempo){
      printf("Nao\n");
    }
    else{
      printf("Sim\n");
    }
  }
}
  
void inicia_pilha(t_pilha *p){
    p->topo = -1;
}
  
int pilha_vazia(t_pilha p){
    return(p.topo == -1);
}
  
int pilha_cheia(t_pilha p){
    return (p.topo == MAX_PILHA-1);
}
  
int tamanho(t_pilha p){
    return p.topo+1;   
}
  
void empilha(int i, t_pilha *p){
    p->topo++;
    p->dados[p->topo] = i;        
}
  
void desempilha(t_pilha *p){
    p->topo--;
}

void mostra_pilha(t_pilha p, char *msg){
    int i;
    printf("\n%s\n", msg);
    if(pilha_vazia(p)){
        printf("Vazia\n\n");
    }
    else{
        for(i=p.topo; i>=0; i--){
            printf("\n%d", p.dados[i]);
        }
        printf("\n\n");
    }
}

int top(t_pilha p) {
      return (p.dados[p.topo]); 
}1