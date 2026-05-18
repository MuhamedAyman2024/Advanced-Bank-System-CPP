#ifndef H_IPRINTABLE_H
#define H_IPRINTABLE_H
#include <iostream>

class IPrintable {
friend std::ostream& operator<<(std::ostream& os, const IPrintable& obj) {
  obj.print(os);
  return os;
}
public:
  virtual void print(std::ostream& os) const = 0;
};

#endif // H_IPRINTABLE_H