#include "player.h"

Player::Player(wxRealPoint location, double tile_size, int call_horiz): Actor(tile_size, call_horiz){
    loc->x = location.x;
    loc->y = location.y;

    player_pic = new wxBitmap();
    player_pic->LoadFile(_("./assets/player.png"),wxBITMAP_TYPE_PNG);
}

Player::~Player(){
}

void Player::DrawActor(wxPanel *panel){
    wxClientDC dc(panel);
    dc.DrawBitmap(*player_pic, loc->x + (tile_size / 2), loc->y - 20 - (tile_size/4), false);
}
