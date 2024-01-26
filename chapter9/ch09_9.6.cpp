// Listing 9.6. Passing by reference using pointers.



      #include <iostream.h>



      void swap(int *x, int *y);



      int main()

      {

        int x = 5, y = 10;



        cout << "Main. Before swap, x: " << x << " y: " << y << "\n";

        swap(&x,&y);

        cout << "Main. After swap, x: " << x << " y: " << y << "\n";

     return 0;

      }



      void swap (int *px, int *py)

      {

        int temp;



        cout << "Swap. Before swap, *px: " << *px << " *py: " << *py << "\n";



        temp = *px;

        *px = *py;

        *py = temp;



        cout << "Swap. After swap, *px: " << *px << " *py: " << *py << "\n";



 }

// end of script...
