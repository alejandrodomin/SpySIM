#include "ai.h"

AI::AI(wxRealPoint location,double tile_size, int call_horiz): Actor(tile_size, call_horiz){
    loc->x = location.x;
    loc->y = location.y;

    ai_pic = new wxBitmap();
    ai_pic->LoadFile(_("./ai.png"),wxBITMAP_TYPE_PNG);
}

AI::~AI(){
}

void AI::DrawActor(wxPanel *panel){
    wxClientDC dc(panel);
    dc.DrawBitmap(*ai_pic, loc->x + (tile_size/2), loc->y - 15 - (tile_size/4), false);
}
