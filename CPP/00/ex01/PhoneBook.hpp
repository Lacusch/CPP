#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <string>

class Phone_Book {
public:
  Phone_Book(void);
  ~Phone_Book(void);

  void run_phoneBook(void);
  void add_contact(void);
  void list_contact(void);
  void list_elem(Contact c, int index);

private:
  Contact _cottacts[8];
  int _oldest;
  int _number;
};
#endif
