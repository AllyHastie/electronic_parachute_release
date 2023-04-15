#include "state_machine.h"

/******************************************************************************
Function Name: getNextState
Sets the next state and updates the value when a condition is met.
    Input: N/A
    Output: int
        0 - No error
        -1 - No reading and/or error
******************************************************************************/
int getNextState (DataNode* prevNode, DataNode* currentNode, float nthPrevAltitude)
{   
    switch(prevNode->state)
    {
        case state:: STATE_ARMED: 
        // if current altitude - previous altitude is greater than 5m change state
            if (currentNode->altitude - prevNode->altitude >= SC_DISTANCE)
            {
                timeOfAscent = millis();
                currentNode->state = state :: STATE_ASCENT;
            } 
            else
            {
                currentNode->state = state :: STATE_ARMED;
            }
            break;
        case state:: STATE_ASCENT: 
        // if previous altitude - current altitude is less than 5m change state
            if (currentNode->altitude - prevNode->altitude <= -(SC_DISTANCE))
            {
                currentNode->state = state :: STATE_DESCENT;
                prevNode->state = state :: STATE_APOGEE;
            }
            else
            {
                currentNode->state = state :: STATE_ASCENT;
            }
            break;
        case state:: STATE_DESCENT: 
        // if nth previous altitude - current altitude less than 1 m change state
            if (nthPrevAltitude - currentNode->altitude < 1)
            {
                currentNode->state = state :: STATE_LANDED;
            }
            else
            {
                currentNode->state = state :: STATE_DESCENT;
                // if current altitude equals deployment altitude release parachute
                if ((currentNode->altitude - startAltitude) < deployAltitude)
                {
                    // open servo
                }
            }
            break;
        case state:: STATE_LANDED: 
            currentNode->state = state :: STATE_LANDED;
            break;
        default: 
            // set error flag
            currentNode->state = state :: STATE_ERROR;
            deployAltitude = -1;
            return -1;     
    }
    return 0;
    
}

