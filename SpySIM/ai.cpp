#include "ai.h"

AI::AI(){
    ai_pic->LoadFile(_("/home/fiu/SpySIM/SpySIM/ai.png"),wxBITMAP_TYPE_PNG);
}

AI::~AI(){
}

void AI::DrawActor(wxPanel *panel){
    wxClientDC dc(panel);
    dc.DrawBitmap(*ai_pic, 50, 50, false);
}
