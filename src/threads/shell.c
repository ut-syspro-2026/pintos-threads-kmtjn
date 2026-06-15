#include <threads/shell.h>

#include <string.h>
#include <console.h>
#include <stdio.h>
#include "devices/input.h"

#define MAX_INPUT_LEN 64

static char input[MAX_INPUT_LEN + 1];//includes end

//get user input until the user strokes the enter key
static char *get_user_input(void){
    uint8_t ch;//the character user stroked
    int i = 0;//iteration index
    while((i < MAX_INPUT_LEN) && ((ch = input_getc()) != 13)){
        putchar(ch);
        input[i] = (char)ch;
        i++;
    }
    putchar('\n');
    input[i] = 0;//end
    return input;
}

//interpret the user input and take actions
static void parse(char *input){
    if(strcmp(input, "whoami") == 0)
        printf("05261009\n");
    else
        printf("invalid command\n");
}

void start_shell(void){
    while(1){
        printf("PKUOS>");//print a prompt
        char *input = get_user_input();
        if(strcmp(input, "exit") == 0)
            break;
        parse(input);
    }
}