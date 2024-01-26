// Listing 9.7. swap() rewritten with references.

      // using references!



        #include <iostream.h>



        void swap(int &x, int &y);



        int main()

        {

            int x = 5, y = 10;



            cout << "Main. Before swap, x: " << x << " y: " << y << "\n";

             swap(x,y);

             cout << "Main. After swap, x: " << x << " y: " << y << "\n";

     return 0;

           }



           void swap (int &rx, int &ry)

           {

             int temp;



                cout << "Swap. Before swap, rx: " << rx << " ry: " << ry << "\n";



                temp = rx;

                rx = ry;

                ry = temp;



                cout << "Swap. After swap, rx: " << rx << " ry: " << ry << "\n";



 }

// end of script...
