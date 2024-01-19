#include <iostream>
#include <vector>
#include <algorithm>

#include "Assign4asm616.h"

using namespace std;

vector<Board> bfs(Board initial, Board final) {
    queue<pair<Board, vector<Board>>> q;
    q.emplace(initial, vector<Board>({initial}));

    while (!q.empty()) {
    auto curr = q.front();
     q.pop();

    if (curr.first == final) {
    return curr.second;
    }

    for (Board n : curr.first.getNeigbors()) {
    if (find(curr.second.begin(), curr.second.end(), n) == curr.second.end()) {
     vector<Board> newPath = curr.second;
     newPath.push_back(n);
     q.emplace(n, newPath);
            }
        }
    }

  return vector<Board>();
}

vector<Board> solve(Board initial, Board final) 
{
    return bfs(initial,final);
}

void get_input(Board &initial, Board &goal) {
    cout << "Enter initial Series Of Path\n";
    cin >> initial;
    cout << "Enter goal Series Of Path\n";
    cin >> goal;
}

void print_solution(const vector<Board>& result) {
    if (result.empty()) {
        cout << "Not able to find Solution" << endl;
    } else {
        int sz = static_cast<int>(result.size());
        for (int i = 0; i < sz; ++i) {
            std::cout << result[i];
            if (i != sz - 1) {
                cout << "\n forthcoming state:\n";
            }
        }
        cout << endl;
    }
}


int main() {
    const vector<vector<int>> default_final = {
        {1, 2, 3},
        {8, 0, 4},
        {7, 6, 5}};

    const vector<vector<int>> default_start = {
        {1, 2, 3},
        {4, 6, 0},
        {7, 5, 8}};

    Board initial(default_start);
    Board goal(default_final);

    get_input(initial, goal);
    vector<Board> result;

    char option = ' ';
    cout << "Choose the method: \n Select a Alphabet from the two options\n"<< "B for breath First Search \n D for depth First Search \n and H for heuristics (not implemented)\n";
    cin >> option;

    switch (option) {
        case 'B':
            cout << "Found solution\n";
            result = bfs(initial, goal);
            cout << "Found solution\n";
            print_solution(result);
            break;

        case 'D':
            cout << "Not implemented\n";
            return -2;

        case 'H':
            cout << "Not implemented\n";
            return -3;

        default:
            break;
    }

    return -1;
}
