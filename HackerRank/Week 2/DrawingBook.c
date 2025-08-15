#include <stdio.h>

int main(){
    
    int n, p, front, back;
    scanf("%d", &n);
    scanf("%d", &p);
    
    front = p/2;
    back = n/2 - front;
    
    if(front < back){
        printf("%d", front);
    }else{
        printf("%d", back);
    }
    
    return 0;
}