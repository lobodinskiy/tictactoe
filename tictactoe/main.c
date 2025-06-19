#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

char board[3][3];             // Ігрове поле 3x3
char currentPlayer = 'X';      // Поточний гравець ('X' або 'O')

// Ініціалізація поля
void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Відображення поля разом із номерами клітинок
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        // Відображення вмісту клітинок
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j] == ' ' ? ' ' : board[i][j]);
            if (j < 2) printf("|");
        }
        // Відображення номеровки
        printf("     %d | %d | %d\n", 1 + i * 3, 2 + i * 3, 3 + i * 3);
        if (i < 2) printf("---|---|---     ---|---|---\n");
    }
    printf("\n");
}

// Перевірка виграшних умов
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

// Перевірка на нічию
int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') return 0;
    return 1;
}

int main(void) {
    setlocale(LC_ALL, "");            // Використовує системну локаль для кирилиці
    initBoard();                        // Підготовка поля

    int pos;
    while (1) {
        printBoard();                   // Вивід поля
        printf("Гравець %c, оберіть клітинку (1-9): ", currentPlayer);
        if (scanf("%d", &pos) != 1) {
            fflush(stdin);             // Очищення буфера вводу
            continue;
        }
        if (pos < 1 || pos > 9) {
            printf("Число поза діапазоном!\n");
            continue;
        }
        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;
        if (board[row][col] != ' ') {
            printf("Клітинка зайнята!\n");
            continue;
        }
        board[row][col] = currentPlayer;  // Виконання ходу

        if (checkWin()) {
            printBoard();
            printf("Гравець %c переміг!\n", currentPlayer);
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("Нічия!\n");
            break;
        }
        // Зміна гравця
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}
