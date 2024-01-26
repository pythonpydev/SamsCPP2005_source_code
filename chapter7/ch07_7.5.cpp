// Listing 7.5. while (1) loops.

    // Demonstrates a while true loop



    #include <iostream.h>



    int main()

    {

      int counter = 0;



      while (1)

      {

         counter ++;

         if (counter > 10)

             break;

      }

      cout << "Counter: " << counter << "\n";

       return 0;

 

// end of script...
