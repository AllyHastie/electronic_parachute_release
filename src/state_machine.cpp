#include "state_machine.h"

/******************************************************************************
Function Name: getNextState
Sets the next state and updates the value when a condition is met.
    Input: N/A
    Output: state
******************************************************************************/
int getNextState (DataNode* prevNode, DataNode* node)
{   
    switch(prevNode->state)
    {
        case state:: STATE_ARMED: 
            // if altitude is > previous altitude, change state
            node->state = state :: STATE_ASCENT;
            break;
        case state:: STATE_ASCENT: 
            // if altitude is < previous altitude, change state
            // if accelerated is not valid then skip to STATE_DESCENT
            node->state = state :: STATE_ARMED;
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
            node->state = state :: STATE_ERROR;
            return 1;     
    }
    return 0;
    
}




