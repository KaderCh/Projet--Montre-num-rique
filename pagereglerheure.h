#ifndef PAGEREGLERHEURE_H
#define PAGEREGLERHEURE_H
#include"myAppMain.h"
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class PageReglerHeure: public wxFrame
{
    public:

        PageReglerHeure(wxFrame *frame, const wxString& title,wxWindow*pre);
        ~PageReglerHeure();
private:
    enum
        {
            ID_he=0,
            ID_min,
            ID_v,
            ID_a
        };
         DECLARE_EVENT_TABLE()
        wxWindow *m_pre;
        wxPanel *panel_2;
        wxTextCtrl *heure;
        wxTextCtrl *minute;
        wxButton *bvalider;
        wxButton *bannuler;
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void annuler(wxCommandEvent& event);
      void valider(wxCommandEvent& event);

};

#endif // PAGEREGLERHEURE_H
