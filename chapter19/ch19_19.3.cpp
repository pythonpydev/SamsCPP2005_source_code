// Listing 19.3. Non-template friend function.



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



       // friend function

       friend void Intrude(Array<int>);



     private:

        T *pType;

        int  itsSize;

     };



       // friend function. Not a template, can only be used

       // with int arrays! Intrudes into private data.

      void Intrude(Array<int> theArray)

      {

       cout << "\n*** Intrude ***\n";

       for (int i = 0; i < theArray.itsSize; i++)

          cout << "i: " <<    theArray.pType[i] << endl;

       cout << "\n";

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

        }



        int j, k;

        for (j = 0; j < theArray.GetSize(); j++)

        {

           cout << "theZoo[" << j << "]:\t";

           theZoo[j].Display();

           cout << endl;

        }

        cout << "Now use the friend function to ";

        cout << "find the members of Array<int>";

        Intrude(theArray);



        // return the allocated memory before the arrays are destroyed.

        for (k = 0; k < theArray.GetSize(); k++)

           delete &theZoo[j];



        cout << "\n\nDone.\n";

        return 0;

 }

// end of script...
