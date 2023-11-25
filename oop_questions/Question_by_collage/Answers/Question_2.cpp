/*2)
 Create two classes DM and DB which store the value of distances. DM stores distances in
meters and centimeters and DB in feet and inches. Write a program that can read values
for the class objects and add one object of DM with another object of DB. Use a friend
function to carry out the addition operation. The object that stores the results may be a
DM object or DB object, depending on the units in which the results are required. The
display should be in the format of feet and inches or meters and centimeters depending on
the object on display.*/

#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
class DB;
class DM;

class DM
{
    private:
    int m;
    int cm;
    friend DM sum_DM(DM,DB);
    friend DB sum_DB(DM,DB);
    public:
    DM(){cout<<"DM Class Object Created Successfully";
        cout<<endl<<"Enter Meter Value: ";
        cin>>m;
        cout<<endl<<"Enter Centi-Meter Value: ";
        cin>>cm;}


    

    };

class DB
{
    public:
    int ft;
    int in;

friend DM sum_DM(DM,DB);
friend DB sum_DB(DM,DB);
DB(){cout<<endl<<"DB Class Object Created Successfully";
        cout<<endl<<"Enter Feet Value: ";
        cin>>ft;
        cout<<endl<<"Enter Inch Value: ";
        cin>>in;}
};
DM sum_DM(DM obj1,DB obj2)
{
    obj1.m=obj1.m+(obj2.ft*0.3048);//1ft=0.3048 meters
    obj1.cm=obj1.cm+(obj2.in*2.54);//1 Inch = 2.54cm 
    cout<<endl<<"sum of both object are stored in dm: ";
    cout<<endl<<"Meter: "<<obj1.m;
    cout<<ends<<"    Centi-Meter: "<<obj1.cm<<endl<<endl;
}
DB sum_DB(DM obj1, DB obj2)
{
    obj2.ft=obj2.ft+(obj1.m*3.28084);//1meter=3.28084feet
    obj2.in=obj2.in+(obj1.cm*0.3937);//1cm=0.3937 inch
    cout<<"sum of both object stored in db:";
    cout<<endl<<"Feet: "<<obj2.ft;
    cout<<"    Inch: "<<obj2.in<<endl<<endl;
}

int main()
{   DM x;
    DB y;
    int opt;
        system("cls");
    while (opt!=0)
    {   
        cout<<endl<<"Press 1 to Sum both class object";
        cout<<endl<<"Press 0 to Exit From Programe";
        cout<<endl<<"Enter Option: ";
        cin>>opt;
        
        if(opt==1)
        {   system("cls");
            int check;
            cout<<"Press 1 For Result in DM";
            cout<<endl<<"Press 2 For Result in DB";
            cout<<endl<<"Enter Option: ";
            cin>>check;
            if(check==1){system("cls");sum_DM(x,y);}
            else if(check==2){system("cls");sum_DB(x,y);}
            else{cout<<"wrong input";}
        }
        

    }
    
}
