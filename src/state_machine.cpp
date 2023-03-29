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
            // if altitude is > previous altitude, change state
            break;
        case state:: STATE_ASCENT: 
            // if altitude is < previous altitude, change state
            // if accelerated is not valid then skip to STATE_DESCENT
            break;
        case state:: STATE_APOGEE: 
            // store state of apogee
            break;
        case state:: STATE_DESCENT: 
            // if altitude == previous altitude, change state
            break;
        case state:: STATE_LANDED: 
            break;
        default: 
            * state = state :: STATE_ERROR;
            return 1;     
    }

    return 0;
    
}




