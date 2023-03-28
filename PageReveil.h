#ifndef PAGEREVEIL_H
#define PAGEREVEIL_H
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include"PageAlarme.h"
#include "classes.h"
class PageReveil: public wxFrame
{
    public:

        PageReveil(wxFrame *frame, const wxString& title,wxWindow *prer);
        ~PageReveil();
private:
     enum
        {
            ID_hr,
            ID_mr,
            ID_ar,
            ID_sr,
            ID_vr,ID_L,ID_M,ID_Me,ID_J,ID_V,ID_S,ID_D,ID_M1,ID_M2,ID_M3

        };
         DECLARE_EVENT_TABLE()
         int jour[7];
         int hr,mr,son=1;

        wxWindow *m_prer;
        wxPanel *panel_6;
        wxTextCtrl *heure;
        wxTextCtrl *minute;
        wxCheckBox *L;
        wxCheckBox *M;
        wxCheckBox *Me;
        wxCheckBox *J;
        wxCheckBox *V;
        wxCheckBox *S;
        wxCheckBox *D;
        wxCheckBox *M1;
        wxCheckBox *M3;
        wxCheckBox *M2;
        wxButton *bvalider;
        wxButton *bannuler;
        wxButton *bsupprimer;
        void annulerr(wxCommandEvent& event);
        void validerr(wxCommandEvent& event);
        void supprimerr(wxCommandEvent& event);


};

#endif //

