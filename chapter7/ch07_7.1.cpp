// Listing 7.1. Looping with the keyword goto.

    // Looping with goto



    #include <iostream.h>



    int main()

    {

           int counter = 0;      // initialize counter

    loop:  counter ++;           // top of the loop

            cout << "counter: " << counter << "\n";

           if (counter < 5)            // test the value

               goto loop;                 // jump to the top



           cout << "Complete. Counter: " << counter << ".\n";

       return 0;

 }

// end of script...
