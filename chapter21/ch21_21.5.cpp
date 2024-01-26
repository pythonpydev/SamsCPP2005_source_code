// Listing 21.5. Using ctime().

     #include <time.h>

     #include <iostream.h>



     int main()

     {

        time_t currentTime;



        // get and print the current time

        time (&currentTime); // fill now with the current time

       cout << "It is now " << ctime(&currentTime) << endl;



       struct tm * ptm= localtime(&currentTime);



       cout << "Today is " << ((ptm->tm_mon)+1) << "/";

       cout << ptm->tm_mday << "/";

       cout << ptm->tm_year << endl;



       cout << "\nDone.";

     return 0;

 }

// end of script...
