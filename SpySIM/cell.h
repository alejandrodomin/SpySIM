#ifndef CELL_H
#define CELL_H

#include <wx/gdicmn.h>
#include <wx/panel.h>
#include <wx/dcclient.h>

# define PI          3.141592653589793238462643383279502884L

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
