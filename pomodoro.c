#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>


struct pcycle {
    unsigned int wt;
    unsigned int it;
};
typedef struct pcycle pcycle_t;

static void print_usage(){
    fprintf(stderr,
            "USAGE: pomodoro [NUM] [WT]:[IT]\n"
            "    for NUM cycles with WT minutes of work time and IT minutes of interval time\n"
            "    if no work time and interval time are provided it is assumed that it is 25:5\n"
            "    all numeric arguments that are provided must be integers greater than zero.\n"
            );
}

static pcycle_t str_to_pcycle( char* str ){
    /* returns a {0, 0} cycle if something goes wrong */
    char numbuffer[64];
    pcycle_t cycle = {0, 0};
    unsigned long int comma_pos = 0;
    unsigned long int length = strlen(str);

    for( int i = 0; i < length; i++){
        if( str[i] != ':' && str[i] != '0' && str[i] != '1' && str[i] != '2' &&
            str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' &&
            str[i] != '7' && str[i] != '8' && str[i] != '9'){
            return cycle;
        }
    }

    for(int i = 0; str[i] != ':' && i < length; i++ ){
        numbuffer[i] = str[i];
        comma_pos = i + 2;
    }

    cycle.wt = atoi(numbuffer);
    memset(numbuffer, 0, 64);

    for(int j = comma_pos; j < length; j++){
        numbuffer[j - comma_pos] = str[j];
    }

    cycle.it = atoi(numbuffer);

    return cycle;
}

int main(int argc, char* argv[argc+1]){
    /* check for args */
    if(argc < 2){
        print_usage();
        return EXIT_FAILURE;
    }

    unsigned int cycle_count = atoi(argv[1]);

    if(cycle_count <= 0){
        print_usage();
        return EXIT_FAILURE;
    }

    pcycle_t def_cycle = {25, 5};
    pcycle_t cycle;

    if(argc == 2){
        cycle = def_cycle;
    } else {
        cycle = str_to_pcycle(argv[2]);
        if( cycle.wt == 0 || cycle.it == 0 ){
            print_usage();
        }
    }

    for(int n = 0; n < cycle_count; n++){
        system("date +'work %H:%M'");
        sleep(cycle.wt * 60);
        system("date +'intv %H:%M'");
        sleep(cycle.it * 60);
    }

    return EXIT_SUCCESS;
}
