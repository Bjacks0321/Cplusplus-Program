/*Brittney Jackson
Date: 5/19/2023
Description: Create a code to display 12- hour and 24-hour clocks using functions*/
#ifndef my_clocksfunctions_h // checks if header file "my_clocksfunctions_h" has already been included 
#define my_clocksfunctions_h // defines the macro "my-clocksfunctions_h" to avoid redefinition
#include <string> // <string> header file using the string data type
// Functions declarations
void displayMenu();
void displayTime(int hour12, int min12, int sec12, std::string ampm, int hour24, int min24, int sec24);
void addOneHour(int &hour);
void addOneMin(int &min);
void addOneSec(int &sec);
void updateTime(int &hour12, int &min12, int &sec12, std::string &ampm, int &hour24, int &min24, int &sec24);
void initializeTime(int &hour12, int &min12, int &sec12, std:: string &ampm, int &hour24, int &min24, int &sec24);
#endif