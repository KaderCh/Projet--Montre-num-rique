#include "pagereglerheure.h"
#include"myAppMain.h"
#include <wx/wx.h>
BEGIN_EVENT_TABLE(PageReglerHeure, wxFrame)
EVT_BUTTON(ID_v,PageReglerHeure::valider)
END_EVENT_TABLE()
PageReglerHeure::PageReglerHeure(wxFrame *frame, const wxString& title,wxWindow *pre) : wxFrame(frame, -1, title),m_pre(pre)
{
    SetMinSize(wxSize(800,500));
    SetMaxSize(wxSize(800,500));
    panel_2 = new wxPanel(this);
    wxStaticText *nom = new wxStaticText(panel_2,wxID_ANY, "REGLAGE DE L'HEURE",wxPoint(250,10),wxSize(300,70));
    wxStaticText *nheure =new wxStaticText(panel_2,wxID_ANY, "HEURE",wxPoint(200,100),wxSize(60,50));
     heure = new wxTextCtrl(panel_2, ID_he, '0', wxPoint(310,90),wxSize(70,30));
    wxStaticText *nminute=new wxStaticText(panel_2,wxID_ANY, "MINUTE",wxPoint(200,200),wxSize(60,50));
   minute = new wxTextCtrl(panel_2, ID_min,'0', wxPoint(310,190),wxSize(70,30));
    bvalider= new wxButton(panel_2, ID_v,"VALIDER",wxPoint(100,300),wxSize(100,30));
    bannuler= new wxButton(panel_2, ID_a,"ANNULER",wxPoint(500,300),wxSize(100,30));
    Connect(ID_a,wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageReglerHeure::annuler));
    //connect(ID_v, wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(PageReglerHeure::valider));
}
PageReglerHeure::~PageReglerHeure()
{

}
void PageReglerHeure::annuler(wxCommandEvent& event)
{
    Close();
    m_pre->Show();
}
void PageReglerHeure::valider(wxCommandEvent& event)
{
int a,b;
a=atoi(heure->GetValue().c_str());
b=atoi(minute->GetValue().c_str());
 if(a>=0&&a<=23&&b>=0&&b<=59)
    {
  myAppFrame* frame = new myAppFrame(0L, _("wxWidgets Application Template"),a,b);
    frame->Show();
 Close();
    }
    }
