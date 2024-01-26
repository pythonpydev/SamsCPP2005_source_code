// Listing 21.7. Using qsort().

     /* qsort example */



     #include <iostream.h>

     #include <stdlib.h>



     // form of sort_function required by qsort

     int sortFunction( const void *intOne, const void *intTwo);



     const int TableSize = 10;  // array size



    int main(void)

    {

       int i,table[TableSize];



       // fill the table with values

       for (i = 0; i<TableSize; i++)

       {

          cout << "Enter a number: ";

          cin >> table[i];

       }

       cout << "\n";



       // sort the values

       qsort((void *)table, TableSize, sizeof(table[0]), sortFunction);



       // print the results

       for (i = 0; i < TableSize; i++)

          cout << "Table [" << i << "]: " << table[i] << endl;



       cout << "Done." << endl;

     return 0;

    }



    int sortFunction( const void *a, const void *b)

    {

       int intOne = *((int*)a);

       int intTwo = *((int*)b);

       if (intOne < intTwo)

          return -1;

       if (intOne == intTwo)

          return 0;

       return 1;

 }

// end of script...
