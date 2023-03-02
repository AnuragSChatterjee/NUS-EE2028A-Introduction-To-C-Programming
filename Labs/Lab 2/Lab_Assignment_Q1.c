/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<ctype.h>
#include<ctype.h>

int main() {
  int balance=1000;
  char input;
  int attempts=0;
  int deposit;
  int withdrawal; 
  printf("Welcome to our Dream Bank!\n");
  printf("Your current balance: %d\n",balance);
  
  printf("==================\n");

  printf("What would you like to do?\n");
  printf("D - Deposit\n");
  printf("W - Withdrawal\n");
  printf("B - Balance Inquiry\n");
  printf("Q - Quit\n");
  
  printf("Please enter:");
  scanf("%c",&input);
  input = toupper(input);
    switch (input) 
  {
    case 'D':
    printf("How much would you like to deposit?\n");
    scanf("%d",&deposit);
    if (deposit % 10 != 0) {
    printf("Unacceptable transcation, deposit only in increments of 10!\n");
    }
    else {
    printf("Transaction approved!");
    balance += deposit;
    printf("Your current balance: %d\n",balance);
    }
    break;
                
    case 'W':
    printf("How much would you like to withdraw?\n");
    scanf("%d",&withdrawal);
    if (balance > withdrawal) {
      if (withdrawal % 10 != 0) {
        printf("Unacceptable transcation, withdrawal only in increments of 10!\n");
        break;
        }
      else if (withdrawal % 10 == 0){
        printf("Transaction approved!");
        balance -= withdrawal;
        printf("Your current balance: %d\n",balance);
        break;
        }
      else {
        printf("Insufficient balance!");
        printf("Your current balance:%d\n",balance);
        break;
        }
      }
      break;
                
    case 'B':
      printf("Your current balance: %d\n",balance);
      break;
        
    case 'Q':
      printf("Your current balance: %d\n",balance);
      printf("Thanks for working with us. Have a nice day!");
      return 0;
        
    default:
      if (attempts >= 3) {
        printf("The number of trials is exceeded, your account is blocked!");
        return 0;
        }
      else {
        attempts ++;
        printf("Invalid option, please enter a valid option!");
        }
      }
    }
  

   
                    
            
    
    

    
    
    
    
    
    
    



   
                    
            
    
    

    
    
    
    
    
    
    


   
                    
            
    
    

    
    
    
    
    
    
    



   
                    
            
    
    

    
    
    
    
    
    
    

