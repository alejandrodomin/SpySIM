#ifndef GRID_H
#define GRID_H

#include "cell.h"

class Grid : public Cell{
    private:
    protected:
        void DrawIsoRow(wxRealPoint& point, int difficulty, wxPanel *Panel1,double tile_size);
    public:
        void DrawIsoGrid(wxRealPoint& point, wxRadioBox* RadioBox, wxPanel *Panel1,double tile_size);
};

#endif
