/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<math.h>
int main()
{
//initializing n value, hydrogen atomic number, i value for loop as integers and energy, energy difference and k value as float
    int orbit,atomic_number=1;
    int i;
    double energy,energy_difference,k=2.179e-18;
    printf("The atomic number of the hydrogen %d, the Rydberg constant %g J\n",atomic_number,k);
    scanf("%d%d%d%g%g%g",&orbit,&atomic_number,&i,&energy,&energy_difference,&k);
    
//first loop to calculate E(n) of the orbits of values n represented as integers i
    for (i=1;i<7;i++) {
        energy = -(k * (atomic_number*atomic_number))/(i*i);
        printf("Energy of the electron when n=%d is E(%d) = %g J\n",energy,i);
    }
    printf("\n");
//second loop to calculate energy difference of the orbits of values n represented as integers i 
    for (i=1;i<6;i++) {
        energy_difference = -(k * (atomic_number*atomic_number))/((i+1)*(i+1)) - -(k * (atomic_number*atomic_number))/((i)*(i));
        printf("Energy difference between levels %d-%d: E(%d) - E(%d) = %g J\n",energy_difference,i+1,i,i+1,i);
    }
return 0;
}



