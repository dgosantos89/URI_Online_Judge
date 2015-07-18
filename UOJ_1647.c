#include <stdio.h>
#include <string.h>
#include <math.h>
  
int main(){
    int n, soma, i, j;
  
    while(scanf("%d", &n) && n){
        long long int m[n], soma;
         
        for(i = 0; i < n; ++i) scanf("%lld", &m[i]);
  
        for(i = n-2; i >= 0; --i){
            for(j = n-1; j > i; --j){
                m[i] += m[j];
            }
        }
        soma = 0;
        for(i = 0; i < n; ++i) soma += m[i];
  
        printf("%lld\n", soma);
    }
}1