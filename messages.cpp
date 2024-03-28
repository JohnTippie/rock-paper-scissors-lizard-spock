#include <iostream>

#include "messages.hpp"

const char* game_open = "Welcome to Rock-Paper-Scissors-Lizard-Spock! "
                        "This is a fictional game based on the TBS show 'The Big Bang Theory'.\n"
                        "The gameplay is identical to standard Rock-Paper-Scissors \n"
                        "with the execption that there are 2 additional selectables: Lizard and Spock.\n"
                        "The rules as follows as explained by the character Sheldon Cooper:\n"
                        "Scissors cuts paper,\n"
                        "paper covers rock,\n"
                        "rock crushes lizard,\n"
                        "lizard poisons Spock,\n"
                        "Spock smashes scissors,\n"
                        "scissors decapitates lizard,\n"
                        "lizard eats paper,\n"
                        "paper disproves Spock,\n"
                        "Spock vaporizes rock,\n"
                        "and as it always has, rock crushes scissors.\n"
                        "Select your choice:\n"
                        "1. Rock\n"
                        "2. Paper\n"
                        "3. Scissors\n"
                        "4. Lizard\n"
                        "5. Spock\n";

const char* determine_tag(outcome result, selection_t user_choice, selection_t computer_choice) {
    if (result == USER) {
        for (int i = 0; i < 2; i++) {
            if(strcmp(user_choice.defeats[i][0], computer_choice.name) == 0)
                return user_choice.defeats[i][1];
        }
    } else {
        for (int i = 0; i < 2; i++) {
            if(strcmp(computer_choice.defeats[i][0], user_choice.name) == 0)
                return computer_choice.defeats[i][1];
        }
    }
    return "undefined";
}

void display_message(message message, selection_t selection) {
    
    switch (message) {
        case GAME_OPEN:
            (void) selection;
            std::cout << game_open << std::endl;
            break;

        case USER_SELECTION:
            if (strcmp(selection.name, "undefined") == 0) {
                (void)selection;
                std::cout << "You have made an invalid selection. Please use a number from 1 to 5." << std::endl;
                break;
            }

            std::cout << "You have selected: " << selection.name << std::endl;
            break;
        
        case COMPUTER_SELECTION:
            std::cout << "The computer selected: " << selection.name << std::endl;
            break;

        default:
            break;
    }

}

void display_outcome(outcome winner, selection_t user_choice, selection_t computer_choice) {

    const char* tag = determine_tag(winner, user_choice, computer_choice);

    switch (winner) {
        case TIED:
            (void) user_choice;
            (void) computer_choice;
            std::cout << "You and the computer have tied!" << std::endl;
            break;
        
        case USER:
            std::cout << user_choice.name << " " << tag << " " << computer_choice.name << std::endl;
            std::cout << "You have beat the computer!" << std::endl;
            break;

        case COMPUTER:
            std::cout << computer_choice.name << " " << tag << " " << user_choice.name << std::endl;
            std::cout << "The computer has beaten you!" << std::endl;
            break;
        
        default:
            break;
    }
}