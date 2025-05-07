//  pengujian  FSM untuk lampu geser

#include <stdio.h>
#include <stdlib.h>
#include "fsm.h"

int main()
{
    printf("%s\n",__FILE__);
    uji_fsm_debounce();
    uji_fsm_geser();
    uji_fsm_edge_detect();
    return 0;
}

uji_fsm_debounce()
{
    char output_filename[]="debounce.csv";

    FILE *out_f ;

    int state;
    int output;
    int input;
    int counter;
    int delay=10; // durasi delay untuk debounce

    int k=0; // simulation time
    out_f =fopen(output_filename, "w");
    fprintf(out_f,"k,input,state,counter,output\n");

    FSM_debounce_init(&state,&counter,&output);
    input=0;

    for(int k=0; k<50; k++)
    {
        input=0; // default

        if(k==5)  // bikin bounce bbrp
        {
            input=1;
        }

        if(k==7)  // bikin bounce bbrp
        {
            input=1;
        }


        if(k>8 && k<20)
        {
            input=1;
        }
// #bounce again

        if(k==22)  // bikin bounce bbrp
        {
            input=1;
        }
        if(k==25)  // bikin bounce bbrp
        {
            input=1;
        }
        if(k>40)
        {
            input=1;
        }

        FSM_debounce(input,&state,&counter,&output,delay);
        fprintf(out_f,"%d,%d,%d,%d,%d\n", k,input,state,counter,output);
    }
}

void uji_fsm_edge_detect()
{
    char output_filename[]="edge.csv";

    FILE *out_f ;
    int edge_state;
    int edge_output;
    int edge_input;

    int k=0; // simulation time
    out_f =fopen(output_filename, "w");
    fprintf(out_f,"k,edge_input,edge_state,edge_output\n");

    FSM_edge_detect_init(&edge_state,&edge_output);
    edge_input=0;

    for(int k=0; k<30; k++)
    {
        edge_input=0; // default

        if(k>3 && k<7)
        {
            edge_input=1;
        }

        if(k>11 && k<15)
        {
            edge_input=1;
        }
        if(k>18 && k<23)
        {
            edge_input=1;
        }

        FSM_edge_detect(edge_input,&edge_state,&edge_output);
        fprintf(out_f,"%d,%d,%d,%d\n", k,edge_input,edge_state,edge_output);
    }
}

void uji_fsm_geser()
{
    char output_filename[]="geser.csv";

    FILE *out_f ;
    int geser_state;
    int geser_output;
    int geser_input_kiri;
    int geser_input_kanan;
    int k=0; // simulation time
    out_f =fopen(output_filename, "w");
    fprintf(out_f,"k,geser_input_kiri,geser_input_kanan,geser_state,geser_output\n");

    FSM_geser_init(&geser_state,&geser_output);
    geser_input_kiri=0;
    geser_input_kanan=0;

    for(int k=0; k<30; k++)
    {
        geser_input_kiri=0; // default
        geser_input_kanan=0; // default

        if(k==3)
        {
            geser_input_kiri=1;
        }
        if(k==6)
        {
            geser_input_kiri=1;
        }
        if(k==9)
        {
            geser_input_kiri=1;
        }

        if(k==12)
        {
            geser_input_kiri=1;
        }
        if(k==15)
        {
            geser_input_kiri=1;
        }

        if(k==17)
        {
            geser_input_kanan=1;
        }
        if(k==19)
        {
            geser_input_kanan=1;
        }
        if(k==21)
        {
            geser_input_kanan=1;
        }
        if(k==23)
        {
            geser_input_kanan=1;
        }
        if(k==25)
        {
            geser_input_kanan=1;
        }
        FSM_geser(geser_input_kiri,geser_input_kanan,&geser_state,&geser_output);
        fprintf(out_f,"%d,%d,%d,%d,%d\n", k,geser_input_kiri,geser_input_kanan,geser_state,geser_output);
    }
}
