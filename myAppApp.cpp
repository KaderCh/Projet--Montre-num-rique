/***************************************************************
 * Name:      myAppApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2022-01-21
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "myAppApp.h"
#include "myAppMain.h"
#include "pagereglerheure.h"
#include "pagereglerDate.h"
#include "pageChrono.h"
#include "pageMinuterie.h"
#include "pageReveil.h"
IMPLEMENT_APP(myAppApp);

bool myAppApp::OnInit()
{
    myAppFrame* frame = new myAppFrame(0L, _("wxWidgets Application Template"));
    frame->Show();
    return true;
}
