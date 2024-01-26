// Listing 15.9. Overloading operator<<().

     #include <iostream.h>

     #include <string.h>



     class String

     {

        public:

           // constructors

           String();

            String(const char *const);

           String(const String &);

          ~String();



          // overloaded operators

          char & operator[](int offset);

          char operator[](int offset) const;

          String operator+(const String&);

          void operator+=(const String&);

          String & operator= (const String &);

          friend ostream& operator<<

             ( ostream& theStream,String& theString);

          // General accessors

          int GetLen()const { return itsLen; }

          const char * GetString() const { return itsString; }

          // static int ConstructorCount;

       private:

          String (int);         // private constructor

          char * itsString;

          unsigned short itsLen;

    };



    ostream& operator<<

        ( ostream& theStream,String& theString)

    {

        theStream << theString.GetString();

        return theStream;

    }

    int main()

    {

       String theString("Hello world.");

       cout << theString;

     return 0;

 }

// end of script...
