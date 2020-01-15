#ifndef myList_H
#define myList_H

#include <cstddef>
#include <iostream>
#include <iterator>
#include <ostream>
#include <type_traits>

// T type of value, E defines equality
template <typename T> class my_list {
  struct node{
    T value;
    node* next;

    node() : next(nullptr) {}
    // ~node() { next = nullptr; }
    explicit node(const node& other) : value(other.value), next(nullptr) {}
    node(const T& v, node* n) : value(v), next(n) {}
    explicit node(const T& v) : value(v), next(nullptr) {}
  };
  
private:
  node* _head;
  node* _tail;
  unsigned int _size;
  
public:
  my_list() : _head(nullptr), _tail(nullptr), _size(0) {}

  explicit my_list(const T& value) : _head(nullptr), _size(0){
    _head = new node(value);
    _tail = _head;
    ++_size;
  }

  my_list(const my_list& other) : _head(nullptr), _tail(nullptr), _size(0) {
    node* curr = other._head;

    while(curr != nullptr)
      {
	add(curr->value);
	curr = curr->next;
      }
  }

  ~my_list() { clear(); }
  
  my_list& operator=(const my_list& rhs)  {
    if(this != &rhs)
      {
	my_list tmp(rhs);
	std::swap(_head,tmp._head);
	std::swap(_tail,tmp._tail);
	std::swap(_size,tmp._size);
      }
    return *this;
  }

  unsigned int size() const{
    return _size;
  }

  void add(const T& value)  {
    node* tmp = new node(value);

    if(_head == nullptr)
      {
	_head = tmp;
	_tail = tmp;
      }
      
    else {
      _tail->next = tmp;
      _tail = tmp;
	}

    ++_size;
  }

  void clear() {
    node* curr = _head;
    node* tmp = nullptr;

    while(curr != nullptr)
      {
	tmp = curr->next;
	delete curr;
	curr = tmp;
      }

    _head = nullptr;
    _tail = nullptr;
    _size = 0;
  }

  
  class const_iterator{
    const node* _n;

    // traits
  public:
    typedef std::forward_iterator_tag iterator_category;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef const T* pointer;
    typedef const T& reference;

    const_iterator() : _n(nullptr) {}
    const_iterator(const const_iterator& other) : _n(other._n) {}
    const_iterator& operator=(const const_iterator& rhs){
      _n = rhs._n;
      return *this;
    }
    ~const_iterator() {};

    reference operator*() const {
      return _n->value;
    }

    const_iterator operator++(int) {
      const_iterator tmp(*this);
      _n = _n->next;
      return tmp;
    }

    const_iterator& operator++()
    {
      _n = _n->next;
      return *this;
    }

    bool operator==(const const_iterator& other){
      return (_n == other._n);
    }

    bool operator!=(const const_iterator& other){
      return (_n != other._n);
    }

    private:
    friend class my_list;
    explicit const_iterator(const node* n) : _n(n) {}
    
  };

  const_iterator begin() const {
    return const_iterator(_head);
  }

  const_iterator end() const{
    return const_iterator(nullptr);
  }

};

template <typename T>
std::ostream& operator<<(std::ostream &os, const my_list<T>& list) {

  typename my_list<T>::const_iterator i,ie;
  i = list.begin();
  ie = list.end();

  while(i != ie)
    {
      os << *i << " ";
      ++i;
    }
  return os;
}

#endif
