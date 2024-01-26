// Listing 21.1. strlen().

     #include <iostream.h>

     #include <string.h>



     int main()

     {

        char buffer80];

        do

        {

           cout << "Enter a string up to 80 characters: ";

          cin.getline(buffer,80);

          cout << "Your string is " << strlen(buffer);

          cout << " characters long." << endl;

       }    while (strlen(buffer));

       cout << "\nDone." << endl;

     return 0;

 }

// end of script...
