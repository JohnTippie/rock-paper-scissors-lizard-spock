#include "selection.hpp"

selection_t set_information(selection choice) {

    selection_t result = {
        .name = "undefined",
        .defeats = "undefined"
    };

    switch (choice){
        case ROCK:
            return result = {
                .name = "rock",
                .defeats = {
                    {"scissors", "crushes"},
                    {"lizard", "crushes"}
                }
            };
            break;

        case PAPER:
            return result = {
                .name = "paper",
                .defeats = {
                    {"rock", "covers"},
                    {"spock", "disproves"}
                }
            };
            break;

        case SCISSORS:
            return result = {
                .name = "scissors",
                .defeats = {
                    {"paper", "cuts"},
                    {"lizard", "decapitates"}
                }
            };
            break;

        case LIZARD:
            return result = {
                .name = "lizard",
                .defeats = {
                    {"spock", "poisons"},
                    {"paper", "eats"}
                }
            };
            break;

        case SPOCK:
            return result = {
                .name = "spock",
                .defeats = {
                    {"rock", "vaporizes"},
                    {"scissors", "smashes"}
                }
            };
            break;
            
        default:
            return result;
            break;
    }
}

selection input_to_enum(int choice) {
    
    switch (choice) {
        case 1:
            return ROCK;
            break;
        case 2:
            return PAPER;
            break;
        case 3:
            return SCISSORS;
            break;
        case 4:
            return LIZARD;
            break;
        case 5:
            return SPOCK;
            break;
        default:
            return UNDEFINED;
            break;
    }
}