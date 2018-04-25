#ifndef LADDER_H
#define LADDER_H

#include "grid.h"
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/bitmap.h>

class Ladder: public Grid
{
   public:
      Ladder(wxRealPoint location, double tile_size);
      ~Ladder();

      void DrawLadder(wxPanel *panel);
   protected:
   private:
      wxBitmap *ladder_pic;
};

#endif
