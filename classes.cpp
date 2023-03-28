#include"myAppMain.h"
#include <wx/wx.h>
#include "classes.h"
#include<string>
#include <ctime>
#include<stdlib.h>
Heure::Heure()
{
	recupHeure();

}
Heure::recupHeure()
{
	time_t t =time(0);
	tm*now=localtime(&t);
	heure=now->tm_hour;
	minute=now->tm_min;
	seconde=now->tm_sec;
}
Heure::modifierHeure(int a , int b)
{
heure =a;
minute= b;
seconde=0;
}
Date::Date()
{
		recupDate();

}
Date::recupDate()
{

	time_t t =time(0);
	tm*now=localtime(&t);
	jour=now->tm_wday;
	annee=now->tm_year+1900;
	mois=now->tm_mon +1;
	date=now->tm_mday;
	if (jour==0)
    {
        jr="Dimanche";
    }
    else if (jour==1)
         {
       jr="Lundi";
       }
    else if (jour==2)
     {
       jr="Mardi";
       }
    else if (jour==3)
     {
           jr="Mercredi";
           }
    else if (jour==4)
     {
           jr="Jeudi";
           }

    else if (jour==5)
         {
       jr="Vendredi";
    }
    else
     {
       jr="Samedi";
   }
}
Date::modifierDate(int a, int b, int c, int d)
{
jour=a;
date=b;
mois=c;
annee=d;
}
Chronometre::Chronometre()
{
minute=0;
heure=0;
seconde=0;
}
Minuteur::Minuteur()
{
  minute=0;
  heure=0;
seconde=0;
}
Reveil::Reveil()
{
    son=1;
    u=0;
    heure=6;
    minute=0;
    seconde=0;
}
Reveil::recup()
{
    time_t t =time(0);
	tm*now=localtime(&t);
	j=now->tm_wday;
}

