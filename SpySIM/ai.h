#ifndef AI_H
#define AI_H

#include "actor.h"

#include <wx/bitmap.h>
#include <wx/dcclient.h>

class AI: public Actor
{
    public:
        AI(wxRealPoint location,double tile_size, int call_horiz);
        ~AI();

        virtual void DrawActor(wxPanel *panel);
        bool View(wxRealPoint *playerpos);

    protected:
    private:
        wxBitmap *ai_pic;
};

#endif // AI_H
