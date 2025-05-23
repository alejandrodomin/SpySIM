/***************************************************************
 * Name:      SpySIMApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Alejandro Dominguez (adomi120@fiu.edu)
 * Created:   2018-03-31
 * Copyright: Alejandro Dominguez ()
 * License:
 **************************************************************/

#include "SpySIMApp.h"

//(*AppHeaders
#include "SpySIMMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SpySIMApp);

bool SpySIMApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	SpySIMFrame* Frame = new SpySIMFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

