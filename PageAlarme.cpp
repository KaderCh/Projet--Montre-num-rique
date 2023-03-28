#include "PageAlarme.h"
#include<iostream>
#include "classes.h"
#include"myAppMain.h"
#include"PageAlarme.h"
#include <wx/wx.h>
#include <wx/sound.h>
#include <windows.h>
#include<cstdio>
 #include<mmsystem.h>
 #pragma comment(lib,"winmm.lib")
 using namespace std;
BEGIN_EVENT_TABLE(PageAlarme, wxFrame)
EVT_BUTTON(ID_aa,PageAlarme::arretera)
END_EVENT_TABLE()
PageAlarme::PageAlarme(wxFrame *frame, const wxString& title) : wxFrame(frame, -1, title)
{
     SetMinSize(wxSize(800,500));
    SetMaxSize(wxSize(800,500));
    panel_7 = new wxPanel(this);
    wxPNGHandler *Handler =new wxPNGHandler;
    wxImage::AddHandler(Handler);
    wxStaticBitmap *image;
      barreter= new wxButton(panel_7,ID_aa,"ARRETER ALARME",wxPoint(320,400),wxSize(120,30));
   image = new wxStaticBitmap(panel_7,wxID_ANY,wxBitmap("image.png",wxBITMAP_TYPE_PNG),wxPoint(0,0),wxSize(800,500));
PlaySound(TEXT("C:\\Users\\22961\\Pictures\\myApp\\ALARME1.WAV"), NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
}
void PageAlarme::arretera(wxCommandEvent& event)
{
    PlaySound(NULL, NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
    Close();
}
