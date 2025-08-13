#include <stdio.h>

int main(){
    int d,m,n,i,j,p=0;
    
    scanf("%d",&n);
    
    int s[n];
    for (i=0; i<n; i++)
        scanf("%d", &s[i]);
        scanf("%d%d", &d,&m);
    
    for (i=0; i<n; i++) {
        int sum=0;
        for (j=0; j<m; j++) 
            sum = sum + s[i+j];
            if (sum == d){ 
                p++;
            }
    }
    printf("%d",p);
    return 0;
}