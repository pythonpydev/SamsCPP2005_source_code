// Listing 15.1. The String class.

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



          // General accessors

          int GetLen()const { return itsLen; }

          const char * GetString() const { return itsString; }

          // static int ConstructorCount;



       private:

          String (int);         // private constructor

          char * itsString;

          unsigned short itsLen;



    };



    // default constructor creates string of 0 bytes

    String::String()

    {

       itsString = new char[1];

       itsString[0] = `\0';

       itsLen=0;

       // cout << "\tDefault string constructor\n";

       // ConstructorCount++;

    }



    // private (helper) constructor, used only by

    // class methods for creating a new string of

    // required size.  Null filled.

    String::String(int len)

    {

       itsString = new char[len+1];

       for (int i = 0; i<=len; i++)

          itsString[i] = `\0';

       itsLen=len;

       // cout << "\tString(int) constructor\n";

       // ConstructorCount++;

    }



    // Converts a character array to a String

    String::String(const char * const cString)

    {

       itsLen = strlen(cString);

       itsString = new char[itsLen+1];

       for (int i = 0; i<itsLen; i++)

          itsString[i] = cString[i];

       itsString[itsLen]='\0';

       // cout << "\tString(char*) constructor\n";

       // ConstructorCount++;

    }



    // copy constructor

    String::String (const String & rhs)

    {

       itsLen=rhs.GetLen();

       itsString = new char[itsLen+1];

       for (int i = 0; i<itsLen;i++)

          itsString[i] = rhs[i];

       itsString[itsLen] = `\0';

       // cout << "\tString(String&) constructor\n";

       // ConstructorCount++;

    }



    // destructor, frees allocated memory

    String::~String ()

    {

       delete [] itsString;

       itsLen = 0;

       // cout << "\tString destructor\n";

    }



    // operator equals, frees existing memory

    // then copies string and size

    String& String::operator=(const String & rhs)

    {

       if (this == &rhs)

          return *this;

       delete [] itsString;

       itsLen=rhs.GetLen();

       itsString = new char[itsLen+1];

       for (int i = 0; i<itsLen;i++)

          itsString[i] = rhs[i];

       itsString[itsLen] = `\0';

       return *this;

      // cout << "\tString operator=\n";

   }



   //non constant offset operator, returns

   // reference to character so it can be

   // changed!

   char & String::operator[](int offset)

   {

      if (offset > itsLen)

         return itsString[itsLen-1];

      else

         return itsString[offset];

   }



   // constant offset operator for use

   // on const objects (see copy constructor!)

   char String::operator[](int offset) const

   {

      if (offset > itsLen)

         return itsString[itsLen-1];

      else

         return itsString[offset];

   }



   // creates a new string by adding current

   // string to rhs

   String String::operator+(const String& rhs)

   {

      int  totalLen = itsLen + rhs.GetLen();

      String temp(totalLen);

      int i, j;

      for (i = 0; i<itsLen; i++)

         temp[i] = itsString[i];

      for (j = 0; j<rhs.GetLen(); j++, i++)

         temp[i] = rhs[j];

      temp[totalLen]='\0';

      return temp;

   }



   // changes current string, returns nothing

   void String::operator+=(const String& rhs)

   {

      unsigned short rhsLen = rhs.GetLen();

      unsigned short totalLen = itsLen + rhsLen;

      String  temp(totalLen);

      for (int i = 0; i<itsLen; i++)

         temp[i] = itsString[i];

      for (int j = 0; j<rhs.GetLen(); j++, i++)

         temp[i] = rhs[i-itsLen];

      temp[totalLen]='\0';

      *this = temp;

   }



 // int String::ConstructorCount = 0;

// end of script...
