// Listing 13.9. Implementing pure virtual functions.

     //Implementing pure virtual functions



     #include <iostream.h>



     enum BOOL { FALSE, TRUE };



     class Shape

     {

     public:

       Shape(){}

       ~Shape(){}

       virtual long GetArea() = 0; // error

       virtual long GetPerim()= 0;

       virtual void Draw() = 0;

    private:

    };



     void Shape::Draw()

    {

       cout << "Abstract drawing mechanism!\n";

    }



    class Circle : public Shape

    {

    public:

          Circle(int radius):itsRadius(radius){}

          ~Circle(){}

          long GetArea() { return 3 * itsRadius * itsRadius; }

          long GetPerim() { return 9 * itsRadius; }

          void Draw();

    private:

       int itsRadius;

       int itsCircumference;

    };



    void Circle::Draw()

    {

       cout << "Circle drawing routine here!\n";

       Shape::Draw();

    }



 

    class Rectangle : public Shape

    {

    public:

          Rectangle(int len, int width):

             itsLength(len), itsWidth(width){}

          ~Rectangle(){}

          long GetArea() { return itsLength * itsWidth; }

          long GetPerim() {return 2*itsLength + 2*itsWidth; }

          virtual int GetLength() { return itsLength; }

          virtual int GetWidth() { return itsWidth; }

          void Draw();

    private:

       int itsWidth;

       int itsLength;

    };



    void Rectangle::Draw()

    {

       for (int i = 0; i<itsLength; i++)

       {

          for (int j = 0; j<itsWidth; j++)

             cout << "x ";



          cout << "\n";

       }

       Shape::Draw();

    }





    class Square : public Rectangle

    {

    public:

          Square(int len);

          Square(int len, int width);

          ~Square(){}

          long GetPerim() {return 4 * GetLength();}

    };

 

    Square::Square(int len):

       Rectangle(len,len)

    {}



    Square::Square(int len, int width):

       Rectangle(len,width)



    {

       if (GetLength() != GetWidth())

          cout << "Error, not a square... a Rectangle??\n";

    }



    int main()

    {

       int choice;

       BOOL fQuit = FALSE;

       Shape * sp;

 

       while (1)

      {

         cout << "(1)Circle (2)Rectangle (3)Square (0)Quit: ";

         cin >> choice;



         switch (choice)

         {

            case 1: sp = new Circle(5);

            break;

            case 2: sp = new Rectangle(4,6);

            break;

            case 3: sp = new Square (5);

            break;

            default: fQuit = TRUE;

            break;

         }

         if (fQuit)

            break;



         sp->Draw();

         cout << "\n";

      }

     return 0;

 }

// end of script...
