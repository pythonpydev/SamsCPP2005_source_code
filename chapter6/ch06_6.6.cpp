// Listing 6.6. Cat class declaration in CAT.HPP

  #include <iostream.h>

  class Cat

   {

  public:

   Cat (int initialAge);

   ~Cat();

    int GetAge() { return itsAge;}             // inline!

    void SetAge (int age) { itsAge = age;}     // inline!

    void Meow() { cout << "Meow.\n";}             // inline!

  private:

 int itsAge;

 };

// end of script...
