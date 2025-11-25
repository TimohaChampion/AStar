
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <windows.h>
#include <tuple>

using namespace std;

// Функция вычисляет эвристическое расстояние (манхэттенское)
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Функция ищет ближайшую незанятую область для трактора
pair<int, int> findNearestUnseeded(const vector<vector<int>>& field, int agentSize, int current_x, int current_y) {
    int min_dist = INT_MAX;
    pair<int, int> nearest_unseeded = { -1,-1 };

    // Ищем позицию для верхнего левого угла трактора
    for (int i = 0; i <= (int)field.size() - agentSize; ++i) {
        for (int j = 0; j <= (int)field[0].size() - agentSize; ++j) {
            bool canPlace = true;
            //Проверяем каждую ячейку, которую займет трактор
            for (int x = i; x < i + agentSize; ++x) {
                for (int y = j; y < j + agentSize; ++y) {
                    if (field[x][y] != 0) {
                        canPlace = false;
                        break;
                    }
                }
                if (!canPlace) break;
            }

            if (canPlace) {
                int dist = heuristic(current_x, current_y, i, j);
                if (dist < min_dist) {
                    min_dist = dist;
                    nearest_unseeded = { i,j };
                }
            }
        }
    }
    return nearest_unseeded;
}

// Функция A* для поиска пути
vector<pair<int, int>> aStar(vector<vector<int>>& field, int startX, int startY, int targetX, int targetY, int agentSize) {
    vector<vector<bool>> visited(field.size(), vector<bool>(field[0].size(), false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push(make_tuple(0, startX, startY));

    vector<pair<int, int>> path;
    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    while (!pq.empty()) {
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if (x == targetX && y == targetY) {
            path.push_back({ x, y });
            return path;
        }

        if (visited[x][y]) continue;
        visited[x][y] = true;


        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            bool canMove = true;

            for (int a = nx; a < nx + agentSize; ++a) {
                for (int b = ny; b < ny + agentSize; ++b) {
                    if (!(a >= 0 && a < field.size() && b >= 0 && b < field[0].size() && field[a][b] != -1)) {
                        canMove = false;
                        break;
                    }
                }
                if (!canMove) break;
            }

            if (canMove) {
                int new_f = heuristic(nx, ny, targetX, targetY);
                pq.push(make_tuple(new_f, nx, ny));
            }
        }
    }

    return {};
}

// Основная функция для управления трактором
void startWork(vector<vector<int>>& field, int agentSize) {
    int startX = 0, startY = 0; //Начальная позиция

    while (true) { //Пока есть что "засеивать"
        pair<int, int> target = findNearestUnseeded(field, agentSize, startX, startY);
        int targetX = target.first;
        int targetY = target.second;

        if (targetX == -1) break; // Если нет больше пустых мест

        vector<pair<int, int>> path = aStar(field, startX, startY, targetX, targetY, agentSize);

        if (path.empty()) break;

        for (auto& node : path) {
            //Заполняем поле
            for (int i = node.first; i < node.first + agentSize; ++i) {
                for (int j = node.second; j < node.second + agentSize; ++j) {
                    field[i][j] = 1;
                }
            }
            startX = node.first;
            startY = node.second;

            for (const auto& row : field) { //Вывод в консоль
                for (int cell : row) {
                    cout << cell << "\t";
                }
                cout << endl;
            }
            Sleep(3000);
            system("cls");
        }
    }

    cout << endl;
    for (const auto& row : field) {
        for (int cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> field = {
              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };
    int agentSize = 2; // Размер трактора
    startWork(field, agentSize);
    return 0;
}
