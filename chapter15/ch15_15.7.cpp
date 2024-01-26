// Listing 15.7. Friend class illustrated.

      #include <iostream.h>

    

      typedef unsigned long ULONG;

      typedef unsigned short USHORT;

    

    

      // **************** Part ************

    

      // Abstract base class of parts

      class Part

       {

       public:

          Part():itsPartNumber(1) {}

          Part(ULONG PartNumber):

              itsPartNumber(PartNumber){}

          virtual ~Part(){}

          ULONG GetPartNumber() const 

              { return itsPartNumber; }

          virtual void Display() const =0; 

       private:

          ULONG itsPartNumber;

       };

     

       // implementation of pure virtual function so that

       // derived classes can chain up

       void Part::Display() const

       {

           cout << "\nPart Number: ";

           cout << itsPartNumber << endl;

       }

     

       // **************** Car Part ************

     

       class CarPart : public Part

       {

       public:

          CarPart():itsModelYear(94){}

          CarPart(USHORT year, ULONG partNumber);

          virtual void Display() const 

          { 

              Part::Display(); 

              cout << "Model Year: ";

              cout << itsModelYear << endl;  

          }

       private:

          USHORT itsModelYear;

       };

     

       CarPart::CarPart(USHORT year, ULONG partNumber):

          itsModelYear(year),

          Part(partNumber)

       {}

     

 

       // **************** AirPlane Part ************

     

       class AirPlanePart : public Part

       {

       public:

          AirPlanePart():itsEngineNumber(1){};

          AirPlanePart

              (USHORT EngineNumber, ULONG PartNumber);

          virtual void Display() const

          { 

              Part::Display(); 

              cout << "Engine No.: ";

              cout << itsEngineNumber << endl;  

          }

       private:

          USHORT itsEngineNumber;

       };

     

       AirPlanePart::AirPlanePart

           (USHORT EngineNumber, ULONG PartNumber):

          itsEngineNumber(EngineNumber),

          Part(PartNumber)

       {}

     

     // **************** Part Node ************

     class PartNode

     {

     public:

        friend class PartsList;

        PartNode (Part*);

        ~PartNode();

        void SetNext(PartNode * node) 

            { itsNext = node; }

        PartNode * GetNext() const;

        Part * GetPart() const;

     private:

        Part *itsPart;

        PartNode * itsNext;

     };

    

       

          PartNode::PartNode(Part* pPart):

          itsPart(pPart),

          itsNext(0)

          {}

       

          PartNode::~PartNode()

          {

              delete itsPart;

              itsPart = 0;

              delete itsNext;

              itsNext = 0;

           }

        

           // Returns NULL if no next PartNode

           PartNode * PartNode::GetNext() const

           {

                 return itsNext;

           }

        

           Part * PartNode::GetPart() const

           {

              if (itsPart)

                 return itsPart;

              else

                 return NULL; //error

           }

        

    

     // **************** Part List ************

     class PartsList

     {

     public:

        PartsList();

        ~PartsList();

        // needs copy constructor and operator equals!

        void     Iterate(void (Part::*f)()const) const;

        Part*    Find(ULONG & position, ULONG PartNumber) const;

        Part*    GetFirst() const;

        void       Insert(Part *);

        Part*    operator[](ULONG) const;

        ULONG    GetCount() const { return itsCount; }

        static    PartsList& GetGlobalPartsList() 

                { 

                    return  GlobalPartsList;

                }

     private:

        PartNode * pHead;

        ULONG itsCount;

        static PartsList GlobalPartsList;

     };

    

     PartsList PartsList::GlobalPartsList;

    

     // Implementations for Lists...

    

     PartsList::PartsList():

        pHead(0),

        itsCount(0)

        {}

    

     PartsList::~PartsList()

     {

        delete pHead;

     }

    

     Part*   PartsList::GetFirst() const

     {

        if (pHead)

           return pHead->itsPart;

        else

           return NULL;  // error catch here

     }

    

     Part * PartsList::operator[](ULONG offSet) const

     {

        PartNode* pNode = pHead;

    

        if (!pHead)

           return NULL; // error catch here

    

        if (offSet > itsCount)

           return NULL; // error

    

        for (ULONG i=0;i<offSet; i++)

           pNode = pNode->itsNext;

    

       return   pNode->itsPart;

     }

    

    Part* PartsList::Find(ULONG & position, ULONG PartNumber) const

     {

        PartNode * pNode = 0;

        for (pNode = pHead, position = 0;

              pNode!=NULL;

              pNode = pNode->itsNext, position++)

        {

           if (pNode->itsPart->GetPartNumber() == PartNumber)

              break;

        }

        if (pNode == NULL)

           return NULL;

        else

           return pNode->itsPart;

     }

    

     void PartsList::Iterate(void (Part::*func)()const) const

     {

        if (!pHead)

           return;

        PartNode* pNode = pHead;

        do

           (pNode->itsPart->*func)();

        while (pNode = pNode->itsNext);

     }

    

     void PartsList::Insert(Part* pPart)

     {

        PartNode * pNode = new PartNode(pPart);

        PartNode * pCurrent = pHead;

        PartNode * pNext = 0;

    

        ULONG New =  pPart->GetPartNumber();

        ULONG Next = 0;

        itsCount++;

    

        if (!pHead)

        {

           pHead = pNode;

           return;

        }

    

        // if this one is smaller than head

        // this one is the new head

        if (pHead->itsPart->GetPartNumber() > New)

        {

           pNode->itsNext = pHead;

           pHead = pNode;

           return;

        }

    

        for (;;)

        {

           // if there is no next, append this new one

           if (!pCurrent->itsNext)

           {

              pCurrent->itsNext = pNode;

              return;

           }

 

           // if this goes after this one and before the next

           // then insert it here, otherwise get the next

           pNext = pCurrent->itsNext;

           Next = pNext->itsPart->GetPartNumber();

           if (Next > New)

           {

              pCurrent->itsNext = pNode;

              pNode->itsNext = pNext;

              return;

           }

           pCurrent = pNext;

        }

     }

    

     class PartsCatalog : private PartsList

     {

     public:

        void Insert(Part *);

        ULONG Exists(ULONG PartNumber);

        Part * Get(int PartNumber);

        operator+(const PartsCatalog &);

        void ShowAll() { Iterate(Part::Display); }

     private:

     };

    

     void PartsCatalog::Insert(Part * newPart)

     {

        ULONG partNumber =  newPart->GetPartNumber();

        ULONG offset;

    

        if (!Find(offset, partNumber))

           PartsList::Insert(newPart);

        else

        {

           cout << partNumber << " was the ";

           switch (offset)

           {

              case 0:  cout << "first "; break;

              case 1:  cout << "second "; break;

              case 2:  cout << "third "; break;

              default: cout << offset+1 << "th ";

           }

           cout << "entry. Rejected!\n";

        }

     }

    

     ULONG PartsCatalog::Exists(ULONG PartNumber)

     {

        ULONG offset;

        Find(offset,PartNumber);

        return offset;

     }

    

     Part * PartsCatalog::Get(int PartNumber)

     {

        ULONG offset;

        return (Find(offset, PartNumber));

    

     }

    

     int main()

     {

        PartsCatalog pc;

        Part * pPart = 0;

        ULONG PartNumber;

        USHORT value;

        ULONG choice;

    

        while (1)

        {

           cout << "(0)Quit (1)Car (2)Plane: ";

           cin >> choice;

    

           if (!choice)

              break;

    

           cout << "New PartNumber?: ";

           cin >>  PartNumber;

    

           if (choice == 1)

           {

              cout << "Model Year?: ";

              cin >> value;

              pPart = new CarPart(value,PartNumber);

           }

           else

           {

              cout << "Engine Number?: ";

              cin >> value;

              pPart = new AirPlanePart(value,PartNumber);

           }

           pc.Insert(pPart);

        }

        pc.ShowAll();

       return 0;

 }

// end of script...
