// Listing 9.4. References to objects.

    // References to class objects



    #include <iostream.h>



    class SimpleCat

    {

       public:

          SimpleCat (int age, int weight);

         ~SimpleCat() {}

         int GetAge() { return itsAge; }

         int GetWeight() { return itsWeight; }

      private:

         int itsAge;

         int itsWeight;

   };



   SimpleCat::SimpleCat(int age, int weight)

   {

        itsAge = age;

        itsWeight = weight;

   }



   int main()

   {

        SimpleCat Frisky(5,8);

        SimpleCat & rCat = Frisky;



        cout << "Frisky is: ";

        cout << Frisky.GetAge() << " years old. \n";

        cout << "And Frisky weighs: ";

        cout << rCat.GetWeight() << " pounds. \n";

   return 0;

 }

// end of script...
