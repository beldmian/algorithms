#include "graph.h"
#include "stdio.h"

MatrixGraph *make_matrix_graph(size_t verts_count) {
  MatrixGraph *graph = malloc(sizeof(MatrixGraph));
  graph->verts_count = verts_count;
  graph->edges_matrix = calloc(verts_count, sizeof(MATRIX_GRAPH_EDGE_TYPE **));
  for (int i = 0; i < verts_count; i++) {
    graph->edges_matrix[i] =
        calloc(verts_count, sizeof(MATRIX_GRAPH_EDGE_TYPE));
  }
  return graph;
}

void free_matrix_graph(MatrixGraph *graph) {
  for (int i = 0; i < graph->verts_count; i++) {
    free(graph->edges_matrix[i]);
  }
  free(graph->edges_matrix);
  free(graph);
};

void matrix_graph_set_edge(MatrixGraph *graph, size_t from, size_t to,
                           MATRIX_GRAPH_EDGE_TYPE edge) {
  graph->edges_matrix[from][to] = edge;
}

void dfs_loop(MatrixGraph *graph, GraphVisitor *visitor, size_t start,
              size_t *visited) {
  visited[start] = 1;
  if (graph->edges_matrix[start] == NULL) {
    return;
  }
  for (size_t i = 0; i < graph->verts_count; i++) {
    if ((graph->edges_matrix[start][i] != 0) && (visited[i] == 0)) {
      visitor->visit(graph, start, i);
      dfs_loop(graph, visitor, i, visited);
    }
  }
}

void dfs(MatrixGraph *graph, GraphVisitor *visitor, size_t start) {
  size_t *visited = calloc(graph->verts_count, sizeof(size_t));
  for (int i = 0; i < graph->verts_count; i++) {
    visited[i] = 0;
  }
  dfs_loop(graph, visitor, start, visited);
  free(visited);
}

void dfs_print(MatrixGraph *graph, size_t from, size_t to) {
  printf("Visiting: %lu->%lu\n", from, to);
}

void free_graph_visitor(GraphVisitor *visitor) { free(visitor); }

GraphVisitor *make_print_visitor() {
  GraphVisitor *visitor = malloc(sizeof(GraphVisitor));
  visitor->visit = (void (*)(MatrixGraph *, size_t, size_t))dfs_print;
  return visitor;
}
