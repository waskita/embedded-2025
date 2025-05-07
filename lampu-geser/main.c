//  pengujian  FSM untuk lampu geser

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%s\n",__FILE__);
    uji_fsm_geser();
    return 0;
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
