// Listing 16.9. Using peek() and putback().

     #include <iostream.h>



     int main()

     {

        char ch;

        cout << "enter a phrase: ";

        while ( cin.get(ch) )

        {

          if (ch == `!')

             cin.putback(`$');

          else

             cout << ch;

          while (cin.peek() == `#')

             cin.ignore(1,'#');

       }

     return 0;

 }

// end of script...
