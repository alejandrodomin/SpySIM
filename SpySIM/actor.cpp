#include "actor.h"

Actor::Actor(double tile_size, int call_horiz):Grid(tile_size)
{
    this->call_horiz = call_horiz;
}

bool Actor::moveLeft()
{
    if (call2>0)
    {
        loc->x -= tile_size;
        call2--;
    }
    return true;

}
bool Actor::moveRight()
{
    if (call2<call_horiz)
    {
        loc->x += tile_size;
        call2++;
    }
    return true;
}

bool Actor::moveUp()
{
    if (call<4)
    {
        loc->x += yHoriz;
        loc->y -= yVert;
        call++;
    }
    return true;
}
bool Actor::moveDown()
{
    if (call>0)
    {
        loc->x -= yHoriz;
        loc->y += yVert;
        call--;
    }
    return true;
}

Actor::~Actor()
{


}

int Actor::RetCall()
{
    return call;
}

int Actor::RetCall2()
{
        return call2;
}
