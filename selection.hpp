#pragma once

enum selection {
    ROCK,
    PAPER,
    SCISSORS,
    LIZARD,
    SPOCK,
    UNDEFINED
};

typedef struct {
    const char* name;
    const char* defeats[2][2]; 
} selection_t;

selection_t set_information(selection choice);
selection input_to_enum(int choice);