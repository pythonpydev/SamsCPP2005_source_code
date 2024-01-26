// Listing 17.8. Levels of debugging.

    enum LEVEL { NONE, LOW, MEDIUM, HIGH };

    const int FALSE = 0;

    const int TRUE = 1;

    typedef int BOOL;

    

     #define DEBUGLEVEL HIGH

    

     #include <iostream.h>

     #include <string.h>

    

     #if DEBUGLEVEL < LOW  // must be medium or high

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

    

     #if DEBUGLEVEL < MEDIUM

     #define EVAL(x)

     #else

     #define EVAL(x) \

       cout << #x << ":\t" << x << endl;

     #endif

    

    #if DEBUGLEVEL < HIGH

     #define PRINT(x)

     #else

     #define PRINT(x) \

       cout << x << endl;

     #endif

    

    

     class String

     {

        public:

           // constructors

           String();

           String(const char *const);

           String(const String &);

           ~String();

    

           char & operator[](int offset);

           char operator[](int offset) const;

    

           String & operator= (const String &);

           int GetLen()const { return itsLen; }

           const char * GetString() const 

            { return itsString; }

           BOOL Invariants() const;

 

        private:

           String (int);         // private constructor

           char * itsString;

           unsigned short itsLen;

     };

    

     BOOL String::Invariants() const

     {

         PRINT("(String Invariants Checked)");

         return ( (BOOL) (itsLen && itsString) || 

             (!itsLen && !itsString) );

     }

    

     class Animal

     {

     public:

        Animal():itsAge(1),itsName("John Q. Animal")

            {ASSERT(Invariants());}

    

        Animal(int, const String&);

        ~Animal(){}

    

        int GetAge() 

            {  

                ASSERT(Invariants()); 

                return itsAge;

            }

    

        void SetAge(int Age) 

            { 

                ASSERT(Invariants()); 

                itsAge = Age; 

                ASSERT(Invariants());

            }

        String& GetName() 

            { 

                ASSERT(Invariants()); 

                return itsName;  

            }

    

        void SetName(const String& name)

            { 

                ASSERT(Invariants()); 

                itsName = name; 

                ASSERT(Invariants());

            }

    

        BOOL Invariants();

     private:

        int itsAge;

        String itsName;

     };

    

     BOOL Animal::Invariants()

     {

        PRINT("(Animal Invariants Checked)");

        return (itsAge > 0 && itsName.GetLen());

     }

    

     int main()

     {

        const int AGE = 5;

        EVAL(AGE);

        Animal sparky(AGE,"Sparky");

        cout << "\n" << sparky.GetName().GetString();

        cout << " is ";

        cout << sparky.GetAge() << " years old.";

        sparky.SetAge(8);

        cout << "\n" << sparky.GetName().GetString();

        cout << " is ";

        cout << sparky.GetAge() << " years old.";

        return 0;

 }

// end of script...
