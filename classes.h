#ifndef CLASSES_H
#define CLASSES_H
#include"myAppMain.h"
#include<string>
#ifndef WX_PRECOMP
#include <wx/wx.h>

#endif

class Heure
{
private:

public:
    int heure;
	int minute;
    int seconde;
	Heure();
	recupHeure();
	modifierHeure(int , int);
};
class Date
{
private:


public:
    std::string jr;
    int jour;
	int date;
	int mois;
	int annee;
	Date();
	recupDate();
	modifierDate(int, int ,int ,int);
};
class Chronometre: public Heure
{
	private:


	public:
	    int i=0;
		Chronometre();

};
class Minuteur: public Heure
{
private:

public:
    Minuteur();
    int i=0;
    int j=0;
    int a,b,c;

};
class Reveil
{
private:

public:
    int j,u=0,heure,h,son,minute,seconde;
	//int jour[7];
	Reveil();
	recup();
	sonner();
	arreterSon();
};
#endif
