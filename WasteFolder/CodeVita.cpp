#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int board[MAX][MAX];
int n, m;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j] = -1;
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        board[u][board[u][0]++] = v;
    }
    int steps[MAX];
    int num_steps = 0;
    while (scanf("%d", &steps[num_steps]) != EOF) {
        num_steps++;
    }

    int visited[MAX][MAX];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= num_steps; j++) {
            visited[i][j] = 0;
        }
    }

    int snakes = 0;
    int ladders = 0;

    visited[1][0] = 1;

    for (int j = 0; j < num_steps; j++) {
        for (int i = 1; i <= n; i++) {
            if (visited[i][j]) {
                for (int k = 1; k <= m; k++) {
                    int new_pos = board[i][k];
                    if (new_pos == n) {
                        visited[n][j + 1] = 1;
                        break;
                    }
                    if (new_pos > i) {
                        visited[new_pos][j + 1] = 1;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= num_steps; j++) {
            if (visited[i][j]) {
                for (int k = 1; k <= m; k++) {
                    if (board[i][k] > i) {
                        ladders++;
                    } else if (board[i][k] < i) {
                        snakes++;
                    }
                }
            }
        }
    }

    if (visited[n][num_steps]) {
        printf("Possible %d %d\n", snakes, ladders);
    } else {
        printf("Not possible %d %d %d\n", snakes, ladders, n);
    }

    return 0;
}
