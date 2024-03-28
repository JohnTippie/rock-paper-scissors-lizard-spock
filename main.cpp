#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "messages.hpp"
#include "selection.hpp"
#include "user_choice.hpp"

selection_t users_choice = set_information(UNDEFINED);
selection_t computers_choice = set_information(UNDEFINED);
bool is_quit = false;

outcome evaluate_winner(selection_t users_choice, selection_t computers_choice) {
    if (strcmp(users_choice.name, computers_choice.name) == 0)
        return TIED;
    
    // Loop over "defeats" category of users_choice; If computers_choice.name exists return USER WIN
    for (int i = 0; i < 2; i++) {
        if(strcmp(users_choice.defeats[i][0], computers_choice.name) == 0)
            return USER;
    }
    return COMPUTER;
}

int main() {
    // Seed Random Generator for use with Computer choice
    std::srand(std::time(NULL));

    display_message(GAME_OPEN, users_choice);
    
    // Grab the user Selection and display to screen
    int user_select_int;
    std::cin >> user_select_int;
    selection user_select_enum = input_to_enum(user_select_int);
    users_choice = set_information(user_select_enum);
    display_message(USER_SELECTION, users_choice);

    // Have the computer randomly select and display to screen
    int computer_select_int = 1 + (rand() % 5);
    selection computer_select_enum = input_to_enum(computer_select_int);
    computers_choice = set_information(computer_select_enum);
    display_message(COMPUTER_SELECTION, computers_choice);

    // Evaluate and display win condition
    outcome result = evaluate_winner(users_choice, computers_choice);
    display_outcome(result, users_choice, computers_choice);

    return 0;
}