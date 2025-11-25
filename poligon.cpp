//#include <iostream>
//#include <queue>
//#include <vector>
//#include <cmath>
//#include <climits>
//#include <iomanip>
//
//using namespace std;
//
//// Структура для узла в алгоритме A*
//struct Node {
//    int x, y;
//    double g, f;  // g - стоимость от старта, f = g + h
//    pair<int, int> parent;
//
//    bool operator>(const Node& other) const {
//        return f > other.f;
//    }
//};
//
//// Эвристика - манхэттенское расстояние (подходит для сетки)
//double heuristic(int x, int y, int goalX, int goalY) {
//    return abs(x - goalX) + abs(y - goalY);
//}
//
//// Проверка границ поля
//bool isValid(int x, int y, int rows, int cols) {
//    return x >= 0 && x < rows && y >= 0 && y < cols;
//}
//
//// A* алгоритм для оптимального пути засеивания
//vector<pair<int, int>> aStar(vector<vector<int>>& field, int startX, int startY, int goalX, int goalY) {
//    int rows = field.size();
//    int cols = field[0].size();
//
//    // Массивы для отслеживания стоимости и родителей
//    vector<vector<double>> gCost(rows, vector<double>(cols, INFINITY));
//    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, { -1, -1 }));
//    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
//
//    // Приоритетная очередь для A*
//    priority_queue<Node, vector<Node>, greater<Node>> openSet;
//
//    // Начальная позиция
//    gCost[startX][startY] = 0;
//    double h = heuristic(startX, startY, goalX, goalY);
//    openSet.push({ startX, startY, 0, h, {-1, -1} });
//
//    int dx[] = { -1, 0, 1, 0 };  // Соседние клетки: вверх, вправо, вниз, влево
//    int dy[] = { 0, 1, 0, -1 };
//
//    while (!openSet.empty()) {
//        Node current = openSet.top();
//        openSet.pop();
//
//        int x = current.x, y = current.y;
//
//        if (visited[x][y]) continue;
//        visited[x][y] = true;
//
//        // Цель достигнута
//        if (x == goalX && y == goalY) {
//            // Восстанавливаем путь
//            vector<pair<int, int>> path;
//            pair<int, int> pos = { x, y };
//            while (pos.first != -1) {
//                path.push_back(pos);
//                pos = parent[pos.first][pos.second];
//            }
//            reverse(path.begin(), path.end());
//            return path;
//        }
//
//        // Проверяем соседние клетки
//        for (int i = 0; i < 4; i++) {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//
//            if (isValid(nx, ny, rows, cols) && field[nx][ny] != -1 && !visited[nx][ny]) {
//                double moveCost = 1.0;  // Стоимость перемещения
//
//                if (gCost[nx][ny] > gCost[x][y] + moveCost) {
//                    gCost[nx][ny] = gCost[x][y] + moveCost;
//                    parent[nx][ny] = { x, y };
//
//                    double h = heuristic(nx, ny, goalX, goalY);
//                    openSet.push({ nx, ny, gCost[nx][ny], gCost[nx][ny] + h, {x, y} });
//                }
//            }
//        }
//    }
//
//    return {};  // Путь не найден
//}
//
//int main() {
//    setlocale(0, "ru");
//    // Создаем произвольное поле 8x8
//    // 0 - нужно засеять, 1 - засеяно, -1 - препятствие
//    vector<vector<int>> field = {
//        {0, 0, 0, -1, 0, 0, 0, 0},
//        {0, 1, 0, 0, 0, -1, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0},
//        {-1, 0, 0, 0, -1, 0, 0, 0},
//        {0, 0, -1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0},
//        {0, -1, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0}
//    };
//
//    int startX = 0, startY = 0;  // Начальная точка
//    int goalX = 0, goalY = 7;    // Конечная точка
//
//    cout << "Поле до засеивания:" << endl;
//    for (const auto& row : field) {
//        for (int cell : row) {
//            if (cell == -1) cout << " - ";
//            else if (cell == 1) cout << " + ";
//            else cout << " . ";
//        }
//        cout << endl;
//    }
//
//    // Находим оптимальный путь
//    vector<pair<int, int>> path = aStar(field, startX, startY, goalX, goalY);
//
//    if (!path.empty()) {
//        cout << "\nОптимальный путь засеивания (траектория трактора):" << endl;
//        for (size_t i = 0; i < path.size(); i++) {
//            int x = path[i].first, y = path[i].second;
//            field[x][y] = 1;  // Помечаем как засеянное
//            cout << "Шаг " << i << ": (" << x << ", " << y << ")" << endl;
//        }
//
//        cout << "\nПоле после засеивания:" << endl;
//        for (const auto& row : field) {
//            for (int cell : row) {
//                if (cell == -1) cout << " - ";
//                else if (cell == 1) cout << " + ";
//                else cout << " 0 ";
//            }
//            cout << endl;
//        }
//
//        cout << "Общая стоимость пути: " << path.size() - 1 << " шагов" << endl;
//    }
//    else {
//        cout << "Оптимальный путь не найден!" << endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <queue>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//int counter = 0; // количество повторений
//
//// Структура для состояния трактора
//struct State {
//    int x, y;  // Координаты
//    double cost; // Стоимость (пройденное расстояние)
//    vector<pair<int, int>> path; // Путь
//
//    // Оператор сравнения для priority_queue (минимальная стоимость)
//    bool operator>(const State& other) const {
//        return cost > other.cost;
//    }
//};
//
//// Проверяем, что координаты в пределах поля
//bool isValid(int x, int y, int rows, int cols) {
//    return x >= 0 && x < rows && y >= 0 && y < cols;
//}
//
//// Алгоритм A* для полного засеивания поля
//vector<pair<int, int>> aStarFullField(vector<vector<int>>& field, int startX, int startY) {
//    int rows = field.size();
//    int cols = field[0].size();
//    vector<pair<int, int>> path; // Итоговый путь
//
//    // Начинаем с начальной позиции
//    priority_queue<State, vector<State>, greater<State>> pq;
//    pq.push({ startX, startY, 0, {{startX, startY}} });
//
//    while (!pq.empty()) {
//        State current = pq.top();
//        pq.pop();
//
//        int x = current.x, y = current.y;
//       
//        // Если клетка ещё не засеяна
//        if (field[x][y] == 0) {
//            field[x][y] = 1;     // Засеиваем клетку
//            path.insert(path.end(), current.path.begin(), current.path.end()); // Добавляем путь к общему маршруту
//        }
//        
//        // Проверяем, всё ли поле засеяно
//        bool allSeeded = true;
//        for (const auto& row : field) {
//            for (int cell : row) {
//                if (cell == 0) {
//                    allSeeded = false;
//                    break;
//                }
//            }
//            if (!allSeeded) break;
//        }
//        if (allSeeded) break;  // Если всё поле засеяно, выходим
//
//        int dx[] = { 0, 0, 1, -1 }; // Возможные перемещения
//        int dy[] = { 1, -1, 0, 0 };
//
//        for (int i = 0; i < 4; ++i) {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//
//            // Проверяем, что клетка в пределах поля и не является препятствием
//            if (isValid(nx, ny, rows, cols) && field[nx][ny] != -1) {
//                double newCost = current.cost + 1; // Стоимость перемещения 1
//                vector<pair<int, int>> newPath = current.path;
//                newPath.push_back({ nx, ny });
//                pq.push({ nx, ny, newCost, newPath });
//            }
//
//        }
//    }
//
//    return path;
//}
//
//int main() {
//    setlocale(0, "ru");
//    // Пример поля (0 - не засеяно, 1 - засеяно, -1 - препятствие)
//    /*vector<vector<int>> field = {
//        {0, 0, 0, -1, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, -1, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0},
//        {-1, 0, 0, 0, -1, 0, 0, 0},
//        {0, 0, -1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0},
//        {0, -1, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0}
//    };*/
//    vector<vector<int>> field = {
//        {0, 0, 0, -1},
//        {0, 0, 0, 0},
//        {0, 0, 0, 0},
//        {-1, 0, 0, 0},
//
//    };
//
//    int startX = 0, startY = 0;  // Начальная позиция трактора
//
//    vector<pair<int, int>> path = aStarFullField(field, startX, startY);
//
//    cout << "Путь трактора (порядок засеивания): " << endl;
//    for (auto const& p : path) {
//        cout << "(" << p.first << ", " << p.second << ") ";
//    }
//    cout << endl;
//    cout << endl;
//    for (auto const& f : field) {
//        for (int cell : f) {
//            if (cell == 1)cout << " 1 ";
//            else if (cell == -1) cout << " -1 ";
//            else cout << " 0 ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    return 0;
//}














