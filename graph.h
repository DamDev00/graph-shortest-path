#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cstdlib>

#define INDEX_ROW 0
#define INDEX_COLUMN 1

#define ROWS 9
#define COLUMNS 7

struct point {
    int row;
    int column;
};

class Graph {

    private:
        
    public:
        Graph(char map[ROWS][COLUMNS]);
        Graph();

        int BFS(struct point start, struct point end, char map[ROWS][COLUMNS]);

        bool hasVisited(std::pair<int, int> item, std::vector<std::pair<int, int>> array);

        std::vector<std::pair<int, int>> hasNeighboar(struct point item, char map[ROWS][COLUMNS]);

};
