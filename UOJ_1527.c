#include <stdio.h>
#include <string.h>
 
int P[100100];
int L[100100];
int V[100100];
int rg;
 
int findset(int v) {
    if (P[v] == v) return v;
    return P[v] = findset(P[v]);
}
 
int unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a==b) return 0;
     
    P[b] = a;
    L[a] += L[b];
    V[a] += V[b];
    if (rg==b) rg = a;
}
 
int main() {
    int n, k, i;
    while(scanf("%d %d", &n, &k), n|k) {
        int rw = 0;
        rg = 1;
         
        for(i=1; i<=n; i++) {
            scanf("%d", L+i);            
            P[i] = i;
            V[i] = 0;
        }
        for(i=0; i<k; i++) {
            int q, a, b;
            scanf("%d %d %d", &q, &a, &b);
             
            if (q==1) {
                unionset(a, b);
            } else {
                int fa = findset(a), fb = findset(b);
                if (L[fa] > L[fb]) {
                    V[fa]++;
                    if (rg == fa) rw++;
                }
                if (L[fa] < L[fb]) {
                    V[fb]++;
                    if (rg == fb) rw++;
                }
            }
        }
        printf("%d\n", rw);
    }
}1