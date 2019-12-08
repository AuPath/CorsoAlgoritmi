#include <iostream>
#include "corsoAlgoritmi.h"
#include "eserciziCorsoAlgoritmi.h"
#include "graph.h"
#include "vertex.h"
#include "my_list.h"
#include <iostream>
#include <list>
#include <string>

int main()
{
  my_list<int> li;
  li.add(1);
  li.add(2);

  vertex<int> v1(1),v2(2),v3(3);
  my_list<vertex<int>> v_adj;
  v_adj.add(v2);
  v_adj.add(v3);
  vertex<int> v4(4);
  v4.set_adj_list(v_adj);

  my_list<vertex<int>> g_vertices;
  g_vertices.add(v1);
  g_vertices.add(v2);
  g_vertices.add(v3);
  g_vertices.add(v4);
  
  my_graph<int> g(g_vertices);
  

  std::cout << g;

  return 0;
}

