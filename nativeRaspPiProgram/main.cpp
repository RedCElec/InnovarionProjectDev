//Lets go code the cpp file here for RaspberryPI
#include<iostream>
#include<wiringPi.h>


int main() {

        wiringPiSetup();

        pinMode(7, INPUT);
        int value = digitalRead(7);

        std::cout << value;



return 0;   
}