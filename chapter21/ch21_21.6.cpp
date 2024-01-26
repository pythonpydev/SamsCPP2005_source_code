// Listing 21.6. Using atoi() and related functions.

     #include <stdlib.h>

     #include <iostream.h>



     int main()

     {

        char buffer[80];

        cout << "Enter a number: ";

        cin >> buffer;



       int number;

       // number = buffer; compile error

       number = atoi(buffer);

       cout << "Here's the number: " << number << endl;



       // int sum = buffer + 5;

       int sum = atoi(buffer) + 5;

       cout << "Here's sum: " << sum << endl;

     return 0;

 }

// end of script...
