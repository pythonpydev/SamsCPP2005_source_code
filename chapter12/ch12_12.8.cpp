// Listing 12.8. Using virtual methods.



     #include <iostream.h>



     class Mammal

     {

     public:

        Mammal():itsAge(1) { cout << "Mammal constructor...\n"; }

        ~Mammal() { cout << "Mammal destructor...\n"; }

       void Move() const { cout << "Mammal move one step\n"; }

       virtual void Speak() const { cout << "Mammal speak!\n"; }

    protected:

       int itsAge;



    };



    class Dog : public Mammal

    {

    public:

       Dog() { cout << "Dog Constructor...\n"; }

       ~Dog() { cout << "Dog destructor...\n"; }

       void WagTail() { cout << "Wagging Tail...\n"; }

       void Speak()const { cout << "Woof!\n"; }

       void Move()const { cout << "Dog moves 5 steps...\n"; }

    };



    int main()

    {



       Mammal *pDog = new Dog;

       pDog->Move();

       pDog->Speak();



     return 0;

 }

// end of script...
