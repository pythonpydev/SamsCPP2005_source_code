// Listing 16.4. Using get() with no parameters.

     #include <iostream.h>



     int main()

     {

        char ch;

        while ( (ch = cin.get()) != EOF)

        {

           cout << "ch: " << ch << endl;

       }

       cout << "\nDone!\n";

     return 0;

 }

// end of script...
