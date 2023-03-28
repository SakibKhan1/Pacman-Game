#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int BOARD_WIDTH = 20;
const int BOARD_HEIGHT = 10;
int pacman_x, pacman_y, player_score;

char game_board[BOARD_HEIGHT][BOARD_WIDTH] = {
    "###################",
    "#.................#",
    "#.###.###.###.###.#",
    "#.#...#...#...#...#",
    "#.#.###.#.#.#.###.#",
    "#.#.#...#.#.#...#.#",
    "#...#.###.#.#.#.#.#",
    "#.#.#...#...#.#.#.#",
    "#.#.###.###.#.#.#.#",
    "#.................#",
    "###################"
};

void clear_screen() {
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursor_position = {0, 0};
    DWORD characters_written;
    CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
    GetConsoleScreenBufferInfo(console_handle, &console_screen_buffer_info);
    FillConsoleOutputCharacter(console_handle, ' ', console_screen_buffer_info.dwSize.X * console_screen_buffer_info.dwSize.Y, cursor_position, &characters_written);
    SetConsoleCursorPosition(console_handle, cursor_position);
}

void display_board() {
    clear_screen();
    cout << "Score: " << player_score << endl;
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            cout << game_board[i][j];
        }
        cout << endl;
    }
}

void move_pacman(int dx, int dy) {
    int new_x = pacman_x + dx;
    int new_y = pacman_y + dy;
    if (new_x >= 0 && new_x < BOARD_WIDTH && new_y >= 0 && new_y < BOARD_HEIGHT && game_board[new_y][new_x] != '#') {
        pacman_x = new_x;
        pacman_y = new_y;
        if (game_board[pacman_y][pacman_x] == '.') {
            player_score++;
            game_board[pacman_y][pacman_x] = ' ';
        }
    }
}

int main() {
    pacman_x = 1;
    pacman_y = 1;
    player_score = 0;

    while (true) {
        display_board();
        char input = getch();
        switch (input) {
            case 'w':
                move_pacman(0, -1);
                break;
            case 'a':
                move_pacman(-1, 0);
                break;
            case 's':
                move_pacman(0, 1);
                break;
            case 'd':
                move_pacman(1, 0);
                break;
            case 'q':
                return 0;
            default:
                break;
        }
    }

    return 0;
}
