#include "circular_buffer.h"

/******************************************************************************
Function Name: addData
Stores time, state altitude and acceleration into circular buffer
    Input: position, date, time, altitude, acceleration
    Output: N/A
******************************************************************************/
void circular_buffer :: addData(float newAltitude, axis newAccel) 
{
    DataNode newNode;

    // stores altitude data
    newNode.altitude = newAltitude;

    // stores acceleration data
    newNode.acceleration.x = newAccel.x;
    newNode.acceleration.y = newAccel.y;
    newNode.acceleration.z = newAccel.z;

    // check if data is stored in previouse node
    DataNode prevNode = getPrevNode();
    if(isEmpty(prevNode) == false)
    {
        getNextState(prevNode, &newNode);
    } else
    {
        // if no previous data set state to armed
        newNode.state = state :: STATE_ARMED;
    }

    // increment head index
    head = (head + 1) % BUFFER_SIZE;

    // store data in new node
    buffer[head]= newNode;

    // stores node in EEPROM if conditions are met
    if (newNode.state != state :: STATE_ARMED || newNode.state != state :: STATE_LANDED)
    {
        if (millis() - prevStore >= readTime)
        {
            nvm.writeEEPROM(newNode, &nvm.startAddress);
            prevStore = millis();
        }
    }

}

/******************************************************************************
Function Name: getPrevData
Returns the data stored in the previous node
    Input: N/A
    Output: DataNode
******************************************************************************/
DataNode circular_buffer :: getPrevNode() 
{
    // gets previous index
    int prevIndex = head - 1;

    // checks if previous index is less than zero
    if (prevIndex < 0) 
    {
        prevIndex = BUFFER_SIZE - 1;
    }

    return buffer[prevIndex];
}

/******************************************************************************
Function Name: isEmpty
Checks if previous node is 
    Input: DataNode
    Output: bool
******************************************************************************/
bool circular_buffer :: isEmpty(DataNode node)
{
    if(node.altitude!='\0' || node.acceleration.x !='\0' || node.acceleration.y !='\0' || node.acceleration.z !='\0')
    {
        return false;
    }

    return true;
}