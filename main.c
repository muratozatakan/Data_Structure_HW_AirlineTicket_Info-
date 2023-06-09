// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcpy function used in addPassenger functio and also strcmp function used in deletePassenger function

// Struct for passenger
struct passenger {
    char name[50];  // Name of the passenger
    char departure[50]; // Starting point of the journey
    char arrival[50];   // Ending point of the journey
    char date[10]; // Date of the journey
    int seat_number; // Passenger's seat number
    struct passenger* next; // Pointer to the next passenger
};

// Function prototypes
void mainMenu(); // Function for displaying the menu
int checkDuplicate (struct passenger** head, char name[]); // Function for checking if there is a passenger with the same name
void addPassenger (struct passenger** head, char name[], char departure[], char arrival[], char date[], int seat_number); // Function for adding a passenger
void deletePassenger (struct passenger** head, char name[]); // Function for deleting a passenger
void searchPassenger (struct passenger** head, char name[]); // Function for searching a passenger
void displayPassenger(struct passenger** head); // Function for displaying all passengers

struct passenger* head = NULL; // Creating a head pointer

int main() {
    mainMenu(); // Calling the mainMenu function
    return 0;
}

// Function for displaying the menu
// This function will be called in the main function
// This function will be called again if the user wants to continue to main menu
// This function will be called again if the user enters an invalid choice
void mainMenu(){
    char name[50], departure[50], arrival[50], date[10]; // Variables for passenger's info
    int seat_number; // Variable for passenger's seat number
    int user_choice, user_end_choice; // Variables for user's choice
     // Printing the menu
        printf("Press 1 to add passenger\n");
        printf("Press 2 to delete passenger\n");
        printf("Press 3 to search for passenger by name\n");
        printf("Press 4 to display all passengers\n");
        printf("Press 5 for exit\n");
        printf("Enter your choice: "); // Getting the user's choice
        scanf("%d", &user_choice); // Storing the user's choice

        // If else statements for user's choice
        // If user's choice is 1 this codeblock will be executed
        // addPassenger function will be called
        if (user_choice == 1) {
            printf("Enter the name of the passenger\n"); // Getting the passenger's name
            printf("Enter the name with _ instead of space: "); // Informing the user about the name format
            scanf("%s", name); // Storing the passenger's name
            printf("Enter the departure of the passenger: "); // Getting the passenger's departure
            scanf("%s", departure); // Storing the passenger's departure
            printf("Enter the arrival of the passenger: "); // Getting the passenger's arrival
            scanf("%s", arrival); // Storing the passenger's arrival
            printf("Enter the date of the passenger\n"); // Getting the passenger's date
            printf("Enter the without . like 14.05.2023 enter 14052023: "); // Informing the user about the date format
            scanf("%s", date); // Storing the passenger's date
            printf("Enter the seat number of the passenger: "); // Getting the passenger's seat number
            scanf("%d", &seat_number); // Storing the passenger's seat number
            addPassenger(&head, name, departure, arrival, date, seat_number); // Calling the addPassenger function
            printf("Do you want to continue to main menu? (1 for yes, 0 for no)\n"); // Asking the user if they want to continue to main menu
            scanf("%d", &user_end_choice); // Getting the user's choice
            // If else statments for user's choice
            // If user's choice is 1 this codeblock will be executed
            // mainMenu function will be called
            if (user_end_choice == 1){
                mainMenu(); // Calling the mainMenu function
            }
            // If user's choice is 0 this codeblock will be executed
            // The program will be terminated
            else if (user_end_choice == 0){
                printf("Exiting...\n"); // Exit message will be printed
                return; // Breaking the while loop
            }
            // If user's choice is not 0 or 1 this codeblock will be executed
            else {
                printf("Invalid choice!\n"); // Printing the error message
                mainMenu(); // Calling the mainMenu function
            }
            
        } 
        // If user's choice is 2 this codeblock will be executed
        // deletePassenger function will be called
        else if (user_choice == 2) {
            printf("Enter the name of the passenger\n"); // Getting the passenger's name
            printf("If passenger's name entered with _ enter with _\n"); // Informing the user about the name format
            printf("Like Name_Surname: "); // Informing the user about the name format
            scanf("%s", name); // Storing the passenger's name 
            deletePassenger(&head, name); // Calling the deletePassenger function
            printf("Do you want to continue to main menu? (1 for yes, 0 for no)\n"); // Asking the user if they want to continue to main menu
            scanf("%d", &user_end_choice); // Getting the user's choice
            // If else statments for user's choice
            // If user's choice is 1 this codeblock will be executed
            // mainMenu function will be called
            if (user_end_choice == 1){
                mainMenu(); // Calling the mainMenu function
            }
            // If user's choice is 0 this codeblock will be executed
            // The program will be terminated
            else if (user_end_choice == 0){
                printf("Exiting...\n"); // Exit message will be printed
                return; // Breaking the while loop
            }
            // If user's choice is not 0 or 1 this codeblock will be executed
            else {
                printf("Invalid choice!\n"); // Printing the error message
                mainMenu(); // Calling the mainMenu function
            }
        } 
        // If user's choice is 3 this codeblock will be executed
        // searchPassenger function will be called
        else if (user_choice == 3) {
            printf("Enter the name of the passenger\n"); // Getting the passenger's name
            printf("If passenger's name entered with _ enter with _\n"); // Informing the user about the name format
            printf("Like Name_Surname: "); // Informing the user about the name format
            scanf("%s", name); // Storing the passenger's name
            searchPassenger(&head, name); // Calling the searchPassenger function
            printf("Do you want to continue to main menu? (1 for yes, 0 for no)\n"); // Asking the user if they want to continue to main menu
            scanf("%d", &user_end_choice); // Getting the user's choice
            // If else statments for user's choice
            // If user's choice is 1 this codeblock will be executed
            // mainMenu function will be called
            if (user_end_choice == 1){
                mainMenu(); // Calling the mainMenu function
            }
            // If user's choice is 0 this codeblock will be executed
            // The program will be terminated
            else if (user_end_choice == 0){
                printf("Exiting...\n"); // Exit message will be printed
                return; // Breaking the while loop
            }
            // If user's choice is not 0 or 1 this codeblock will be executed
            else {
                printf("Invalid choice!\n"); // Printing the error message
                mainMenu(); // Calling the mainMenu function
            }            
        } 
        // If user's choice is 4 this codeblock will be executed
        // displayPassengers function will be called
        else if (user_choice == 4) {
            displayPassenger(&head); // Calling the displayPassengers function
            printf("Do you want to continue to main menu? (1 for yes, 0 for no)\n"); // Asking the user if they want to continue to main menu
            scanf("%d", &user_end_choice); // Getting the user's choice
            // If else statments for user's choice
            // If user's choice is 1 this codeblock will be executed
            // mainMenu function will be called
            if (user_end_choice == 1){
                mainMenu(); // Calling the mainMenu function
            }
            // If user's choice is 0 this codeblock will be executed
            // The program will be terminated
            else if (user_end_choice == 0){
                printf("Exiting...\n"); // Exit message will be printed
                return; // Breaking the while loop
            }
            // If user's choice is not 0 or 1 this codeblock will be executed
            else {
                printf("Invalid choice!\n"); // Printing the error message
                mainMenu(); // Calling the mainMenu function
            }
        } 
        // If user's choice is 5 this codeblock will be executed
        // The program will be terminated
        else if (user_choice == 5) {
            printf("Exiting...\n"); // Exit message will be printed
            return; // Breaking the while loop
        } 
        
        else { // If user's choice is not between 1 and 5, then the program will print an error message
            printf("Invalid choice!\n"); // Printing the error message
            mainMenu(); // Calling the mainMenu function
        }


}

