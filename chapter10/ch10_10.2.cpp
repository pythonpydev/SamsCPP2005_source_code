// Listing 10.2. Using default values.

     #include <iostream.h>



     typedef unsigned short int USHORT;

     enum BOOL { FALSE, TRUE};



     // Rectangle class declaration

     class Rectangle

     {

    public:

       // constructors

       Rectangle(USHORT width, USHORT height);

       ~Rectangle(){}

       void DrawShape(USHORT aWidth, USHORT aHeight, BOOL UseCurrentVals =  Â                  FALSE) const;



    private:

       USHORT itsWidth;

       USHORT itsHeight;

    };



    //Constructor implementation

    Rectangle::Rectangle(USHORT width, USHORT height):

    itsWidth(width),       // initializations

    itsHeight(height)

    {}                     // empty body





    // default values used for third parameter

    void Rectangle::DrawShape(

       USHORT width,

       USHORT height,

       BOOL UseCurrentValue

       ) const

    {

       int printWidth;

       int printHeight;



       if (UseCurrentValue == TRUE)

       {

          printWidth = itsWidth;       // use current class values

          printHeight = itsHeight;

       }

       else

       {

          printWidth = width;         // use parameter values

          printHeight = height;

       }





       for (int i = 0; i<printHeight; i++)

       {

          for (int j = 0; j< printWidth; j++)

          {

             cout << "*";

          }

          cout << "\n";

       }

    }



    // Driver program to demonstrate overloaded functions

    int main()

    {

       // initialize a rectangle to 10,20

       Rectangle theRect(30,5);

       cout << "DrawShape(0,0,TRUE)...\n";

       theRect.DrawShape(0,0,TRUE);

       cout <<"DrawShape(40,2)...\n";

       theRect.DrawShape(40,2);

     return 0;

 }

// end of script...
