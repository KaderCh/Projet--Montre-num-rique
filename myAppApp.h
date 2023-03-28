/***************************************************************
 * Name:      myAppApp.h
 * Purpose:   Defines Application Class
 * Author:     ()
 * Created:   2022-01-21
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef MYAPPAPP_H
#define MYAPPAPP_H
#include "pagereglerheure.h"
#include "pagereglerDate.h"
#include "pageChrono.h"
#include "pageMinuterie.h"
#include "pageReveil.h"
#include <wx/app.h>

class myAppApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // MYAPPAPP_H
