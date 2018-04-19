#include "cell.h"

Cell::Cell(){}
Cell::Cell(double tile){
    tile_size=tile;

}


wxRealPoint Cell::DrawIsoSquare(wxRealPoint& point, wxPanel *Panel1)
{
    wxClientDC dc(Panel1);
    dc.SetBrush(*wxBLACK_BRUSH);

    wxSize panel_size = Panel1->GetClientSize(); //Get size of panel
    wxRealPoint *center = new wxRealPoint(point);
    wxRealPoint *slave = new wxRealPoint(*center);
    slave->x += tile_size;
    dc.DrawLine(*center,*slave);

    wxRealPoint *center2 = new wxRealPoint(*center);
    center2->y -= tile_size * 0.5; // 0.5 is sin(30 degrees)
    center2->x += tile_size * cos(PI/6); // cosine of 30 degrees

    dc.DrawLine(*center,*center2);

    wxRealPoint *center3 = new wxRealPoint(*slave);
    center3->y -= tile_size * 0.5; // 0.5 is sin(30 degrees)
    center3->x += tile_size * cos(PI/6); // cosine of 30 degrees

    dc.DrawLine(*slave,*center3);
    dc.DrawLine(*center2,*center3);

    //loc = new wxRealPoint((slave->x + (tile_size / 4)),( slave->y - (tile_size/(1/cos(PI/6)))) ) ;
    loc = new wxRealPoint(center->x+tile_size,center->y-(tile_size/4));
    if(center != NULL){
        delete center;
        center = NULL;
    }
    if(slave != NULL){
        delete slave;
        slave = NULL;
    }
    if(center2 != NULL){
        delete center2;
        center2 = NULL;
    }
    if(center3 != NULL){
        delete center3;
        center3 = NULL;
    }
    //dc.DrawCircle(*loc, 2);
    return *loc;
}
