// Listing 11.4. Creating an array of objects.



     #include <iostream.h>



     class CAT

     {

        public:

           CAT() { itsAge = 1; itsWeight=5; } 

           ~CAT() {}        

          int GetAge() const { return itsAge; }

          int GetWeight() const { return itsWeight; }

          void SetAge(int age) { itsAge = age; }



       private:

          int itsAge;

          int itsWeight;

    };



    int main()

    {

       CAT Litter[5];

       int i;

       for (i = 0; i < 5; i++)

          Litter[i].SetAge(2*i +1);



       for (i = 0; i < 5; i++)

       {

          cout << "Cat #" << i+1<< ": ";

          cout << Litter[i].GetAge() << endl;

       }

     return 0;

 }

// end of script...
