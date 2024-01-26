// Listing 2.5. FUNC.CPP demonstrates a simple function.

    #include <iostream.h>

    int Add (int x, int y)

    {



      cout << "In Add(), received " << x << " and " << y << "\n";

      return (x+y);

    }



    int main()

    {

         cout << "I'm in main()!\n";

         int a, b, c;

         cout << "Enter two numbers: ";

         cin >> a;

         cin >> b;

         cout << "\nCalling Add()\n";

         c=Add(a,b);

         cout << "\nBack in main().\n";

         cout << "c was set to " << c;

         cout << "\nExiting...\n\n";

         return 0;

 }

// end of script...
