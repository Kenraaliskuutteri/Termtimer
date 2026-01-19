#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main(){

    void timer_loop(volatile __sig_atomic_t *keep_running);
    
    int secs = 0;
    int mins = 0;
    int hours = 0;

    while ("keep_running")
    {
        secs++;
        mins = secs / 60;
        hours = mins / 60;
        printf("\r%02d: %02d: %02d", hours % 24, mins % 60, secs % 60);

        fflush(stdout);
        sleep(1);

    }
    printf("\nTimer Stopped. \n");
    return 0;
}