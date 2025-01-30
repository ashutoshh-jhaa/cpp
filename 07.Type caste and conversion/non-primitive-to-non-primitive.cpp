#include <iostream>
using namespace std;

class Item {
 private:
  float discountAmount;

 public:
  Item() { cout << "Item default constructor called\n"; }

  // Parameterized constructor for Item (also acts as a conversion constructor)
  // This constructor allows the conversion of a primitive type (float) into an
  // Item object.
  Item(float d) : discountAmount(d) {
    cout << "Item parameterized constructor called\n";
  }

  void display() const {
    cout << "Discount Amount: " << discountAmount << endl;
  }
};

class Product {
 private:
  float standardPrice, size;

 public:
  Product() { cout << "Product default constructor called\n"; }

  Product(float p, float s) : standardPrice(p), size(s) {
    cout << "Product parameterized constructor called\n";
  }

  // Conversion operator: Converts a Product object to an Item object
  // The conversion operator allows an implicit conversion from Product to Item.
  // This operator is called when we assign a Product object to an Item object,
  // and it constructs an Item by using the standardPrice of Product.
  operator Item() {
    return Item(0.5 * standardPrice);  // Converts standardPrice to
                                       // discountAmount (half of the price)
  }

  void display() const {
    cout << "Standard Price: " << standardPrice << endl;
    cout << "Size: " << size << endl;
  }
};

int main() {
  Product p(42, 82);

  Item i;
  i = p;  // Implicitly calls the conversion operator `operator Item()`

  // Display the converted Item's discount amount (which is half the Product's
  // standard price)
  i.display();

  return 0;
}
