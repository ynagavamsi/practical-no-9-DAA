#include <iostream>
using namespace std;

#define INF 9999

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[20][20];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    int visited[20] = {0};
    visited[0] = 1;

    int edges = 0, total = 0;

    cout << "\nMinimum Spanning Tree:\n";

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << u << " - " << v << " = " << min << endl;

        visited[v] = 1;
        total += min;
        edges++;
    }

    cout << "Total MST Cost = " << total << endl;

    return 0;
}
