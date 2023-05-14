#include <graph.h>
#include <linkedList.h>


Graph::Graph(){}
Graph::Graph(char map[ROWS][COLUMNS]){};


int Graph::BFS(struct point start, struct point end, char map[ROWS][COLUMNS]){

    std::vector<std::pair<int, struct _map*>> array;
    std::vector<std::pair<int, int>> visited;
    int size = 0;

    struct _map* arrayIndex = NULL;
    int sizeArrayIndex = 0;
    std::pair<int, int> initializer;
    
    initializer.first = start.row;
    initializer.second = start.column;

    push(initializer, &arrayIndex, 0, sizeArrayIndex);
    
    while(sizeArrayIndex > 0){

        int tmp_size = arrayIndex->size_src;
        std::pair<int, int> tmp = getFirst(&arrayIndex, sizeArrayIndex);
        visited.push_back(std::make_pair(tmp.first, tmp.second));

        if((tmp.first == end.row) && (tmp.second == end.column)){
            delete[] arrayIndex;
            return tmp_size;
            break; 
        }

        struct point tmp_point;

        tmp_point.row = tmp.first;
        tmp_point.column = tmp.second;

        std::vector<std::pair<int, int>> neighboars = hasNeighboar(tmp_point, map);

        for(auto& neighboar : neighboars){
            if(!hasVisited(neighboar, visited)){
                push(neighboar, &arrayIndex, tmp_size + 1, sizeArrayIndex);
            }
        }

    }

    delete[] arrayIndex;

    return -1;

}

std::vector<std::pair<int, int>> Graph::hasNeighboar(struct point item, char map[ROWS][COLUMNS]){

    std::vector<std::pair<int, int>> index;

    if((item.column >= COLUMNS || !(item.column >= 0)) || (item.row >= ROWS) || !(item.row >= 0)) 
        exit(1);

    //right
    if((item.column + 1 >= 0) && (item.column + 1 < COLUMNS)){
        if(map[item.row][item.column + 1] == '.'){
            index.push_back(std::make_pair(item.row, item.column + 1));
        }
    }

    //left
    if((item.column - 1 >= 0) && (item.column - 1 < COLUMNS)){
        if(map[item.row][item.column - 1] == '.'){
            index.push_back(std::make_pair(item.row, item.column - 1));
        }
    }

    //top
    if((item.row - 1 >= 0) && (item.row - 1 < ROWS)){
        if(map[item.row - 1][item.column] == '.'){
            index.push_back(std::make_pair(item.row - 1, item.column));
        }
    }

    //low
    if((item.row + 1 >= 0) && (item.row + 1 < ROWS)){
        if(map[item.row + 1][item.column] == '.'){
            index.push_back(std::make_pair(item.row + 1, item.column));
        }
    }

    //low-right
    if((item.row + 1 >= 0) && (item.row + 1 < ROWS) && (item.column + 1 >= 0) && (item.column + 1 < COLUMNS)){
        if(map[item.row + 1][item.column + 1] == '.'){
            index.push_back(std::make_pair(item.row + 1, item.column + 1));
        }
    }

    //low-left
    if((item.row + 1 >= 0) && (item.row + 1 < ROWS) && (item.column - 1 >= 0) && (item.column - 1 < COLUMNS)){
        if(map[item.row + 1][item.column - 1] == '.'){
            index.push_back(std::make_pair(item.row + 1, item.column - 1));
        }
    }

    //top-left
    if((item.row - 1 >= 0) && (item.row - 1 < ROWS) && (item.column - 1 >= 0) && (item.column - 1 < COLUMNS)){
        if(map[item.row - 1][item.column - 1] == '.'){
            index.push_back(std::make_pair(item.row - 1, item.column - 1));
        }
    }

    //top-right
    if((item.row - 1 >= 0) && (item.row - 1 < ROWS) && (item.column + 1 >= 0) && (item.column + 1 < COLUMNS)){
        if(map[item.row - 1][item.column + 1] == '.'){
            index.push_back(std::make_pair(item.row - 1, item.column + 1));
        }
    }

    return index;

}

bool Graph::hasVisited(std::pair<int, int> item, std::vector<std::pair<int, int>> array){

    bool flag = false;

    if(array.size() == 0) return false;

    for(auto const& value : array){
        if((value.first == item.first) && (value.second == item.second)){
            flag = true;
            break;
        }
    }

    return flag;

}
