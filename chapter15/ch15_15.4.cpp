// Listing 15.4. Passing by value

     void PrintFunc(Employee);

     void rPrintFunc(const Employee&);



     int main()

     {

        Employee Edie("Jane","Doe","1461 Shore Parkway", 20000);

        Edie.SetSalary(20000);

        Edie.SetFirstName("Edythe");

        String LastName("Levine");

       Edie.SetLastName(LastName);



       cout << "Constructor count: " ;

       cout << String::ConstructorCount << endl;

       rPrintFunc(Edie);

       cout << "Constructor count: ";

        cout << String::ConstructorCount << endl;

       PrintFunc(Edie);

       cout << "Constructor count: ";

        cout << String::ConstructorCount << endl;

     return 0;

    }

    void PrintFunc (Employee Edie)

    {



       cout << "Name: ";

       cout << Edie.GetFirstName().GetString();

       cout << " " << Edie.GetLastName().GetString();

       cout << ".\nAddress: ";

       cout << Edie.GetAddress().GetString();

       cout << ".\nSalary: " ;

       cout << Edie.GetSalary();

       cout << endl;



    }



    void rPrintFunc (const Employee& Edie)

    {

       cout << "Name: ";

       cout << Edie.GetFirstName().GetString();

       cout << " " << Edie.GetLastName().GetString();

       cout << "\nAddress: ";

       cout << Edie.GetAddress().GetString();

       cout << "\nSalary: " ;

       cout << Edie.GetSalary();

       cout << endl;

 }

// end of script...
