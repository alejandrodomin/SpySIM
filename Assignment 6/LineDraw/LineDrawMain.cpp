/***************************************************************
 * Name:      LineDrawMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Alejandro Dominguez (adomi120@fiu.edu)
 * Created:   2018-02-14
 * Copyright: Alejandro Dominguez ()
 * License:
 **************************************************************/

#include "LineDrawMain.h"
#include <wx/msgdlg.h>
#include <iterator>
#include <wx/dcclient.h>
#include <wx/clrpicker.h>
#include <wx/colour.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/log.h>
#include <wx/xml/xml.h>

//(*InternalHeaders(LineDrawDialog)
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

//(*IdInit(LineDrawDialog)
const long LineDrawDialog::ID_PANEL1 = wxNewId();
const long LineDrawDialog::ID_BUTTON4 = wxNewId();
const long LineDrawDialog::ID_BUTTON3 = wxNewId();
const long LineDrawDialog::ID_COLOURPICKERCTRL1 = wxNewId();
const long LineDrawDialog::ID_BUTTON1 = wxNewId();
const long LineDrawDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LineDrawDialog,wxDialog)
    //(*EventTable(LineDrawDialog)
    //*)
    EVT_LEFT_UP(LineDrawDialog::OnSingleClick)
    EVT_PAINT(LineDrawDialog::paintEvent)
    EVT_COLOURPICKER_CHANGED(wxID_ANY,LineDrawDialog::selectColour)
END_EVENT_TABLE()

LineDrawDialog::LineDrawDialog(wxWindow* parent,wxWindowID id)
{
     points_index = 0;
    drawMode = false;
    //(*Initialize(LineDrawDialog)
    Create(parent, wxID_ANY, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(506,376));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(539,235), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Button4 = new wxButton(this, ID_BUTTON4, _("Open"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer2->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ColourPickerCtrl1 = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
    BoxSizer2->Add(ColourPickerCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LineDrawDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LineDrawDialog::OnQuit);
    //*)
    Panel1->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(LineDrawDialog::OnSingleClick), NULL, this);
    Panel1->Connect(wxEVT_LEFT_DCLICK, wxPaintEventHandler(LineDrawDialog::paintEvent), NULL, this);
    lineColor = *wxBLACK;

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LineDrawDialog::OnSave);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LineDrawDialog::OnOpen);
}

LineDrawDialog::~LineDrawDialog()
{
    //(*Destroy(LineDrawDialog)
    //*)
}

void LineDrawDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void LineDrawDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = "Single click to register points.\nDouble click to draw a line through those points.\nDouble click again to start over.";
    wxMessageBox(msg, _("How to play."));
}

void LineDrawDialog::OnSingleClick(wxMouseEvent& event)
{
    if(!drawMode){
    wxPoint point = event.GetPosition();
    points[points_index] = point;

    points_index++;
    total_numPoints = points_index;

    wxClientDC dc(Panel1);
    dc.SetPen(wxPen(wxColor(lineColor), 5));
    dc.DrawCircle(point, 3);
    }
}

void LineDrawDialog::paintEvent(wxPaintEvent & evt)
{
    wxClientDC dc(Panel1);
    render(dc);
}

void LineDrawDialog::render(wxDC&  dc)
{
    if(!drawMode){
        dc.SetPen(wxPen(wxColor(lineColor), 5));

        points_index--;
        while(points_index > 0){
            dc.DrawLine(points[points_index], points[(points_index - 1)]);

            points_index--;
        }
        drawMode = true;
        points_index = 0;
    }
    else {
        Panel1->Refresh();
        drawMode = false;
    }
}

void LineDrawDialog::selectColour(wxColourPickerEvent &event)
{
    lineColor = ColourPickerCtrl1->GetColour();
}

void LineDrawDialog::OnSave(wxCommandEvent &event)
{
    wxFileDialog saveFileDialog(this, _("Save drawing file"), "", "", "DRW files (*.drw)|*.drw", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    wxXmlDocument xmlDoc;
    wxXmlNode *root = new wxXmlNode(NULL, wxXML_ELEMENT_NODE, "Root");
    xmlDoc.SetRoot(root);

    wxXmlNode *color = new wxXmlNode(root, wxXML_ELEMENT_NODE, "Color");
    color->AddAttribute("color", lineColor.GetAsString(wxC2S_CSS_SYNTAX));

    wxXmlNode *xml_point = new wxXmlNode(root, wxXML_ELEMENT_NODE, "Points");
    xml_point->AddAttribute("points", "(x,y)");

    wxString pointx, pointy;
    wxXmlNode *xml_pointX, *xml_pointY;
    for(int index = 0; index < total_numPoints; index++){
        pointx << points[index].x;
        xml_pointX = new wxXmlNode(xml_point, wxXML_ELEMENT_NODE, "Point_X");
        xml_pointX->AddChild(new wxXmlNode(wxXML_TEXT_NODE, "", pointx));

        pointy << points[index].y;
        xml_pointY = new wxXmlNode(xml_point, wxXML_ELEMENT_NODE, "Point_Y");
        xml_pointY->AddChild(new wxXmlNode(wxXML_TEXT_NODE, "", pointy));
    }

    wxString extension = ".drw";
    xmlDoc.Save(saveFileDialog.GetPath() + extension, wxXML_NO_INDENTATION);
}

void LineDrawDialog::OnOpen(wxCommandEvent &WXUNUSED(event))
{
    if (false)
    {
        if (wxMessageBox(_("Current content has not been saved! Proceed?"), _("Please confirm"),
                         wxICON_QUESTION | wxYES_NO, this) == wxNO )
            return;
        //else: proceed asking to the user the new file to open
    }

    wxFileDialog openFileDialog(this, _("Save drawing file"), "", "", "DRW files (*.drw)|*.drw",  wxFD_OPEN|wxFD_FILE_MUST_EXIST);
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

    wxXmlDocument doc;
    if(!doc.Load(openFileDialog.GetPath()))
        return;

    if(doc.GetRoot()->GetName() != "Root");
        return;

    wxXmlNode *prolog = doc.GetDocumentNode()->GetChildren();
    while(prolog)
    {
        if(prolog->GetType() == wxXML_ELEMENT_NODE && prolog->GetName() == "Color")
        {
            lineColor = wxColour(prolog->GetContent());
        }
    }

    int pointx, pointy;
    int increment = 0;
    points_index = 0;
    wxXmlNode *child = doc.GetRoot()->GetChildren();
    while(child)
    {
        if(child->GetName() == "PointX")
        {
            pointx = wxAtoi(child->GetContent());
            points[points_index].x = pointx;
            increment++;
        }
        else if(child->GetName() == "PointY")
        {
            pointy = wxAtoi(child->GetContent());
            points[points_index].y = pointy;
            increment++;
        }

        if(increment == 2){
            points_index++;
            increment = 0;
        }
        child = child->GetNext();
    }

    points_index = 0;

    wxClientDC dc(Panel1);
    render(dc);
}
