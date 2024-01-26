// Listing 3.7. A demonstration of enumerated constants.

  #include <iostream.h>

  int main()

  {

       enum Days { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday,                     Â_Saturday };



       Days DayOff;

       int x;



       cout << "What day would you like off (0-6)? ";

      cin  >> x;

      DayOff = Days(x);



      if (DayOff == Sunday || DayOff == Saturday)

            cout << "\nYou're already off on weekends!\n";

      else

            cout << "\nOkay, I'll put in the vacation day.\n";

       return 0;

 }

// end of script...
