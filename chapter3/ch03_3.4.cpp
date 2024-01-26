// Listing 3.5. A demonstration of adding too large a number to a signed integer.

  #include <iostream.h>

  int main()

  {

     short int smallNumber;

     smallNumber = 32767;

     cout << "small number:" << smallNumber << endl;

     smallNumber++;

     cout << "small number:" << smallNumber << endl;

     smallNumber++;

    cout << "small number:" << smallNumber << endl;

        return 0;

 }

// end of script...
