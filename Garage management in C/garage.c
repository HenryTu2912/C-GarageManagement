//
// Created by hungt on 2023-03-31.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "garage.h"
/*
Purpose: Dynamically allocates a string to store a vehicle's information. Specifically, the value and model year
are stored in the first 4 bytes. The remaining memory is for the description of the vehicle.
Parameters : None
Returns: a dynamically allocated block of memory containing the vehicle's information
*/
char* createVehicle()
{
    //Declare char * vehicle and allocated an amount block memory
    char * vehicle = (char *) malloc(sizeof (int) + sizeof (char) * 256);
    if(vehicle)
    {
        //Declare variable to contain value, year, and description of the vehicle from user input
        unsigned int value = 0;
        unsigned int year = 0;
        char * desc = (char *) malloc(256);
        //Declare the int variable to contain the year and value of vehicle and assign to variable
        unsigned int rs = 0;
        //Prompt user to input value, year, and description of the vehicle
        printf("Please enter the value of your vehicle: \n");
        scanf_s("%d", &value);
        while(value > 2097151)
        {
            printf("Please re-enter the value of your vehicle from (0-2097151): \n");
            scanf_s("%d", &value);
        }
        printf("Please enter the year of your vehicle: \n");
        scanf_s("%d", &year);
        while(year > 2047)
        {
            printf("Please re-enter the year of your vehicle from (0-2047): \n");
            scanf_s("%d", &year);
        }
        printf("Enter the description of your vehicle: \n");
        getc(stdin);
        fgets(desc, 256, stdin);
        //Use bit operation to combine value and year or vehicle
        rs = (value<<11) | year;
        //Copy each byte of value, year, and description in the variable to the vehicle
        memcpy_s(vehicle,sizeof (int),&rs, sizeof (int));
        memcpy_s(vehicle+sizeof (int), 256, desc, 256);
        //Free memory for description
        free(desc);
//        printf("Size of desc: %d\n", sizeof (desc));
//        printf("Test desc: %s\n", (char*)(vehicle+sizeof (int)));
    }
    return vehicle;
}

/*
Purpose: Display the information stored in a vehicle
Parameters: char* representing all information stored for a vehicle
Returns: Nothing
*/
void displayVehicle(char* vehicle)
{
    //Declare the variable to contain value and year of vehicle
    unsigned int info = 0;
    //Copy the data from vehicle to the info variable
    memcpy_s(&info,sizeof (int),vehicle, sizeof (int));
    //Print the information of the vehicle
    printf("The value is %d and the year is %d\n", info>>11, (info<<21)>>21);
//    printf("The value is %d and the year is %d\n", (info & 0xfffff800)>>11, info & 0x7ff);
    printf("The description of the vehicle is: %s\n", (char*)(vehicle+sizeof (int)));
}

/*
Purpose: Store multiple vehicles in an array. Dynamically allocates an array of char pointers.
Calls the createVehicle method for each vehicle to be created
Parameters: int - Number of vehicles to add to the array
Returns: a dynamically array of char*'s, each pointer representing a vehicle
*/
char** createGarage(int num)
{
    //Declare the garage variable as double pointer
    char ** garage = (char **) malloc(num * (sizeof (int) + sizeof (char) * 256));
    //Loop to create vehicle in the garage
    for(int i = 0; i < num; i++)
    {
        garage[i] = createVehicle();
    }
    return garage;
}

/*
Purpose: Display all the information stored for each vehicle in the garage. Calls
displayVehicle for each vehicle in the garage.
Parameters: char** - pointer to the garage
int - number of vehicles in the garage
Returns: Nothing.
*/
void displayGarage(char** garage, int num)
{
    //Loop to print the information of vehicle in the garage using displayVehicle method
    for(int i = 0; i < num; i++)
    {
        printf("Vehicle number: %d\n", i+1);
        displayVehicle(garage[i]);
        printf("+++++++++++++++++++++++++++++++++\n");
    }
}

/*
Purpose: Remove a vehicle from the garage. Returns a new dynamically allocated garage with remaining cars stored in it.
Note that this function should free the garage passed in.
Parameters:  char** - pointer to current garage
int - number of vehicles in current garage
int - index of the vehicle to remove (0 based)
Returns: a reference to the new dynamically allocated garage
*/
char ** removeVehicle(char** garage, int curNum, int index)
{
    //Create a new allcated garage
    char ** newGarage = (char **) malloc(curNum * (sizeof (int) + sizeof (char) * 256));
    //Loop to copy each vehicle in the old garage except the vehicle at the removed index
    for(int i=0;i<curNum;i++)
    {
        if(i<index)
        {
            *(newGarage+i) = *(garage+i);
        }
        if(i>=index)
        {
            *(newGarage+i) = *(garage+i+1);
        }
    }
    return newGarage;
}