// Listing 6.1. Accessing the public members of a simple class.

   // Demonstrates declaration of a class and

   // definition of an object of the class,



   #include <iostream.h>   // for cout



   class Cat                // declare the class object

   {

    public:                 // members which follow are public

      int itsAge;

     int itsWeight;

  };





  void main()

  {

     Cat Frisky;

     Frisky.itsAge = 5;    // assign to the member variable

     cout << "Frisky is a cat who is " ;

     cout << Frisky.itsAge << " years old.\n";

 

// end of script...