int checkDuplicate (struct passenger** head, char name[]) {
    struct passenger* temp = *head; // Creating a temporary passenger
    // While loop for checking if there is a passenger with the same name
    // If there is a passenger with the same name, then the function will return 1
    while(temp != NULL) {
        // If there is a passenger with the same name, then the function will return 1
        if (strcmp(temp->name, name) == 0) {
            return 1;
        }
        temp = temp->next; // Going to the next passenger
    }
    return 0; // If there is no passenger with the same name, then the function will return 0
}

// This function is adding a new passenger to the linked list
// This function is taking the head of the linked list, name, departure, arrival, date and seat number as parameters
void addPassenger (struct passenger** head, char name[], char departure[], char arrival[], char date[], int seat_number) {
    // If statement is checking if there is a passenger with the same name
    // If there is a passenger with the same name, then the function will return
    if(checkDuplicate(head, name) == 1) {
        printf("There is already a passenger with the same name!\n"); // Printing the error message
        return; // Breaking the function
    }

    struct passenger* new_passenger = (struct passenger*) malloc(sizeof(struct passenger)); // New passenger will be created
    strcpy(new_passenger->name, name); // Copy the name entered by the user to the new passenger's name
    strcpy(new_passenger->departure, departure); // Copy the departure entered by the user to the new passenger's departure
    strcpy(new_passenger->arrival, arrival); // Copy the arrival entered by the user to the new passenger's arrival
    strcpy(new_passenger->date, date); // Copy the date entered by the user to the new passenger's date
    new_passenger->seat_number = seat_number; // Copy the seat number entered by the user to the new passenger's seat number


    // If statement is checking if the linked list is empty or not
    if (*head == NULL) {
        *head = new_passenger; // If linked list is empty then the new passenger will be the first node of the linked list
    }

    else {
        struct passenger* last_node = *head; // Creating a new node for the finding the last node of the linked list

        // While loop for finding the last node of the linked list
        while (last_node->next != NULL) {
            last_node = last_node->next; // Last node will be the next node
        }

        last_node->next = new_passenger; // The next node of the last node will be the new passenger
    }
    printf("Passenger named %s has been added successfully.\n", name); // Printing the success message with the passenger's name    
}

