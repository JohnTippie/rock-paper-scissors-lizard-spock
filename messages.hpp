#pragma once

#include <cstring>

#include "selection.hpp"

enum message {
    GAME_OPEN,
    USER_SELECTION,
    COMPUTER_SELECTION,
};

enum outcome {
    TIED,
    USER,
    COMPUTER
};

void display_message(message message, selection_t selection);
void display_outcome(outcome winner, selection_t user_choice, selection_t computer_choice);
const char* determine_tag(outcome result, selection_t user_choice, selection_t computer_choice);