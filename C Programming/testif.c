#include <stdio.h>
int main(){
  int x;
  printf("Enter the number you want to check +ve or -ve : ");
  scanf("%d", &x);

  if(x>0){
    printf("The number %d is +ve" ,x);
  }
  else 
  printf("The number %d is -ve", x);

  return 0;
}