// This function is for deleting a passenger from the linked list
// This function takes two parameters
// The first parameter is the head of the linked list
// The second parameter is the name of the passenger that will be deleted
void deletePassenger (struct passenger** head, char name[]) {
    struct passenger* current = *head; // Creating a new node for the current node
    struct passenger* prev = NULL; // Creating a new node for the previous node

    // The loop continues as long as the current node is not NULL
    // So the loop will continue until the end of the linked list
    while (current != NULL) {
        // If statement is checking if the name entered by the user is equal to the name of the current node
        // The strcmp() compares two strings character by character. If the strings are equal, the function returns 0
        if(strcmp(current->name, name) == 0) {
            // If current->name is equal to name, then the current node will be deleted
            printf("Passenger named %s has been deleted successfully.\n", name); // Printing the success message with the passenger's name
            if(prev == NULL) {
                *head = current->next; // The next node of the current node will be the head node
            }
            //If the current node's name does not match, we need to continue iterating through the list to look for a matching node
            else {
                prev->next = current->next;
            }
            free(current); // Deallocates the memory used by the node that matches the input name
            return;
        }
        prev = current; // The previous node will be the current node
        current = current->next; // The current node will be the next node
    }
    // If the name entered by the user does not match any of the names in the list, then the function will print an error message
    printf("There is no passenger named %s\n", name); // Printing the error message
}
 // Function for displaying the passengers
 // This function takes the head node as a parameter
 // The head node is the first node of the linked list
void searchPassenger (struct passenger** head, char name[]) {
    struct passenger* temp = *head; // Creating a new node for the temporary node

    // The loop continues as long as the temp node is not NULL
    // So the loop will continue until the end of the linked list
    while (temp != NULL) {
        // If statement is checking if the name entered by the user is equal to the name of the temp node
        // The strcmp() compares two strings character by character. If the strings are equal, the function returns 0
        if(strcmp(temp->name, name) == 0) {
            printf("Name: %s\n", temp->name); // Printing the name of the passenger
            printf("Departure: %s\n", temp->departure); // Printing the departure of the passenger
            printf("Arrival: %s\n", temp->arrival); // Printing the arrival of the passenger
            printf("Date: %s\n", temp->date); // Printing the date of the passenger
            printf("Seat Number: %d\n", temp->seat_number); //
            return;
        }
        temp = temp->next; // The temp node will be the next node
    }
    printf("Passenger named %s does not exist.\n", name); // If the passenger does not exist, then the program will print an error message
}

// Function for displaying the passengers
// This function takes the head node as a parameter
void displayPassenger(struct passenger** head) {
    struct passenger* temp = *head; // Creating a new node for the temporary node
    
    // If statement is checking if the head node is NULL or not
    // If head node is NULL, then the linked list is empty
    if(head == NULL) {
        printf("There is no passenger in the list.\n"); // Printing the error message
        return; // Breaking the function
    }
    // If head node is not NULL, then the linked list is not empty
    // The loop continues as long as the temp node is not NULL
    // So the loop continues until the end of the linked list
    while(temp != NULL) {
        printf("Name: %s\n", temp->name); // Printing the name of the passenger
        printf("Departure: %s\n", temp->departure); // Printing the departure of the passenger
        printf("Arrival: %s\n", temp->arrival); // Printing the arrival of the passenger
        printf("Date: %s\n", temp->date); // Printing the date of the passenger
        printf("Seat Number: %d\n", temp->seat_number); // Printing the seat number of the passenger

        temp = temp->next; // The temp node will be the next node
    }
}