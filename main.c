#include <stdio.h>
#include <stdlib.h>

// Struct for passenger
struct passenger {
    char name[50];  // Name of the passenger
    char departure[50]; // Starting point of the journey
    char arrival[50];   // Ending point of the journey
    char date[10]; // Date of the journey
    int seat_number; // Passenger's seat number
    struct passenger* next; // Pointer to the next passenger
};

struct passenger* head = NULL; // Creating a head pointer


int main() {

    return 0;
}