//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cmath>
//
//using namespace std;
//
//// Структура для представления узла в A*
//struct Node {
//    int x, y;
//    int g, h, f; // g - стоимость пути от старта, h - эвристика, f = g + h
//    Node* parent;
//
//    Node(int x, int y) : x(x), y(y), g(0), h(0), f(0), parent(nullptr) {}
//};
//
//// Функция для вычисления манхэттенского расстояния (эвристика)
//int heuristic(int x1, int y1, int x2, int y2) {
//    return abs(x1 - x2) + abs(y1 - y2);
//}
//
//// Функция для поиска незасеянных участков. Возвращает координаты ближайшего незасеянного участка.
//pair<int, int> findNearestUnseeded(const vector<vector<int>>& field, int current_x, int current_y) {
//    int min_dist = INT_MAX;
//    pair<int, int> nearest_unseeded = { -1,-1 };
//    for (int i = 0; i < field.size(); i++) {
//        for (int j = 0; j < field[0].size(); j++) {
//            if (field[i][j] == 0) {
//                int dist = heuristic(current_x, current_y, i, j);
//                if (dist < min_dist) {
//                    min_dist = dist;
//                    nearest_unseeded = { i,j };
//                }
//            }
//        }
//    }
//    return nearest_unseeded;
//}
//
//// Функция A* для поиска пути
//vector<pair<int, int>> aStar(vector<vector<int>>& field, int startX, int startY, int targetX, int targetY) {
//    // (Опущено для краткости, требует знания реализации A*)
//    //  Реализация A* для поиска пути от startX, startY до targetX, targetY.
//    return {};  // Возвращает путь в виде вектора координат (x, y).
//}
//
//
//int main() {
//    // Пример поля
//    vector<vector<int>> field = {
//                {0, -1, 0, -1, 0, 0, 0, 0},
//                {-1, 0, 0, 0, 0, -1, 0, 0},
//                {0, 0, 0, 0, 0, 0, 0, 0},
//                {-1, 0, 0, 0, -1, 0, 0, 0},
//                {0, 0, -1, 0, 0, 0, 0, 0},
//                {0, 0, 0, 0, 0, 0, 0, 0},
//                {0, -1, 0, 0, 0, 0, 0, 0},
//                {0, 0, 0, 0, 0, 0, 0, 0}
//    };
//
//    int startX = 0, startY = 0; // Начальная позиция трактора
//
//    while (true) {
//        // 1. Найти ближайшую цель (незасеянный участок).
//        pair<int, int> target = findNearestUnseeded(field, startX, startY);
//        int targetX = target.first;
//        int targetY = target.second;
//        if (targetX == -1) break; // Все засеяно
//
//        // 2. Найти путь с помощью A*.
//       // vector<pair<int, int>> path = aStar(field, startX, startY, targetX, targetY);
//        vector<pair<int, int>> path = { {targetX, targetY} }; //Временно
//
//        // 3. Движение трактора и засеивание
//        for (auto& node : path) {
//            field[node.first][node.second] = 1; // Засеяли
//            startX = node.first;
//            startY = node.second;
//            cout << node.first << "," << node.second << endl;
//        }
//    }
//    cout << endl;
//
//    // Вывод результата
//    for (const auto& row : field) {
//        for (int cell : row) {
//            cout << cell << "\t";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}





