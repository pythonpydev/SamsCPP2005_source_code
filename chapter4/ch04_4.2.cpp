// Listing 4.2. A demonstration of subtraction and integer overflow.

 // integer overflow

 #include <iostream.h>



 int main()

 {

    unsigned int difference;

    unsigned int bigNumber = 100;

    unsigned int smallNumber = 50;

   difference = bigNumber - smallNumber;

   cout << "Difference is: " << difference;

   difference = smallNumber - bigNumber;

   cout << "\nNow difference is: " << difference <<endl;

       return 0;

 }

// end of script...
