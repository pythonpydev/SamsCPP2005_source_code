// Listing 11.7. Creating an array by using new.



     #include <iostream.h>



     class CAT

     {

        public:

           CAT() { itsAge = 1; itsWeight=5; } 

           ~CAT();         

          int GetAge() const { return itsAge; }

          int GetWeight() const { return itsWeight; }

          void SetAge(int age) { itsAge = age; }



       private:

          int itsAge;

          int itsWeight;

    };



    CAT :: ~CAT()

    {

      // cout << "Destructor called!\n";

    }



    int main()

    {

       CAT * Family = new CAT[500];

       int i;

       CAT * pCat;

       for (i = 0; i < 500; i++)

       {

          pCat = new CAT;

          pCat->SetAge(2*i +1);

          Family[i] = *pCat;

          delete pCat;

       }



       for (i = 0; i < 500; i++)

       {

          cout << "Cat #" << i+1 << ": ";

          cout << Family[i].GetAge() << endl;

       }



       delete [] Family;



     return 0;

 }

// end of script...
