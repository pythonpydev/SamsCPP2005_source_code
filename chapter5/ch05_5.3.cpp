// Listing 5.3. Demonstrating global and local variables.

   #include <iostream.h>

   void myFunction();           // prototype



   int x = 5, y = 7;            // global variables

   int main()

   {



        cout << "x from main: " << x << "\n";

        cout << "y from main: " << y << "\n\n";

       myFunction();

       cout << "Back from myFunction!\n\n";

       cout << "x from main: " << x << "\n";

       cout << "y from main: " << y << "\n";

       return 0;

  }



  void myFunction()

  {

       int y = 10;



       cout << "x from myFunction: " << x << "\n";

       cout << "y from myFunction: " << y << "\n\n";

 }

// end of script...
