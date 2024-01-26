// Listing 16.2. Trying to write more than one word to cin.



     #include <iostream.h>



     int main()

     {

        char YourName[50];

        cout << "Your first name: ";

        cin >> YourName;

       cout << "Here it is: " << YourName << endl;

       cout << "Your entire name: ";

       cin >> YourName;

       cout << "Here it is: " << YourName << endl;

     return 0;

 }

// end of script...
