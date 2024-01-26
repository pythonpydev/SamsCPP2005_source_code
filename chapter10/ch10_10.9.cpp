// Listing 10.9. Returning a temporary object.

     // operator++ returns a temporary object



     typedef unsigned short  USHORT;

     #include <iostream.h>



     class Counter

     {

        public:

          Counter();

          ~Counter(){}

          USHORT GetItsVal()const { return itsVal; }

          void SetItsVal(USHORT x) {itsVal = x; }

          void Increment() { ++itsVal; }

          Counter operator++ ();



       private:

          USHORT itsVal;



    };



    Counter::Counter():

    itsVal(0)

    {};



    Counter Counter::operator++()

    {

        ++itsVal;

        Counter temp;

        temp.SetItsVal(itsVal);

        return temp;

    }



    int main()

    {

       Counter i;

       cout << "The value of i is " << i.GetItsVal() << endl;

       i.Increment();

       cout << "The value of i is " << i.GetItsVal() << endl;

       ++i;

       cout << "The value of i is " << i.GetItsVal() << endl;

       Counter a = ++i;

       cout << "The value of a: " << a.GetItsVal();

       cout << " and i: " << i.GetItsVal() << endl;

     return 0;

 }

// end of script...
