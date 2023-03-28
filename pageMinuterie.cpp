#include "pageMinuterie.h"
#include "classes.h"
#include"myAppMain.h"
#include <wx/wx.h>
#include<iostream>
using namespace std;
BEGIN_EVENT_TABLE(PageMinuterie, wxFrame)
EVT_TIMER(TIMER_IDM, PageMinuterie::Ontimer)
 EVT_BUTTON(ID_lm,PageMinuterie::lancerm)
 EVT_BUTTON(ID_am,PageMinuterie::arreterm)
 EVT_BUTTON(ID_rm,PageMinuterie::redemarrerm)
END_EVENT_TABLE()

PageMinuterie::PageMinuterie(wxFrame *frame, const wxString& title,wxWindow *prem) : wxFrame(frame, -1, title),m_prem(prem),m_timer(this, TIMER_IDM)
{
     m_timer.Start(1000);
    SetMinSize(wxSize(800,500));
    SetMaxSize(wxSize(800,500));
    panel_5 = new wxPanel(this);
    wxStaticText *nom = new wxStaticText(panel_5,wxID_ANY, "MINUTERIE",wxPoint(350,10),wxSize(300,70));
     wxStaticText *point1 = new wxStaticText(panel_5,wxID_ANY, ":",wxPoint(250,100),wxSize(5,50));
      wxStaticText *point2= new wxStaticText(panel_5,wxID_ANY, ":",wxPoint(450,100),wxSize(5,50));
    heure= new wxTextCtrl(panel_5, ID_hm, wxEmptyString, wxPoint(100,90),wxSize(70,30));
    minute= new wxTextCtrl(panel_5, ID_mm, wxEmptyString, wxPoint(300,90),wxSize(70,30));
   seconde= new wxTextCtrl(panel_5, ID_sm, wxEmptyString, wxPoint(500,90),wxSize(70,30));
    blancer= new wxButton(panel_5,ID_lm,"LANCER",wxPoint(100,190),wxSize(100,30));
    barreter= new wxButton(panel_5,ID_am,"PAUSE/RELANCER",wxPoint(300,190),wxSize(100,30));
    bredemarrer= new wxButton(panel_5,ID_rm,"REINITIALISER",wxPoint(500,190),wxSize(100,30));
    bquitter= new wxButton(panel_5,ID_qm,"QUITTER",wxPoint(300,350),wxSize(100,30));
    Connect(ID_qm,wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PageMinuterie::annulerm));
}
PageMinuterie::~PageMinuterie()
{

}
void PageMinuterie::Ontimer(wxTimerEvent& event)
{
    if(M.i==1)
    {
 M.seconde --;
    if(M.seconde==-1)
    {
        M.seconde=59; M.minute--;
    }
    if(M.minute ==-1)
    {
        M.minute=59;M.heure--;
    }
    if(M.heure==0&&M.minute==0&&M.seconde==0)
    {
        M.i=0;
    }
            ma_secondem.Printf(_("%d"),M.seconde);
                    ma_minutem.Printf(_("%d"),M.minute);
                    mon_heurem.Printf(_("%d"),M.heure);
         if (M.heure<10)
    {
        heure->SetLabel(zero+=mon_heurem);
        zero="0";
    }
    else
    {
        heure->SetLabel(mon_heurem);
         zero="0";
    }
      if (M.minute<10)
    {
        minute->SetLabel(zero+=ma_minutem);
         zero="0";
    }
    else
    {
        minute->SetLabel(ma_minutem);
    }
      if (M.seconde<10)
    {
        seconde->SetLabel(zero+=ma_secondem);
         zero="0";
    }
    else
    {
        seconde->SetLabel(ma_secondem);
    }
}
}
 void PageMinuterie::annulerm(wxCommandEvent& event)
{
   Close();
    m_prem->Show();
}
 void PageMinuterie::lancerm(wxCommandEvent& event)
 {
M.heure=atoi(heure->GetValue().c_str());
M.minute=atoi(minute->GetValue().c_str());
M.seconde=atoi(seconde->GetValue().c_str());
M.a=M.heure;
M.b=M.minute;
M.c=M.seconde;
if(M.heure>=0 && M.heure<=23 && M.minute>=0 && M.minute<=59 && M.seconde>=0&&M.seconde<=59)
{
M.i=1;
}
 }
  void PageMinuterie::arreterm(wxCommandEvent& event)
  {
      if(M.j%2==0)
      {
          M.i=0;
      }
      else
      {
          M.i=1;
      }
      M.j++;
  }
   void PageMinuterie::redemarrerm(wxCommandEvent& event)
  {
      M.i=0;
      M.heure=M.a;
     M.minute=M.b;
     M.seconde=M.c;

     ma_secondem.Printf(_("%d"),M.seconde);
    ma_minutem.Printf(_("%d"),M.minute);
mon_heurem.Printf(_("%d"),M.heure);

      if (M.heure<10)
    {
        heure->SetLabel(zero+=mon_heurem);
        zero="0";
    }
    else
    {
        heure->SetLabel(mon_heurem);
         zero="0";
    }
      if (M.minute<10)
    {
        minute->SetLabel(zero+=ma_minutem);
         zero="0";
    }
    else
    {
        minute->SetLabel(ma_minutem);
    }
      if (M.seconde<10)
    {
        seconde->SetLabel(zero+=ma_secondem);
         zero="0";
    }
    else
    {
        seconde->SetLabel(ma_secondem);
    }
  }




