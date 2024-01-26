// Listing 20.3. Class hierarchies and exceptions.

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

    

        // define the exception classes

          class xBoundary {};

          class xSize {};

          class xTooBig : public xSize {};

          class xTooSmall : public xSize {};

          class xZero  : public xTooSmall {};

          class xNegative  : public xSize {};

       private:

          int *pType;

          int  itsSize;

       };

    

    

       Array::Array(int size):

       itsSize(size)

       {

          if (size == 0)

             throw xZero();

          if (size > 30000)

             throw xTooBig();

          if (size <1)

             throw xNegative();

          if (size < 10)

             throw xTooSmall();

 

          pType = new int[size];

          for (int i = 0; i<size; i++)

            pType[i] = 0;

       }

 

           int& Array::operator[](int offSet)

        {

             int size = GetitsSize();

             if (offSet >= 0 && offSet < GetitsSize())

                return pType[offSet];

             throw xBoundary();

             return pType[0];  // appease MFC

        }

    

    

        const int& Array::operator[](int offSet) const

        {

             int mysize = GetitsSize();

             if (offSet >= 0 && offSet < GetitsSize())

                return pType[offSet];

             throw xBoundary();

             return pType[0];

             return pType[0];  // appease MFC

        }

    

     int main()

     {

    

        try

        {

           Array intArray(5);

           for (int j = 0; j< 100; j++)

           {

              intArray[j] = j;

              cout << "intArray[" << j << "] okay...\n";

           }

        }

        catch (Array::xBoundary)

        {

           cout << "Unable to process your input!\n";

        }

        catch (Array::xTooBig)

        {

           cout << "This array is too big...\n";

        }

    

        catch (Array::xZero)

        {

           cout << "You asked for an array";

           cout << " of zero objects!\n"; 

        }

    

        catch (Array::xTooSmall)

        {

           cout << "This array is too small...\n";

        }

 

        catch (...)

        {

           cout << "Something went wrong!\n";

         }

          cout << "Done.\n";

        return 0

 }

// end of script...
