#include <stdio.h>
#include <string.h>
 
 
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); } 
 
int main(){
 int n,a,b;
 while(1){
  scanf("%d", &n);
  if (n){
   scanf("%d %d", &a, &b);
    
   int total = (n/a) + (n/b) - (n/lcm(a,b));
   printf("%d\n", total);
  }else break;
 }
 return 0;
}1