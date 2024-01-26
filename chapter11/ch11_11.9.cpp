// Listing 11.9. Filling an array.



     #include <iostream.h>



     int main()

     {

        char buffer[80];

        cout << "Enter the string: ";

        cin.get(buffer, 79);       // get up to 79 or newline

       cout << "Here's the buffer:  " << buffer << endl;

     return 0;

 }

// end of script...
