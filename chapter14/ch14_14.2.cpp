// Listing 14.2. Accessing static members without an object.



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



    void TelepathicFunction();



    int main()

    {

       const int MaxCats = 5; int i;

       Cat *CatHouse[MaxCats];

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

       cout << "There are ";

       cout << Cat::HowManyCats << " cats alive!\n";

 }

// end of script...
