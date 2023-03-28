
#include "pageReveil.h"
#include"myAppMain.h"
#include "classes.h"
#include "PageAlarme.h"
#include <wx/wx.h>
#include"PageAlarme.h"
BEGIN_EVENT_TABLE(PageReveil, wxFrame)
EVT_BUTTON(ID_vr,PageReveil::validerr)
EVT_BUTTON(ID_sr,PageReveil::supprimerr)
END_EVENT_TABLE()
PageReveil::PageReveil(wxFrame *frame, const wxString& title, wxWindow *prer) : wxFrame(frame, -1, title), m_prer(prer)
{
    SetMinSize(wxSize(800,600));
    SetMaxSize(wxSize(800,600));
    panel_6= new wxPanel(this);
    wxStaticText *nom = new wxStaticText(panel_6,wxID_ANY, "Regler un Reveil",wxPoint(250,10),wxSize(300,70));
    wxStaticText *nheure =new wxStaticText(panel_6,wxID_ANY, "HEURE",wxPoint(100,100),wxSize(60,50));
     heure = new wxTextCtrl(panel_6, ID_hr, '6', wxPoint(210,90),wxSize(70,30));
    wxStaticText *nminute=new wxStaticText(panel_6,wxID_ANY, "MINUTE",wxPoint(100,200),wxSize(60,50));
   minute = new wxTextCtrl(panel_6, ID_mr, '0', wxPoint(210,190),wxSize(70,30));
    bvalider= new wxButton(panel_6, ID_vr,"VALIDER",wxPoint(100,500),wxSize(100,30));
    bannuler= new wxButton(panel_6, ID_ar,"ANNULER",wxPoint(500,500),wxSize(100,30));
    bsupprimer=new wxButton (panel_6,ID_sr,"SUPPRIMER ALARME",wxPoint(265,500),wxSize(150,30));
    D=new wxCheckBox(panel_6,ID_D,"Dimanche",wxPoint(100,290),wxSize(70,30));
    L=new wxCheckBox(panel_6,ID_L,"Lundi",wxPoint(100,340),wxSize(70,30));
    M=new wxCheckBox(panel_6,ID_M,"Mardi",wxPoint(100,390),wxSize(70,30));
    Me=new wxCheckBox(panel_6,ID_Me,"Mercredi",wxPoint(100,440),wxSize(70,30));
    J=new wxCheckBox(panel_6,ID_J,"Jeudi",wxPoint(400,290),wxSize(70,30));
    V=new wxCheckBox(panel_6,ID_V,"Vendredi",wxPoint(400,340),wxSize(70,30));
    S=new wxCheckBox(panel_6,ID_S,"Samedi",wxPoint(400,390),wxSize(70,30));
    for(int i=0;i<6;i++)
    {
        jour[i]=0;
    }
     Connect(ID_ar,wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageReveil::annulerr));
}
PageReveil::~PageReveil()
{

}
void PageReveil::annulerr(wxCommandEvent& event)
{
 Close();
    m_prer->Show();
}
void PageReveil::validerr(wxCommandEvent& event)
{
    hr=atoi(heure->GetValue().c_str());
    mr=atoi(minute->GetValue().c_str());
    if(D->GetValue())
    {
        jour[0]=1;
    }
    if(L->GetValue())
    {
        jour[1]=1;
    }
    if(M->GetValue())
    {
        jour[2]=1;
    }
    if(Me->GetValue())
    {
        jour[3]=1;
    }
    if(V->GetValue())
    {
        jour[5]=1;
    }
    if(S->GetValue())
    {
        jour[6]=1;
    }
    if(J->GetValue())
    {
        jour[4]=1;
    }
    if(hr>=0&&hr<=23&&mr>=0&&mr<59)
    {
    myAppFrame* frame = new myAppFrame(0L, _("wxWidgets Application Template"),hr,mr,jour);
    frame->Show();
 Close();
    }
}
void PageReveil::supprimerr(wxCommandEvent& event)
{
    for(int i=0;i<6;i++)
    {
        jour[i]=0;
    }
 heure->SetLabel('6');
  minute->SetLabel('0');
}
