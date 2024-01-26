// Listing 7.7. Demonstrates do...while loop.

      // Demonstrates do while



      #include <iostream.h>



      int main()

      {

         int counter;

         cout << "How many hellos? ";

        cin >> counter;

        do

        {

           cout << "Hello\n";

           counter--;

        }  while (counter >0 );

        cout << "Counter is: " << counter << endl;

         return 0;

 }

// end of script...
