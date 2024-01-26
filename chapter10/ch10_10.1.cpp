// Listing 10.1. Overloading member functions.

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



       // overloaded class function DrawShape

       void DrawShape() const;

       void DrawShape(USHORT aWidth, USHORT aHeight) const;



    private:

       USHORT itsWidth;

       USHORT itsHeight;

    };



    //Constructor implementation

    Rectangle::Rectangle(USHORT width, USHORT height)

    {

       itsWidth = width;

       itsHeight = height;

    }





    // Overloaded DrawShape - takes no values

    // Draws based on current class member values

    void Rectangle::DrawShape() const

    {

        DrawShape( itsWidth, itsHeight);

    }





    // overloaded DrawShape - takes two values

    // draws shape based on the parameters

    void Rectangle::DrawShape(USHORT width, USHORT height) const

    {

       for (USHORT i = 0; i<height; i++)

       {

          for (USHORT j = 0; j< width; j++)

          {

             cout << "*";

          }

          cout << "\n";

       }

    }



    // Driver program to demonstrate overloaded functions

    int main()

    {

       // initialize a rectangle to 30,5

       Rectangle theRect(30,5);

       cout << "DrawShape(): \n";

       theRect.DrawShape();

       cout << "\nDrawShape(40,2): \n";

       theRect.DrawShape(40,2);

     return 0;

 }

// end of script...
