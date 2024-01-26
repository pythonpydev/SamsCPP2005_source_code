// Listing 14.6. Rewriting Listing 14.5 without the pointer to function.



     #include <iostream.h>



     void Square (int&,int&);

     void Cube (int&, int&);

     void Swap (int&, int &);

     void GetVals(int&, int&);

     void PrintVals(int, int);

    enum BOOL { FALSE, TRUE };



    int main()

    {

       BOOL fQuit = FALSE;

       int valOne=1, valTwo=2;

       int choice;

       while (fQuit == FALSE)

       {

          cout << "(0)Quit (1)Change Values (2)Square (3)Cube (4)Swap: ";

          cin >> choice;

          switch (choice)

          {

             case 1:

                PrintVals(valOne, valTwo);

                GetVals(valOne, valTwo);

                PrintVals(valOne, valTwo);

                break;



             case 2:

                PrintVals(valOne, valTwo);

                Square(valOne,valTwo);

                PrintVals(valOne, valTwo);

                break;



             case 3:

                PrintVals(valOne, valTwo);

                Cube(valOne, valTwo);

                PrintVals(valOne, valTwo);

                break;



             case 4:

                PrintVals(valOne, valTwo);

                Swap(valOne, valTwo);

                PrintVals(valOne, valTwo);

                break;



                default :

                fQuit = TRUE;

                break;

          }

 

          if (fQuit)

             break;

       }

     return 0;

 }

// end of script...
