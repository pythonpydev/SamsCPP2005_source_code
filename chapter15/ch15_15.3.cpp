// Listing 15.3. Contained class constructors.

     int main()

     {

        cout << "Creating Edie...\n";

        Employee Edie("Jane","Doe","1461 Shore Parkway", 20000);

        Edie.SetSalary(20000);

        cout << "Calling SetFirstName with char *...\n";

        Edie.SetFirstName("Edythe");

        cout << "Creating temporary string LastName...\n";

        String LastName("Levine");

       Edie.SetLastName(LastName);



       cout << "Name: ";

       cout << Edie.GetFirstName().GetString();

       cout << " " << Edie.GetLastName().GetString();

       cout << "\nAddress: ";

       cout << Edie.GetAddress().GetString();

       cout << "\nSalary: " ;

       cout << Edie.GetSalary();

       cout << endl;

     return 0;

 }

// end of script...
