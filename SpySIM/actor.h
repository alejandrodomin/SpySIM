#ifndef ACTOR_H
#define ACTOR_H

#include "grid.h"

class Actor: public Grid
{
public:
    Actor(double tile_size, int call_horiz);

    virtual ~Actor();

    virtual void DrawActor(wxPanel *panel)=0;

    bool moveLeft();
    bool moveRight();
    bool moveUp();
    bool moveDown();

private:
    int call_horiz;
    int call=0;
    int call2=0;
    double yVert = tile_size / 2;
    double yHoriz = tile_size/(1/cos(PI/6));
protected:



};

#endif
