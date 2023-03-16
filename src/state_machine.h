
#ifndef state_machine_h
#define state_machine_h

enum class state {
    STATE_ARMED, 
    STATE_ASCENT,
    STATE_APOGEE,
    STATE_DESCENT,
    STATE_LANDED,
    STATE_ERROR
};

int getNextState(state *state);
state initState();

#endif