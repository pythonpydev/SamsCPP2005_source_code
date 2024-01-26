// Listing 14.3. Accessing static members using non-static member functions.



     #include <iostream.h>



     class Cat

     {

     public:

        Cat(int age):itsAge(age){HowManyCats++; }

        virtual ~Cat() { HowManyCats--; }

       virtual int GetAge() { return itsAge; }

       virtual void SetAge(int age) { itsAge = age; }

       virtual int GetHowMany() { return HowManyCats; }





    private:

       int itsAge;

       static int HowManyCats;

    };



    int Cat::HowManyCats = 0;



    int main()

    {

       const int MaxCats = 5; int i;

       Cat *CatHouse[MaxCats];

       for (i = 0; i<MaxCats; i++)

          CatHouse[i] = new Cat(i);



       for (i = 0; i<MaxCats; i++)

       {

          cout << "There are ";

          cout << CatHouse[i]->GetHowMany();

          cout << " cats left!\n";

          cout << "Deleting the one which is ";

          cout << CatHouse[i]->GetAge()+2;

          cout << " years old\n";

          delete CatHouse[i];

          CatHouse[i] = 0;

       }

     return 0;

 }

// end of script...
