#ifndef graph_H
#define graph_H

#include "my_list.h"
#include "vertex.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <list>
#include <type_traits>

template <typename T> class my_graph {

private:
  my_list<vertex<T>> _vertices;
  unsigned int _size;

public:
  my_graph() : _size(0) {}
  ~my_graph() { _vertices.clear(); }
  my_graph(const my_graph<T>& other) : _vertices(other._vertices), _size(other._size) {}

  my_graph(const my_list<vertex<T>>& vertices) : _vertices(vertices), _size(vertices.size()) {}

  my_graph<T>& operator=(const my_graph<T>& rhs){
    if(this != &rhs)
      {
	my_graph<T> tmp(rhs);
	std::swap(_vertices,tmp._vertices);
	std::swap(_size,tmp._size);
      }
    return *this;
  }

  unsigned int size() const{
    return _size;
  }

  friend std::ostream& operator<<(std::ostream& os, const my_graph<T>& g)
  {
    os << g._vertices;
    return os;
  }
  
};




    

#endif
  
