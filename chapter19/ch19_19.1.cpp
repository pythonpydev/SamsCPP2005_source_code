// Listing 19.1. A template of an Array class

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



       // accessors

       int getSize() { return itsSize; }



    private:

       T *pType;

       int  itsSize;

 }; 

// end of script...
