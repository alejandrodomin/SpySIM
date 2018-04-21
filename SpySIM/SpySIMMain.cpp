/***************************************************************
 * Name:      SpySIMMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Alejandro Dominguez (adomi120@fiu.edu)
 * Created:   2018-03-31
 * Copyright: Alejandro Dominguez ()
 * License:
 **************************************************************/

#include "SpySIMMain.h"
#include "grid.h"

//(*InternalHeaders(SpySIMFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(SpySIMFrame)
const long SpySIMFrame::ID_BUTTON1 = wxNewId();
const long SpySIMFrame::ID_PANEL1 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT1 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT2 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT3 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT4 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT5 = wxNewId();
const long SpySIMFrame::ID_PANEL2 = wxNewId();
const long SpySIMFrame::ID_RADIOBOX1 = wxNewId();
const long SpySIMFrame::idMenuQuit = wxNewId();
const long SpySIMFrame::idMenuAbout = wxNewId();
const long SpySIMFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SpySIMFrame,wxFrame)
    //(*EventTable(SpySIMFrame)
    //*)
    EVT_IDLE(SpySIMFrame::OnIdle)
END_EVENT_TABLE()

SpySIMFrame::SpySIMFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SpySIMFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(833,748));
    Button1 = new wxButton(this, ID_BUTTON1, _("Play"), wxPoint(432,600), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(600,500), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Timer: "), wxPoint(616,64), wxSize(200,17), 0, _T("ID_STATICTEXT1"));
    flr_Count = new wxStaticText(this, ID_STATICTEXT2, _("Current Floor: "), wxPoint(616,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Score: "), wxPoint(616,120), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("How to Play:"), wxPoint(624,160), wxSize(176,144), 0, _T("ID_STATICTEXT4"));
    Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(0,600), wxSize(368,64), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Stats go in here"), wxPoint(128,32), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    wxString __wxRadioBoxChoices_1[3] =
    {
    	_("Easy"),
    	_("Medium"),
    	_("Hard")
    };
    RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Difficulty"), wxPoint(616,8), wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SpySIMFrame::OnButton1Click);
    Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&SpySIMFrame::OnRadioBox1Select);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SpySIMFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SpySIMFrame::OnAbout);
    //*)
    Panel1->Bind(wxEVT_CHAR_HOOK,&SpySIMFrame::KeyMove, this);
}

SpySIMFrame::~SpySIMFrame()
{
    //(*Destroy(SpySIMFrame)
    //*)
}

void SpySIMFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SpySIMFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

//centers[3];


void SpySIMFrame::OnRadioBox1Select(wxCommandEvent& event)
{
    wxSize panel_size = Panel1->GetClientSize();
    int selection = RadioBox1->GetSelection();

    if(selection == 0)
    {
        tile_size = panel_size.GetWidth() / (15 + panel_size.GetWidth()*0.025);
        call_horiz=15-1;
    }// 15 *5
    else if(selection == 1)
    {
        tile_size = panel_size.GetWidth() / (10 + panel_size.GetWidth()*0.025);
        call_horiz=10-1;
    } // 10 *5
    else if(selection == 2)
    {
        tile_size = panel_size.GetWidth() / (5 + panel_size.GetWidth()*0.025);
        call_horiz=5-1;
    } // 5 *5

    centers[0] = new wxRealPoint(panel_size.GetWidth()*0.025,panel_size.GetHeight()/2); //middle center
    centers[1] = new wxRealPoint(panel_size.GetWidth()*0.025,panel_size.GetHeight()/4);//top center2
    centers[2] = new wxRealPoint(panel_size.GetWidth()*0.025,panel_size.GetHeight()/1.3);//bottom  center3
    player = new wxRealPoint(*centers[1]);
    player->x += tile_size ;
    player->y -= tile_size / 4;
    Draw(selection);

    // easy     75
    // medium   50
    // hard     25
}
wxStopWatch sw;

bool start=false;
void AImove();

void SpySIMFrame::OnButton1Click(wxCommandEvent& event)
{
    sw.Start();

    start=true;

    bob = new Player(*centers[2], tile_size, call_horiz);
    bob->DrawActor(Panel1);
    floor=1;
    flr_Count->SetLabel(wxString::Format(wxT("Current Floor: %i"),floor));
    skel = new AI(*centers[1], tile_size, call_horiz);
    skel->DrawActor(Panel1);

    wxRealPoint ladd = *centers[0];
    wxRealPoint ladd2 = *centers[1];
    wxRealPoint ladd3 = *centers[2];


    int difficulty = RadioBox1->GetSelection();
    int num_tiles = 0;
    if(difficulty == 0)
        num_tiles = 15;
    else if(difficulty == 1)
        num_tiles = 10;
    else if(difficulty == 2)
        num_tiles = 5;

    ladd.x += ((num_tiles - 1) * tile_size) + (tile_size / 2);
    ladd.y -= (4 * (tile_size / 2)) - (tile_size / 2);

    ladd2.x += ((num_tiles - 1) * tile_size) + (tile_size / 2);
    ladd2.y -= (4 * (tile_size / 2)) - (tile_size / 2);

    ladd3.x += ((num_tiles - 1) * tile_size) + (tile_size / 2);
    ladd3.y -= (4 * (tile_size / 2)) - (tile_size / 2);

    lad = new Ladder(ladd, tile_size);
    lad->DrawLadder(Panel1);
    lad2 = new Ladder(ladd2, tile_size);
    lad2->DrawLadder(Panel1);
    lad3 = new Ladder(ladd3, tile_size);
    lad3->DrawLadder(Panel1);


//    AI *bobby = new AI();
//    bobby->DrawActor(Panel1);
}

