// Listing 16.3. Multiple input.



     #include <iostream.h>



     int main()

     {

        int myInt;

        long myLong;

        double myDouble;

       float myFloat;

       unsigned int myUnsigned;

       char myWord[50];



       cout << "int: ";

       cin >> myInt;

       cout << "Long: ";

       cin >> myLong;

       cout << "Double: ";

       cin >> myDouble;

       cout << "Float: ";

       cin >> myFloat;

       cout << "Word: ";

       cin >> myWord;

       cout << "Unsigned: ";

       cin >> myUnsigned;



       cout << "\n\nInt:\t" << myInt << endl;

       cout << "Long:\t" << myLong << endl;

       cout << "Double:\t" << myDouble << endl;

       cout << "Float:\t" << myFloat << endl;

       cout << "Word: \t" << myWord << endl;

       cout << "Unsigned:\t" << myUnsigned << endl;



       cout << "\n\nInt, Long, Double, Float, Word, Unsigned: ";

       cin >> myInt >> myLong >> myDouble;

       cin >> myFloat >> myWord >> myUnsigned;

       cout << "\n\nInt:\t" << myInt << endl;

       cout << "Long:\t" << myLong << endl;

       cout << "Double:\t" << myDouble << endl;

       cout << "Float:\t" << myFloat << endl;

       cout << "Word: \t" << myWord << endl;

       cout << "Unsigned:\t" << myUnsigned << endl;





     return 0;

 }

// end of script...
