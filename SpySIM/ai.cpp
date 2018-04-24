#include "ai.h"

AI::AI(wxRealPoint location,double tile_size, int call_horiz): Actor(tile_size, call_horiz){
    srand ( time(NULL) );
    int xrand= rand()%5+1;
    int yrand= rand()%5+1;
    call2=xrand;
    call=yrand;

    loc->x = location.x+tile_size*xrand+yHoriz*yrand;
    loc->y = location.y-yVert*yrand;

    ai_pic = new wxBitmap();
    ai_pic->LoadFile(_("./ai.png"),wxBITMAP_TYPE_PNG);
    circ=new wxBitmap(_("./circle.png"),wxBITMAP_TYPE_PNG);
    drawc=true;
}

AI::AI(wxRealPoint location,double tile_size, int call_horiz, bool objective): Actor(tile_size, call_horiz){
    loc->x = location.x;
    loc->y = location.y;
    circ=new wxBitmap();
    ai_pic = new wxBitmap();
    ai_pic->LoadFile(_("./chest.png"),wxBITMAP_TYPE_PNG);
}

AI::~AI(){
}

void AI::DrawActor(wxPanel *panel){
    wxClientDC dc(panel);
    if(drawc)
    dc.DrawBitmap(*circ, loc->x-5 , loc->y - 18 , false);
    else
    circ=new wxBitmap();

    dc.DrawBitmap(*ai_pic, loc->x + (tile_size/2), loc->y - 15 - (tile_size/4), false);

}

bool AI::View(wxRealPoint *playerpos){
    bool endgame=false;

    if((playerpos->x - loc->x < 2 && playerpos->x - loc->x > -2)
       && (playerpos->y - loc->y < 2 && playerpos->y - loc->y > -2)){
        endgame=true;
    }
    return endgame;

}
bool AI::View2(wxRealPoint *playerpos){
    bool endgame=false;

    if((playerpos->x - loc->x < 20 && playerpos->x - loc->x > -20)
       && (playerpos->y - loc->y < 20 && playerpos->y - loc->y > -20)){
        endgame=true;
    }
    return endgame;

}
