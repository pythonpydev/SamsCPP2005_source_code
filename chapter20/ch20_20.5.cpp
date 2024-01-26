// Listing 20.6. Using exceptions with templates.

      #include <iostream.h>

    

      const int DefaultSize = 10;

      class xBoundary {};

    

      template <class T>

      class Array

      {

      public:

         // constructors

         Array(int itsSize = DefaultSize);

         Array(const Array &rhs);

         ~Array() { delete [] pType;}

    

         // operators

         Array& operator=(const Array<T>&);

         T& operator[](int offSet);

         const T& operator[](int offSet) const;

    

         // accessors

         int GetitsSize() const { return itsSize; }

    

         // friend function

        friend ostream& operator<< (ostream&, const Array<T>&);

    

       // define the exception classes

    

         class xSize {};

    

      private:

         int *pType;

         int  itsSize;

      };

    

      template <class T>

      Array<T>::Array(int size):

      itsSize(size)

      {

         if (size <10 || size > 30000)

            throw xSize();

         pType = new T[size];

         for (int i = 0; i<size; i++)

           pType[i] = 0;

      }

 

      template <class T>

      Array<T>& Array<T>::operator=(const Array<T> &rhs)

      {

         if (this == &rhs)

            return *this;

         delete [] pType;

         itsSize = rhs.GetitsSize();

         pType = new T[itsSize];

         for (int i = 0; i<itsSize; i++)

            pType[i] = rhs[i];

      }

      template <class T>

      Array<T>::Array(const Array<T> &rhs)

      {

         itsSize = rhs.GetitsSize();

         pType = new T[itsSize];

         for (int i = 0; i<itsSize; i++)

            pType[i] = rhs[i];

      }

    

      template <class T>

      T& Array<T>::operator[](int offSet)

      {

         int size = GetitsSize();

         if (offSet >= 0 && offSet < GetitsSize())

            return pType[offSet];

         throw xBoundary();

         return pType[0];

      }

    

      template <class T>

      const T& Array<T>::operator[](int offSet) const

      {

         int mysize = GetitsSize();

         if (offSet >= 0 && offSet < GetitsSize())

            return pType[offSet];

         throw xBoundary();

      }

    

      template <class T>

      ostream& operator<< (ostream& output, const Array<T>& theArray)

      {

         for (int i = 0; i<theArray.GetitsSize(); i++)

            output << "[" << i << "] " << theArray[i] << endl;

         return output;

      }

    

    

      int main()

      {

 

         try

         {

            Array<int> intArray(9);

            for (int j = 0; j< 100; j++)

            {

               intArray[j] = j;

               cout << "intArray[" << j << "] okay..." << endl;

            }

         }

         catch (xBoundary)

         {

            cout << "Unable to process your input!\n";

         }

         catch (Array<int>::xSize)

         {

            cout << "Bad Size!\n";

         }

    

         cout << "Done.\n";

        return 0;

 }

// end of script...
