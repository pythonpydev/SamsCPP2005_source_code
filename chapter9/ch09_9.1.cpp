// Listing 9.1. Creating and using references.

    // Demonstrating the use of References



    #include <iostream.h>



    int main()

    {

         int  intOne;

         int &rSomeRef = intOne;



        intOne = 5;

        cout << "intOne: " << intOne << endl;

        cout << "rSomeRef: " << rSomeRef << endl;



        rSomeRef = 7;

        cout << "intOne: " << intOne << endl;

        cout << "rSomeRef: " << rSomeRef << endl;

   return 0;

 }

// end of script...
