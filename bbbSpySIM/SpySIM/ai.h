#ifndef AI_H
#define AI_H

#include "actor.h"

#include <wx/bitmap.h>
#include <wx/dcclient.h>

class AI: public Actor
{
    public:
        AI(wxRealPoint location,double tile_size, int call_horiz);
        AI(wxRealPoint location,double tile_size, int call_horiz, bool objective);
        ~AI();

        virtual void DrawActor(wxPanel *panel);
        bool View(wxRealPoint *playerpos);
        bool View2(wxRealPoint *playerpos);
    protected:
    private:
        wxBitmap *ai_pic;
        wxBitmap * circ;
        bool drawc=false;
};

#endif // AI_H
