// Listing 12.6. Hiding methods.



     #include <iostream.h>



     class Mammal

     {

     public:

        void Move() const { cout << "Mammal move one step\n"; }

        void Move(int distance) const 

       { 

          cout << "Mammal move ";

          cout << distance <<" _steps.\n"; 

       }

    protected:

       int itsAge;

       int itsWeight;

    };



    class Dog : public Mammal

    {

    public:

 // You may receive a warning that you are hiding a function!

       void Move() const { cout << "Dog move 5 steps.\n"; }

    };      



    int main()

    {

       Mammal bigAnimal;

       Dog fido;

       bigAnimal.Move();

       bigAnimal.Move(2);

       fido.Move();

       // fido.Move(10);

     return 0;

 }

// end of script...
