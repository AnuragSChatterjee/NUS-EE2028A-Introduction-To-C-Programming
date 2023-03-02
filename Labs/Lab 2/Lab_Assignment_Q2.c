#include <stdio.h>

int Fibonacci(int n)
{
   if (n == 0) {
      return 0;
   }
   else if (n == 1) {
      return 1;
   }
   else {
      return (Fibonacci(n-1) + Fibonacci(n-2));
   }
}

int main() {
  int start,end,i =1,product=0,sum=0,div2=0,div3=0,div5=0;
  int arrayseq[end-start+1];
  printf("Please enter n:");
  scanf("%d",&start);
  printf("Please enter m:");
  scanf("%d",&end);
  printf("=====\n");

  while (start <= end)
  {
    arrayseq[i-1]= Fibonacci(start-1);
    sum += arrayseq[i-1];
    if (i== 1){
      product = arrayseq[i-1] * Fibonacci(start -1);
    }
    else
      product = arrayseq[i-1] * arrayseq[i-2];
    printf("(%d,%d,%d)",i,arrayseq[i-1],product);
    if (product%2==0) {
      printf("(2,");
      div2++;
    }
    else {
      printf("(_,");
    }
    if (product%3==0) {
      printf("3,");
      div3++;
    }
    else {
      printf("_,");
    }
    if (product%5==0) {
      printf("5)");
      div5++;
    }
    else {
      printf("_)");
    }
    printf("\n");
    i ++;
    start ++;
  }
printf("Number of product terms divisible by 2: %d\n",div2);
printf("Number of product terms divisible by 3: %d\n",div3);
printf("Number of product terms divisible by 5: %d\n",div5);
printf("Sum of all Fibonnaci numbers: %d\n",sum);
return 0;
}
  



