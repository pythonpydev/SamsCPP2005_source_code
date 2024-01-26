// Listing 13.8. Abstract Data Types.

  class Shape

  {

  public:

       Shape(){}

       ~Shape(){}

       virtual long GetArea() = 0; // error

       virtual long GetPerim()= 0;

       virtual void Draw() = 0;

  private:

// end of script...
