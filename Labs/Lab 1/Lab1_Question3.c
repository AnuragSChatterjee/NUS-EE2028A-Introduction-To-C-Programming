/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
#include<math.h>
  
//I will create a function which would check if a year is a leap year or not 
int leapyear(int year){
  if (year % 400 == 0) {
    return 1;
  }
  else if (year % 100 == 0) {
    return 0;
  }
  else if (year % 4 == 0) {
    return 1;
  }
  else {
    return 0;
  }
}
//I will check the number of days for each month now by a function
int checkmonthdays(int starting_month,int leapyear) {
switch(starting_month) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
  return 31;
  break;
  case 4:
  case 6:
  case 9:
  case 11:
  return 30;
  break;
  case 2:
  if (leapyear == 1) {
    return 29;
  }
  else {
    return 28;
  }
  break;
  }
}

int main() {
//initializing the years, months and days as integers
  int year,month,day;
  int starting_day,input_day,number_days;
  int starting_month;
  int input_year;
  int number_months,number_years;
  number_months = 0;
  number_years = 0;
   
  printf("Your input days:");
  scanf("%d",&input_day);
  printf("days");
  printf("Your starting month:");
  scanf("%d",&starting_month);
  printf("Your starting day:");
  scanf("%d",&starting_day);
  printf("Your input year:");
  scanf("%d",&input_year);
  
  number_days = input_day; 
  
//Now I'll do the calculations on converting days into years, months and integers
while (number_days > checkmonthdays(starting_month, leapyear(input_year))) {
        number_days -= checkmonthdays(starting_month, leapyear(input_year));
        if (starting_month > 11) {
            starting_month = 1;
        }
        else {
            starting_month += 1;  //check the next month
        }
        number_months += 1;   //keep counter of how many months passed 

    }

    number_years = number_months / 12;
    number_months = number_months % 12;

    printf("%d days from %d / %d / %d = %d year %d months %d days", input_day, starting_day, starting_month, input_year, number_years, number_months, number_days);
    return 0;
  
}


  
  
  
  
  
  
