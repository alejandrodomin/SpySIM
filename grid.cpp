#include "grid.h"

void Grid::DrawIsoRow(wxRealPoint& point, int difficulty, wxPanel *Panel1,double tile_size)
{
    wxRealPoint *center = new wxRealPoint(point);
    DrawIsoSquare(*center,Panel1, tile_size);
    tiles.push_back(center);

    int num_tiles = 0;
    if(difficulty == 0)
        num_tiles = 15;
    else if(difficulty == 1)
        num_tiles = 10;
    else if(difficulty == 2)
        num_tiles = 5;

    for(int i = 1; i < num_tiles; i++){ // define a max number or rows
        tiles.push_back( new wxRealPoint(*center));    // based on the panel width
        array[i]->x += tile_size * (i+1);

        DrawIsoSquare(*array[i],Panel1, tile_size);
    }

    if(center != NULL){
        delete center;
        center = NULL;
    }
    if(array != NULL){
        delete [] array;
        array = NULL;
    }
}

void Grid::DrawIsoGrid(wxRealPoint& point, wxRadioBox* RadioBox, wxPanel *Panel1,double tile_size){

    wxClientDC dc(Panel1);
    //dc.Clear();
    wxRealPoint *center = new wxRealPoint(point);
    DrawIsoRow(*center, RadioBox->GetSelection(),Panel1, tile_size);

    wxRealPoint **array = new wxRealPoint*[5];

    for(int i = 0; i < 4; i++){ // define a max number or rows
        array[i] = new wxRealPoint(*center);    // based on the panel width
        array[i]->x += (tile_size * cos(PI/6)) * (i + 1);
        array[i]->y -= (tile_size * 0.5) * (i + 1);

        DrawIsoRow(*array[i], RadioBox->GetSelection(),Panel1, tile_size);
    }

    tru_center.x = /*num of tiles in x depending on difficulty */ * (tile_size * cos(PI/6)) * (i + 1)
        +  ((tile_size * cos(PI/6)) * (i + 1)))/2;
    tru_center.y = /*num of tiles in y depending on difficulty */ * (tile_size * 0.5) * (i + 1)
        +  ((tile_size * 0.5) * (i + 1))/2;
}
