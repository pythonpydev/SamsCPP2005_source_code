// Listing 20.1. Raising an exception.

       #include <iostream.h>

    

       const int DefaultSize = 10;

    

       class Array

       {

       public:

          // constructors

          Array(int itsSize = DefaultSize);

          Array(const Array &rhs);

          ~Array() { delete [] pType;}

    

          // operators

          Array& operator=(const Array&);

          int& operator[](int offSet);

          const int& operator[](int offSet) const;

    

          // accessors

          int GetitsSize() const { return itsSize; }

    

          // friend function

         friend ostream& operator<< (ostream&, const Array&);

    

          class xBoundary {};  // define the exception class

       private:

          int *pType;

          int  itsSize;

       };

    

    

       Array::Array(int size):

       itsSize(size)

       {

          pType = new int[size];

          for (int i = 0; i<size; i++)

            pType[i] = 0;

       }

    

    

       Array& Array::operator=(const Array &rhs)

       {

          if (this == &rhs)

             return *this;

          delete [] pType;

          itsSize = rhs.GetitsSize();

          pType = new int[itsSize];

          for (int i = 0; i<itsSize; i++)

             pType[i] = rhs[i];

          return *this;

       }

    

       Array::Array(const Array &rhs)

       {

          itsSize = rhs.GetitsSize();

          pType = new int[itsSize];

          for (int i = 0; i<itsSize; i++)

             pType[i] = rhs[i];

       }

    

    

       int& Array::operator[](int offSet)

       {

          int size = GetitsSize();

          if (offSet >= 0 && offSet < GetitsSize())

             return pType[offSet];

          throw xBoundary();

          return pType[0]; // appease MSC 

       }

    

 

       const int& Array::operator[](int offSet) const

       {

          int mysize = GetitsSize();

          if (offSet >= 0 && offSet < GetitsSize())

             return pType[offSet];

          throw xBoundary();

          return pType[0]; // appease MSC 

       }

    

       ostream& operator<< (ostream& output, const Array& theArray)

       {

          for (int i = 0; i<theArray.GetitsSize(); i++)

             output << "[" << i << "] " << theArray[i] << endl;

          return output;

       }

    

       int main()

       {

          Array intArray(20);

          try

          {

             for (int j = 0; j< 100; j++)

             {

                intArray[j] = j;

                cout << "intArray[" << j << "] okay..." << endl;

             }

          }

          catch (Array::xBoundary)

          {

             cout << "Unable to process your input!\n";

          }

          cout << "Done.\n";

         return 0;

 }

// end of script...
