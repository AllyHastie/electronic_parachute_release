#include "linked_list.h"

/******************************************************************************
Function Name: addData
Stores time, state altitude and acceleration into the linked list
    Input: position, date, time, altitude, acceleration
    Output: N/A
******************************************************************************/

void linked_list :: addData(float newAltitude, axis newAccel) 
{
    DataNode* newNode = new DataNode;

    // stores altitude data
    newNode->altitude = newAltitude;

    // stores acceleration data
    newNode->acceleration.x = newAccel.x;
    newNode->acceleration.y = newAccel.y;
    newNode->acceleration.z = newAccel.z;

    if(tail!=NULL)
    {
        getNextState(tail, newNode);
    }
    // sets previous and next location of linked list to NULL
    newNode->prev = NULL;
    newNode->next = NULL;

    // due to memory limitations only X data points are stored in RAM
    DataNode* tmpNode = getNthPrevData(dataStored);
    if (tmpNode!=NULL)
    {
        delete tmpNode;
    }

    // sets head and tail is linked list is NULL
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->state = state::STATE_ARMED;
    } 
    else 
    {
        // stores location on newNode in pevious Node
        tail->next = newNode;
        // sets previous location in newNode as tails location
        newNode->prev = tail;
        // sets newNode as tail
        tail = newNode;
    }
}

/******************************************************************************
Function Name: getPrevData
Returns the data stored in the previous node
    Input: N/A
    Output: DataNode
******************************************************************************/

DataNode* linked_list :: getPrevData() 
{
    DataNode* currentNode = tail;

    if (currentNode == NULL || currentNode->prev == NULL) 
    {
        // if tail is empty return NULL
        return NULL;
    } 
    else 
    {
        // returns location of previous node
        return currentNode->prev;
    }
}

/******************************************************************************
Function Name: getNthPrevData
Returns the data stored in the nth position.
    Input: position
    Output: DataNode
******************************************************************************/
DataNode* linked_list :: getNthPrevData(int n) 
{
    DataNode* currentNode = tail;

    for (int i = 0; i < n && currentNode != NULL; i++) 
    {
        // sets current node as previous node
        currentNode = currentNode->prev;
    } 
    // returns location of node in nth previous position
    return currentNode;
}



/******************************************************************************
Function Name: getPrevAltitude
Returns the alitude stored in the previous position.
    Input: N/A
    Output: float
******************************************************************************/
float linked_list :: getPrevAltitude()
{
    return getPrevData()->altitude;
}

/******************************************************************************
Function Name: getPrevAltitude
Returns the acceleration datat stored in the previous position.
    Input: N/A
    Output: axis
******************************************************************************/
axis linked_list :: getPrevAccel()
{
    return getPrevData()->acceleration;
}

/******************************************************************************
Function Name: getPrevState
Returns the state stored in the previous position.
    Input: N/A
    Output: state
******************************************************************************/
state linked_list :: getPrevState()
{
    return getPrevData()->state;
}

/******************************************************************************
Function Name: getAlitude
Returns the altitude stored in the current position.
    Input: N/A
    Output: altitude
******************************************************************************/
float linked_list :: getAltitude()
{
    return tail->altitude;
}

/******************************************************************************
Function Name: getAccel
Returns the acceleration stored in the current position.
    Input: N/A
    Output: axis
******************************************************************************/
axis linked_list :: getAccel()
{
    return tail->acceleration;
}

/******************************************************************************
Function Name: getState
Returns the state stored in the current position.
    Input: N/A
    Output: state
******************************************************************************/
state linked_list :: getState()
{
    return tail->state;
}