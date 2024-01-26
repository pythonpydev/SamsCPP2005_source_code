// Listing 7.4. break and continue.

    // Demonstrates break and continue



    #include <iostream.h>



    int main()

    {

      unsigned short small;

      unsigned long  large;

      unsigned long  skip;

      unsigned long target;

      const unsigned short MAXSMALL=65535;



      cout << "Enter a small number: ";

      cin >> small;

      cout << "Enter a large number: ";

      cin >> large;

      cout << "Enter a skip number: ";

      cin >> skip;

      cout << "Enter a target number: ";

      cin >> target;



    cout << "\n";



     // set up 3 stop conditions for the loop

      while (small < large && large > 0 && small < 65535)



      {



        small++;



         if (small % skip == 0)  // skip the decrement?

         {

           cout << "skipping on " << small << endl;

           continue;

         }



         if (large == target)    // exact match for the target?

         {

           cout << "Target reached!";

           break;

         }



         large-=2;

      }                   // end of while loop



      cout << "\nSmall: " << small << " Large: " << large << endl;

    return 0;

 }

// end of script...
