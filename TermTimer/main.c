#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
//removed the time library since it was unused
char *clearcomm = "clear";


static const char *BIG_DIGITS[11][5] = {
    {" ██ ","█  █","█  █","█  █"," ██ "},
    {"  █ "," ██ ","  █ ","  █ "," ███"},
    {" ██ ","█  █","  ██"," █  ","████"},
    {" ██ ","█  █","  ██","█  █"," ██ "},
    {"█  █","█  █","████","   █","   █"},
    {"████","█   ","███ ","   █","███ "},
    {" ██ ","█   ","███ ","█  █"," ██ "},
    {"████","   █","  █ "," █  "," █  "},
    {" ██ ","█  █"," ██ ","█  █"," ██ "},
    {" ██ ","█  █"," ███","   █"," ██ "},
    {"    "," ██ ","    "," ██ ","    "}
};

void print_big_time(int hours, int mins, int secs){
    char buf[9];
    snprintf(buf, sizeof(buf), "%02d:%02d:%02d", hours, mins, secs);

    printf("\033[2J\033[H");
    printf("\033[1m");

    for (int row = 0; row < 5; ++row){
        for (size_t i = 0; i < strlen(buf); ++i){
            char c = buf[i];
            int idx = 0;
            if (c == ':') idx = 10; else idx = c - '0';
            printf("%s  ", BIG_DIGITS[idx][row]);
        }
        printf("\n");
    }

    printf("\033[0m\n");
}

int main(){
    int secs = 0;
    int mins = 0;
    int hours = 0;
    
    #ifdef _WIN32
    clearcomm = "cls";
    #endif

    while (1)
    {
        secs++;
        mins = secs / 60;
        hours = mins / 60;
        print_big_time(hours % 24, mins % 60, secs % 60);
        fflush(stdout);
        sleep(1);
        system(clearcomm);
    }

    return 0;
}
