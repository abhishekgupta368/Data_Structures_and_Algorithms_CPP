// github.com/andy489

// https://www.hackerrank.com/challenges/the-quickest-way-up/problem

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define TABLE_SIZE 101
#define FIN 100
#define DICE 6

void createEmptyTable(vvi &table) {
    int i, j;
    for (i = 1; i < TABLE_SIZE; ++i)
        for (j = 1; j <= DICE; ++j)
            if (i + j < TABLE_SIZE)
                table[i].push_back(i + j);
}

void readLadders(vvi &table) {
    int ladders, i, j, ls, le;
    cin >> ladders;
    for (i = 0; i < ladders; ++i) {
        cin >> ls >> le; // ladder start, ladder end
        table[ls].clear();

        for (j = DICE; j >= 1; --j)
            if (ls - j > 0)
                table[ls - j].push_back(le);
    }
}

void readSnakes(vvi &table) {
    int snakes, i, j, head, tail;
    cin >> snakes;
    for (i = 0; i < snakes; ++i) {
        cin >> head >> tail;
        table[head].clear();
        for (j = DICE; j >= 1; --j)
            if (head - j > 0)
                table[head - j].push_back(tail);
    }
}

struct Graph {
    const vvi &adj;

    Graph(const vvi &adj) : adj(adj) {}

    int bfs(int start) {
        int level(0);
        queue<int> Q;
        vector<bool> visited(TABLE_SIZE);
        Q.push(start);
        visited[start] = true;

        int SIZE = Q.size();

        while (!Q.empty()) {
            while (SIZE--) {
                int curr = Q.front();
                Q.pop();

                for (const int &child:adj[curr]) {
                    if (!visited[child]) {
                        if (child == FIN)
                            return level + 1;
                        visited[child] = true;
                        Q.push(child);
                    }
                }
            }
            SIZE = Q.size();
            ++level;
        }
        return -1;
    }
};

int main() {
    int tests;
    cin >> tests;

    ostringstream ostr;

    while (tests--) {
        vvi table(TABLE_SIZE);
        createEmptyTable(table);
        readLadders(table);
        readSnakes(table);
        Graph G(table);
        ostr << G.bfs(1) << '\n';
    }
    return cout << ostr.str(), 0;
}
