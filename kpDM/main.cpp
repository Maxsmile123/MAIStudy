#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <list> 
#include <stack> 
#include <vector> 

#define NIL -1 

using namespace std;

int x = 0;

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    if (a < b) {
        return a;
    }
}

class Edge {
public:
    int u;
    int v;
    Edge(int u, int v);
};

Edge::Edge(int u, int v)
{
    this->u = u;
    this->v = v;
}

// Класс граф
class Graph {
    int V; // Вершин
    int E; // Ребер
    list<int>* adj; // Список смежности 

    //ДФС для BCC()
    void BCCUtil(int u, int disc[], int low[],
        list<Edge>* st, int parent[]);

public:
    Graph(int V); // Конструктор от кол-ва вершин
    void addEdge(int v, int w); // Добавлять рёбра в граф
    void BCC(); // Печатает компоненты вершинной двусвязности (блоки)
};

Graph::Graph(int V)
{
    this->V = V;
    this->E = 0;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    E++;
}

// Рекурсивно ищет блоки ДФСом по глубинным номерам
// u следующая вершина обхода
// disc[] глубинные номера
// low[] -- >> вершина с минимальным глубинным номером из поддерева
// st сохраняем путь
void Graph::BCCUtil(int u, int disc[], int low[], list<Edge>* st,
    int parent[])
{
    // Статическое время для упрощения кода (глубинный номер)
    static int time = 0;

    // Инициализируем номера
    disc[u] = low[u] = ++time;
    int children = 0;

    // Проходимся по списку смежности
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i;

        // Если не посещена
        if (disc[v] == -1) {
            children++;
            parent[v] = u;
            // Сохраняем
            st->push_back(Edge(u, v));
            BCCUtil(v, disc, low, st, parent);

            // Проверяем минимумы
            low[u] = min(low[u], low[v]);

            // Вытаскиваем из стека
            if ((disc[u] == 1 && children > 1) || (disc[u] > 1 && low[v] >= disc[u])) {
                while (st->back().u != u || st->back().v != v) {
                    cout << st->back().u << "-" << st->back().v << " ";
                    st->pop_back();
                }
                cout << st->back().u << "-" << st->back().v;
                st->pop_back();
                cout << endl;
                x++;
            }
        }

        // 2 случай
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
            if (disc[v] < disc[u]) {
                st->push_back(Edge(u, v));
            }
        }
    }
}

// ДФС
void Graph::BCC()
{
    int* disc = new int[V];
    int* low = new int[V];
    int* parent = new int[V];
    list<Edge>* st = new list<Edge>[E];

    // Инициализируем невалидными значениями
    for (int i = 0; i < V; i++) {
        disc[i] = NIL;
        low[i] = NIL;
        parent[i] = NIL;
    }

    for (int i = 0; i < V; i++) {
        if (disc[i] == NIL)
            BCCUtil(i, disc, low, st, parent);

        int j = 0;
        //Если стек не пустой -- опустошаем
        while (st->size() > 0) {
            j = 1;
            cout << st->back().u << "-" << st->back().v << " ";
            st->pop_back();
        }
        if (j == 1) {
            cout << endl;
            x++;
        }
    }
}

int main(int argc, char* argv[])
{
    freopen(argv[1], "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> ish(n, vector<int>(n));
    Graph g(n);
    int buf;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> buf;
            ish[i][j] = buf;
            if (buf)
            {
                g.addEdge(i, j);
            }
        }

    freopen(argv[1], "w", stdout);
    cout.clear();
    cout << n << "\n";
    for (auto& i : ish)
    {
        for (auto& j : i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "Text: " << endl;
    g.BCC();
    cout << "Blocks: " << x;
    return 0;
}
