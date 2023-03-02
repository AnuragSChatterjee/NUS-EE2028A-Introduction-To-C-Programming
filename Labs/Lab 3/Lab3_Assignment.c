/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h> //for random number generation
void Print_Arr(int Signal[50], int size) {
    int i;
    for (i = 0;i < size;i++) {
        printf("%d\t",Signal[i]); //Creates new tabs whenever the loop iterates  
        i+=1; //i value increments by 1
        if (i % 10 == 0) {
            printf("%d\n"); //If i is divisible by 10 then a new line should be created else another tab
        }
        else {
            printf("%d \t");
        }
    }
    printf("\n");
}
void Max_Min(int Signal[50],int size) {
    int i;
    int maxvalue,minvalue;
    maxvalue=0;
    minvalue=0;
    for (i=0;i<size;i++) {
        if (Signal[i] > maxvalue) {
        maxvalue = Signal[i];
        }
        if (Signal[i] < minvalue) {
        minvalue = Signal[i];
        }
    }
    printf("Max Signal Value : %d\n",maxvalue);
    printf("Min Signal Value : %d\n",minvalue);
}
int Zero_Bias(int Signal[50],int size) {
    int storingarray[50]; //stores the result array for zeros
    int i;
    int negval[50]; //array storing negative value elements
    int count=0; //number of negative values
    for (i=0;i<size;i++) {
        if ((Signal[i]) >= 0) {
            storingarray[i] = Signal[i]; // if signal value is 0 make it 0 else no
        }
        else {
        storingarray[i] = 0;    
        }
        if (Signal[i] < 0) {
            storingarray[i] = 0;
            count+=1;
            negval[count]=i;//increases negative count for elements below 0
        }
    }
    printf("Negative at indices: \n");
	Print_Arr(negval, count);
	printf("Total number of negative values: %d \n", count);
	Print_Arr(storingarray, 50);
}
int Threshold_Detect_Count(int Signal[50],int size) {
    int exceeded4=0;
    int i;
    int belowminus4=0;
    for (i=0;i<size;i++) {
        if (Signal[i]< -4) { 
        belowminus4+=1;
        }
        else if (Signal[i] > 4) { 
        exceeded4+=1;
        }
    }
    if ((exceeded4 >= 10) && (belowminus4 >= 10)) {
        printf("Original signal category: HPHA");
        printf("\n");
    }
    else if ((exceeded4 <= 9) && (belowminus4 <= 9)) {
        printf("Original signal category: HPLA");
        printf("\n");
        printf("Original signal category: Normal");
        printf("\n");
    }
}
int Missing_Samples(int Signal[50],int arrsize) {
    int i,x;
    int missing[50];
    int missingnumbers = 0;
    for (x=-10;x<=10;x++) {		//finds numbes between -10 and 10
		for (int i = 0; i < arrsize; i++) {		//iterates through Signal array
			if (Signal[i] == x) {					//if number is found, break the loop
				break;
			}
			else if (i == (arrsize - 1)) {	//if the number is found at the end of Signal
				if (Signal[i] != x) {				
					missingnumbers+=1;
					missing[i] = x;	
					break;
				}
			}
		}
	}
	printf("Num.of samples missing in the range[-10, 10]: %d \n", missingnumbers);
	Print_Arr(missing, missingnumbers);
}
int main() {
		/* Intializes random number generator */
		srand(time(NULL));

		int Signal[50];

		for (int i = 0; i < 50; i++) {
			Signal[i] = rand() % 21 - 10;			//each element is a random number from range -10 to 10 (21 numbers inlcuding 0)
		}
    printf("Signal Analysis\n");
    printf("Original Signal\n");
		Print_Arr(Signal, 50);
         
	
		Max_Min(Signal, 50);

	
	  Zero_Bias(Signal, 50);

		

	
		Threshold_Detect_Count(Signal, 50);


		Missing_Samples(Signal, 50);

	
		return 0;
}


    
    
    
    