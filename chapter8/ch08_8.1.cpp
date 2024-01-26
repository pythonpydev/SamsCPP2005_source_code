// Listing 8.1. Demonstrating address of variables.

   // and addresses of local variables



   #include <iostream.h>



   int main()

   {

      unsigned short shortVar=5;

      unsigned long  longVar=65535;

     long sVar = -65535;



     cout << "shortVar:\t" << shortVar;

     cout << " Address of shortVar:\t";

     cout <<  &shortVar  _<< "\n";



     cout << "longVar:\t"  << longVar;

      cout  << " Address of longVar:\t" ;

      cout <<  &longVar  _<< "\n";



     cout << "sVar:\t"     << sVar;

       cout     << " Address of sVar:\t" ;

       cout     <<  &sVar     _<< "\n";



  return 0;

 }

// end of script...
