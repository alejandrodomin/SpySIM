/***************************************************************
 * Name:      SpySIMMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2018-02-08
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef SPYSIMMAIN_H
#define SPYSIMMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "SpySIMApp.h"


#include <wx/button.h>
#include <wx/statline.h>
class SpySIMDialog: public wxDialog
{
    public:
        SpySIMDialog(wxDialog *dlg, const wxString& title);
        ~SpySIMDialog();

    protected:
        enum
        {
            idBtnQuit = 1000,
            idBtnAbout
        };
        wxStaticText* m_staticText1;
        wxButton* BtnAbout;
        wxStaticLine* m_staticline1;
        wxButton* BtnQuit;

    private:
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};

#endif // SPYSIMMAIN_H
