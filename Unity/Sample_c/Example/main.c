#include <stdio.h>
#include "funprototype.h"

int main()
{

  int n1, n2, addition = 0, subtraction = 0;

  printf("Enter the Number A : ");
  scanf("%d", &n1);

  printf("Enter the Number B : ");
  scanf("%d", &n2);

  addition = add(n1,n2);
  subtraction = sub(n1,n2);

  printf("Additon of Number is : %d \n\n", addition);
  printf("Subtraction of Number is : %d \n\n", subtraction);

  return 0;
}