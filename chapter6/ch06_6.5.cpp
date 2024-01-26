// Listing 6.5. A demonstration of violations of the interface.

   // Demonstrates compiler errors





   #include <iostream.h>          // for cout



  class Cat

  {

   public:

      Cat(int initialAge);

     ~Cat();

     int GetAge() const;          // const accessor function

     void SetAge (int age);

     void Meow();

  private:

    int itsAge;

 };



    // constructor of Cat,

    Cat::Cat(int initialAge)

    {

       itsAge = initialAge;

       cout << "Cat Constructor\n";

    }



    Cat::~Cat()                   // destructor, takes no action

    {

       cout << "Cat Destructor\n";

    }

   // GetAge, const function

   // but we violate const!

   int Cat::GetAge() const

   {

      return (itsAge++);         // violates const!

   }



   // definition of SetAge, public

   // accessor function



   void Cat::SetAge(int age)

   {

      // set member variable its age to

      // value passed in by parameter age

      itsAge = age;

   }



  // definition of Meow method

  // returns: void

  // parameters: None

  // action: Prints "meow" to screen

  void Cat::Meow()

  {

     cout << "Meow.\n";

  }



  // demonstrate various violations of the

   // interface, and resulting compiler errors

  int main()

  {

     Cat Frisky;                 // doesn't match declaration

     Frisky.Meow();

     Frisky.Bark();              // No, silly, cat's can't bark.

     Frisky.itsAge = 7;          // itsAge is private

      return 0;

 } 

// end of script...
