#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

struct board {
    int n;
    char a[MAX][MAX];
};
int turn = 0;

void draw_board(board &b) {
    int i, j;
    printf("nhap kich thuoc:");
    scanf("%d", &b.n);
    for(i = 1; i <= b.n; i++) {
        printf("   %d  ", i);
    }
    printf("\n");

    for(i = 1; i <= b.n; i++) {
        printf("%d",i);
        for(j = 1; j <= b.n; j++) {
            printf("  %c   |",b.a[i][j]);
        }
        printf("\n");
        printf("-------------------");
        printf("\n");
    }
}

int get_coordinate(board &b) {
    int x, y;
    scanf("x: %d", &x);
    scanf("y: %d", &y);
}

int get_turn() {
    if(turn % 2 == 0) {
        return 1;
    }
    else {
        return 2;
    }
}

void read_board(board b) {
    int i, j;
    for(i = 1; i <= b.n; i++) {
        printf("   %d  ", i);
    }
    printf("\n");

    for(i = 1; i <= b.n; i++) {
        printf("%d",i);
        for(j = 1; j <= b.n; j++) {
            if(b.a[i][j] == 1) {
                printf("  %c  |",b.a[i][j] + 78);
            }
            else if(b.a[i][j] == 2) {
                printf("  %c  |",b.a[i][j] + 86);
            }
            else {
                printf("  %c   |", b.a[i][j]);
            }
            printf("%c", b.a[i][j]);
        }
        printf("\n");
        printf("-------------------");
        printf("\n");
    }
}

void fill_board(board &b, int hor, int ver, int status) {
    if(status == 1) {
        b.a[hor][ver] = 1;
    }
    else {
        b.a[hor][ver] = 2;
    }
}

int check_win(board b, int i, int j) {
    //ktra hang
    int d = 0, k = i, h;
    while(b.a[k][j] == b.a[i][j]) {
        d++;
        k++;
    }
    k = i - 1;
    while(b.a[k][j] == b.a[i][j]) {
        d++;
        k--;
    }
    if(d > 2) return true;
    d = 0;
    h = j;

    //ktra cot
    while(b.a[i][h] == b.a[i][j]) {
        d++;
        h++;
    }
    h = j - 1;
    while(b.a[i][h] == b.a[i][j]) {
        d++;
        h--;
    }
    if(d > 2) return true;

    // ktra cheo 1
    h = i;
    k = j;
    d = 0;
    while(b.a[i][j] == b.a[h][k]) {
        d++;
        h++;
        k++;
    }
    h = i - 1;
    k = j - 1;
    while (b.a[i][j] == b.a[h][k])
    {
        d++;
        h--;
        k--;
    }
    if(d > 2) return true;

    // ktra cheo 2

    h = i;
    k = j;
    d = 0;

    while(b.a[i][j] == b.a[h][k]) {
        d++;
        k--;
        h++;
    }
    h = i - 1;
    k = j + 1;
    while(b.a[i][j] == b.a[h][k]) {
        d++;
        k++;
        h--;
    }

    if(d > 2) return true;

    return false;
}

int main() {
    board b;
    // draw initial board
    draw_board(b);
    // start play
    while(true) {
        printf("----Let's Play----\n");
        read_board(b);
        if(get_turn() == 1) {
            printf("It's O turn! type coordinate! Ex: 2 3");
            printf("\n");
        }
        else {
            printf("It's X turn! type coordinate! Ex: 2 3");
            printf("\n");
        }
        // read vertical & horizon 
        int ver, hor;
        printf("hor:");
        scanf("%d", &hor);
        printf("ver:");
        scanf("%d", &ver);

        // add ver-hor to board & check win
        if(ver <= b.n && ver > 0 && hor > 0 && hor <= b.n && b.a[hor][ver] == 0) {
            int status = get_turn();
            fill_board(b,hor,ver,status);
            printf("gia tri:%d", b.a[hor][ver]);
            printf("\n");
            if(turn > 3 && check_win(b, hor, ver) == true) {
                read_board(b);
                if(get_turn() == 1) {
                    printf("O win!");
                    break;
                }
                else {
                    printf("X win!");
                    break;
                }
            }
            turn = turn + 1;
            if(turn == b.n*b.n) {
                read_board(b);
                printf("Draw!");
                break;
            }
        }
    }
    return 0;
}