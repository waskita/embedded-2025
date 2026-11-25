#include "fsm.h"

void FSM_hold_init(int *state, int *counter, int *output)
{
    *state = FSM_HOLD_OFF;
    *output = 0;
    *counter=10;
}
void FSM_hold(int input, int *state, int *counter,int *output, int delay)
{
    int next_state = *state; // default: tidak ganti state
    if (*state==FSM_HOLD_OFF)
    {
        if(input==0)
        {
            next_state=FSM_HOLD_OFF;
            *counter=0;
            *output=0;
        }
        else
        {
            next_state=FSM_HOLD_ON_0;
            *counter=0;
            *output=0;
        }
    }
    if (*state==FSM_HOLD_ON_0)
    {
        if(input==1 && *counter<delay)
        {
            next_state=FSM_HOLD_ON_0;
            *counter=*counter+1;
            *output=0;
        }
        if(input==0 && *counter<delay)
        {
            next_state=FSM_HOLD_OFF;
            *output=0;
        }

        if(input==1 && *counter>=delay)
        {
            next_state=FSM_HOLD_ON_1;
            *output=1;
        }
    }
    if (*state==FSM_HOLD_ON_1)
    {
        if(input==1)
        {
            next_state=FSM_HOLD_ON_1;
            *output=0;
        }
        if(input==0)
        {
            next_state=FSM_HOLD_OFF;
            *output=0;
        }

    }

    *state=next_state;
}

