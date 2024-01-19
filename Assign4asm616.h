#include <vector>
#include <cassert>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
using std::vector;
using std::queue;
using std::set;
using std::map;
using std::priority_queue;

class Board 
{
  const vector<int> dx = {0, 1, 0, -1};
  const vector<int> dy = {1, 0, -1, 0};

public:

  vector<vector<int>> board;

  Board();
  Board(vector<vector<int>> other);

  pair<int, int> get_free_tile();
  vector<Board> getNeigbors();
  vector<Board> solve(Board initial, Board goal);
  vector<Board> bfs(Board initial, Board final);
 

  friend ostream& operator << (ostream& out, const Board& b);
  friend istream& operator >> (istream& in, Board &b);
  friend bool operator ==(Board b, Board other);
  void operator =(const Board &other) 
  {
    for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j) {
        board[i][j] = other.board[i][j];
      }
    }
  }

};

void get_input(Board &initial, Board &goal);

