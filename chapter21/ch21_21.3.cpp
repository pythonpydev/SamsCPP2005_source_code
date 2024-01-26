// Listing 21.3. Using strncpy().

     #include <iostream.h>

     #include <string.h>



     int main()

     {

        char stringOne[80];

        char stringTwo[10];

        char stringThree[80];



       stringOne[0]='\0';

       stringTwo[0]='\0';

       stringThree[0]='\0';



       cout << "String One: " << stringOne << endl;

       cout << "String Two: " << stringTwo << endl;

       cout << "String Three: " << stringThree << endl;



       cout << "Enter a long string: ";

       cin.getline(stringOne,80);

       strcpy(stringThree,stringOne);

      //   strcpy(stringTwo,stringOne);



       cout << "\nString One: " << stringOne << endl;

       cout << "String Two: " << stringTwo << endl;

       cout << "String Three: " << stringThree << endl;



       strncpy(stringTwo,stringOne,9);



       cout << "\nString One: " << stringOne << endl;

       cout << "String Two: " << stringTwo << endl;

       cout << "String Three: " << stringThree << endl;



       stringTwo[9]='\0';



       cout << "\nString One: " << stringOne << endl;

       cout << "String Two: " << stringTwo << endl;

       cout << "String Three: " << stringThree << endl;

       cout << "\nDone." << endl;

     return 0;

 }

// end of script...
