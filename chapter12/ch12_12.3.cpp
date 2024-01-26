// Listing 12.3. Constructors and destructors called.



     #include <iostream.h>

     enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };



     class Mammal

     {

     public:

        // constructors

       Mammal();

       ~Mammal();



       //accessors

       int GetAge() const { return itsAge; }

       void SetAge(int age) { itsAge = age; }

       int GetWeight() const { return itsWeight; }

       void SetWeight(int weight) { itsWeight = weight; }



       //Other methods

       void Speak() const { cout << "Mammal sound!\n"; }

       void Sleep() const { cout << "shhh. I'm sleeping.\n"; }





    protected:

       int itsAge;

       int itsWeight;

    };



    class Dog : public Mammal

    {

    public:



       // Constructors

       Dog();

       ~Dog();



       // Accessors

       BREED GetBreed() const { return itsBreed; }

       void SetBreed(BREED breed) { itsBreed = breed; }



       // Other methods

       void WagTail() { cout << "Tail wagging...\n"; }

       void BegForFood() { cout << "Begging for food...\n"; }



    private:

       BREED itsBreed;

    };



    Mammal::Mammal():

    itsAge(1),

    itsWeight(5)

    {

       cout << "Mammal constructor...\n";

    }



    Mammal::~Mammal()

    {

       cout << "Mammal destructor...\n";

    }



    Dog::Dog():

    itsBreed(YORKIE)

    {

       cout << "Dog constructor...\n";

    }



    Dog::~Dog()

    {

       cout << "Dog destructor...\n";

    }

    int main()

    {

       Dog fido;

       fido.Speak();

       fido.WagTail();

       cout << "Fido is " << fido.GetAge() << " years old\n";

     return 0;

 }

// end of script...
