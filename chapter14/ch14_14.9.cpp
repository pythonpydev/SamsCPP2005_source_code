// Listing 14.9. Using typedef to make pointers to functions more readable.



   #include <iostream.h>



   void Square (int&,int&);

   void Cube (int&, int&);

   void Swap (int&, int &);

   void GetVals(int&, int&);

   typedef  void (*VPF) (int&, int&) ;

   void PrintVals(VPF,int&, int&);

   enum BOOL { FALSE, TRUE };



   int main()

   {

   int valOne=1, valTwo=2;

   int choice;

   BOOL fQuit = FALSE;



   VPF pFunc;



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



   void PrintVals( VPF pFunc,int& x, int& y)

   {

   cout << "x: " << x << " y: " << y << endl;

   pFunc(x,y);

   cout << "x: " << x << " y: " << y << endl;

 }

// end of script...
