#ifndef AI_H
#define AI_H

#include "actor.h"

#include <wx/bitmap.h>
#include <wx/dcclient.h>

class AI: public Actor
{
    public:
        AI();
        ~AI();

        virtual void DrawActor(wxPanel *panel);
    protected:
    private:
        wxBitmap *ai_pic;
};

#endif // AI_H