//
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <cmath>
//#include <unordered_set>
//
//using namespace std;
//
//// Структура для состояния трактора
//struct State {
//    int x, y;  // Координаты
//    double cost; // Стоимость (пройденное расстояние)
//    vector<pair<int, int>> path; // Путь
//
//    // Оператор сравнения для priority_queue (минимальная стоимость)
//    bool operator>(const State& other) const {
//        return cost > other.cost;
//    }
//};
//
//// Хеш-функция для pair<int, int>
//struct PairHash {
//    size_t operator()(const pair<int, int>& p) const {
//        return hash<int>()(p.first) ^ hash<int>()(p.second);
//    }
//};
//
//// Проверяем, что координаты в пределах поля
//bool isValid(int x, int y, int rows, int cols) {
//    return x >= 0 && x < rows && y >= 0 && y < cols;
//}
//
//// Алгоритм A* для полного засеивания поля
//vector<pair<int, int>> aStarFullField(vector<vector<int>>& field, int startX, int startY) {
//    int rows = field.size();
//    int cols = field[0].size();
//    vector<pair<int, int>> path; // Итоговый путь
//
//    // Множество посещенных клеток
//    unordered_set<pair<int, int>, PairHash> visited;
//
//    // Начинаем с начальной позиции
//    priority_queue<State, vector<State>, greater<State>> pq;
//    pq.push({ startX, startY, 0, {{startX, startY}} });
//    visited.insert({ startX, startY });
//
//    while (!pq.empty()) {
//        State current = pq.top();
//        pq.pop();
//
//        int x = current.x, y = current.y;
//
//        // Если клетка ещё не засеяна
//        if (field[x][y] == 0) {
//            field[x][y] = 1;     // Засеиваем клетку
//            path.insert(path.end(), current.path.begin(), current.path.end()); // Добавляем путь к общему маршруту
//        }
//
//        // Проверяем, всё ли поле засеяно
//        bool allSeeded = true;
//        for (const auto& row : field) {
//            for (int cell : row) {
//                if (cell == 0) {
//                    allSeeded = false;
//                    break;
//                }
//            }
//            if (!allSeeded) break;
//        }
//        if (allSeeded) break;  // Если всё поле засеяно, выходим
//
//        int dx[] = { 0, 0, 1, -1 }; // Возможные перемещения
//        int dy[] = { 1, -1, 0, 0 };
//
//        for (int i = 0; i < 4; ++i) {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//
//            // Проверяем, что клетка в пределах поля и не является препятствием
//            if (isValid(nx, ny, rows, cols) &&
//                field[nx][ny] != -1 &&
//                visited.find({ nx, ny }) == visited.end()) {
//
//                // Проверяем возможность проезда через соседние клетки
//                bool canMove = true;
//                for (int j = 0; j < 4; ++j) {
//                    int checkX = nx + dx[j];
//                    int checkY = ny + dy[j];
//                    if (isValid(checkX, checkY, rows, cols) && field[checkX][checkY] == -1) {
//                        canMove = false;
//                        break;
//                    }
//                }
//
//                if (canMove) {
//                    double newCost = current.cost + 1; // Стоимость перемещения 1
//                    vector<pair<int, int>> newPath = current.path;
//                    newPath.push_back({ nx, ny });
//                    pq.push({ nx, ny, newCost, newPath });
//                    visited.insert({ nx, ny });
//                }
//            }
//        }
//    }
//
//    return path;
//}
//
//int main() {
//    setlocale(0, "ru");
//    // Пример поля (0 - не засеяно, 1 - засеяно, -1 - препятствие)
//    /*vector<vector<int>> field = {
//        {0, 0, 0, -1, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, -1, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0},
//        {-1, 0, 0, 0, -1, 0, 0, 0},
//        {0, 0, -1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0},
//        {0, -1, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0}
//    };*/
//    vector<vector<int>> field = {
//        {0, 0, 0, -1},
//        {0, 0, 0, 0},
//        {0, 0, 0, 0},
//        {-1, 0, 0, 0},
//
//    };
//
//    int startX = 0, startY = 0;  // Начальная позиция трактора
//
//    vector<pair<int, int>> path = aStarFullField(field, startX, startY);
//
//    cout << "Путь трактора (порядок засеивания): " << endl;
//    for (auto const& p : path) {
//        cout << "(" << p.first << ", " << p.second << ") ";
//    }
//    cout << endl;
//    cout << endl;
//    for (auto const& f : field) {
//        for (int cell : f) {
//            if (cell == 1)cout << " 1 ";
//            else if (cell == -1) cout << " -1 ";
//            else cout << " 0 ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    return 0;
//}







