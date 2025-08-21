#include <stdio.h>

int main(){
    
    int i,m,n, level=0, score;
    scanf("%d", &n);
    int rank[n];
    
    for(int i=0;i<n;i++){
        scanf("%d", &rank[level+1]);
        if(rank[level+1] != rank[level])
            level ++;
    }
    
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        scanf("%d", &score);
        
// If our level is zero then it is only one case when we are rank one then while loop will not execute and it will print rank 1
        while (level && score >= rank[level]) 
            level--;
            printf("%d\n", level+1);
    }
    return 0;
}