void SpySIMFrame::Draw(int difficulty)
{
    wxClientDC dc(Panel1);
    dc.Clear();



    Grid floor1(tile_size);
    floor1.DrawIsoGrid(*centers[0],RadioBox1,Panel1);
    Grid floor2(tile_size);
    floor2.DrawIsoGrid(*centers[1],RadioBox1,Panel1);
    Grid floor3(tile_size);
    floor3.DrawIsoGrid(*centers[2],RadioBox1,Panel1);
}

void SpySIMFrame::KeyMove(wxKeyEvent& event)
{
    double yVert = tile_size / 2;
    double yHoriz = tile_size/(1/cos(PI/6));

    if (start)
    {
        wxClientDC dc(Panel1);
        dc.Clear();


        Draw(RadioBox1->GetSelection());

        switch(event.GetKeyCode())
        {
        case WXK_LEFT :
        case WXK_CONTROL_A:
            bob->moveLeft();

            break;
        case WXK_RIGHT :
        case WXK_CONTROL_D:
            bob->moveRight();

            break;
        case WXK_UP :
        case WXK_CONTROL_W:
            bob->moveUp();

            break;
        case WXK_DOWN :
        case WXK_CONTROL_S:
            bob->moveDown();

            break;
        }

        if((((bob->loc->x - lad->loc->x) < 3.0) && ((bob->loc->x - lad->loc->x) > -3.0))
            && (((bob->loc->y - lad->loc->y) < 3.0) && ((bob->loc->y - lad->loc->y) > -3.0))
           ||(((bob->loc->x - lad2->loc->x) < 3.0) && ((bob->loc->x - lad2->loc->x) > -3.0))
            && (((bob->loc->y - lad2->loc->y) < 3.0) && ((bob->loc->y - lad2->loc->y) > -3.0))
           ||(((bob->loc->x - lad3->loc->x) < 3.0) && ((bob->loc->x - lad3->loc->x) > -3.0))
            && (((bob->loc->y - lad3->loc->y) < 3.0) && ((bob->loc->y - lad3->loc->y) > -3.0))) /*IF Player crosses Ladder*/
        {

            //bob = new Player(*center2, tile_size, call_horiz);
            //Teleport(*bob,*center2);
            if(floor==1) Teleport(*bob,*centers[0]);
            else if(floor==2) Teleport(*bob,*centers[1]);
            else if(floor==3){floor = 0; Teleport(*bob, *centers[2]); }
            int difficulty = RadioBox1->GetSelection();
            int num_tiles = 0;
            if(difficulty == 0)
                num_tiles = 15;
            else if(difficulty == 1)
                num_tiles = 10;
            else if(difficulty == 2)
                num_tiles = 5;

            //bob->loc->x += (num_tiles * tile_size);
            //bob->loc->y -= num_tiles * (tile_size / 8);
        }

        dc.SetBrush(*wxGREEN_BRUSH);
        bob->DrawActor(Panel1);
        skel->DrawActor(Panel1);
        lad->DrawLadder(Panel1);
        lad2->DrawLadder(Panel1);
        lad3->DrawLadder(Panel1);
    }
}


void SpySIMFrame::Teleport(Player old, wxRealPoint nFloor)
{
    floor++;
    int xmvs = old.RetCall();
    int ymvs = old.RetCall2();
    bob = new Player(nFloor, tile_size, call_horiz);
    for (int i=0;i<ymvs;i++){bob->moveRight();}
    for (int i=0;i<=xmvs;i++){bob->moveUp();}
    flr_Count->SetLabel(wxString::Format(wxT("Current Floor: %i"),floor));

}



void SpySIMFrame::OnIdle(wxIdleEvent& event)
{
    wxClientDC dc(Panel1);
    if (start)
    {
        double timer = (double)sw.Time()/1000;
        StaticText1->SetLabel(wxString::Format(wxT("Timer: %lf"),timer));
        AImove();
        event.Skip();
    }


}

void SpySIMFrame::AImove()
{
    wxClientDC dc(Panel1);
    if((sw.Time()%2000)==0)
    {
        srand ( time(NULL) );
        int nrand= rand()%4;
        switch(nrand)
        {
        case 0:
            skel->moveLeft();
            break;
        case 1:
            skel->moveRight();
            break;
        case 2:
            skel->moveUp();
            break;
        case 3:
            skel->moveDown();
            break;

        }


        dc.Clear();
        Draw(RadioBox1->GetSelection());
        bob->DrawActor(Panel1);
        skel->DrawActor(Panel1);
        lad->DrawLadder(Panel1);
        lad2->DrawLadder(Panel1);
        lad3->DrawLadder(Panel1);
    }


}

int Score(double time)
{
    int score;
    if (time<= 30 )
    {
        score=200;
    }
    else if (time<= 60 )
    {
        score=100;
    }
    else if (time<= 90 )
    {
        score=50;
    }
    else
    {
        score=25;
    }

    return score;


}


