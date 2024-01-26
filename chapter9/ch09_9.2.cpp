// Listing 9.2. Taking the address of a reference.

    // Demonstrating the use of References



    #include <iostream.h>



    int main()

    {

        int  intOne;

        int &rSomeRef = intOne;



       intOne = 5;

       cout << "intOne: " << intOne << endl;

       cout << "rSomeRef: " << rSomeRef << endl;



       cout << "&intOne: "  << &intOne << endl;

       cout << "&rSomeRef: " << &rSomeRef << endl;



   return 0;

 }

// end of script...
