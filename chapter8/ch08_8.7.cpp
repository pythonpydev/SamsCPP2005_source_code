// Listing 8.7. Pointers as member data.

  // Pointers as data members



    #include <iostream.h>



    class SimpleCat

    {

    public:

            SimpleCat();

            ~SimpleCat();

            int GetAge() const { return *itsAge; }

            void SetAge(int age) { *itsAge = age; }



            int GetWeight() const { return *itsWeight; }

            void setWeight (int weight) { *itsWeight = weight; }



    private:

            int * itsAge;

            int * itsWeight;

       };



       SimpleCat::SimpleCat()

       {

            itsAge = new int(2);

            itsWeight = new int(5);

       }



       SimpleCat::~SimpleCat()

       {

            delete itsAge;

            delete itsWeight;

       }



       int main()

       {

              SimpleCat *Frisky = new SimpleCat;

              cout << "Frisky is " << Frisky->GetAge() << " years old\n";

              Frisky->SetAge(5);

              cout << "Frisky is " << Frisky->GetAge() << " years old\n";

              delete Frisky;

       return 0;

 }

// end of script...
