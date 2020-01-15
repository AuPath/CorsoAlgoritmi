#ifndef vertex_H
#define vertex_H


#include "my_list.h"
#include <iostream>
#include <type_traits>
template <typename T> class vertex {

private:
  T _value;
  my_list<vertex<T>> _adj_list;

public:
  vertex() {}

  ~vertex() { _adj_list.clear(); }

  vertex(const vertex<T>& other) : _value(other._value), _adj_list(other._adj_list) {}

  explicit vertex(const T& value) : _value(value) {}

  vertex(const T& value, const my_list<vertex<T>>& adj) : _value(value), _adj_list(adj) {}

  vertex<T>& operator=(const vertex<T>& rhs){
    if(this != &rhs)
      {
	vertex<T> tmp(rhs);
	std::swap(_value,tmp._value);
	std::swap(_adj_list,tmp._adj_list);
      }
    return *this;
  }

  const T& value() const {
    return _value;
  }

  const my_list<vertex<T>>& adj_list() const{
    return _adj_list;
  }

  void set_value(const T& value)
  {
    _value = value;
  }

  void set_adj_list(const my_list<vertex<T>>& adj)
  {
    _adj_list = adj;
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const vertex<T>& v)
{
  
  
  if(v.adj_list().size() == 0)
    os << v.value();
  else 
    os << v.value() << " --> " << v.adj_list();      
    
  return os;
}

#endif
