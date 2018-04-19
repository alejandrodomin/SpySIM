#ifndef CELL_H
#define CELL_H

#include "SpySIMMain.h"
class Cell{
    private:



    protected:
    public:
        double tile_size;
        Cell();
        Cell(double tile);
        wxRealPoint* loc;
        wxRealPoint DrawIsoSquare(wxRealPoint& point, wxPanel *Panel1);
};

#endif
