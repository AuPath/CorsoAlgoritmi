#ifndef graph_H
#define graph_H

#include "my_list.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <list>
#include <type_traits>

template <typename T> class my_graph {

private:
  my_list<my_list<T>> _adj_list;
  unsigned int _size;

public:
  my_graph() : _adj_list(), _size(0) {}

  my_graph(const my_graph& other) : _adj_list(), _size(0) {
    
  }

  my_graph<T>& operator=(const my_graph<T>& rhs){
    if(this != &rhs)
      {
	my_graph<T> tmp(rhs);
	std::swap(_adj_list, tmp._adj_list);
	std::swap(_size, tmp._size);
      }
    return *this;    
  }

  ~my_graph() { clear(); }

  unsigned int size() const{
    return _size;
  }

  void add(const my_list<T>& li){
    _adj_list.add(li);
    ++_size;    
  }

  void clear()
  {
    _adj_list.clear();
  }

  friend std::ostream& operator<<(std::ostream& os, const my_graph<T>& g)
  {
    typename my_list<my_list<T>>::const_iterator i,ie;
    i = g._adj_list.begin();
    ie = g._adj_list.end();
    unsigned int cont = 1;
    while(i != ie)
      {
	if(cont != g._size)
	  os << *i << std::endl;
	else
	  os << *i;
	++i;
	++cont;	
      }
    
    return os;
  }
  
};


    

#endif
  
