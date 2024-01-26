// Listing 7.3. Complex while loops.

    // Complex while statements



    #include <iostream.h>



    int main()

    {

      unsigned short small;

      unsigned long  large;

      const unsigned short MAXSMALL=65535;



      cout << "Enter a small number: ";

      cin >> small;

      cout << "Enter a large number: ";

      cin >> large;



       cout << "small: " << small << "...";



      // for each iteration, test three conditions

      while (small < large && large > 0 && small < MAXSMALL)



      {

         if (small % 5000 == 0)  // write a dot every 5k lines

           cout << ".";



         small++;



         large-=2;

      }



      cout << "\nSmall: " << small << " Large: " << large << endl;

     return 0;

 }

// end of script...
