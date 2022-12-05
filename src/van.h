#ifndef VAN_H
#define VAN_H

#include <iostream>
#include <simlib.h>



class Van : public Process {
    private:
        Store *vans;
        Stat *LOAD_TIME;

    public:
        Van(Store *vans);

        void Behavior();
};

#endif