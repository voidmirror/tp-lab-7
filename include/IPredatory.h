//
// Created by fiskirton on 10.04.2020.
//

#ifndef OCEAN_IPREDATORY_H
#define OCEAN_IPREDATORY_H

enum satiety{HUNGRY=1, NORMAL=5, FULL=10};

class IPredatory{
public:
    virtual bool hunt() = 0;
};

#endif //OCEAN_IPREDATORY_H
