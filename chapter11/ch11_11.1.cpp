// Listing 11.1. Using an integer array.

     #include <iostream.h>



     int main()

     {

        int myArray[5];

        int i;

        for ( i=0; i<5; i++)  // 0-4

        {

           cout << "Value for myArray[" << i << "]: ";

          cin >> myArray[i];

       }

       for (i = 0; i<5; i++)

          cout << i << ": " << myArray[i] << "\n";

     return 0;

 }

// end of script...
