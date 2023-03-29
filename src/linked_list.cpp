#include "linked_list.h"

/******************************************************************************
Function Name: addData
Stores gps latitude and longitude, date, time, altitude and acceleration into 
the linked list
    Input: position, date, time, altitude, acceleration
    Output: N/A
******************************************************************************/

void linked_list :: addData(position newLocation, DDMMYY newDate, HHMMSS newTime, float newAltitude, axis newAccel) 
{
    DataNode* newNode = new DataNode;

    // stores latitude and longitude data
    newNode->location.latitude = newLocation.latitude;
    newNode->location.longitude= newLocation.longitude;

    // stores date data
    newNode->date.day = newDate.day;
    newNode->date.month = newDate.month;
    newNode->date.year = newDate.year;

    // stores time data
    newNode->time.hour = newTime.hour;
    newNode->time.minute = newTime.minute;
    newNode->time.second = newTime.second;

    // stores altitude data
    newNode->altitude = newAltitude;

    // stores acceleration data
    newNode->acceleration.x = newAccel.x;
    newNode->acceleration.y = newAccel.y;
    newNode->acceleration.z = newAccel.z;

    // sets previous and next location of linked list to NULL
    newNode->prev = NULL;
    newNode->next = NULL;

    // sets head and tail is linked list is NULL
    if (head == NULL) {
        head = newNode;
        tail = newNode;
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

DataNode* linked_list :: getPrevData() {
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
DataNode* linked_list :: getNthPrevData(int n) {
    DataNode* currentNode = tail;

    for (int i = 0; i < n && currentNode != NULL; i++) 
    {
        // sets current node as previous node
        currentNode = currentNode->prev;
    } 
    // returns location of node in nth previous position
    return currentNode;
}

