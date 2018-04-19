#include "player.h"

Player::Player(){
    player_pic->LoadFile(_("/home/fiu/SpySIM/SpySIM/player.png"),wxBITMAP_TYPE_PNG);
}

Player::~Player(){
}

void Player::DrawActor(wxPanel *panel){
    wxClientDC dc(panel);
    dc.DrawBitmap(*player_pic, 50, 50, false);
}
