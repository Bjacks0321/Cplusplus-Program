/*Brittney Jackson
Date: 5/19/2023
Description: Create a code to display 12- hour and 24-hour clocks using definitions of functions*/
#include "my_clocksfunctions.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string repeatChar(char c, int count) {
    string result;
    for (int i = 0; i < count; i++) {
        result += c;
    }
    return result;
}

void displayMenu() {
    cout << repeatChar('*', 26) << endl; //The menu header
    cout << "* 1-Add One Hour         *" << endl; // Option 1 displayed
    cout << "* 2-Add One Minute       *" << endl; // Option 2 displayed
    cout << "* 3-Add One Second       *" << endl; // Option 3 displayed
    cout << "* 4-Exit Program         *" << endl; // Option 4 displayed
    cout << repeatChar('*', 26) << endl; // The menu footer
}

void displayTime(int hour12, int min12, int sec12, string ampm, int hour24, int min24, int sec24) {
    cout << repeatChar('*', 26) << "   " << repeatChar('*', 26) << endl; // The header for clocks
    cout << "*      12-Hour Clock     *   *    24-Hour Clock       *\n"; // The clocks format displayed
    cout << "*      ";
    cout << setw(2) << setfill('0') << hour12 << ":"; // Two digits displayed for the hour 
    cout << setw(2) << setfill('0') << min12 << ":"; // Two digits displayed for minutes
    cout << setw(2) << setfill('0') << sec12 << " " << ampm << "       *"; // the second and Am/PM indicator displayed
    cout << "   *    "; // Separator between the two clocks
    cout << setw(2) << setfill('0') << hour24 << ":"; // Two digits displayed for the hour
    cout << setw(2) << setfill('0') << min24 << ":"; // Two digits displayed for mintues
    cout << setw(2) << setfill('0') << sec24 << "            *\n"; // Display seconds
    cout << repeatChar('*', 26) << "   " << repeatChar('*', 26) << endl; // The footer for clocks
}
void addOneHour(int &hour) {
    hour =(hour + 1) % 12; // add one hour and wrap to 1 if the result is 0
    if (hour == 0) { // if the is 0, set the hour t o 12
        hour = 12;
    }
}

void addOneMin(int &min) {
    min = (min + 1) % 60; // add one minute and wrap around to 0 if the result is 60 
}

void addOneSec(int &sec) {
    sec = (sec + 1) % 60; // add one second and wrap around to 0 if the result is 60
}
void updateTime(int &hour12, int &min12, int &sec12, string &ampm, int &hour24, int &min24, int &sec24) {
    // display current time in both 12-hour and 24-hour formats
   displayTime(hour12, min12, sec12, ampm, hour24, min24, sec24);
    // display the menu of options for the user to choose from
   displayMenu();
   cout << "Enter your choice (1-4): ";  // prompt the user to enter their choice and store it in the 'choice' variable
   int choice;
   cin >> choice;

   switch (choice) {
       case 1: // if the user chose option 1, add one hour to both 12-hour and 24-hour clocks
           addOneHour(hour12);
           addOneHour(hour24);
           break;
       case 2: // if the user chose option 2, add one minute to both 12-hour and 24-hour clocks
           addOneMin(min12);
           addOneMin(min24);
           break;
       case 3: // if the user chose option 3, add one second to both 12-hour and 24-hour clocks
           addOneSec(sec12);
           addOneSec(sec24);
           break;
       case 4: // if the user chose option 4, exit the program
           cout << "Exiting program..." << endl;
           exit(0);
       default: // if the user entered an invalid choice, display an error message
           cout << "Invalid choice. Please try again." << endl;
           break;
   }
     // if the 12-hour clock just struck 12:00:00, toggle the AM/PM indicator
   if (hour12 == 12 && min12 == 0 && sec12 == 0) {
       if (ampm == "AM") {
           ampm = "PM";
       } else {
           ampm = "AM";
       }
   }
}

void initializeTime(int &hour12, int &min12, int &sec12, string &ampm, int &hour24, int &min24, int &sec24) {
   int initialHour, initialMin, initialSec;
   cout << "Enter the initial time (HH:MM:SS): "; //Prompt user to Enter the initial time:
   scanf("%d:%d:%d", &initialHour, &initialMin, &initialSec); // Read the input time from the user and store it in variables
   // Assign the initial time values to corresponding variables
   hour12 = initialHour % 12;
   hour24 = initialHour;
   min12 = initialMin;
   min24 = initialMin;
   sec12 = initialSec;
   sec24 = initialSec;
   ampm = (initialHour < 12) ? "AM" : "PM";
}