//// рабочий варинат
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cmath>
//#include <algorithm>
//#include <windows.h>
//
//using namespace std;
//
//struct Node {
//    int x, y;
//    int g, h, f;
//    Node* parent;
//
//    Node(int x, int y) : x(x), y(y), g(0), h(0), f(0), parent(nullptr) {}
//};
//
//int heuristic(int x1, int y1, int x2, int y2) {
//    return abs(x1 - x2) + abs(y1 - y2);
//}
//
//pair<int, int> findNearestUnseeded(const vector<vector<int>>& field, int current_x, int current_y) {
//    int min_dist = INT_MAX;
//    pair<int, int> nearest_unseeded = { -1,-1 };
//    for (int i = 0; i < field.size(); i++) {
//        for (int j = 0; j < field[0].size(); j++) {
//            if (field[i][j] == 0) {
//                int dist = heuristic(current_x, current_y, i, j);
//                if (dist < min_dist) {
//                    min_dist = dist;
//                    nearest_unseeded = { i,j };
//                }
//            }
//        }
//    }
//    return nearest_unseeded;
//}
//
//bool isValid(int x, int y, const vector<vector<int>>& field) {
//    return x >= 0 && x < field.size() && y >= 0 && y < field[0].size() && field[x][y] != -1;
//}
//
//vector<pair<int, int>> aStar(vector<vector<int>>& field, int startX, int startY, int targetX, int targetY) {
//    vector<vector<bool>> visited(field.size(), vector<bool>(field[0].size(), false));
//    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
//    pq.push({ 0, {startX, startY} });
//
//    vector<pair<int, int>> path;
//
//    while (!pq.empty()) {
//        int x = pq.top().second.first;
//        int y = pq.top().second.second;
//        int f = pq.top().first;
//        pq.pop();
//
//        if (x == targetX && y == targetY) {
//            path.push_back({ x, y });
//            return path;
//        }
//
//        if (visited[x][y]) continue;
//        visited[x][y] = true;
//
//        int dx[] = { 0, 0, 1, -1 };
//        int dy[] = { 1, -1, 0, 0 };
//
//        for (int i = 0; i < 4; ++i) {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//
//            if (isValid(nx, ny, field)) {
//                int new_f = heuristic(nx, ny, targetX, targetY);
//                pq.push({ new_f, {nx, ny} });
//            }
//        }
//      
//    }
//
//    return {};
//}
//
//void startWork(vector<vector<int>>& field) {
//    int startX = 0, startY = 0;
//
//    while (true) {
//        pair<int, int> target = findNearestUnseeded(field, startX, startY);
//        int targetX = target.first;
//        int targetY = target.second;
//        if (targetX == -1) break;
//
//        vector<pair<int, int>> path;
//        path = aStar(field, startX, startY, targetX, targetY);
//
//        for (auto& node : path) {
//
//            field[node.first][node.second] = 1;
//            startX = node.first;
//            startY = node.second;
//            //cout << node.first << "," << node.second << endl;         
//            for (const auto& row : field) {
//                for (int cell : row) {
//                    cout << cell << "\t";
//                }
//                cout << endl;
//            }
//            Sleep(1000);
//            system("cls");
//        }
//    }
//    cout << endl;
//
//    for (const auto& row : field) {
//        for (int cell : row) {
//            cout << cell << "\t";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//
//    vector<vector<int>> field = {
//                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                {0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                {0, 0, 0, 0, 0, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                {0, 0, 0, 0, 0, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                {0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
//    };
//
//    startWork(field);
//}
/*
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
*/

/*
{0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, -1, 0, 0, 0, 0, -1},
                {0, 0, 0, 0, 0, 0, -1, -1},
                {0, 0, 0, 0, 0, -1, -1, -1},
                {0, 0, 0, 0, 0, 0, -1, -1},
                {0, 0, 0, 0, 0, 0, 0, -1},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0}
*/

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
