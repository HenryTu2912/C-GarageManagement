//
// Created by hungt on 2023-03-31.
//

#ifndef TU4422HO4847COSC292A2_GARAGE_H
#define TU4422HO4847COSC292A2_GARAGE_H
char* createVehicle();
void displayVehicle(char* vehicle);
char** createGarage(int num);
void displayGarage(char** garage, int num);
char ** removeVehicle(char** garage, int curNum, int index);
#endif //TU4422HO4847COSC292A2_GARAGE_H
