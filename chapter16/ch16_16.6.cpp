// Listing 16.7. Using getline().

     #include <iostream.h>



     int main()

     {

        char stringOne[256];

        char stringTwo[256];

        char stringThree[256];



       cout << "Enter string one: ";

       cin.getline(stringOne,256);

       cout << "stringOne: " << stringOne << endl;



       cout << "Enter string two: ";

       cin >> stringTwo;

       cout << "stringTwo: " << stringTwo << endl;



       cout << "Enter string three: ";

       cin.getline(stringThree,256);

       cout << "stringThree: " << stringThree << endl;

     return 0;

 }

// end of script...
