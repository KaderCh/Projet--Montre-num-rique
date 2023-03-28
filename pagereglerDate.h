#ifndef PAGEREGLERDATE_H
#define PAGEREGLERDATE_H
#include"myAppMain.h"
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class PageReglerDate: public wxFrame
{
    public:

        PageReglerDate(wxFrame *frame, const wxString& title,wxWindow* pred);
        ~PageReglerDate();
private:
     enum
        {
            ID_j=1000,
            ID_d,
            ID_m,
            ID_an,
            ID_Ad,
            ID_Vd
        };
        DECLARE_EVENT_TABLE()
        wxWindow *m_pred;
        wxPanel *panel_3;
        wxTextCtrl *jour;
        wxTextCtrl *date;
        wxTextCtrl *mois;
        wxTextCtrl *annee;
        wxButton *bvalider;
        wxButton *bannuler;
     void annulerd(wxCommandEvent& event);
    void validerd(wxCommandEvent& event);


};

#endif // PAGEREGLERHEURE_H
