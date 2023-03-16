#include "state_machine.h"

/******************************************************************************
Function Name: initState
Initialises new state variable to armed.
    Input: N/A
    Output: state
******************************************************************************/

state initState()
{
    return state::STATE_ARMED;
}


/******************************************************************************
Function Name: getNextState
Sets the next state and updates the value when a condition is met.
    Input: state 
    Output: int
        0 - No error
        1 - No reading and/or error
******************************************************************************/
int getNextState (state *state){
    switch(*state)
    {
        case state:: STATE_ARMED: 
            break;
        case state:: STATE_ASCENT: 
            break;
        case state:: STATE_APOGEE: 
            break;
        case state:: STATE_DESCENT: 
            break;
        default: 
            * state = state :: STATE_ERROR;
            return 1;     
    }

    return 0;
    
}




