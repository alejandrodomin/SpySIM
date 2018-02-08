/***************************************************************
 * Name:      SpySIMApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2018-02-08
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "SpySIMApp.h"
#include "SpySIMMain.h"

IMPLEMENT_APP(SpySIMApp);

bool SpySIMApp::OnInit()
{
    
    SpySIMDialog* dlg = new SpySIMDialog(0L, _("wxWidgets Application Template"));
    
    dlg->Show();
    return true;
}
