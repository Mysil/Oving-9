#include "Dummy.h"
#include <iostream> 

using namespace std; 



void dummyTest() 
{
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;
    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;
    *b.num = 3;
    *c.num = 5;
    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;
    cout << c.num << endl; 
    cout << a.num << endl; 
}

//I de fire første linjene oprettes det en "shallow copy" av alle objektene 
//av typen Dummy. Det vil si at a,b og c peker det til den samme lokasjonen i minne.
//Og når vi i første omgang dereferer til objektene vil alle ha den samme verdien, 4. 
//Det samme skjer i andre omgang, lokasjonen i minne settes til 5 før a,b og c skrives ut.

//Programmet kræsjer etter siste linje. Jeg antar at dette har noe med destruktøren å gjøre, 
//her har vi tre objekter som alle peker til samme minnelokasjon, hvilke av objektene er ansvarlig for å 
//rydde opp og slette minne? Antar at den første destruktøren som kjøres går uten exceptions, mens når 
//nummer to kjøres vil den prøve å slette en lokasjon i minne som ikke eksisterer. 


