#include <stdio.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

char s[MAX_HEIGHT][MAX_WIDTH];
int vis[MAX_HEIGHT][MAX_WIDTH];
int n, m, x, y, dirX, dirY;

int valido(int x, int y) { 
    return x > -1 && y > -1 && x < n && y < m;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);

    while (valido(x, y)) {
        if (vis[x][y]) {
            printf("!\n");
            return 0;
        }
        if (s[x][y] == '*') {
            printf("*\n");
            return 0;
        }
        if (s[x][y] == '>')
            dirX = 0, dirY = 1;
        else if (s[x][y] == '<')
            dirX = 0, dirY = -1;
        else if (s[x][y] == 'v')
            dirX = 1, dirY = 0;
        else if (s[x][y] == '^')
            dirX = -1, dirY = 0;
        
        vis[x][y] = 1;
        x += dirX;
        y += dirY;
    }

    return 0;
}
