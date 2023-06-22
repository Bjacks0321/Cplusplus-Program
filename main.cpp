/*Brittney Jackson
Date: 5/19/2023
Description: Create a code to display 12- hour and 24-hour clocks*/

#include <iostream>
#include <iomanip>
#include <string>
#include "my_clocksfunctions.h"

using namespace std;


int main() {
    int hour12, min12, sec12, hour24, min24, sec24;
    string ampm;
    initializeTime(hour12, min12, sec12, ampm, hour24, min24, sec24); // Initialize the time variables
    
    while (true) {
        updateTime(hour12, min12, sec12, ampm, hour24, min24, sec24); // Update the time variables
    }

    return 0; // reutrn 0, the program was executed successfully
}