#include <iostream>

#include "RingArray.h"

void fer_assert(const bool expr, const char* msg) {
  if (!expr) {
    std::cout << msg << std::endl;
    exit(1);
  }
}

template <class T, unsigned N>
void RingArray<T, N>::add(T value) {
  // TODO: implement this method.
      buf[_last] = value;
      _last++;
    if(_last==N)
  {
     fer_assert(false,"Erro: anel cheio.");
  } 
}

template <class T, unsigned N>
T RingArray<T, N>::get() {
  // TODO: implement this method.
  if(_first==_last)
    fer_assert(false,"Erro: anel vazio.");
  else{
    T aux = buf[0];
    for(int i=0;i<_last;i++){
        int j = i + 1;
        buf[i] = buf[j];
    }_last--;
    return aux;
  }

}

template <class T, unsigned N>
bool RingArray<T, N>::isFull() const {
  // TODO: implement this method.
  return ((_last + 1) % N == _first);
}

template <class T, unsigned N>
bool RingArray<T, N>::isEmpty() const {
  // TODO: implement this method.
   return (_first==_last);
}

template <class T>
void test_add_then_get() {
  RingArray<T, 8> r;
  T value;
  while (std::cin >> value) {
    r.add(value);
  }
  while (!r.isEmpty()) {
    std::cout << r.get() << std::endl;
  }
}

template <class T>
void test_add_or_get() {
  RingArray<T, 8> r;
  T value;
  char c;
  while (std::cin >> c) {
    if (c == '+') {
      std::cin >> value;
      r.add(value);
    } else if (c == '-') {
      std::cout << r.get() << std::endl;
    } else {
      std::cout << "Invalid operation\n";
    }
  }
}

int main () {
  char data;
  while (std::cin >> data) {
    switch (data) {
      case 'd': test_add_then_get<double>();
                break;
      case 's': test_add_then_get<std::string>();
                break;
      case 'D': test_add_or_get<double>();
                break;
      case 'S': test_add_or_get<std::string>();
                break;
      default: std::cout << "Invalid type\n";
    }
  }
  return 0;
}