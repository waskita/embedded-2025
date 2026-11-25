//  pengujian  FSM untuk user interface

#include <stdio.h>
#include <stdlib.h>
#include "fsm.h"

int main()
{
    printf("%s\n",__FILE__);

    printf("Uji Deteksi Hold 2 detik\n");
    uji_fsm_hold();
    return 0;
}

uji_fsm_hold()
{
    char output_filename[]="hold.csv";

    FILE *out_f ;

    int state;
    int output;
    int input;
    int counter;
    int delay=20; // durasi delay untuk sinyal HOLD

    int k=0; // simulation time
    out_f =fopen(output_filename, "w");
    fprintf(out_f,"k,input,state,counter,output\n");

    FSM_hold_init(&state,&counter,&output);
    input=0;

    for(int k=0; k<50; k++)
    {
        input=0; // default

        if (k>5 && k<30)
        {
            input=1; // bikin sinyal panjang
        }
        if (k>40 && k<45)
        {
            input=1; // bikin sinyal pendek
        }

        FSM_hold(input,&state,&counter,&output,delay);
        fprintf(out_f,"%d,%d,%d,%d,%d\n", k,input,state,counter,output);
    }
}

