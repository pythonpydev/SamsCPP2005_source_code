// Listing 5.4. Variables scoped within a block.

    // scoped within a block



    #include <iostream.h>



    void myFunc();



    int main()

    {

      int x = 5;

      cout << "\nIn main x is: " << x;



      myFunc();



      cout << "\nBack in main, x is: " << x;

        return 0;

   }



   void myFunc()

   {



      int x = 8;

      cout << "\nIn myFunc, local x: " << x << endl;



      {

         cout << "\nIn block in myFunc, x is: " << x;



         int x = 9;



         cout << "\nVery local x: " << x;

      }



      cout << "\nOut of block, in myFunc, x: " << x << endl;

 }

// end of script...
