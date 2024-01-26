// Listing 15.8. Friendly operator+.



     #include <iostream.h>

     #include <string.h>



     // Rudimentary string class

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

          friend String operator+(const String&, const String&);

          void operator+=(const String&);

          String & operator= (const String &);



          // General accessors

          int GetLen()const { return itsLen; }

          const char * GetString() const { return itsString; }



       private:

          String (int);         // private constructor

          char * itsString;

          unsigned short itsLen;

    };



    // creates a new string by adding current

    // string to rhs

    String String::operator+(const String& rhs)

    {

       int  totalLen = itsLen + rhs.GetLen();

       String temp(totalLen);

       for (int i = 0; i<itsLen; i++)

          temp[i] = itsString[i];

       for (int j = 0; j<rhs.GetLen(); j++, i++)

          temp[i] = rhs[j];

       temp[totalLen]='\0';

       return temp;

    }



    // creates a new string by adding

    // one string to another

    String operator+(const String& lhs, const String& rhs)

    {

       int  totalLen = lhs.GetLen() + rhs.GetLen();

       String temp(totalLen);

       for (int i = 0; i<lhs.GetLen(); i++)

          temp[i] = lhs[i];

       for (int j = 0; j<rhs.GetLen(); j++, i++)

          temp[i] = rhs[j];

       temp[totalLen]='\0';

       return temp;

    }



    int main()

    {

       String s1("String One ");

       String s2("String Two ");

       char *c1 = { "C-String One " } ;

       String s3;

       String s4;

       String s5;



       cout << "s1: " << s1.GetString() << endl;

       cout << "s2: " << s2.GetString() << endl;

       cout << "c1: " << c1 << endl;

       s3 = s1 + s2;

       cout << "s3: " << s3.GetString() << endl;

       s4 = s1 + c1;

       cout << "s4: " << s4.GetString() << endl;

       s5 = c1 + s1;

       cout << "s5: " << s5.GetString() << endl;

     return 0;

 }

// end of script...
