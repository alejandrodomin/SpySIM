#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"

#include <wx/bitmap.h>
#include <wx/dcclient.h>

class Player: public Actor
{
    public:
        Player(wxRealPoint location, double tile_size, int call_horiz);
        ~Player();

        virtual void DrawActor(wxPanel *panel);
    private:
        wxBitmap *player_pic;
    protected:
};

#endif // PLAYER_H
