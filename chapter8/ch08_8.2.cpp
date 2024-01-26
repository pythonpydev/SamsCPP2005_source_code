// Listing 8.2. Manipulating data by using pointers.



     #include <iostream.h>



     typedef unsigned short int USHORT;

     int main()

     {

        USHORT myAge;         // a variable

        USHORT * pAge = 0;    // a pointer

       myAge = 5;

       cout << "myAge: " << myAge << "\n";



       pAge = &myAge;     // assign address of myAge to pAge



       cout << "*pAge: " << *pAge << "\n\n";



       cout << "*pAge = 7\n";



       *pAge = 7;         // sets myAge to 7



       cout << "*pAge: " << *pAge << "\n";

       cout << "myAge: " << myAge << "\n\n";





       cout << "myAge = 9\n";



       myAge = 9;



       cout << "myAge: " << myAge << "\n";

       cout << "*pAge: " << *pAge << "\n";



    return 0;

 }

// end of script...
