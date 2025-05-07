#include "fsm.h"



void FSM_debounce_init(int *state, int *counter, int *output)
{
    *state = FSM_DEBOUNCE_STATE_0;
    *output = 0;
    *counter=10;
}
void FSM_debounce(int input, int *state, int *counter,int *output, int delay)
{
    int next_state = *state; // default: tidak ganti state
    if (*state==FSM_DEBOUNCE_STATE_0)
    {
        if(input==1 && *counter>=delay)
        {
            next_state=FSM_DEBOUNCE_STATE_1;
            *counter=0;
            *output=1;
        }
        else
        {
            (*counter)++;
            if((*counter)>=delay) // limit counter supaya tidak overflow
            {
                *counter=delay;
            }

        }

    }
    if (*state==FSM_DEBOUNCE_STATE_1)
    {
        if(input==0 && *counter>=delay)
        {
            next_state=FSM_DEBOUNCE_STATE_0;
            *counter=0;
            *output=0;
        }
        else
        {
            (*counter)++;
            // limit counter di delay, supaya tidak overflow
            if((*counter)>=delay)
            {
                *counter=delay;
            }
        }
    }
    *state=next_state;
}


void FSM_edge_detect_init(int *state, int *output)
{
    *state = FSM_EDGE_STATE_0;
}
void FSM_edge_detect(int input, int *state, int *output)
{
    int next_state = *state;
    if (*state == FSM_EDGE_STATE_0 && input == 0)
    {
        next_state = FSM_EDGE_STATE_0;
        *output = 0;
    }
    if (*state == FSM_EDGE_STATE_0 && input == 1)
    {
        next_state = FSM_EDGE_STATE_1;
        *output = 1;
    }
    if (*state == FSM_EDGE_STATE_1 && input == 0)
    {
        next_state = FSM_EDGE_STATE_0;
        *output = 0;
    }
    if (*state == FSM_EDGE_STATE_1 && input == 1)
    {
        next_state = FSM_EDGE_STATE_1;
        *output = 0;
    }
    *state = next_state;
}


void FSM_geser_init(int *state, int *output)
{
    *state = FSM_GESER_STATE_S1;
    *output = 1;
}

void FSM_geser(int input_kiri, int input_kanan, int *state, int *output)
{
    int next_state = *state;  // default not change state

    if (*state == FSM_GESER_STATE_S1 && input_kiri == 1)
    {
        next_state = FSM_GESER_STATE_S4;
        *output = 4;
    }
    if (*state == FSM_GESER_STATE_S1 && input_kanan == 1)
    {
        next_state = FSM_GESER_STATE_S2;
        *output = 2;
    }
    if (*state == FSM_GESER_STATE_S2 && input_kiri == 1)
    {
        next_state = FSM_GESER_STATE_S1;
        *output = 1;
    }
    if (*state == FSM_GESER_STATE_S2 && input_kanan == 1)
    {
        next_state = FSM_GESER_STATE_S3;
        *output = 3;
    }
    if (*state == FSM_GESER_STATE_S3 && input_kiri == 1)
    {
        next_state = FSM_GESER_STATE_S2;
        *output = 2;
    }
    if (*state == FSM_GESER_STATE_S3 && input_kanan == 1)
    {
        next_state = FSM_GESER_STATE_S4;
        *output = 4;
    }
    if (*state == FSM_GESER_STATE_S4 && input_kiri == 1)
    {
        next_state = FSM_GESER_STATE_S3;
        *output = 3;
    }
    if (*state == FSM_GESER_STATE_S4 && input_kanan == 1)
    {
        next_state = FSM_GESER_STATE_S1;
        *output = 1;
    }
    *state = next_state;
}
