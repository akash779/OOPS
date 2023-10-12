//OOP
#include<iostream>
using namespace std;

class Person //Class Person Created
{
    public:  //Access Modifier
    int age; //properties or data members


};

int main()
{ 

    Person ramesh; //Creation Of Object
    cout<<"Enter Age of Ramesh ";
    cin>>ramesh.age; // By Using . (dot) One Can Access Data Members of OBJECT RAMESH WHICH IS OF CLASS PERSON  
    cout<<"Ramesh Age if: "<<ramesh.age; 
    return 0;
}