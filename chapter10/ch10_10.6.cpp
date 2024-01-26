// Listing 10.6. The Counter class.

     // The Counter class



     typedef unsigned short  USHORT;

     #include <iostream.h>



     class Counter

     {

        public:

          Counter();

          ~Counter(){}

          USHORT GetItsVal()const { return itsVal; }

          void SetItsVal(USHORT x) {itsVal = x; }



       private:

          USHORT itsVal;



    };



    Counter::Counter():

    itsVal(0)

    {};



    int main()

    {

       Counter i;

       cout << "The value of i is " << i.GetItsVal() << endl;

     return 0;

 }

// end of script...
