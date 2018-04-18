#ifndef GRID_H
#define GRID_H

#include "cell.h"

class Grid : public Cell{
    private:
    protected:
        void DrawIsoRow(wxRealPoint& point, int difficulty);
    public:
        void DrawIsoGrid(wxRealPoint& point, wxRadioBox* RadioBox);
};

#endif