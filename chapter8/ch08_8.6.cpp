// Listing 8.6. Accessing member data of objects on the free store.

     // Accessing data members of objects on the heap



      #include <iostream.h>



      class SimpleCat

      {

      public:

             SimpleCat() {itsAge = 2; }

             ~SimpleCat() {}

             int GetAge() const { return itsAge; }

             void SetAge(int age) { itsAge = age; }

     private:

             int itsAge;

        };



        int main()

        {

               SimpleCat * Frisky = new SimpleCat;

               cout << "Frisky is " << Frisky->GetAge() << " years old\n";

               Frisky->SetAge(5);

               cout << "Frisky is " << Frisky->GetAge() << " years old\n";

               delete Frisky;

        return 0;

 }

// end of script...
