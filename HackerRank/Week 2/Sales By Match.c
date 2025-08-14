#include <stdio.h>

int main(){
    
    int n,i,j,pairs=0,a[101]={0};
    
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d", &j);
        a[j]++;
    }
    
    for (i=0; i<101; i++) {
        pairs = a[i]/2 + pairs;
    }
    
    printf("%d", pairs);
    return 0;
    
}