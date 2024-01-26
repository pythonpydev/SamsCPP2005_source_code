// Listing 16.8. Using ignore().

     #include <iostream.h>



     int main()

     {

        char stringOne[255];

        char stringTwo[255];



        cout << "Enter string one:";

       cin.get(stringOne,255);

       cout << "String one" << stringOne << endl;



       cout << "Enter string two: ";

       cin.getline(stringTwo,255);

       cout << "String two: " << stringTwo << endl;



       cout << "\n\nNow try again...\n";



       cout << "Enter string one: ";

       cin.get(stringOne,255);

       cout << "String one: " << stringOne<< endl;



       cin.ignore(255,'\n');



       cout << "Enter string two: ";

       cin.getline(stringTwo,255);

       cout << "String Two: " << stringTwo<< endl;

     return 0;

 }

// end of script...
