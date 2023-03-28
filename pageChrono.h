#ifndef PAGECHRONO_H
#define PAGECHRONO_H

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include"myAppMain.h"
#include "classes.h"
class PageChrono: public wxFrame
{
    public:
    std:: string zero="0";
        PageChrono(wxFrame *frame, const wxString& title,wxWindow *prec);
        ~PageChrono();
        void Ontimer(wxTimerEvent& event);
private:
     enum
        {
            TIMER_IDC,
            ID_hc,
            ID_mc,
            ID_sc,
            ID_lc,
            ID_ac,
            ID_rc,
            ID_qc

        };
           DECLARE_EVENT_TABLE()
        Chronometre C;
         wxTimer m_timer;
        wxWindow *m_prec;
        wxPanel *panel_4;
         wxString ma_secondec;
        wxString ma_minutec;
        wxString mon_heurec;
        wxTextCtrl *heure;
        wxTextCtrl *minute;
        wxTextCtrl *seconde;
        wxButton *barreter;
        wxButton *blancer;
         wxButton *breinitialiser;
          wxButton *bquitter;
        void annulerc(wxCommandEvent& event);
        void lancerc(wxCommandEvent& event);
        void arreterc(wxCommandEvent& event);
       void reinitialiserc(wxCommandEvent& event);


};

#endif // PAGEREGLERHEURE_H

