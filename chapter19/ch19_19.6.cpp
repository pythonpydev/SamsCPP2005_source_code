// Listing 19.6. Specializing template implementations.

     #include <iostream.h>



     const int DefaultSize = 3;



     // A trivial class for adding to arrays

       class Animal

       {

       public:

          // constructors

         Animal(int);

         Animal();

         ~Animal();



         // accessors

         int GetWeight() const { return itsWeight; }

         void SetWeight(int theWeight) { itsWeight = theWeight; }



         // friend operators

         friend ostream& operator<< (ostream&, const Animal&);



      private:

         int itsWeight;

      };



       // extraction operator for printing animals

      ostream& operator<< 

          (ostream& theStream, const Animal& theAnimal)

      {

        theStream << theAnimal.GetWeight();

        return theStream;

      }



      Animal::Animal(int weight):

      itsWeight(weight)

      {

         cout << "animal(int) ";

      }



      Animal::Animal():

      itsWeight(0)

      {

         cout << "animal() ";

      }



      Animal::~Animal()

      {

        cout << "Destroyed an animal...";

      }



    template <class T>  // declare the template and the parameter

    class Array            // the class being parameterized

    {

    public:

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



       // friend function

      friend ostream& operator<< (ostream&, const Array<T>&);



    private:

       T *pType;

       int  itsSize;

    };



    template <class T>

    Array<T>::Array(int size = DefaultSize):

    itsSize(size)

    {

       pType = new T[size];

       for (int i = 0; i<size; i++)

         pType[i] = (T)0;

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

       return *this;

    }

    template <class T>

    Array<T>::Array(const Array &rhs)

    {

       itsSize = rhs.GetSize();

       pType = new T[itsSize];

      for (int i = 0; i<itsSize; i++)

         pType[i] = rhs[i];

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

      pType = new Animal[AnimalArraySize];

   }





   void IntFillFunction(Array<int>& theArray);

   void AnimalFillFunction(Array<Animal>& theArray);

   enum BOOL {FALSE, TRUE};



   int main()

   {

      Array<int> intArray;

      Array<Animal> animalArray;

      IntFillFunction(intArray);

      AnimalFillFunction(animalArray);

      cout << "intArray...\n" << intArray;

      cout << "\nanimalArray...\n" << animalArray << endl;

     return 0;

   }



   void IntFillFunction(Array<int>& theArray)

   {

      BOOL Stop = FALSE;

      int offset, value;

      while (!Stop)

      {

         cout << "Enter an offset (0-9) and a value. ";

         cout << "(-1 to stop): " ;

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

   }





   void AnimalFillFunction(Array<Animal>& theArray)

   {

      Animal * pAnimal;

      for (int i = 0; i<theArray.GetSize(); i++)

      {

         pAnimal = new Animal(i*10);

         theArray[i] = *pAnimal;

         delete pAnimal;

      }

 }

// end of script...
