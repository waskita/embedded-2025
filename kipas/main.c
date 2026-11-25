#include <stdio.h>
#include <stdlib.h>

#define STATE_OFF 0
#define STATE_H1  1
#define STATE_H1P 2
#define STATE_H2 3
#define STATE_H2P 4
#define STATE_H3 5
#define STATE_H3P 6
#define STATE_H4 7
#define STATE_H4P 8
#define STATE_H5 9
#define STATE_H5P 10
#define STATE_H6 11
#define STATE_H6P 12

#define STATE_TOMBOL_0 1001
#define STATE_TOMBOL_1 1002
#define STATE_TOMBOL_H 1003




void fsm_kipas_init(int *state){
    *state=STATE_OFF;

}


void fsm_kipas_transisi(int *state){
    switch(*state){

    case STATE_H1:{
    break;
    }
    }
}

void fsm_tombol_init(int *state){
    *state=STATE_TOMBOL_0;
}
void fsm_tombol_transisi(int *state, int *counter, int input, int *output_hold, int *output_fall){
                *output_hold=0;
                *output_fall=0;
printf("%d %d\n",*state,input);
    switch (*state)
    {
        case STATE_TOMBOL_0:{
            if(input==1){
                *counter=0;
                *state=STATE_TOMBOL_1;
            }
        break;
        }
        case STATE_TOMBOL_1:{
            if (input==0){
                *output_hold=0;
                *output_fall=1;
                               *state=STATE_TOMBOL_0;

            }
        break;
        }
        case STATE_TOMBOL_H:{
        break;
        }

    }
}

int main()
{
    int i;
    int tombol_state;
    int kipas_state;
    int tombol_counter;
    int tombol_output_hold,tombol_output_fall;
    fsm_tombol_init(&tombol_state);
    fsm_kipas_init(&kipas_state);
//    printf("Hello world!\n");

    // skenario 1
    for (i=0;i<10;i++)
    {
        int input,output=0;
        input=0;
        if(i>4 && i<8)
            input=1;
        fsm_tombol_transisi(&tombol_state,&tombol_counter,input,&tombol_output_hold,&tombol_output_fall);
        printf("%d %d %d\n",i,input,tombol_state);
    }
    // testing
    return 0;


}
