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
const long SpySIMFrame::ID_PANEL1 = wxNewId();
const long SpySIMFrame::ID_RADIOBOX1 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT1 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT2 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT3 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT4 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT5 = wxNewId();
const long SpySIMFrame::ID_STATICTEXT6 = wxNewId();
const long SpySIMFrame::ID_PANEL2 = wxNewId();
const long SpySIMFrame::ID_BUTTON1 = wxNewId();
const long SpySIMFrame::ID_SAVE_BUTTON = wxNewId();
const long SpySIMFrame::ID_BUTTON3 = wxNewId();
const long SpySIMFrame::ID_LOAD_BUTTON = wxNewId();
const long SpySIMFrame::idMenuQuit = wxNewId();
const long SpySIMFrame::idMenuSave = wxNewId();
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
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(2, 2, 0, 0);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(458,354), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(2, 1, 0, 0);
    wxString __wxRadioBoxChoices_1[3] =
    {
    	_("Easy"),
    	_("Medium"),
    	_("Hard")
    };
    RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Difficulty"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
    FlexGridSizer2->Add(RadioBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(3, 2, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Timer:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer4->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer4->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Floor:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer4->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    flr_Count = new wxStaticText(this, ID_STATICTEXT4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer4->Add(flr_Count, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Score:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer4->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer4->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxSize(235,81), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    FlexGridSizer1->Add(Panel2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SaveButton = new wxButton(this, ID_SAVE_BUTTON, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SAVE_BUTTON"));
    FlexGridSizer3->Add(SaveButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer3->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LoadButton = new wxButton(this, ID_LOAD_BUTTON, _("Load"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_LOAD_BUTTON"));
    FlexGridSizer3->Add(LoadButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4, CTRL-W"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuItem3 = new wxMenuItem(Menu1, idMenuSave, _("Save\tCTRL-S"), _("Saves the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
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
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&SpySIMFrame::OnRadioBox1Select);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SpySIMFrame::OnButton1Click);
    Connect(ID_SAVE_BUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SpySIMFrame::OnSaveButtonClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SpySIMFrame::OnQuit);
    Connect(ID_LOAD_BUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SpySIMFrame::OnLoadButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SpySIMFrame::OnQuit);
    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SpySIMFrame::OnSaveButtonClick);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SpySIMFrame::OnAbout);
    //*)
    Panel1->Bind(wxEVT_CHAR_HOOK,&SpySIMFrame::KeyMove, this);
    Button1->Enable(false);
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

    Button1->Enable(true);

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
    flr_Count->SetLabel(wxString::Format(wxT("%i"),floor));
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

    LoadButton->Enable(false);
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
        endgame=skel->View(bob->loc);
        lad->DrawLadder(Panel1);
        lad2->DrawLadder(Panel1);
        lad3->DrawLadder(Panel1);
    }
    LoadButton->Enable(false);
}


void SpySIMFrame::Teleport(Player old, wxRealPoint nFloor)
{
    floor++;
    int xmvs = old.RetCall();
    int ymvs = old.RetCall2();
    bob = new Player(nFloor, tile_size, call_horiz);
    for (int i=0;i<ymvs;i++){bob->moveRight();}
    for (int i=0;i<=xmvs;i++){bob->moveUp();}
    flr_Count->SetLabel(wxString::Format(wxT("%i"),floor));
}



void SpySIMFrame::OnIdle(wxIdleEvent& event)
{

    wxClientDC dc(Panel1);
    if (start)
    {

        if (endgame){
            wxMessageBox(_("Finished"));
            endgame=false;
        }
        double timer = (double)sw.Time()/1000;
        StaticText2->SetLabel(wxString::Format(wxT("%lf"),timer));
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



void SpySIMFrame::OnSaveButtonClick(wxCommandEvent& event)
{
    wxFileDialog saveFileDialog(this, _("Save SPY file"), "", "", "SPY files (*.spy)|*.spy", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    // save the current contents in the file;
    // this can be done with e.g. wxWidgets output streams:
    wxFileOutputStream output_stream(saveFileDialog.GetPath());
    if (!output_stream.IsOk())
    {
        wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
        return;
    }

    LoadButton->Enable(true);
}

void SpySIMFrame::OnLoadButtonClick(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, _("Open SPY file"), "", "", "SPY files (*.spy)|*.spy", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    // proceed loading the file chosen by the user;
    // this can be done with e.g. wxWidgets input streams:
    wxFileInputStream input_stream(openFileDialog.GetPath());
    if (!input_stream.IsOk())
    {
        wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
        return;
    }
}
