// Listing 14.1. Static member data.



     #include <iostream.h>



     class Cat

     {

     public:

        Cat(int age):itsAge(age){HowManyCats++; }

        virtual ~Cat() { HowManyCats--; }

       virtual int GetAge() { return itsAge; }

       virtual void SetAge(int age) { itsAge = age; }

       static int HowManyCats;



    private:

       int itsAge;



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

          cout << Cat::HowManyCats;

          cout << " cats left!\n";

          cout << "Deleting the one which is ";

          cout << CatHouse[i]->GetAge();

          cout << " years old\n";

          delete CatHouse[i];

          CatHouse[i] = 0;

       }

     return 0;

 }

// end of script...
