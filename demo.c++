#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cstdlib>

using namespace std;

#define INDEX_ROW 0
#define INDEX_COLUMN 1

#define ROWS 9
#define COLUMNS 7

struct point {
    int row;
    int column;
};

struct _map {
    _map* next;
    int size_src;
    int x, y;
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

Graph::Graph(){}
Graph::Graph(char map[ROWS][COLUMNS]){};

void print(struct _map **head);

int push(std::pair<int, int> item, struct _map** head, int&& size, int& sizeArray);

int remove(int index, struct _map** head, int& sizeArray);

std::pair<int, int> getFirst(struct _map** head, int& sizeArray);

std::vector<std::pair<int, int>> hasNeighboar(struct point item, char map[ROWS][COLUMNS]);

bool hasVisited(std::pair<int, int> item, std::vector<std::pair<int, int>> array);

int BFS(struct point start, struct point end, char map[ROWS][COLUMNS]);


int main()
{
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

    cout << graph.BFS(start, end, map);

}

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

std::pair<int, int> getFirst(struct _map** head, int& sizeArray){

    if((*head) == NULL) exit(1);

    int index = 0;

    std::pair<int, int> item;

    item.first = (*head)->x;
    item.second = (*head)->y;

    remove(index, head, sizeArray);

    return item;

}
int remove(int index, struct _map** head, int& sizeArray){

    struct _map* node = (_map*)malloc(sizeof(_map));

    if(index == 0 && (*head) != NULL){
        node = (*head)->next;
        (*head) = node;
        sizeArray--;
        return 1;
    }

    struct _map* prec = (*head);
    struct _map* succ = (*head)->next;
    struct _map* temp = (*head);
    int count = 0;

    while(temp != NULL){
		if(index == count){
			prec->next = temp->next;
			return 0;
		}
		prec = temp;
		temp = temp->next;
        count++;
	}

    sizeArray--;

    return 1;


}

void print(struct _map **head)
{
	
	struct _map *n = (*head);
	
	while(n != NULL){
		std::cout << n->x << " " << n->y << "\n";
		n = n->next;
	}
	
}


int push(std::pair<int, int> item, struct _map** head, int&& size, int& sizeArray){

    struct _map* node = (_map*)malloc(sizeof(_map));

    node->x = item.first;
    node->y = item.second;
    node->size_src = size;
    node->next = NULL;
   
	
    if((*head) == NULL){
        (*head) = node;
        sizeArray++;
        return 1;
    } 

    struct _map* current = (*head);

    while(current->next != NULL){
        current = current->next;
    }

    current->next = node;
    sizeArray++;

}