// Listing 7.6. Skipping the body of the while Loop.

      // Demonstrates skipping the body of

      // the while loop when the condition is false.



      #include <iostream.h>



      int main()

      {

         int counter;

        cout << "How many hellos?: ";

        cin >> counter;

        while (counter > 0)

        {

           cout << "Hello!\n";

           counter--;

        }

        cout << "Counter is OutPut: " << counter;

         return 0;

 }

// end of script...
