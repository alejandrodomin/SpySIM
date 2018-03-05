/***************************************************************
 * Name:      LineDrawMain.h
 * Purpose:   Defines Application Frame
 * Author:    Alejandro Dominguez (adomi120@fiu.edu)
 * Created:   2018-02-14
 * Copyright: Alejandro Dominguez ()
 * License:
 **************************************************************/

#ifndef LINEDRAWMAIN_H
#define LINEDRAWMAIN_H

//(*Headers(LineDrawDialog)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/clrpicker.h>
//*)
#include <list>

class LineDrawDialog: public wxDialog
{
    public:

        LineDrawDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~LineDrawDialog();

    private:

        //(*Handlers(LineDrawDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(LineDrawDialog)
        static const long ID_PANEL1;
        static const long ID_BUTTON4;
        static const long ID_BUTTON3;
        static const long ID_COLOURPICKERCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(LineDrawDialog)
        wxPanel* Panel1;
        wxButton* Button4;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxBoxSizer* BoxSizer2;
        wxColourPickerCtrl* ColourPickerCtrl1;
        wxBoxSizer* BoxSizer1;
        //*)

        bool drawMode;
        int points_index;
        int total_numPoints;

        wxPoint points[100];

        wxColour lineColor;

        void OnSingleClick(wxMouseEvent& event);

        void paintEvent(wxPaintEvent & evt);
        void render(wxDC& dc);

        void selectColour(wxColourPickerEvent &event);

        void OnSave(wxCommandEvent &event);
        void OnOpen(wxCommandEvent &WXUNUSED(event));

        DECLARE_EVENT_TABLE()
};

#endif // LINEDRAWMAIN_H
