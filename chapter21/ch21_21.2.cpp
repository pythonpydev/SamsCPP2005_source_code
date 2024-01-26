// Listing 21.2. Using strcpy.

     #include <iostream.h>

     #include <string.h>



     int main()

     {

        char stringOne80];

        char stringTwo80];



        stringOne0]='\0';

       stringTwo0]='\0';



       cout << "String One: " << stringOne << endl;

       cout << "String Two: " << stringTwo << endl;



       cout << "Enter a string: ";

       cin.getline(stringOne,80);



       cout << "\nString One: " << stringOne << endl;

       cout << "String Two: " << stringTwo << endl;



       cout << "copying..." << endl;

       strcpy(stringTwo,stringOne);



       cout << "\nString One: " << stringOne << endl;

       cout << "String Two: " << stringTwo << endl;

       cout << "\nDone " << endl;

     return 0;

 }

// end of script...
