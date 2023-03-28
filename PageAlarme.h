#ifndef PAGEALARME_H
#define PAGEALARME_H

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include"myAppMain.h"
#include "classes.h"
#include<windows.h>

class PageAlarme: public wxFrame
{
    public:
PageAlarme(wxFrame *frame, const wxString& title );
        void arretera(wxCommandEvent& event);
    private:
        enum
        {
            ID_aa,
        };
        DECLARE_EVENT_TABLE()
         wxWindow *m_prea;
        wxPanel *panel_7;
        wxButton *barreter;

};
#endif
