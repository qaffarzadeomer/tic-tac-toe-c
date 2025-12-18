#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[9] = {'1','2','3','4','5','6','7','8','9'};

void printBoard() {
    printf("\n");
    for(int i = 0; i < 9; i++) {
        printf(" %c ", board[i]);
        if (i % 3 != 2) printf("|");
        if (i % 3 == 2 && i != 8)
            printf("\n---+---+---\n");
    }
    printf("\n\n");
}

int checkWin() {
    int wins[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for(int i = 0; i < 8; i++) {
        if(board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][1]] == board[wins[i][2]])
            return 1;
    }
    return 0;
}

void playerMove() {
    int move;
    while(1) {
        printf("Sənin gedişin (1-9): ");
        scanf("%d", &move);
        move--;

        if(move >= 0 && move < 9 && board[move] != 'X' && board[move] != 'O') {
            board[move] = 'X';
            break;
        } else {
            printf("Yanlış gediş! Yenidən cəhd et.\n");
        }
    }
}

void botMove() {
    int move;
    while(1) {
        move = rand() % 9;
        if(board[move] != 'X' && board[move] != 'O') {
            board[move] = 'O';
            break;
        }
    }
    printf("Botun gedişi...\n");
}

int main() {
    int moves = 0;
    srand(time(NULL));

    printf("X və O oyunu (Tic-Tac-Toe)\n");
    printBoard();

    while(moves < 9) {
        playerMove();
        printBoard();
        moves++;
        if(checkWin()) {
            printf("🎉 Təbriklər! Sən qalib gəldin!\n");
            return 0;
        }

        if(moves == 9) break;

        botMove();
        printBoard();
        moves++;
        if(checkWin()) {
            printf("🤖 Bot qalib gəldi!\n");
            return 0;
        }
    }

    printf("🤝 Heç-heçə!\n");
    return 0;
}
