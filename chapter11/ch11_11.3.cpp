// Listing 11.3. Using consts and enums in arrays.

     // Dimensioning arrays with consts and enumerations



     #include <iostream.h>

     int main()

     {

        enum WeekDays { Sun, Mon, Tue, 

             Wed, Thu, Fri, Sat, DaysInWeek };

        int ArrayWeek[DaysInWeek] = { 10, 20, 30, 40, 50, 60, 70 };



       cout << "The value at Tuesday is: " << ArrayWeek[Tue];

     return 0;

 }

// end of script...
