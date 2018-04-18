#ifndef ACTOR_H
#define ACTOR_H

#include "grid.h"

class Actor: public Grid
{

public:
    Actor();
    virtual ~Actor();

private:
protected:
    wxRealPoint pos;


};

#endif
