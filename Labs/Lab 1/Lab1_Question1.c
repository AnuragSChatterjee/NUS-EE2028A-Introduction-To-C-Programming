/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<math.h>
#define PI 3.14f
int main() //Debugging Exercise
{
    printf("Debugging Exercise \n");
    float radius_cylinder, radius_cone, height_cylinder, _height_cone;
    float CYLINDER_Volume, CONE_Volume;
    float CONE_SA, CONE_SA_bottom;
    float CYLINDER_BSA, CYLINDER_LSA;
    float SA_large_bottom_cone, SA_small_bottom_cone, circumference_cylinder;
    float SA_large_BC, SA_small_BC;
    
    printf("Please enter the height of a cylinder:");
    scanf("%f",&height_cylinder);
    printf("Please enter the radius of a cylinder:");
    scanf("%f",&radius_cylinder);
    _radius_cone = radius_cylinder*2;
    _height_cone = height_cylinder/2;
//##########################################VOLUME############################################
    CYLINDER_Volume = PI * radius_cylinder * height_cylinder;
    CONE_Volume = (1.0/3) * PI * _radius_cone * _radius_cone * _height_cone;
    printf("Volume of a cylinder = %.3f\n",CYLINDER_Volume);
    printf("Volume of a cone is: %.3f\n",CONE_Volume);
    printf("Total volume of the arrow is: %.3f\n",(CONE_Volume+CYLINDER_Volume));
//######################################CYLINDER AREA#########################################
    CYLINDER_BSA = PI * pow(radius_cylinder,2);
    printf("Bottom surface area of a cylinder = %.3f\n",CYLINDER_BSA);
    circumference_cylinder = 2 * PI * radius_cylinder;
    CYLINDER_LSA = circumference_cylinder * height_cylinder;
    printf("Lateral Surface Area of a cylinder = %.3d\n",CYLINDER_LSA);
//######################################CONE AREA#############################################
    CONE_SA = PI * _radius_cone * sqrt(_radius_cone * _radius_cone + _height_cone * _height_cone);
    SA_large_BC = PI * _radius_cone * _radius_cone;
    SA_small_BC = PI * radius_cylinder * radius_cylinder;
    CONE_SA_bottom = SA_large_bottom_cone - SA_small_bottom_cone;
    printf("Surface area of a cone is %.3f, Surface bottom area of a cone is %.3f \n",CONE_SA,CONE_SA_bottom);
//#################################TOTAL AREA OF THE ARROW############################################# 
    printf("Total area of the arrow is %.3f \n",(CONE_SA+CONE_SA_bottom+CYLINDER_LSA+CYLINDER_BSA));
return 0;
}



