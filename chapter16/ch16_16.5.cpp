// Listing 16.6. Using get() with a character array.

     #include <iostream.h>



     int main()

     {

        char stringOne[256];

        char stringTwo[256];



        cout << "Enter string one: ";

       cin.get(stringOne,256);

       cout << "stringOne: " << stringOne << endl;



       cout << "Enter string two: ";

       cin >> stringTwo;

       cout << "StringTwo: " << stringTwo << endl;

     return 0;

 }

// end of script...
