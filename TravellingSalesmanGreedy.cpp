#include <iostream.h>
#include <conio.h>
#define INF 10000

int n=4;
int dist[4][4]={{0, 10, 15, 20},{10, 0, 35, 25},{15, 35, 0, 30},{20, 25, 30, 0}};

int visited[4];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tspGreedy(int start) {
    int cost = 0;
    int current = start;
    for (int i = 0; i < n; ++i) 
	visited[i] = 0;

    visited[current] = 1;

    for (int count = 1; count < n; ++count) {
        int nextCity = -1;
        int minDist = INF;

        for (int j = 0; j < n; ++j) {
            if (visited[j]==0 && dist[current][j] < minDist) {
                minDist = dist[current][j];
                nextCity = j;
            }
        }

        if (nextCity == -1) break;

        visited[nextCity] = 1;
        cost += minDist;
        current = nextCity;
    }

    // Return to starting city
    cost += dist[current][start];

    return cost;
}

int main() {

    int result = tspGreedy(0); // Start from city 0
    clrscr();
    cout << "Approximate minimum cost using greedy: " << result << "\n";

    return 0;
}
