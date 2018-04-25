#include "ladder.h"

Ladder::Ladder(wxRealPoint location, double tile_size) : Grid(tile_size){
   loc->x = location.x;
   loc->y = location.y;

   ladder_pic = new wxBitmap();
   ladder_pic->LoadFile(_("./ladder.png"),wxBITMAP_TYPE_PNG);
}

Ladder::~Ladder(){
}

void Ladder::DrawLadder(wxPanel *panel){
   wxClientDC dc(panel);
   dc.DrawBitmap(*ladder_pic, loc->x + (tile_size / 2), loc->y - 20 - (tile_size / 4), false);
}
