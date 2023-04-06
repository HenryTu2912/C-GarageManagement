#include <stdio.h>
#include "garage.h"
#include "stdlib.h"


void testGarage() {
    //Number of vehicles to add to the garage
    int numVehicles;

    //Prompt the user to enter how many vehicles to store
    printf("Enter number of vehicles you would like to store: ");
    scanf_s("%d", &numVehicles);

    //Must clear the input stream from newline
    getc(stdin);

    //Create a new garage
    char **garage = createGarage(numVehicles);
    //Display the contents of the garage
    displayGarage(garage, numVehicles);

    printf("The garage after deleted the vehicle at index 1\n");
    //Remove a vehicle
    garage = removeVehicle(garage, numVehicles--, 1);
    //Display the contents of the garage
    displayGarage(garage, numVehicles);
    for(int i = 0; i < numVehicles; i++){
        free(garage[i]);
    }
    free(garage);
}

int main(int argc, char ** argv) {
    testGarage();
}
