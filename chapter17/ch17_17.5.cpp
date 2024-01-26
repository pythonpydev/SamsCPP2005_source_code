// Listing 17.5. A simple assert() macro.

     #define DEBUG

     #include <iostream.h>



     #ifndef DEBUG

        #define ASSERT(x)

     #else

        #define ASSERT(x) \

                 if (! (x)) \

                { \

                   cout << "ERROR!! Assert " << #x << " failed\n"; \

                   cout << " on line " << __LINE__  << "\n"; \

                   cout << " in file " << __FILE__ << "\n";  \

                }

    #endif





    int main()

    {

       int x = 5;

       cout << "First assert: \n";

       ASSERT(x==5);

       cout << "\nSecond assert: \n";

       ASSERT(x != 5);

       cout << "\nDone.\n";

     return 0;

 }

// end of script...
