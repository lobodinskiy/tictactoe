#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

char board[3][3];             // ������ ���� 3x3
char currentPlayer = 'X';      // �������� ������� ('X' ��� 'O')

// ����������� ����
void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// ³���������� ���� ����� �� �������� �������
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        // ³���������� ����� �������
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j] == ' ' ? ' ' : board[i][j]);
            if (j < 2) printf("|");
        }
        // ³���������� ���������
        printf("     %d | %d | %d\n", 1 + i * 3, 2 + i * 3, 3 + i * 3);
        if (i < 2) printf("---|---|---     ---|---|---\n");
    }
    printf("\n");
}

// �������� ��������� ����
int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return 1;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return 1;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return 1;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return 1;
    return 0;
}

// �������� �� ����
int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') return 0;
    return 1;
}

int main(void) {
    setlocale(LC_ALL, "");            // ����������� �������� ������ ��� ��������
    initBoard();                        // ϳ�������� ����

    int pos;
    while (1) {
        printBoard();                   // ���� ����
        printf("������� %c, ������ ������� (1-9): ", currentPlayer);
        if (scanf("%d", &pos) != 1) {
            fflush(stdin);             // �������� ������ �����
            continue;
        }
        if (pos < 1 || pos > 9) {
            printf("����� ���� ���������!\n");
            continue;
        }
        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;
        if (board[row][col] != ' ') {
            printf("������� �������!\n");
            continue;
        }
        board[row][col] = currentPlayer;  // ��������� ����

        if (checkWin()) {
            printBoard();
            printf("������� %c ������!\n", currentPlayer);
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("ͳ���!\n");
            break;
        }
        // ���� ������
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}
