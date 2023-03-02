/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct my_vehicle {
    int vehicle_ID;
    int routes[5]; //Integer of array size 5 
    int vehicle_type; //Integer value
    int vehicle_color; //Integer value 
};

void Vehicles_INIT (struct my_vehicle VehiclesDB []) { //This function would not return anything
    int vehicle_type;
    int vehicle_color;
    int i,j;
    srand(time(NULL));
    for (i=0;i<50;i++) {
        VehiclesDB[i].vehicle_ID = i; //Assign	the	index	value	of	the	current	iteration	as	the	ID	of	that	vehicle.	
        for (j=0;j<5;j++) { //Iterates within array size of 5
            VehiclesDB[i].routes[j] = (rand()%10)+1;
        }
        VehiclesDB[i].vehicle_type = (rand()% 3); //Generates trucks, omni bus, school bus so 3 random number generations
        VehiclesDB[i].vehicle_color = (rand()% 3); //Generates red,blue,green
    }
}

void Vehicle_Search_Normal (struct my_vehicle VehiclesDB []) { //Initializing all variables
    int A_dist_vehicles=0;
    int B_dist_vehicles=0;
    int C_dist_vehicles=0;
    int all_routes_number;
    int routes_7_8_9 = 0;
    int i,j;
    int highest_congested_route = 0,least_congested_route = 0;
    int sum_overall_routes[10] = {0,0,0,0,0,0,0,0,0,0}; //As district A is [1,2,3],district B is [4,5,6,7] and district C is [8,9,10] so I am initializing final results to 0 first
    
    //Generate number of vehicles passing through the different districts 
    for (i=0;i<50;i++){
        for (j=0;j<5;j++) { //As routes in vehiclesDB is an array of size 5
            all_routes_number = VehiclesDB[i].routes[j]; 
            sum_overall_routes[all_routes_number-1] += 1; //Index only runs from 0 to 9 so all_routes_number-1. Storing overall sum values with index of route  
        }
    A_dist_vehicles = sum_overall_routes[0] + sum_overall_routes[1] + sum_overall_routes[2];//As district A is [1,2,3]
    B_dist_vehicles = sum_overall_routes[3] + sum_overall_routes[4] + sum_overall_routes[5] + sum_overall_routes[6];//As district B is [4,5,6,7]
    C_dist_vehicles = sum_overall_routes[7] + sum_overall_routes[8] + sum_overall_routes[9];//As district C is [8,9,10]
    }
    
    // Creating the max and min number of vehicles 
    int maximum_route_number = sum_overall_routes[0]; //From total sum of routes
    int minimum_route_number = sum_overall_routes [0];
    int k;
    for (k=0;k<10;k++) { //Finding max number through all sum of all route numbers which is a total of 10 random nos.
        if (sum_overall_routes[k] > maximum_route_number) {
            maximum_route_number = sum_overall_routes[k];
            highest_congested_route += k;
        }
        else if (sum_overall_routes[k] < minimum_route_number) {
            minimum_route_number = sum_overall_routes[k];
            least_congested_route += k;
        }
    }
    routes_7_8_9 += sum_overall_routes[6] + sum_overall_routes[7] + sum_overall_routes[8];//Index for routes is 1 less
    
    printf("\nNumber of vehicles that go through District_A: %d", A_dist_vehicles);
	printf("\nNumber of vehicles that go through District_B: %d", B_dist_vehicles);
	printf("\nNumber of vehicles that go through District_C: %d", C_dist_vehicles);

	printf("\nHighly congested route: Route %d with %d vehicles", highest_congested_route, maximum_route_number);
	printf("\nLeast congested route: Route %d with %d vehicles",least_congested_route, minimum_route_number);

	printf("\nTotal number of trucks using the routes 7,8,9:", routes_7_8_9);
}

void Vehicle_Search_Using_Pointers (struct my_vehicle *Vehicle_Pointer) { //Initializing all variables
    int A_dist_vehicles=0;
    int B_dist_vehicles=0;
    int C_dist_vehicles=0;
    int all_routes_number;
    int routes_7_8_9 = 0;
    int i,j;
    int highest_congested_route = 0,least_congested_route = 0;
    int sum_overall_routes[10] = {0,0,0,0,0,0,0,0,0,0}; //As district A is [1,2,3],district B is [4,5,6,7] and district C is [8,9,10] so I am initializing final results to 0 first
    
    //Generate number of vehicles passing through the different districts 
    for (i=0;i<50;i++){
        for (j=0;j<5;j++) { //As routes in vehiclesDB is an array of size 5
            all_routes_number = Vehicle_Pointer[i].routes[j]; // As Vehicle Pointer stores vehiclesDB,vehicles[i].routes[j] gives routes
            sum_overall_routes[all_routes_number-1] += 1; //Index only runs from 0 to 9 so all_routes_number-1. Storing overall sum values with index of route  
        }
    A_dist_vehicles = sum_overall_routes[0] + sum_overall_routes[1] + sum_overall_routes[2];//As district A is [1,2,3]
    B_dist_vehicles = sum_overall_routes[3] + sum_overall_routes[4] + sum_overall_routes[5] + sum_overall_routes[6];//As district B is [4,5,6,7]
    C_dist_vehicles = sum_overall_routes[7] + sum_overall_routes[8] + sum_overall_routes[9];//As district C is [8,9,10]
    }
    
    // Creating the max and min number of vehicles 
    int maximum_route_number = sum_overall_routes[0]; //From total sum of routes
    int minimum_route_number = sum_overall_routes [0];
    int k;
    for (k=0;k<10;k++) { //Finding max number through all sum of all route numbers which is a total of 10 random nos.
        if (sum_overall_routes[k] > maximum_route_number) {
            maximum_route_number = sum_overall_routes[k];
            highest_congested_route += k;
        }
        else if (sum_overall_routes[k] < minimum_route_number) {
            minimum_route_number = sum_overall_routes[k];
            least_congested_route += k;
        }
    }
    routes_7_8_9 += sum_overall_routes[6] + sum_overall_routes[7] + sum_overall_routes[8];//Index for routes is 1 less
    
    printf("\nNumber of vehicles that go through District_A: %d", A_dist_vehicles);
	printf("\nNumber of vehicles that go through District_B: %d", B_dist_vehicles);
	printf("\nNumber of vehicles that go through District_C: %d", C_dist_vehicles);

	printf("\nHighly congested route: Route %d with %d vehicles", highest_congested_route, maximum_route_number);
	printf("\nLeast congested route: Route %d with %d vehicles",least_congested_route, minimum_route_number);

	printf("\nTotal number of trucks using the routes 7,8,9:", routes_7_8_9);
}


    
int main()
{
    struct my_vehicle VehiclesDB[50];
    Vehicles_INIT(VehiclesDB);
    struct my_vehicle *Vehicle_Pointer = &VehiclesDB[50];
    Vehicle_Search_Normal(VehiclesDB);
    Vehicle_Search_Using_Pointers(Vehicle_Pointer);
}
