/*
Write a C++ program to define a base class Item with the following attributes:
itemNo (Item Number)
itemName (Item Name)
itemPrice (Item Price)
Derive a class DiscountedItem from Item, which includes an additional attribute:

discountPercentage (Discount Percentage)
A customer purchases n items. The program should:

Accept details for n items, including their name, number, price, and discount
percentage. Display an item-wise bill, including the original price, discount
percentage, and final discounted price. Calculate and display the total original
price and the total discount amount.

Example Input:
how many items do you want to enter? 2

Enter item details:

Item Name: Shirt
Item Number: 1002
Item Price: 400
Discount Percentage: 20

Enter item details:

Item Name: Jeans
Item Number: 1003
Item Price: 800
Discount Percentage: 15

Expected Output:
Item Name       : Shirt
Item No.        : 1002
Item Price      : 400
Discount Percent: 20%
Discounted Price: 320
------------------------
Item Name       : Jeans
Item No.        : 1003
Item Price      : 800
Discount Percent: 15%
Discounted Price: 680
------------------------
Total Price     : 1200
Total Discount  : 200 */

#include <iostream>
using namespace std;

class Item {
 private:
  unsigned int itemNo;
  float itemPrice;
  string itemName;

 public:
  void setItemDetails() {
    cout << "Enter Item Name: ";
    cin.ignore();
    getline(cin, itemName);

    cout << "Enter Item Number: ";
    cin >> itemNo;

    cout << "Enter Item Price: ";
    cin >> itemPrice;
  }

  void getItemDetails() {
    cout << "Item Name       : " << itemName << endl;
    cout << "Item No.        : " << itemNo << endl;
    cout << "Item Price      : " << itemPrice << endl;
  }

  float getItemPrice() { return itemPrice; }
};

class DiscountedItem : public Item {
 private:
  float discountPercentage, discountedPrice;

 public:
  void addProductDetails() {
    setItemDetails();
    cout << "Enter Discount Percentage: ";
    cin >> discountPercentage;
    setDiscountedPrice();
  }

  void setDiscountedPrice() {
    discountedPrice = getItemPrice() * (1 - discountPercentage / 100);
  }

  float getDiscountedPrice() { return discountedPrice; }
  float getDiscountAmount() { return getItemPrice() - discountedPrice; }

  void getProductsDetails() {
    getItemDetails();
    cout << "Discount Percent : " << discountPercentage << "%" << endl;
    cout << "Discounted Price : " << discountedPrice << endl;
    cout << "------------------------" << endl;
  }
};

int main() {
  int n;
  cout << "How many items do you want to enter? ";
  cin >> n;

  DiscountedItem* items = new DiscountedItem[n];

  for (int i = 0; i < n; i++) {
    cout << "\nEnter item details:\n";
    items[i].addProductDetails();
  }

  float totalPrice = 0, totalDiscount = 0;
  cout << "\nOutput:\n";
  for (int i = 0; i < n; i++) {
    items[i].getProductsDetails();
    totalPrice += items[i].getItemPrice();
    totalDiscount += items[i].getDiscountAmount();
  }

  cout << "Total Price     : " << totalPrice << endl;
  cout << "Total Discount  : " << totalDiscount << endl;

  delete[] items;
  return 0;
}