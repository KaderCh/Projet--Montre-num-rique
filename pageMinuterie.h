#ifndef PAGEMINUTERIE_H
#define PAGEMINUTERIE_H
#include"myAppMain.h"
#include "classes.h"
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class PageMinuterie: public wxFrame
{
    public:
        std:: string zero="0";
        PageMinuterie(wxFrame *frame, const wxString& title,wxWindow *prem);
        ~PageMinuterie();
        void Ontimer(wxTimerEvent& event);
private:
     enum
        {
            ID_hm,
            ID_mm,
            ID_sm,
            ID_lm,
            ID_am,
            ID_rm,
            ID_qm,
            TIMER_IDM

        };
        DECLARE_EVENT_TABLE()
        wxTimer m_timer;
        Minuteur M;
        wxWindow *m_prem;
        wxPanel *panel_5;
        wxTextCtrl *heure;
        wxTextCtrl*minute;
        wxTextCtrl *seconde;
        wxButton *barreter;
        wxButton *blancer;
         wxButton *bredemarrer;
          wxButton *bquitter;
           wxString ma_secondem;
        wxString ma_minutem;
        wxString mon_heurem;
        void annulerm (wxCommandEvent& event);
        void lancerm(wxCommandEvent& event);
        void arreterm(wxCommandEvent& event);
        void redemarrerm(wxCommandEvent& event);


};

#endif
