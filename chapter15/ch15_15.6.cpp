// Listing 15.6. Private inheritance.

  //listing 15.6 demonstrates private inheritance



  //rewrites PartsCatalog from listing 15.5



  //see attached notes on compiling



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
