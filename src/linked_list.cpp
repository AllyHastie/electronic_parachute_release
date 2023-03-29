#include "linked_list.h"

/******************************************************************************
Function Name: addData
Stores gps latitude and longitude, date, time, altitude and acceleration into 
the linked list
    Input: position, date, time, altitude, acceleration
    Output: N/A
******************************************************************************/

void addData(position newLocation, DDMMYY newDate, HHMMSS newTime, float newAltitude, axis newAccel) 
{
    DataNode* newNode = new DataNode;
    newNode->location.latitude = newLocation.latitude;
    newNode->location.longitude= newLocation.longitude;
    newNode->date.day = newDate.day;
    newNode->date.month = newDate.month;
    newNode->date.year = newDate.year;
    newNode->time.hour = newTime.hour;
    newNode->time.minute = newTime.minute;
    newNode->time.second = newTime.second;
    newNode->altitude = newAltitude;
    newNode->acceleration.x = newAccel.x;
    newNode->acceleration.y = newAccel.y;
    newNode->acceleration.z = newAccel.z;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } 
    else 
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

/******************************************************************************
Function Name: getNthPrevData
Returns the data stored in the nth position.
    Input: position
    Output: DataNode
******************************************************************************/
DataNode* getNthPrevData(int n) {
    DataNode* currentNode = tail;

    for (int i = 0; i < n && currentNode != NULL; i++) 
    {
        currentNode = currentNode->prev;
    } 
    return currentNode;
}

/******************************************************************************
Function Name: getPrevData
Returns the data stored in the previous node
    Input: N/A
    Output: DataNode
******************************************************************************/

DataNode* getPrevData() {
    DataNode* currentNode = tail;

    if (currentNode == NULL || currentNode->prev == NULL) 
    {
        return NULL;
    } 
    else 
    {
        return currentNode->prev;
    }
}