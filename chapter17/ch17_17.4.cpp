// Listing 17.4. Using inline rather than a macro.

     #include <iostream.h>



     inline unsigned long Square(unsigned long a) { return a * a; }

     inline unsigned long Cube(unsigned long a) 

         { return a * a * a; }

     int main()

     {

        unsigned long x=1 ;

        for (;;)

       {

          cout << "Enter a number (0 to quit): ";

          cin >> x;

          if (x == 0)

             break;

          cout << "You entered: " << x;

          cout << ".  Square(" << x << "): ";

          cout  << Square(x);

          cout<< ". Cube(" _<< x << "): ";

          cout << Cube(x) << "." << endl;

       }

     return 0;

 }

// end of script...
