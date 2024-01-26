// Listing 20.4. Getting data out of an exception object.

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

         class xSize

         {

         public:

            xSize(int size):itsSize(size) {}

            ~xSize(){}

            int GetSize() { return itsSize; }

         private:

            int itsSize;

         };

    

         class xTooBig : public xSize

         {

         public:

            xTooBig(int size):xSize(size){}

         };

    

         class xTooSmall : public xSize

         {

         public:

            xTooSmall(int size):xSize(size){}

         };

    

         class xZero  : public xTooSmall

         {

         public:

            xZero(int size):xTooSmall(size){}

         };

    

         class xNegative : public xSize

         {

         public:

            xNegative(int size):xSize(size){}

         };

    

      private:

         int *pType;

         int  itsSize;

      };

    

 

      Array::Array(int size):

      itsSize(size)

      {

         if (size == 0)

            throw xZero(size);

         if (size > 30000)

            throw xTooBig(size);

         if (size <1)

            throw xNegative(size);

         if (size < 10)

            throw xTooSmall(size);

    

         pType = new int[size];

         for (int i = 0; i<size; i++)

           pType[i] = 0;

      }

    

    

      int& Array::operator[] (int offSet)

      {

          int size = GetitsSize();

          if (offSet >= 0 && offSet < GetitsSize())

            return pType[offSet];

          throw xBoundary();

          return pType[0];

      }

    

      const int& Array::operator[] (int offSet) const

      {

          int size = GetitsSize();

          if (offSet >= 0 && offSet < GetitsSize())

            return pType[offSet];

          throw xBoundary();

          return pType[0];

      }

    

       int main()

       {

    

          try

          {

             Array intArray(9);

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

         catch (Array::xZero theException)

         {

            cout << "You asked for an Array of zero objects!" << endl;

            cout << "Received " << theException.GetSize() << endl;

         }

         catch (Array::xTooBig theException)

         {

            cout << "This Array is too big..." << endl;

            cout << "Received " << theException.GetSize() << endl;

         }

         catch (Array::xTooSmall theException)

         {

            cout << "This Array is too small..." << endl;

            cout << "Received " << theException.GetSize() << endl;

         }

         catch (...)

         {

            cout << "Something went wrong, but I've no idea what!\n";

         }

         cout << "Done.\n";

        return 0;

 }

// end of script...
