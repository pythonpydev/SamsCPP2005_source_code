// Listing 5.1. A function declaration and the definition and use of that function.



   typedef unsigned short USHORT;

   #include <iostream.h>

   USHORT FindArea(USHORT length, USHORT width); //function prototype



   int main()

   {

     USHORT lengthOfYard;

    USHORT widthOfYard;

    USHORT areaOfYard;



    cout << "\nHow wide is your yard? ";

    cin >> widthOfYard;

    cout << "\nHow long is your yard? ";

    cin >> lengthOfYard;



    areaOfYard= FindArea(lengthOfYard,widthOfYard);



    cout << "\nYour yard is ";

    cout << areaOfYard;

    cout << " square feet\n\n";

             return 0;

  }



  USHORT FindArea(USHORT l, USHORT w)

  {

       return l * w;

 }

// end of script...
