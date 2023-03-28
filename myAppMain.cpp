/***************************************************************
 * Name:      myAppMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2022-01-21
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif
#include "pagereglerheure.h"
#include<string>
#include "pagereglerDate.h"
#include "pageChrono.h"
#include "pageMinuterie.h"
#include "pageReveil.h"
#include"PageAlarme.h"
#include "classes.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "myAppMain.h"

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
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
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

BEGIN_EVENT_TABLE(myAppFrame, wxFrame)
EVT_TIMER(TIMER_ID, myAppFrame::OnTimer)
    EVT_BUTTON(ID_rH,myAppFrame::ReglerHeure)
    EVT_BUTTON(ID_rD,myAppFrame::ReglerDate)
    EVT_BUTTON(wxID_EXIT,myAppFrame::OnQuit)
    EVT_BUTTON(ID_chrono,myAppFrame::Chrono)
    EVT_BUTTON(ID_minuterie,myAppFrame::Minuterie)
    EVT_BUTTON(ID_reveil,myAppFrame::Reveil)
    EVT_BUTTON(ID_Rd,myAppFrame::resetDate)
     EVT_BUTTON(ID_Rh,myAppFrame::resetHeure)
    EVT_CLOSE(myAppFrame::OnClose)
    EVT_MENU(idMenuQuit, myAppFrame::OnQuit)
    EVT_MENU(idMenuAbout, myAppFrame::OnAbout)
END_EVENT_TABLE()
myAppFrame::myAppFrame(wxFrame *frame, const wxString& title, int a, int b)
: wxFrame(frame, -1, title),m_timer(this, TIMER_ID)
 {
     R.minute=100;R.heure=100;
   m_timer.Start(1000);
        SetMinSize(wxSize(900,700));
    SetMaxSize(wxSize(900,700));
    panel_1 = new wxPanel(this);
    wxStaticText *nom = new wxStaticText(panel_1,wxID_ANY, "MONTRE A AFFICHAGE NUMERIQUE",wxPoint(350,10),wxSize(600,70));
    wxStaticText *point = new wxStaticText(panel_1,wxID_ANY, ":",wxPoint(350,100),wxSize(5,50));
    wxStaticText *point1 = new wxStaticText(panel_1,wxID_ANY, ":",wxPoint(550,100),wxSize(5,50));
    wxStaticText *du = new wxStaticText(panel_1,wxID_ANY, "DU",wxPoint(10,205),wxSize(20,50));
    heure = new wxStaticText(panel_1, ID_heure, wxEmptyString, wxPoint(200,100),wxSize(100,100));
    minute = new wxStaticText(panel_1, ID_minute, wxEmptyString, wxPoint(400,100),wxSize(100,100));
    seconde = new wxStaticText(panel_1, ID_seconde, wxEmptyString, wxPoint(600,100),wxSize(100,100));
   jour = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(100,200),wxSize(100,30));
    date = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(300,200),wxSize(100,30));
      mois = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(500,200),wxSize(100,30));
      annee = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(700,200),wxSize(100,30));
      reglerHeure= new wxButton(panel_1, ID_rH,"Regler l'heure",wxPoint(100,300),wxSize(170,30));
      reglerDate= new wxButton(panel_1, ID_rD,"Regler la date ",wxPoint(700,300),wxSize(100,30));
      chrono= new wxButton(panel_1, ID_chrono,"Lancer un chronomètre",wxPoint(100,400),wxSize(170,30));
      minuterie= new wxButton(panel_1, ID_minuterie,"Minuterie",wxPoint(450,400),wxSize(100,30));
     reveil= new wxButton(panel_1, ID_reveil,"Regler un reveil",wxPoint(700,400),wxSize(100,30));
      quitter= new wxButton(panel_1, wxID_EXIT,"QUITTER",wxPoint(700,500),wxSize(100,30));
      rDate=new wxButton(panel_1,ID_Rd,"RESET DATE",wxPoint(500,500),wxSize(100,30));
      rHeure=new wxButton(panel_1,ID_Rh,"RESET HEURE",wxPoint(300,500),wxSize(100,30));
      H.modifierHeure(a,b);
      quitter->Enable();
 }
  myAppFrame::myAppFrame(wxFrame *frame, const wxString& title, int a, int b,int c, int d)
   : wxFrame(frame, -1, title),m_timer(this, TIMER_ID)
   {
       R.minute=100;R.heure=100;
      m_timer.Start(1000);
        SetMinSize(wxSize(900,700));
    SetMaxSize(wxSize(900,700));
    panel_1 = new wxPanel(this);
    wxStaticText *nom = new wxStaticText(panel_1,wxID_ANY, "MONTRE A AFFICHAGE NUMERIQUE",wxPoint(350,10),wxSize(600,70));
    wxStaticText *point = new wxStaticText(panel_1,wxID_ANY, ":",wxPoint(350,100),wxSize(5,50));
    wxStaticText *point1 = new wxStaticText(panel_1,wxID_ANY, ":",wxPoint(550,100),wxSize(5,50));
    wxStaticText *du = new wxStaticText(panel_1,wxID_ANY, "DU",wxPoint(10,205),wxSize(20,50));
    heure = new wxStaticText(panel_1, ID_heure, wxEmptyString, wxPoint(200,100),wxSize(100,100));
    minute = new wxStaticText(panel_1, ID_minute, wxEmptyString, wxPoint(400,100),wxSize(100,100));
    seconde = new wxStaticText(panel_1, ID_seconde, wxEmptyString, wxPoint(600,100),wxSize(100,100));
   jour = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(100,200),wxSize(100,30));
    date = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(300,200),wxSize(100,30));
      mois = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(500,200),wxSize(100,30));
      annee = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(700,200),wxSize(100,30));
      reglerHeure= new wxButton(panel_1, ID_rH,"Regler l'heure",wxPoint(100,300),wxSize(170,30));
      reglerDate= new wxButton(panel_1, ID_rD,"Regler la date ",wxPoint(700,300),wxSize(100,30));
      chrono= new wxButton(panel_1, ID_chrono,"Lancer un chronomètre",wxPoint(100,400),wxSize(170,30));
      minuterie= new wxButton(panel_1, ID_minuterie,"Minuterie",wxPoint(450,400),wxSize(100,30));
     reveil= new wxButton(panel_1, ID_reveil,"Regler un reveil",wxPoint(700,400),wxSize(100,30));
     rDate=new wxButton(panel_1,ID_Rd,"RESET DATE",wxPoint(500,500),wxSize(100,30));
      rHeure=new wxButton(panel_1,ID_Rh,"RESET HEURE",wxPoint(300,500),wxSize(100,30));
      quitter= new wxButton(panel_1, wxID_EXIT,"QUITTER",wxPoint(700,500),wxSize(100,30));

      D.modifierDate(a,b,c,d);
   }
myAppFrame::myAppFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title),m_timer(this, TIMER_ID)
{
    //this->SetBackgroundColour(*wxBLACK);
    m_timer.Start(1000);
    R.minute=100;R.heure=100;
        SetMinSize(wxSize(900,700));
    SetMaxSize(wxSize(900,700));
    panel_1 = new wxPanel(this);
    wxStaticText *nom = new wxStaticText(panel_1,wxID_ANY, "MONTRE A AFFICHAGE NUMERIQUE",wxPoint(350,10),wxSize(600,70));
    wxStaticText *point = new wxStaticText(panel_1,wxID_ANY, ":",wxPoint(350,100),wxSize(5,50));
    wxStaticText *point1 = new wxStaticText(panel_1,wxID_ANY, ":",wxPoint(550,100),wxSize(5,50));
    wxStaticText *du = new wxStaticText(panel_1,wxID_ANY, "DU",wxPoint(10,205),wxSize(20,50));
    heure = new wxStaticText(panel_1, ID_heure, wxEmptyString, wxPoint(200,100),wxSize(100,100));
    minute = new wxStaticText(panel_1, ID_minute, wxEmptyString, wxPoint(400,100),wxSize(100,100));
    seconde = new wxStaticText(panel_1, ID_seconde, wxEmptyString, wxPoint(600,100),wxSize(100,100));
   jour = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(100,200),wxSize(100,30));
    date = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(300,200),wxSize(100,30));
      mois = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(500,200),wxSize(100,30));
      annee = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(700,200),wxSize(100,30));
      reglerHeure= new wxButton(panel_1, ID_rH,"Regler l'heure",wxPoint(100,300),wxSize(170,30));
      reglerDate= new wxButton(panel_1, ID_rD,"Regler la date ",wxPoint(700,300),wxSize(100,30));
      chrono= new wxButton(panel_1, ID_chrono,"Lancer un chronomètre",wxPoint(100,400),wxSize(170,30));
      minuterie= new wxButton(panel_1, ID_minuterie,"Minuterie",wxPoint(450,400),wxSize(100,30));
     reveil= new wxButton(panel_1, ID_reveil,"Regler un reveil",wxPoint(700,400),wxSize(100,30));
      quitter= new wxButton(panel_1, wxID_EXIT,"QUITTER",wxPoint(700,500),wxSize(100,30));
      rDate=new wxButton(panel_1,ID_Rd,"RESET DATE",wxPoint(500,500),wxSize(100,30));
      rHeure=new wxButton(panel_1,ID_Rh,"RESET HEURE",wxPoint(300,500),wxSize(100,30));
      quitter->Enable();
}
void myAppFrame::resetDate(wxCommandEvent& event)
{
D.recupDate();
}
void myAppFrame::resetHeure(wxCommandEvent& event)
{
H.recupHeure();
}
 myAppFrame::myAppFrame(wxFrame *frame, const wxString& title, int a, int b,int jr[7])
 : wxFrame(frame, -1, title),m_timer(this, TIMER_ID)
 {
    R.u=1;R.heure=a; R.minute=b;
    for (int i=0; i<7; i++)
    {
        jrs[i]=jr[i];
    }
      m_timer.Start(1000);
        SetMinSize(wxSize(900,700));
    SetMaxSize(wxSize(900,700));
    panel_1 = new wxPanel(this);
    wxStaticText *nom = new wxStaticText(panel_1,wxID_ANY, "MONTRE A AFFICHAGE NUMERIQUE",wxPoint(350,10),wxSize(600,70));
    wxStaticText *point = new wxStaticText(panel_1,wxID_ANY, ":",wxPoint(350,100),wxSize(5,50));
    wxStaticText *point1 = new wxStaticText(panel_1,wxID_ANY, ":",wxPoint(550,100),wxSize(5,50));
    wxStaticText *du = new wxStaticText(panel_1,wxID_ANY, "DU",wxPoint(10,205),wxSize(20,50));
    heure = new wxStaticText(panel_1, ID_heure, wxEmptyString, wxPoint(200,100),wxSize(100,100));
    minute = new wxStaticText(panel_1, ID_minute, wxEmptyString, wxPoint(400,100),wxSize(100,100));
    seconde = new wxStaticText(panel_1, ID_seconde, wxEmptyString, wxPoint(600,100),wxSize(100,100));
   jour = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(100,200),wxSize(100,30));
    date = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(300,200),wxSize(100,30));
      mois = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(500,200),wxSize(100,30));
      annee = new wxStaticText(panel_1, ID_jour, wxEmptyString, wxPoint(700,200),wxSize(100,30));
      reglerHeure= new wxButton(panel_1, ID_rH,"Regler l'heure",wxPoint(100,300),wxSize(170,30));
      reglerDate= new wxButton(panel_1, ID_rD,"Regler la date ",wxPoint(700,300),wxSize(100,30));
      chrono= new wxButton(panel_1, ID_chrono,"Lancer un chronomètre",wxPoint(100,400),wxSize(170,30));
      minuterie= new wxButton(panel_1, ID_minuterie,"Minuterie",wxPoint(450,400),wxSize(100,30));
     reveil= new wxButton(panel_1, ID_reveil,"Regler un reveil",wxPoint(700,400),wxSize(100,30));
      quitter= new wxButton(panel_1, wxID_EXIT,"QUITTER",wxPoint(700,500),wxSize(100,30));
      rDate=new wxButton(panel_1,ID_Rd,"RESET DATE",wxPoint(500,500),wxSize(100,30));
      rHeure=new wxButton(panel_1,ID_Rh,"RESET HEURE",wxPoint(300,500),wxSize(100,30));
      quitter->Enable();
 }
void myAppFrame::OnTimer(wxTimerEvent& event)
{
    H.seconde ++;
    if(H.seconde==60)
    {
        H.seconde=0; H.minute++;
    }
    if(H.minute ==60)
    {
        H.minute=0;H.heure++;
    }
    if(H.heure==24)
    {
        H.heure=0;
    }
            ma_seconde.Printf(_("%d"),H.seconde);
            ma_minute.Printf(_("%d"),H.minute);
             mon_heure.Printf(_("%d"),H.heure);
    if (H.heure<10)
    {
        heure->SetLabel(zero+=mon_heure);
        zero="0";
    }
    else
    {
        heure->SetLabel(mon_heure);
         zero="0";
    }
      if (H.minute<10)
    {
        minute->SetLabel(zero+=ma_minute);
         zero="0";
    }
    else
    {
        minute->SetLabel(ma_minute);
    }
      if (H.seconde<10)
    {
        seconde->SetLabel(zero+=ma_seconde);
         zero="0";
    }
    else
    {
        seconde->SetLabel(ma_seconde);
    }
    if(H.heure==0 && H.minute==0 && H.seconde==0)
	{
		D.jour+=1;D.date+=1;
		if(D.mois==2)
			{

				if(D.date==29 && !( (D.annee%4==0 && !(D.annee%100==0))||(D.annee%400==0)))
				{
					D.mois=3; D.date=1;
				}
				if(D.date==30)
				{
					D.mois=3; D.date=1;
				}
			}

		if((D.mois==4||D.mois==6||D.mois==9||D.mois==11)&&D.date==31)
	    {
	    	D.date=1;D.mois=D.mois+1;

		}
		if((D.mois==1||D.mois==3||D.mois==5||D.mois==7||D.mois==8||D.mois==10||D.mois==12)&&D.date==32)
	    {
	    	D.date=1;
	    	if(D.mois==12)
	    	{
	    		D.mois=1;
	    		D.annee=D.annee+1;
	    	}
	    	else
	    	{
	    		D.mois=D.mois+1;
	    	}

		}


	}
	if (D.jour==0)
    {
        D.jr="Dimanche";
    }
    else if (D.jour==1)
         {
       D.jr="Lundi";
       }
    else if (D.jour==2)
     {
       D.jr="Mardi";
       }
    else if (D.jour==3)
     {
           D.jr="Mercredi";
           }
    else if (D.jour==4)
     {
           D.jr="Jeudi";
           }

    else if (D.jour==5)
         {
       D.jr="Vendredi";
    }
    else
     {
       D.jr="Samedi";
   }
	mon_mois.Printf(_("%d"),D.mois);
	mon_annee.Printf(_("%d"),D.annee);
	 ma_date.Printf(_("%d"),D.date);
    annee->SetLabel(mon_annee);


jour->SetLabel(D.jr);
	if (D.mois<10)
    {
        mois->SetLabel(zero+=mon_mois);
        zero="0";
    }
    else
    {
        mois->SetLabel(mon_mois);
    }
      if (D.date<10)
    {
        date->SetLabel(zero+=ma_date);
         zero="0";
    }
    else
    {
      date->SetLabel(ma_date);
    }
    R.recup();
 if(R.u==1);
 {
    if (jrs[R.j]==1&&H.heure==R.heure&&H.minute==R.minute&&H.seconde==0)
    {
    PageAlarme* frame = new PageAlarme(0l,_("Alarme"));
    frame->Show();
    }
 }
}



myAppFrame::~myAppFrame()
{
}

void myAppFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void myAppFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void myAppFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
 void myAppFrame::ReglerHeure(wxCommandEvent& event)
 {
    PageReglerHeure* frame = new PageReglerHeure(0l,_("Regler Heure"),this);
     Hide();
    frame->Show();

 }
 void myAppFrame::ReglerDate(wxCommandEvent& event)
 {
     PageReglerDate* frame = new PageReglerDate(0l,_("Regler Date"),this);
     Hide();
    frame->Show();
 }
 void myAppFrame::Chrono(wxCommandEvent& event)
 {
      PageChrono* frame = new PageChrono(0l,_("Chronometre"),this);
     Hide();
    frame->Show();
 }
 void myAppFrame::Minuterie(wxCommandEvent& event)
 {
     PageMinuterie* frame = new PageMinuterie(0l,_("Minuterie"),this);
     Hide();
    frame->Show();
 }
 void myAppFrame::Reveil(wxCommandEvent& event)
 {
    PageReveil* frame = new PageReveil(0l,_("Regler Reveil"),this);
     Hide();
    frame->Show();
 }
