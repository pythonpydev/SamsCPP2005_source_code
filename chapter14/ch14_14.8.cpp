// Listing 14.8. Passing pointers to functions as function arguments.



     #include <iostream.h>



     void Square (int&,int&);

     void Cube (int&, int&);

     void Swap (int&, int &);

     void GetVals(int&, int&);

     void PrintVals(void (*)(int&, int&),int&, int&);

    enum BOOL { FALSE, TRUE };



    int main()

    {

       int valOne=1, valTwo=2;

       int choice;

       BOOL fQuit = FALSE;



       void (*pFunc)(int&, int&);



       while (fQuit == FALSE)

       {

          cout << "(0)Quit (1)Change Values (2)Square (3)Cube (4)Swap: ";

          cin >> choice;

          switch (choice)

          {

             case 1:pFunc = GetVals; break;

             case 2:pFunc = Square; break;

             case 3:pFunc = Cube; break;

             case 4:pFunc = Swap; break;

             default:fQuit = TRUE; break;

          }

          if (fQuit == TRUE)

             break;

          PrintVals ( pFunc, valOne, valTwo);

       }



     return 0;

    }



    void PrintVals( void (*pFunc)(int&, int&),int& x, int& y)

    {

       cout << "x: " << x << " y: " << y << endl;

       pFunc(x,y);

       cout << "x: " << x << " y: " << y << endl;

 }

// end of script...
