// Listing 13.1. If horses could fly...

     // Percolating Fly() up into Horse



     #include <iostream.h>



     class Horse

     {

     public:

        void Gallop(){ cout << "Galloping...\n"; }

       virtual void Fly() { cout << "Horses can't fly.\n" ; }

    private:

       int itsAge;

    };



    class Pegasus : public Horse

    {

    public:

       virtual void Fly() { cout << "I can fly! I can fly! I can fly!\n"; }

    };



    const int NumberHorses = 5;

    int main()

    {

       Horse* Ranch[NumberHorses];

       Horse* pHorse;

       int choice,i;

       for (i=0; i<NumberHorses; i++)

       {

          cout << "(1)Horse (2)Pegasus: ";

          cin >> choice;

          if (choice == 2)

             pHorse = new Pegasus;

          else

             pHorse = new Horse;

          Ranch[i] = pHorse;

       }

       cout << "\n";

       for (i=0; i<NumberHorses; i++)

       {

          Ranch[i]->Fly();

          delete Ranch[i];

       }

     return 0;

 }

// end of script...
