#ifndef ACTOR_H
#define ACTOR_H

#include "grid.h"

class Actor: public Grid
{
public:
    Actor();
    virtual ~Actor();

    virtual void DrawActor()=0;

    bool moveLeft();
    bool moveRight();
    bool moveUp();
    bool moveDown();

private:
protected:
    wxRealPoint pos;


};

#endif
