// Listing 6.2. A class with accessor methods.

       // Cat class declaration

       // Data members are private, public accessor methods

       // mediate setting and getting the values of the private data



  class Cat

  {

  public:

       // public accessors

     unsigned int GetAge();

    void SetAge(unsigned int Age);



    unsigned int GetWeight();

    void SetWeight(unsigned int Weight);



      // public member functions

    Meow();



      // private member data

 private:

    unsigned int  itsAge;

    unsigned int  itsWeight;



 }; 

// end of script...
