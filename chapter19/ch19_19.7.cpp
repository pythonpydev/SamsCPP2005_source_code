// Listing 19.7. Using static member data and functions with templates.

     #include <iostream.h>



     template <class T>  // declare the template and the parameter

     class Array            // the class being parameterized

     {

     public:

        // constructors

        Array(int itsSize = DefaultSize);

        Array(const Array &rhs);

       ~Array() { delete [] pType;   itsNumberArrays--; }



       // operators

       Array& operator=(const Array&);

       T& operator[](int offSet) { return pType[offSet]; }

       const T& operator[](int offSet) const 

          { return pType[offSet]; }

       // accessors

       int GetSize() const { return itsSize; }

       static int GetNumberArrays() { return itsNumberArrays; }



       // friend function

      friend ostream& operator<< (ostream&, const Array<T>&);



    private:

       T *pType;

       int  itsSize;

       static int itsNumberArrays;

    };



    template <class T>

       int Array<T>::itsNumberArrays = 0;



    template <class T>

    Array<T>::Array(int size = DefaultSize):

    itsSize(size)

    {

       pType = new T[size];

       for (int i = 0; i<size; i++)

         pType[i] = (T)0;

       itsNumberArrays++;

    }



    template <class T>

    Array<T>& Array<T>::operator=(const Array &rhs)

    {

       if (this == &rhs)

          return *this;

       delete [] pType;

       itsSize = rhs.GetSize();

       pType = new T[itsSize];

       for (int i = 0; i<itsSize; i++)

          pType[i] = rhs[i];

    }



    template <class T>

    Array<T>::Array(const Array &rhs)

    {

       itsSize = rhs.GetSize();

       pType = new T[itsSize];

       for (int i = 0; i<itsSize; i++)

          pType[i] = rhs[i];

       itsNumberArrays++;

    }





    template <class T>

    ostream& operator<< (ostream& output, const Array<T>& theArray)

    {

       for (int i = 0; i<theArray.GetSize(); i++)

          output << "[" << i << "] " << theArray[i] << endl;

       return output;

    }





    Array<Animal>::Array(int AnimalArraySize):

    itsSize(AnimalArraySize)

    {

       pType = new T[AnimalArraySize];

       itsNumberArrays++;

    }



    int main()

    {



       cout << Array<int>::GetNumberArrays() << " integer arrays\n";

       cout << Array<Animal>::GetNumberArrays();

        cout << " animal arrays\n\n";

       Array<int> intArray;

       Array<Animal> animalArray;



       cout << intArray.GetNumberArrays() << " integer arrays\n";

       cout << animalArray.GetNumberArrays();

       cout << " animal arrays\n\n";



       Array<int> *pIntArray = new Array<int>;



       cout << Array<int>::GetNumberArrays() << " integer arrays\n";

       cout << Array<Animal>::GetNumberArrays();

       cout << " animal arrays\n\n";



       delete pIntArray;



      cout << Array<int>::GetNumberArrays() << " integer arrays\n";

      cout << Array<Animal>::GetNumberArrays();

      cout << " animal arrays\n\n";

     return 0;

 }

// end of script...
