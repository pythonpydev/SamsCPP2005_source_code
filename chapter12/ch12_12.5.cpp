// Listing 12.5. Overriding a base class methodin a derived class.



     #include <iostream.h>

     enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };



     class Mammal

     {

     public:

        // constructors

       Mammal() { cout << "Mammal constructor...\n"; }

       ~Mammal() { cout << "Mammal destructor...\n"; }



       //Other methods

       void Speak()const { cout << "Mammal sound!\n"; }

       void Sleep()const { cout << "shhh. I'm sleeping.\n"; }





    protected:

       int itsAge;

       int itsWeight;

    };



    class Dog : public Mammal

    {

    public:



       // Constructors

       Dog(){ cout << "Dog constructor...\n"; }

       ~Dog(){ cout << "Dog destructor...\n"; }



       // Other methods

       void WagTail() { cout << "Tail wagging...\n"; }

       void BegForFood() { cout << "Begging for food...\n"; }

       void Speak()const { cout << "Woof!\n"; }



    private:

       BREED itsBreed;

    };



    int main()

    {

       Mammal bigAnimal;

       Dog fido;

       bigAnimal.Speak();

       fido.Speak();

     return 0;

 }

// end of script...
