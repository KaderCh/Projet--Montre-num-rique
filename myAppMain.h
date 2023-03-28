/***************************************************************
 * Name:      myAppMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2022-01-21
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef MYAPPMAIN_H
#define MYAPPMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "myAppApp.h"
#include<string>
#include "pagereglerheure.h"
#include "pagereglerDate.h"
#include "pageChrono.h"
#include "pageMinuterie.h"
#include "pageReveil.h"
#include "classes.h"
#include"PageAlarme.h"
class myAppFrame: public wxFrame
{
    public:
        myAppFrame(wxFrame *frame, const wxString& title);
          myAppFrame(wxFrame *frame, const wxString& title, int a, int b);
          myAppFrame(wxFrame *frame, const wxString& title, int a, int b,int c, int d);
           myAppFrame(wxFrame *frame, const wxString& title, int a, int b,int jour[7]);
        ~myAppFrame();
         void OnTimer(wxTimerEvent& event);
         Heure H;
         Reveil R;
         int jrs[7];
         std:: string zero="0";

    private:
        enum
        {

            idMenuQuit = 1000,
            idMenuAbout,
            ID_heure,
            ID_minute,
            ID_seconde,
            ID_jour,
             ID_date,
             ID_Rh,
             ID_Rd,
              ID_mois,
               ID_annee,
               ID_rH,
               ID_rD,
               ID_chrono,
               ID_reveil,
               ID_minuterie,
               ID_quitter,
                  TIMER_ID = wxID_HIGHEST +1
        };
         wxTimer m_timer;
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void ReglerHeure(wxCommandEvent& event);
        void ReglerDate(wxCommandEvent& event);
        void Chrono(wxCommandEvent& event);
        void Minuterie(wxCommandEvent& event);
        void Reveil(wxCommandEvent& event);
        void resetDate(wxCommandEvent& event);
        void resetHeure(wxCommandEvent& event);

        DECLARE_EVENT_TABLE()
        wxPanel *panel_1;
        wxStaticText * heure;
        wxStaticText * minute;
        wxStaticText * seconde;
        wxString ma_seconde;
        wxString ma_minute;
        wxString mon_heure;
        wxString mon_jour;
        wxString mon_mois;
        wxString mon_annee;
        wxString ma_date;
        wxStaticText * jour;
        wxStaticText * date;
        wxStaticText * mois;
        wxStaticText * annee;
        wxButton * reglerHeure ;
        wxButton * reglerDate;
        wxButton * chrono;
        wxButton * reveil;
        wxButton * minuterie;
        wxButton * quitter;
        wxButton *date0;
        wxButton *heure0;
        wxButton *rDate;
        wxButton *rHeure;
        Date D;

};


#endif // MYAPPMAIN_H
