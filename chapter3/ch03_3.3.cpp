// Listing 3.3. A demonstration of typedef.

   // *****************

   // Demonstrates typedef keyword

   #include <iostream.h>



   typedef unsigned short int USHORT;       //typedef defined



   void main()

   {

     USHORT  Width = 5;

    USHORT Length;

    Length = 10;

    USHORT Area  = Width * Length;

    cout << "Width:" << Width << "\n";

    cout << "Length: "  << Length << endl;

    cout << "Area: " << Area <<endl;

 }

// end of script...
