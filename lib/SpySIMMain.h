/***************************************************************
 * Name:      SpySIMMain.h
 * Purpose:   Defines Application Frame
 * Author:    Alejandro Dominguez (adomi120@fiu.edu)
 * Created:   2018-03-31
 * Copyright: Alejandro Dominguez ()
 * License:
 **************************************************************/

#ifndef SPYSIMMAIN_H
#define SPYSIMMAIN_H

# define PI          3.141592653589793238462643383279502884L
#include <wx/msgdlg.h>
#include "wx/wx.h"
#include "wx/sizer.h"
#include <wx/event.h>
#include <thread>
#include <wx/stopwatch.h>
#include <tgmath.h>
#include <time.h>
#include <wx/timer.h>
#include <math.h>

#include "player.h"
#include "ai.h"
#include "ladder.h"


//(*Headers(SpySIMFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
//*)
#include <wx/wfstream.h>

class SpySIMFrame: public wxFrame
{
    public:

        SpySIMFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SpySIMFrame();
        void OnIdle(wxIdleEvent& event);
        double tile_size;
        int num_tiles;
        void AImove();

    private:

        //(*Handlers(SpySIMFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnRadioBox1Select(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnSaveButtonClick(wxCommandEvent& event);
        void OnLoadButtonClick(wxCommandEvent& event);
        //*)
        void Draw(int difficulty);
        void DrawIsoGrid(wxRealPoint& point, wxRadioBox* RadioBox);
        void DrawIsoRow(wxRealPoint& point, int difficulty);
        void DrawIsoSquare(wxRealPoint& point);

        void KeyMove(wxKeyEvent& event);
        void Teleport(Player, wxRealPoint);
        void Score(double);


        //(*Identifiers(SpySIMFrame)
        static const long ID_PANEL1;
        static const long ID_RADIOBOX1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_PANEL2;
        static const long ID_BUTTON1;
        static const long ID_SAVE_BUTTON;
        static const long ID_BUTTON3;
        static const long ID_LOAD_BUTTON;
        static const long idMenuQuit;
        static const long idMenuSave;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)
        /*
        wxRealPoint *center;
        wxRealPoint *center2;
        wxRealPoint *center3;
        */
        int floor=0;
        int call=0;
        int call2=0;
        int call_horiz;
        int score=0;
        bool endgame=false;
        bool wongame=false;
        wxRealPoint *player;
        wxRealPoint *centers[3];

        Player *bob;
        AI *skel;
        AI *skel2;
        Ladder *lad, *lad2,*lad3;
        AI *objective;

        //(*Declarations(SpySIMFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* SaveButton;
        wxButton* Button1;
        wxButton* Button3;
        wxStaticText* StaticText1;
        wxPanel* Panel2;
        wxStaticText* StaticText3;
        wxMenuItem* MenuItem3;
        wxStaticText* flr_Count;
        wxButton* LoadButton;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        wxRadioBox* RadioBox1;
        wxStaticText* StaticText6;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SPYSIMMAIN_H
