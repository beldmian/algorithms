#pragma once

#include "stdlib.h"

#define MATRIX_GRAPH_EDGE_TYPE unsigned long

typedef struct MatrixGraph {
  size_t verts_count;
  MATRIX_GRAPH_EDGE_TYPE **edges_matrix;
} MatrixGraph;

MatrixGraph *make_matrix_graph(size_t verts_count);
void free_matrix_graph(MatrixGraph *graph);

void matrix_graph_set_edge(MatrixGraph *graph, size_t from, size_t to,
                           MATRIX_GRAPH_EDGE_TYPE edge);

typedef struct GraphVisitor {
  void (*visit)(MatrixGraph *, size_t, size_t);
} GraphVisitor;
void free_graph_visitor(GraphVisitor *visitor);

void dfs(MatrixGraph *, GraphVisitor *, size_t);

GraphVisitor *make_print_visitor();
