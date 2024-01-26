// Listing 4.4. A demonstration of branching based on relational operators.

  // used with relational operators

  #include <iostream.h>

  int main()

  {

        int RedSoxScore, YankeesScore;

        cout << "Enter the score for the Red Sox: ";

        cin >> RedSoxScore;



       cout << "\nEnter the score for the Yankees: ";

       cin >> YankeesScore;



       cout << "\n";



       if (RedSoxScore > YankeesScore)

            cout << "Go Sox!\n";



       if (RedSoxScore < YankeesScore)

       {

            cout << "Go Yankees!\n";

            cout << "Happy days in New York!\n";

       }



       if (RedSoxScore == YankeesScore)

       {

            cout << "A tie? Naah, can't be.\n";

            cout << "Give me the real score for the Yanks: ";

            cin >> YankeesScore;



            if (RedSoxScore > YankeesScore)

                 cout << "Knew it! Go Sox!";



            if (YankeesScore > RedSoxScore)

                 cout << "Knew it! Go Yanks!";



            if (YankeesScore == RedSoxScore)

                 cout << "Wow, it really was a tie!";

       }



       cout << "\nThanks for telling me.\n";

        return 0;

 }

// end of script...
