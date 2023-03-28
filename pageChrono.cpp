#include "pageChrono.h"
#include"myAppMain.h"
#include <wx/wx.h>
#include "classes.h"
BEGIN_EVENT_TABLE(PageChrono, wxFrame)
EVT_TIMER(TIMER_IDC, PageChrono::Ontimer)
 EVT_BUTTON(ID_lc,PageChrono::lancerc)
 EVT_BUTTON(ID_ac,PageChrono::arreterc)
 EVT_BUTTON(ID_rc,PageChrono::reinitialiserc)
END_EVENT_TABLE()

PageChrono::PageChrono(wxFrame *frame, const wxString& title,wxWindow *prec) : wxFrame(frame, -1, title),m_prec(prec),m_timer(this, TIMER_IDC)
{
    m_timer.Start(1000);
    SetMinSize(wxSize(800,500));
    SetMaxSize(wxSize(800,500));
    panel_4 = new wxPanel(this);
    wxStaticText *nom = new wxStaticText(panel_4,wxID_ANY, "CHRONOMETRE",wxPoint(350,10),wxSize(300,70));
    heure= new wxTextCtrl(panel_4, ID_hc, '0', wxPoint(100,90),wxSize(70,30));
    minute= new wxTextCtrl(panel_4, ID_mc, '0', wxPoint(300,90),wxSize(70,30));
   seconde= new wxTextCtrl(panel_4, ID_sc, '0', wxPoint(500,90),wxSize(70,30));
  heure->Disable();
   minute->Disable();
   seconde->Disable();
   wxStaticText *point1 = new wxStaticText(panel_4,wxID_ANY, ":",wxPoint(250,100),wxSize(5,50));
      wxStaticText *point2= new wxStaticText(panel_4,wxID_ANY, ":",wxPoint(450,100),wxSize(5,50));
    blancer= new wxButton(panel_4,ID_lc,"LANCER",wxPoint(100,190),wxSize(100,30));
    barreter= new wxButton(panel_4,ID_ac,"ARRETER",wxPoint(300,190),wxSize(100,30));
    breinitialiser= new wxButton(panel_4,ID_rc,"REINITIALISER",wxPoint(500,190),wxSize(100,30));
    bquitter= new wxButton(panel_4,ID_qc,"QUITTER",wxPoint(300,350),wxSize(100,30));
    Connect(ID_qc,wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageChrono::annulerc));
}
PageChrono::~PageChrono()
{

}
void PageChrono::Ontimer(wxTimerEvent& event)
{
    if(C.i==1)
    {
 C.seconde ++;
    if(C.seconde==60)
    {
        C.seconde=0; C.minute++;
    }
    if(C.minute ==60)
    {
        C.minute=0;C.heure++;
    }
    if(C.heure==24)
    {
        C.heure=0;
    }
            ma_secondec.Printf(_("%d"),C.seconde);
            ma_minutec.Printf(_("%d"),C.minute);
            mon_heurec.Printf(_("%d"),C.heure);

    if (C.heure<10)
    {
        heure->SetLabel(zero+=mon_heurec);
        zero="0";
    }
    else
    {
        heure->SetLabel(mon_heurec);
         zero="0";
    }
      if (C.minute<10)
    {
        minute->SetLabel(zero+=ma_minutec);
         zero="0";
    }
    else
    {
        minute->SetLabel(ma_minutec);
    }
      if (C.seconde<10)
    {
        seconde->SetLabel(zero+=ma_secondec);
         zero="0";
    }
    else
    {
        seconde->SetLabel(ma_secondec);
    }
    }
}
void PageChrono::annulerc(wxCommandEvent& event)
{
 Close();
    m_prec->Show();
}
void PageChrono::lancerc(wxCommandEvent& event)
{
C.i=1;
}
void PageChrono::arreterc(wxCommandEvent& event)
{
C.i=0;
}
void PageChrono::reinitialiserc(wxCommandEvent& event)
{
    C.i=0;
C.minute=0;
C.heure=0;
C.seconde=0;
 ma_secondec.Printf(_("%d"),C.seconde);
ma_minutec.Printf(_("%d"),C.minute);
mon_heurec.Printf(_("%d"),C.heure);
    if (C.heure<10)
    {
        heure->SetLabel(zero+=mon_heurec);
        zero="0";
    }
    else
    {
        heure->SetLabel(mon_heurec);
         zero="0";
    }
      if (C.minute<10)
    {
        minute->SetLabel(zero+=ma_minutec);
         zero="0";
    }
    else
    {
        minute->SetLabel(ma_minutec);
    }
      if (C.seconde<10)
    {
        seconde->SetLabel(zero+=ma_secondec);
         zero="0";
    }
    else
    {
        seconde->SetLabel(ma_secondec);
    }
    }

