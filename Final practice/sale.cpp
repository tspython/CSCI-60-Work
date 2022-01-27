class Sale{
 public:
   Sale( );
   Sale(double thePrice);
   double bill( ) const;
   double savings(const Sale& other) const;
   //Returns the savings if you buy other instead of the calling object.
   private:
   double price;
   };
   bool operator < (const Sale& first, const Sale& second);
   //Compares two sales to see which is larger.
   Sale::Sale( ) : price(0){
     //Intentionally empty
 }
 Sale::Sale(double thePrice){
   if (thePrice >= 0)
   price = thePrice;
   else{
     cout << "Error: Cannot have a negative price!\n";
     exit(1);
   }
 }

 double Sale::bill( ) const{
   return price;
 }
 double Sale::savings(const Sale& other) const{
   return (bill( ) - other.bill( ));
 }
 bool operator < (const Sale& first, const Sale& second){
   return (first.bill( ) < second.bill( ));
 }

class DiscountSale:Sale{
  public:

  private:
    double discount;
}
