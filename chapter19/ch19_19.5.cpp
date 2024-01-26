// Listing 19.5. Passing template objects to and from functions.

     #include <iostream.h>



     const int DefaultSize = 10;



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

       // cout << "Animal(int)\n";

    }



    Animal::Animal():

    itsWeight(0)

    {

       // cout << "Animal()\n";

    }



    Animal::~Animal()

    {

      // cout << "Destroyed an animal...\n";

    }



    template <class T>  // declare the template and the parameter

    class Array            // the class being parameterized

    {

    public:

       Array(int itsSize = DefaultSize);

       Array(const Array &rhs);

       ~Array() { delete [] pType; }



       Array& operator=(const Array&);

       T& operator[](int offSet) { return pType[offSet]; }

       const T& operator[](int offSet) const 

          { return pType[offSet]; }

       int GetSize() const { return itsSize; }



      // friend function

      friend ostream& operator<< (ostream&, const Array<T>&);



    private:

       T *pType;

       int  itsSize;

    };



    template <class T>

    ostream& operator<< (ostream& output, const Array<T>& theArray)

    {

       for (int i = 0; i<theArray.GetSize(); i++)

          output << "[" << i << "] " << theArray[i] << endl;

       return output;

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

   }





   void AnimalFillFunction(Array<Animal>& theArray)

   {

      Animal * pAnimal;

      for (int i = 0; i<theArray.GetSize(); i++)

      {

         pAnimal = new Animal;

         pAnimal->SetWeight(i*100);

         theArray[i] = *pAnimal;

         delete pAnimal;  // a copy was put in the array

      }

 }

// end of script...
