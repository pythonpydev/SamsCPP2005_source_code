// Listing 18.3. A driver program for PostMasterMessage.

     #include <iostream.h>

     #include <string.h>



     typedef unsigned long pDate;

     enum SERVICE 

       { PostMaster, Interchange, CompuServe, Prodigy, AOL, Internet };

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

          itsString[1] = `\0';

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

      int i,j;

      String temp(totalLen);

      for ( i = 0; i<itsLen; i++)

         temp[i] = itsString[i];

      for ( j = 0; j<rhs.GetLen(); j++, i++)

         temp[i] = rhs[j];

      temp[totalLen]='\0';

      return temp;

   }

   

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



   ostream& operator<<( ostream& theStream,String& theString)

   {

       theStream << theString.GetString();

       return theStream;

   }



   class pAddress

   {

   public:

      pAddress(SERVICE theService,

               const String& theAddress,

               const String& theDisplay):

         itsService(theService),

         itsAddressString(theAddress),

         itsDisplayString(theDisplay)

         {}

      // pAddress(String, String);

      // pAddress();

      // pAddress (const pAddress&);

      ~pAddress(){}

      friend ostream& operator<<( ostream& theStream, pAddress& theAddress);

      String& GetDisplayString() { return itsDisplayString; }

   private:

      SERVICE itsService;

      String itsAddressString;

      String itsDisplayString;

   };



   ostream& operator<<( ostream& theStream, pAddress& theAddress)

   {

       theStream << theAddress.GetDisplayString();

       return theStream;

   }



   class PostMasterMessage

   {

   public:

     // PostMasterMessage();



     PostMasterMessage(const pAddress& Sender,

                     const pAddress& Recipient,

                     const String& Subject,

                     const pDate& creationDate);



     // other constructors here

     // remember to include copy constructor

     // as well as constructor from storage

     // and constructor from wire format

     // Also include constructors from other formats

     ~PostMasterMessage(){}



     void Edit(); // invokes editor on this message



     pAddress& GetSender() const { return itsSender; }

     pAddress& GetRecipient() const { return itsRecipient; }

     String& GetSubject() const { return itsSubject; }

     //  void SetSender(pAddress& );

     // other member accessors



     // operator methods here, including operator equals

     // and conversion routines to turn PostMaster messages

     // into messages of other formats.



   private:

      pAddress itsSender;

      pAddress itsRecipient;

      String  itsSubject;

      pDate itsCreationDate;

      pDate itsLastModDate;

      pDate itsReceiptDate;

      pDate itsFirstReadDate;

      pDate itsLastReadDate;

   };



   PostMasterMessage::PostMasterMessage(

         const pAddress& Sender,

         const pAddress& Recipient,

         const String& Subject,

         const pDate& creationDate):

         itsSender(Sender),

         itsRecipient(Recipient),

         itsSubject(Subject),

         itsCreationDate(creationDate),

         itsLastModDate(creationDate),

         itsFirstReadDate(0),

         itsLastReadDate(0)

     {

       cout << "Post Master Message created. \n";

     }



     void PostMasterMessage::Edit()

      {

         cout << "PostMasterMessage edit function called\n";

      }





   int main()

   {

      pAddress Sender(PostMaster, "jliberty@PostMaster", "Jesse Liberty");

      pAddress Recipient(PostMaster, "sl@PostMaster","Stacey Liberty");

      PostMasterMessage PostMessage(Sender, Recipient, "Saying Hello", 0);

      cout << "Message review... \n";

      cout << "From:\t\t" << PostMessage.GetSender() << endl;

      cout << "To:\t\t" << PostMessage.GetRecipient() << endl;

      cout << "Subject:\t" << PostMessage.GetSubject() << endl;

     return 0;

 }

// end of script...
