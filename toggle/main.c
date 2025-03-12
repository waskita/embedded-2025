#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

// definisi state
#define STATE_ON_1 1
#define STATE_ON_2 2
#define STATE_OFF_1 3
#define STATE_OFF_2 4

void fsm_init(int *state)
{
    *state=STATE_OFF_2;
}

void fsm_run(int input,int *state,int *output)
{
    int next_state;
    next_state=*state; // default
    if (*state==STATE_OFF_1 && input==1)
    {
        next_state=STATE_ON_1;
        *output=1;
    }
    if (*state==STATE_ON_1 && input==0)
    {
        next_state=STATE_ON_2;
        *output=1;
    }
    if (*state==STATE_ON_2 && input==1)
    {
        next_state=STATE_OFF_2;
        *output=0;
    }
    if (*state==STATE_OFF_2 && input==0)
    {
        next_state=STATE_OFF_1;
        *output=0;
    }
    *state=next_state;
}

int main()
{
    char filename[]="../toggle.csv";
    char output_filename[]="../toggle_output.csv";
    // read the csv file
    int state=0;
    fsm_init(&state);
    FILE *fptr = fopen(filename, "r");
    FILE *out_f =fopen(output_filename, "w");

    if(fptr)
    {
        char buff[30];
        printf("k,input,state,output\n");
        fprintf(out_f,"k,input,state,output\n");
        fgets(buff, sizeof(buff), fptr); // buang baris pertama
        while(!feof(fptr))
        {
            int k,input,output;
            fgets(buff, sizeof(buff), fptr);
//            printf("%s\n", buff);
            sscanf(buff,"%d,%d",&k,&input);
            fsm_run(input,&state,&output);
            printf("%2d,%2d,%2d,%2d\n", k,input,state,output);
            fprintf(out_f,"%d,%d,%d,%d\n", k,input,state,output);
        }
        fclose(fptr);
        fclose(out_f);
    }
    else
    {
        printf("error open %s\n",filename);
    }
    return 0;
}

