// Listing 18.2. PostMasterMessages interface

     class PostMasterMessage : public MailMessage

     {

     public:

       PostMasterMessage();

       PostMasterMessage(

           pAddress Sender,

           pAddress Recipient,

           pString Subject,

           pDate creationDate);



      // other constructors here

      // remember to include copy constructor

      // as well as constructor from storage

      // and constructor from wire format

      // Also include constructors from other formats

      ~PostMasterMessage();

      pAddress& GetSender() const;

      void SetSender(pAddress&);

      // other member accessors



      // operator methods here, including operator equals

      // and conversion routines to turn PostMaster messages

      // into messages of other formats.



    private:

       pAddress itsSender;

       pAddress itsRecipient;

       pString  itsSubject;

       pDate itsCreationDate;

       pDate itsLastModDate;

       pDate itsReceiptDate;

       pDate itsFirstReadDate;

       pDate itsLastReadDate;

 };

// end of script...
