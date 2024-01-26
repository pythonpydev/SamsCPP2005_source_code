// Listing 8.9. Creating a stray pointer.

     // Demonstrates a stray pointer

     typedef unsigned short int USHORT;

     #include <iostream.h>



     int main()

     {

        USHORT * pInt = new USHORT;

        *pInt = 10;

       cout << "*pInt: " << *pInt << endl;

       delete pInt;

       pInt = 0;

       long * pLong = new long;

       *pLong = 90000;

       cout << "*pLong: " << *pLong << endl;



       *pInt = 20;      // uh oh, this was deleted!



       cout << "*pInt: " << *pInt  << endl;

       cout << "*pLong: " << *pLong  << endl;

       delete pLong;

    return 0;

 }

// end of script...
