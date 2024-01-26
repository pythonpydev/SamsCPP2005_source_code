// Listing 19.2. The implementation of the template array.

     #include <iostream.h>



     const int DefaultSize = 10;



     // declare a simple Animal class so that we can

     // create an array of animals



     class Animal

     {

    public:

       Animal(int);

       Animal();

       ~Animal() {}

       int GetWeight() const { return itsWeight; }

       void Display() const { cout << itsWeight; }

    private:

       int itsWeight;

    };



    Animal::Animal(int weight):

    itsWeight(weight)

    {}



    Animal::Animal():

    itsWeight(0)

    {}





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



    private:

       T *pType;

       int  itsSize;

    };



    // implementations follow...



    // implement the Constructor

    template <class T>

    Array<T>::Array(int size = DefaultSize):

    itsSize(size)

    {

       pType = new T[size];

       for (int i = 0; i<size; i++)

          pType[i] = 0;

    }



    // copy constructor

    template <class T>

    Array<T>::Array(const Array &rhs)

    {

       itsSize = rhs.GetSize();

       pType = new T[itsSize];

       for (int i = 0; i<itsSize; i++)

          pType[i] = rhs[i];

    }



    // operator=

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



    // driver program

    int main()

    {

       Array<int> theArray;      // an array of integers

       Array<Animal> theZoo;     // an array of Animals

       Animal *pAnimal;



       // fill the arrays

       for (int i = 0; i < theArray.GetSize(); i++)

       {

          theArray[i] = i*2;

          pAnimal = new Animal(i*3);

          theZoo[i] = *pAnimal;

            delete pAnimal;

      }

      // print the contents of the arrays

      for (int j = 0; j < theArray.GetSize(); j++)

      {

         cout << "theArray[" << j << "]:\t";

         cout << theArray[j] << "\t\t";

         cout << "theZoo[" << j << "]:\t";

         theZoo[j].Display();

         cout << endl;

      }



      for (int k = 0; k < theArray.GetSize(); k++)

         delete &theZoo[j];

     return 0;

 }

// end of script...
