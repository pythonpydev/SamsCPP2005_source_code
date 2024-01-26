// Listing 19.4. Using operator ostream.

     #include <iostream.h>



     const int DefaultSize = 10;



     template <class T>  // declare the template and the parameter

     class Array            // the class being parameterized

     {

     public:

        // constructors

       Array(int itsSize = DefaultSize);

       Array(const Array &rhs);

       ~Array() { delete [] pType; }



       // operators

       Array& operator=(const Array&);

       T& operator[](int offSet) { return pType[offSet]; }

       const T& operator[](int offSet) const 

        { return pType[offSet]; }

       // accessors

       int GetSize() const { return itsSize; }



       friend ostream& operator<< (ostream&, Array<T>&);



    private:

       T *pType;

       int  itsSize;

    };



    template <class T>

    ostream& operator<< (ostream& output, Array<T>& theArray)

    {

       for (int i = 0; i<theArray.GetSize(); i++)

          output << "[" << i << "] " << theArray[i] << endl; return output;

    }



    enum BOOL { FALSE, TRUE};



    int main()

    {

       BOOL Stop = FALSE;       // flag for looping

       int offset, value;

       Array<int> theArray;



       while (!Stop)

       {

          cout << "Enter an offset (0-9) ";

          cout << "and a value. (-1 to stop): " ;

          cin >> offset >> value;



          if (offset < 0)

             break;



          if (offset > 9)

          {

             cout << "***Please use values between 0 and 9.***\n";

             continue;

          }



          theArray[offset] = value;

       }



       cout << "\nHere's the entire array:\n";

       cout << theArray << endl;

     return 0;

 }

// end of script...
