// Listing 14.4. Static member functions.



     #include <iostream.h>



     class Cat

     {

     public:

        Cat(int age):itsAge(age){HowManyCats++; }

        virtual ~Cat() { HowManyCats--; }

       virtual int GetAge() { return itsAge; }

       virtual void SetAge(int age) { itsAge = age; }

       static int GetHowMany() { return HowManyCats; }

    private:

       int itsAge;

       static int HowManyCats;

    };



    int Cat::HowManyCats = 0;



    void TelepathicFunction();



    int main()

    {

       const int MaxCats = 5;

       Cat *CatHouse[MaxCats]; int i;

       for (i = 0; i<MaxCats; i++)

       {

          CatHouse[i] = new Cat(i);

          TelepathicFunction();

       }



       for ( i = 0; i<MaxCats; i++)

       {

          delete CatHouse[i];

          TelepathicFunction();

       }

       return 0;

    }



    void TelepathicFunction()

    {

       cout << "There are " << Cat::GetHowMany() << " cats alive!\n";

 }

// end of script...
