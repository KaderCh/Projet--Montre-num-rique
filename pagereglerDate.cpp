#include "pagereglerDate.h"
#include"myAppMain.h"
#include <wx/wx.h>
#include<iostream>
using namespace std;
BEGIN_EVENT_TABLE(PageReglerDate, wxFrame)
EVT_BUTTON(ID_Vd,PageReglerDate::validerd)
END_EVENT_TABLE()
PageReglerDate::PageReglerDate(wxFrame *frame, const wxString& title,wxWindow *pred) : wxFrame(frame, -1, title),m_pred(pred)
{
    SetMinSize(wxSize(800,600));
    SetMaxSize(wxSize(800,600));
    panel_3 = new wxPanel(this);
    wxStaticText *nom = new wxStaticText(panel_3,wxID_ANY, "REGLAGE DE LA DATE",wxPoint(250,10),wxSize(300,70));
    wxStaticText *njour=new wxStaticText(panel_3,wxID_ANY, "Jour",wxPoint(200,100),wxSize(60,50));
     wxStaticText *ndate=new wxStaticText(panel_3,wxID_ANY, "Date",wxPoint(200,150),wxSize(60,50));
      wxStaticText *nmois=new wxStaticText(panel_3,wxID_ANY, "Mois",wxPoint(200,200),wxSize(60,50));
       wxStaticText *nannee=new wxStaticText(panel_3,wxID_ANY, "Annee",wxPoint(200,250),wxSize(60,50));
       wxStaticText *def=new wxStaticText(panel_3,wxID_ANY, "Renseigner le jour avec les chiffres de 1 à 7. Considérant 1 pour Lundi et 7 pour dimanche",wxPoint(50,450),wxSize(700,50));
    jour = new wxTextCtrl(panel_3, ID_j, wxEmptyString, wxPoint(310,90),wxSize(70,30));
   date = new wxTextCtrl(panel_3, ID_d, wxEmptyString, wxPoint(310,140),wxSize(70,30));
    mois = new wxTextCtrl(panel_3, ID_m, wxEmptyString, wxPoint(310,190),wxSize(70,30));
   annee= new wxTextCtrl(panel_3, ID_an, wxEmptyString, wxPoint(310,240),wxSize(70,30));
    bvalider= new wxButton(panel_3,ID_Vd,"VALIDER",wxPoint(100,350),wxSize(100,30));
    bannuler= new wxButton(panel_3,ID_Ad,"ANNULER",wxPoint(500,350),wxSize(100,30));
    Connect(ID_Ad,wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageReglerDate::annulerd));
}

PageReglerDate::~PageReglerDate()
{

}
void PageReglerDate::annulerd(wxCommandEvent& event)
{
 Close();
    m_pred->Show();
}
void PageReglerDate::validerd(wxCommandEvent& event)
{
    int a,b,c,d;

a=atoi(jour->GetValue().c_str());
b=atoi(date->GetValue().c_str());
c=atoi(mois->GetValue().c_str());
d=atoi(annee->GetValue().c_str());
if(a==7)
{
    a=6;
}
 if(a>=0&&a<=6&&b>=0&&b<=31&&c>=1&&c<=12&&d>=0)
    {
  myAppFrame* frame = new myAppFrame(0L, _("wxWidgets Application Template"),a,b,c,d);
    frame->Show();
 Close();
    }
}


