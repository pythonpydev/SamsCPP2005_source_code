// Listing 4.9. A demonstration of the conditional operator.

   //

   #include <iostream.h>

   int main()

   {

      int x, y, z;

      cout << "Enter two numbers.\n";

      cout << "First: ";

      cin >> x;

     cout << "\nSecond: ";

     cin >> y;

     cout << "\n";



     if (x > y)

       z = x;

     else

       z = y;



     cout << "z: " << z;

     cout << "\n";



     z =  (x > y) ? x : y;



     cout << "z: " << z;

     cout << "\n";

        return 0;

 }

// end of script...
