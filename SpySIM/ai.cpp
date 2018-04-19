#include "ai.h"

AI::AI(double tile_size, int call_horiz): Actor(tile_size, call_horiz){
    ai_pic = new wxBitmap();
    ai_pic->LoadFile(_("./ai.png"),wxBITMAP_TYPE_PNG);
}

AI::~AI(){
}

void AI::DrawActor(wxPanel *panel){
    wxClientDC dc(panel);
    dc.DrawBitmap(*ai_pic, 100, 100, false);
}
