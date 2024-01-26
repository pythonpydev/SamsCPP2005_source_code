// Listing 21.4. Using strcat() and strncat().

     #include <iostream.h>

     #include <string.h>





     int main()

     {

        char stringOne[255];

        char stringTwo[255];



       stringOne[0]='\0';

       stringTwo[0]='\0';



       cout << "Enter a  string: ";

       cin.getline(stringOne,80);



       cout << "Enter a second string: ";

       cin.getline(stringTwo,80);



       cout << "String One: " << stringOne << endl;

       cout << "String Two: " << stringTwo << endl;



       strcat(stringOne," ");

       strncat(stringOne,stringTwo,10);



       cout << "String One: " << stringOne << endl;

       cout << "String Two: " << stringTwo << endl;



     return 0;

 }

// end of script...
