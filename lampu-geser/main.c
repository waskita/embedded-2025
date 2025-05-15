//  pengujian  FSM untuk lampu geser

#include <stdio.h>
#include <stdlib.h>
#include "fsm.h"

int main()
{
    printf("%s\n",__FILE__);
    printf("Uji Debouncer\n");
    uji_fsm_debounce();
    printf("Uji Edge Detector\n");
    uji_fsm_edge_detect();
    printf("Uji FSM Geser\n");
    uji_fsm_geser();
    printf("Uji Integrasi\n");
    uji_integrasi();
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

    for(int k=0; k<60; k++)
    {
        input=0; // default
// sinyal utama
        if(k>=5 && k<20)
        {
            input=1;
        }
// tambahkan bounce
        if(k==7)  // bikin bounce bbrp
        {
            input=0;
        }
        if(k==9)  // bikin bounce bbrp
        {
            input=0;
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
        if(k>=35 && k<50)
        {
            input=1;
        }
        if(k==38)  // bikin bounce bbrp
        {
            input=0;
        }
        // tambahkan bounce
        if(k==52)  // bikin bounce bbrp
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

void uji_integrasi()
{
    char output_filename[]="integrasi.csv";

    FILE *out_f ;
    int bounce_delay=10;
    int debounce_ki_state; // kiri
    int debounce_ki_counter;
    int debounce_ki_output;
    int debounce_ka_state; // kanan
    int debounce_ka_counter;
    int debounce_ka_output;
    //
    int edge_ki_state,edge_ka_state;
    int edge_ki_output,edge_ka_output;
    int geser_state;
    int geser_output;
    int input_ki;
    int input_ka;
    int k=0; // simulation time
    out_f =fopen(output_filename, "w");
    fprintf(out_f,"k,input_ki,input_ka,debounce_ki_counter,debounce_ka_counter,debounce_ki_output,debounce_ka_output,edge_ki_output,edge_ka_output,output\n");

    FSM_debounce_init(&debounce_ki_state,&debounce_ki_counter,&debounce_ki_output);
    FSM_debounce_init(&debounce_ka_state,&debounce_ka_counter,&debounce_ka_output);
    FSM_edge_detect_init(&edge_ki_state,&edge_ki_output);
    FSM_edge_detect_init(&edge_ka_state,&edge_ka_output);
    FSM_geser_init(&geser_state,&geser_output);

    for(int k=0; k<250; k++)
    {
        input_ki=0;
        input_ka=0;
        // bikin sinyal utama
        if(k>15 && k<30)
        {
            input_ki=1;
        }
        if(k>15+30 && k<30+30)
        {
            input_ki=1;
        }
        if(k>15+60 && k<30+60)
        {
            input_ki=1;
        }
        if(k>15+90 && k<30+90)
        {
            input_ki=1;
        }
// tambah bounce
        if(k==17)
        {
            input_ki=0;
        }
        if(k==30+3)
        {
            input_ki=1;
        }
        if(k==60+4)
        {
            input_ki=1;
        }

// sinyal kanan
        if(k>15+120 && k<30+120)
        {
            input_ka=1;
        }
        if(k>15+30+120 && k<30+30+120)
        {
            input_ka=1;
        }
        if(k>15+60+120 && k<30+60+120)
        {
            input_ka=1;
        }
        if(k>15+90+120 && k<30+90+120)
        {
            input_ka=1;
        }

        if(k==152)
        {
            input_ka=1;
        }

        FSM_debounce(input_ki,&debounce_ki_state,&debounce_ki_counter,&debounce_ki_output,bounce_delay);
        FSM_debounce(input_ka,&debounce_ka_state,&debounce_ka_counter,&debounce_ka_output,bounce_delay);
        FSM_edge_detect(debounce_ki_output,&edge_ki_state,&edge_ki_output);
        FSM_edge_detect(debounce_ka_output,&edge_ka_state,&edge_ka_output);
        FSM_geser(edge_ki_output,edge_ka_output,&geser_state,&geser_output);
        fprintf(out_f,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
                k,
                input_ki,
                input_ka,
                debounce_ki_counter,
                debounce_ka_counter,
                debounce_ki_output,
                debounce_ka_output,
                edge_ki_output,
                edge_ka_output,
                geser_output);
    }
}
