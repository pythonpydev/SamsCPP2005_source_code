// Listing 14.7. Demonstrates use of an array of pointers to functions.



     #include <iostream.h>



     void Square (int&,int&);

     void Cube (int&, int&);

     void Swap (int&, int &);

     void GetVals(int&, int&);

     void PrintVals(int, int);

    enum BOOL { FALSE, TRUE };



    int main()

    {

       int valOne=1, valTwo=2;

       int choice, i;

       const MaxArray = 5;

       void (*pFuncArray[MaxArray])(int&, int&);



       for (i=0;i<MaxArray;i++)

       {

          cout << "(1)Change Values (2)Square (3)Cube (4)Swap: ";

          cin >> choice;

          switch (choice)

          {

             case 1:pFuncArray[i] = GetVals; break;

             case 2:pFuncArray[i] = Square; break;

             case 3:pFuncArray[i] = Cube; break;

             case 4:pFuncArray[i] = Swap; break;

             default:pFuncArray[i] = 0;

          }

       }



       for (i=0;i<MaxArray; i++)

       {

          pFuncArray[i](valOne,valTwo);

          PrintVals(valOne,valTwo);

       }

     return 0;

 }

// end of script...
