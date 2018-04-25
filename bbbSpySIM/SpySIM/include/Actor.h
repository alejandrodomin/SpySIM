#ifndef ACTOR_H
#define ACTOR_H

#include "grid.h"
class Actor : public Grid
{
    public:
        //Actor(*wxRealPoint);
        Actor(double x, double y);
        virtual ~Actor();

        void setLoc(double x, double y);\
        wxRealPoint pos;

    protected:

    private:

};

#endif // ACTOR_H
