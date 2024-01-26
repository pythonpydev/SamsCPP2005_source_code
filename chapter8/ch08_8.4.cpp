// Listing 8.4. Allocating, using, and deleting pointers.

     // Allocating and deleting a pointer



     #include <iostream.h>

     int main()

     {

        int localVariable = 5;

        int * pLocal= &localVariable;

        int * pHeap = new int;

       if (pHeap == NULL)

        {

            cout << "Error! No memory for pHeap!!";

            return 0;

        }

       *pHeap = 7;

       cout << "localVariable: " << localVariable << "\n";

       cout << "*pLocal: " << *pLocal << "\n";

       cout << "*pHeap: " << *pHeap << "\n";

       delete pHeap;

       pHeap = new int;

       if (pHeap == NULL)

       {

            cout << "Error! No memory for pHeap!!";

            return 0;

       }

       *pHeap = 9;

       cout << "*pHeap: " << *pHeap << "\n";

       delete pHeap;

       return 0;

 }

// end of script...
