#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <graph.h>

using namespace std;

int main(){

    char map[ROWS][COLUMNS] = {{'.', '.', '.', '.', '.', '.', '.'},
                               {'_', '_', '_', '_', '_', '.','.',},
                               {'.', '.', '.','.', '|', '.', '.'},
                               {'.', '.', '.', '_', '.', '.', '.'},
                               {'.', '.', '.', '.', '.', '.', '.'},
                               {'.', '.', '.', '_', '.', '.', '.'},
                               {'.', '.', '.', '.','|', '.', '.'},
                               {'_', '_', '_', '_', '_', '.','.'},
                               {'.', '.', '.', '.', '.', '.', '.'},
                            };
    Graph graph;
    

    struct point start;
    start.row = ROWS-1;
    start.column = COLUMNS-1;

    struct point end;
    end.row = 2;
    end.column = 3;


    std::vector<std::pair<int, int>> temp = graph.hasNeighboar(start, map);

    std::cout << "shortest path -> " << graph.BFS(start, end, map);

}
