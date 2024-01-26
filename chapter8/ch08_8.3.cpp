// Listing 8.3. Finding out what is stored in pointers.



     #include <iostream.h>



     typedef unsigned short int USHORT;

     int main()

     {

        unsigned short int myAge = 5, yourAge = 10;

        unsigned short int * pAge = &myAge;  // a pointer



       cout << "myAge:\t" << myAge <<  "\tyourAge:\t" << yourAge << "\n";

       cout << "&myAge:\t" << &myAge <<  "\t&yourAge:\t" << &yourAge <<"\n";



       cout << "pAge:\t" << pAge << "\n";

       cout << "*pAge:\t" << *pAge << "\n";



       pAge = &yourAge;       // reassign the pointer



       cout << "myAge:\t" << myAge <<  "\tyourAge:\t" << yourAge << "\n";

       cout << "&myAge:\t" << &myAge <<  "\t&yourAge:\t" << &yourAge <<"\n";



       cout << "pAge:\t" << pAge << "\n";

       cout << "*pAge:\t" << *pAge << "\n";



       cout << "&pAge:\t" << &pAge << "\n";

    return 0;

 }

// end of script...
