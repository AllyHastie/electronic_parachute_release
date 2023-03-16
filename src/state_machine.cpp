/* Stages of rocket during flight */
enum class state {
    STATE_ARMED, 
    STATE_IGNITION,
    STATE_APOGEE,
    STATE_DESCENT,
    STATE_LANDED,
    STATE_ERROR
};

/* Function prototypes */
bool getNextState (state *state);

/* State of rocket during flight */
bool getNextState (state *state){
    switch(*state)
    {
        case state:: STATE_ARMED: 
            break;
        case state:: STATE_IGNITION: 
            break;
        case state:: STATE_APOGEE: 
            break;
        case state:: STATE_DESCENT: 
            break;
        default: 
            * state = state :: STATE_ERROR;
            break;
            
    }

    return true;
    
}




