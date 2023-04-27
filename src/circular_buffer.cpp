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

    // increment head index
    head = (head + 1) % BUFFER_SIZE;

    // check if data is stored in previouse node
    DataNode prevNode = getPrevNode();
    if(isEmpty(prevNode) == false)
    {
        getNextState(&prevNode, &newNode, getNthPrevAltitude(BUFFER_SIZE - 1));
    } else
    {
        // if no previous data set state to armed
        newNode.state = state :: STATE_ARMED;
    }

    // store data in new node
    buffer[head]= newNode;

    // stores node in EEPROM if conditions are met
    if (newNode.state != state :: STATE_ARMED)
    {
        if (newNode.state == state :: STATE_APOGEE)
        {
           // nvm.writeEEPROM(prevNode, &nvm.startAddress);
            prevStore = millis();
        }
        else if (millis() - prevStore >= (READ_TIME * 1000) || isEmpty(prevNode) == true || newNode.state != prevNode.state)
        {
            //nvm.writeEEPROM(newNode, &nvm.startAddress);
            prevStore = millis();
        }  
    }
    printData(newNode);

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
Function Name: getNthPrevAltitude
Returns the data stored in the nth previous node
    Input: N/A
    Output: altitude
******************************************************************************/
float circular_buffer :: getNthPrevAltitude(int n) 
{
    // gets index
    int prevIndex = head - n;

    // checks if index is less than zero
    if (prevIndex < 0) 
    {
        prevIndex += BUFFER_SIZE;
    }

    return buffer[prevIndex].altitude;
}

/******************************************************************************
TESTING ONLY
Function Name: printData
Prints all data
    Input: DataNode
    Output: N/A
******************************************************************************/

void printData(DataNode data)
{
    Serial.print("Time: ");
    Serial.println(millis());

    Serial.print("State: ");
    switch(data.state)
    {
        case state :: STATE_ARMED: 
            Serial.println("ARMED");
            break;
        case state :: STATE_ASCENT: 
            Serial.println("ASCENT");
            break;
        case state :: STATE_APOGEE: 
            Serial.println("APOGEE");
            break;
        case state :: STATE_DESCENT: 
            Serial.println("DESCENT");
            break;
        case state :: STATE_LANDED: 
            Serial.println("LANDED");
            break;
        case state :: STATE_ERROR: 
            Serial.println("ERROR");
            break;
    }
    Serial.print("Z: ");
    Serial.println(data.acceleration.x);
    Serial.print("Y: ");
    Serial.println(data.acceleration.y);
    Serial.print("Z: ");
    Serial.println(data.acceleration.z);
    Serial.print("Altitude: ");
    Serial.println(data.altitude);
    Serial.println();

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
