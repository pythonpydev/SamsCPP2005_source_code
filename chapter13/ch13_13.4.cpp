// Listing 13.4. Calling multiple constructors.

     // Calling multiple constructors

     #include <iostream.h>

     typedef int HANDS;

     enum COLOR { Red, Green, Blue, Yellow, White, Black, Brown } ;

     enum BOOL { FALSE, TRUE };



     class Horse

     {

    public:

       Horse(COLOR color, HANDS height);

       virtual ~Horse() { cout << "Horse destructor...\n"; }

       virtual void Whinny()const { cout << "Whinny!... "; }

       virtual HANDS GetHeight() const { return itsHeight; }

       virtual COLOR GetColor() const { return itsColor; }

    private:

       HANDS itsHeight;

       COLOR itsColor;

    };



    Horse::Horse(COLOR color, HANDS height):

       itsColor(color),itsHeight(height)

    {

       cout << "Horse constructor...\n";

    }



    class Bird

    {

    public:

       Bird(COLOR color, BOOL migrates);

       virtual ~Bird() {cout << "Bird destructor...\n";  }

       virtual void Chirp()const { cout << "Chirp... ";  }

       virtual void Fly()const 

       { 

          cout << "I can fly! I can fly! I can fly! "; 

       }

       virtual COLOR GetColor()const { return itsColor; }

       virtual BOOL GetMigration() const { return itsMigration; }

 

    private:

       COLOR itsColor;

       BOOL itsMigration;

    };



    Bird::Bird(COLOR color, BOOL migrates):

       itsColor(color), itsMigration(migrates)

    {

       cout << "Bird constructor...\n";

    }



    class Pegasus : public Horse, public Bird

    {

    public:

       void Chirp()const { Whinny(); }

       Pegasus(COLOR, HANDS, BOOL,long);

       ~Pegasus() {cout << "Pegasus destructor...\n";}

       virtual long GetNumberBelievers() const 

        { 

           return  itsNumberBelievers; 

        }



    private:

       long itsNumberBelievers;

    };

 

    Pegasus::Pegasus(

        COLOR aColor, 

        HANDS height, 

        BOOL migrates, 

        long NumBelieve):

    Horse(aColor, height),

    Bird(aColor, migrates),

    itsNumberBelievers(NumBelieve)

    {

       cout << "Pegasus constructor...\n";

    }



    int main()

    {

       Pegasus *pPeg = new Pegasus(Red, 5, TRUE, 10);

       pPeg->Fly();

       pPeg->Whinny();

       cout << "\nYour Pegasus is " << pPeg->GetHeight();

       cout << " hands tall and ";

       if (pPeg->GetMigration())

          cout << "it does migrate.";

       else

          cout << "it does not migrate.";

       cout << "\nA total of " << pPeg->GetNumberBelievers();

       cout << " people believe it exists.\n";

       delete pPeg;

     return 0;

 }

// end of script...
