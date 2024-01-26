// Listing 11.5. Creating a multidimensional array.

     #include <iostream.h>

     int main()

     {

        int SomeArray[5][2] = { {0,0}, {1,2}, {2,4}, {3,6}, {4,8}};

        for (int i = 0; i<5; i++)

           for (int j=0; j<2; j++)

           {

              cout << "SomeArray[" << i << "][" << j << "]: ";

              cout << SomeArray[i][j]<< endl;

          }



     return 0;

 }

// end of script...
