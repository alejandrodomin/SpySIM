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
enum wxbuildinfoformat {
    short_f, long_f };

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
    SetClientSize(wxSize(534,397));
    Button1 = new wxButton(this, ID_BUTTON1, _("Play"), wxRealPoint(432,344), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Panel1 = new wxPanel(this, ID_PANEL1, wxRealPoint(0,0), wxSize(288,296), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Timer: "), wxRealPoint(312,72), wxSize(72,17), 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Current Floor: "), wxRealPoint(312,104), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Score: "), wxRealPoint(320,136), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("How to Play:"), wxRealPoint(320,168), wxSize(176,144), 0, _T("ID_STATICTEXT4"));
    Panel2 = new wxPanel(this, ID_PANEL2, wxRealPoint(0,328), wxSize(368,64), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Stats go in here"), wxRealPoint(128,32), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    wxString __wxRadioBoxChoices_1[3] =
    {
    	_("Easy"),
    	_("Medium"),
    	_("Hard")
    };
    RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Difficulty"), wxRealPoint(312,8), wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
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

void SpySIMFrame::OnRadioBox1Select(wxCommandEvent& event)
{
    wxSize panel_size = Panel1->GetClientSize();
    int selection = RadioBox1->GetSelection();

    if(selection == 0){
        tile_size = panel_size.GetWidth() / (15 + panel_size.GetWidth()*0.025);
        call_horiz=15-1;}// 15 *5
    else if(selection == 1){
        tile_size = panel_size.GetWidth() / (10 + panel_size.GetWidth()*0.025);
        call_horiz=10-1;} // 10 *5
    else if(selection == 2){
        tile_size = panel_size.GetWidth() / (5 + panel_size.GetWidth()*0.025);
        call_horiz=5-1;} // 5 *5

    center = new wxRealPoint(panel_size.GetWidth()*0.025,panel_size.GetHeight()/2);
    center2 = new wxRealPoint(panel_size.GetWidth()*0.025,panel_size.GetHeight()/4);
    center3 = new wxRealPoint(panel_size.GetWidth()*0.025,panel_size.GetHeight()/1.3);
    player = new wxRealPoint(*center3);
    player->x += tile_size ;
    player->y -= tile_size / 4;
    Draw(selection);

    // easy     75
    // medium   50
    // hard     25
}
wxStopWatch sw;
bool start=false;
void SpySIMFrame::OnButton1Click(wxCommandEvent& event)
{
    sw.Start();
    start=true;


}

int i=0;
void SpySIMFrame::Draw(int difficulty)
{

    wxClientDC dc(Panel1);
    dc.Clear();



    Grid floor1(tile_size);
    floor1.DrawIsoGrid(*center,RadioBox1,Panel1);
    Grid floor2(tile_size);
    floor2.DrawIsoGrid(*center2,RadioBox1,Panel1);
    Grid floor3(tile_size);
    floor3.DrawIsoGrid(*center3,RadioBox1,Panel1);

    if(i==0)
    dc.DrawCircle(*player, 1);


/*
    centers= new wxRealPoint*[5];
    int stepx=0;
    int stepy=0;
    for (int i=1; i<5;i++){
            centers [i-1]=new wxRealPoint[5];
        for (int j=1;j<5;j++){
                centers[i-1][j-1].x=center->x+(tile_size*j);
                centers[i-1][j-1].y=center->y+(tile_size/4);
        }
        stepx+=tile_size/(1/cos(PI/6));
        stepy-=tile_size / 2;
    }


/*

        centers[i+j-2].x=center->x+(tile_size*j)+stepx;
        centers[i+j-2].y=center->y- (tile_size / 4)+stepy;

        stepx+=tile_size/(1/cos(PI/6));
        stepy-=tile_size / 2;

*/

i=1;

}

void SpySIMFrame::KeyMove(wxKeyEvent& event)
{
    double yVert = tile_size / 2;
    double yHoriz = tile_size/(1/cos(PI/6));

    if (start){
    wxClientDC dc(Panel1);
    dc.Clear();


    Draw(RadioBox1->GetSelection());

    switch(event.GetKeyCode()){
        case WXK_LEFT : case WXK_CONTROL_A:
            if (call2>0){
            player->x -= tile_size;
            call2--;
            }
            break;
        case WXK_RIGHT : case WXK_CONTROL_D:
            if (call2<call_horiz){
            player->x += tile_size;
            call2++;
            }
            break;
        case WXK_UP : case WXK_CONTROL_W:
            if (call<4){
            player->x += yHoriz;
            player->y -= yVert;
            call++;
            }
            break;
        case WXK_DOWN : case WXK_CONTROL_S:
            if (call>0){
            player->x -= yHoriz;
            player->y += yVert;
            call--;
            }
            break;
    }

    dc.SetBrush(*wxGREEN_BRUSH);
    dc.DrawCircle(*player, 1);
    }
}

void SpySIMFrame::OnIdle(wxIdleEvent& event){
    wxClientDC dc(Panel1);
    if (start){
    double timer = (double)sw.Time()/1000;
    StaticText1->SetLabel(wxString::Format(wxT("Timer: %lf"),timer));
    srand ( time(NULL) );
    int Rand = rand() %(5*call_horiz);
    //dc.DrawCircle(centers[Rand][2], 1);
    event.Skip();
    }

}

int Score(double time){
    int score;
    if (time<= 30 ){
        score=200;
    }
    else if (time<= 60 ){
        score=100;
    }
    else if (time<= 90 ){
        score=50;
    }
    else {
        score=25;
    }

    return score;


}


