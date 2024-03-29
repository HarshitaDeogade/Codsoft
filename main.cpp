#include <iostream>
#include <vector>

void print_board(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " | ";
        }
        std::cout << "\n";
    }
}

// Function to check if a player has won
bool check_win(const std::vector<std::vector<char>>& board, char player) {
    for (const auto& row : board) {
        if (std::all_of(row.begin(), row.end(), [&](char c) {return c == player; })) {
            return true;
        }
    }
    for (size_t col = 0; col < 3; ++col) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

bool check_draw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        if (std::find_if(row.begin(), row.end(), [](char c) {return c == ' '; }) != row.end()) {
            return false;
        }
    }
    return true;
}

char switch_player(char current_player) {
    return current_player == 'X' ? 'O' : 'X';
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char current_player = 'X';
    bool game_on = true;

    while (game_on) {
        print_board(board);
        if (check_win(board, current_player)) {
            std::cout << "Player " << current_player << " wins!\n";
            game_on = false;
        } else if (check_draw(board)) {
            std::cout << "It's a draw!\n";
            game_on = false;
        } else {
            int row, col;
            do {
                std::cout << "Player " << current_player << ", enter your move (row and column separated by space): ";
                std::cin >> row >> col;
                --row; --col;
            } while (board[row][col] != ' ');
            board[row][col] = current_player;
            current_player = switch_player(current_player);
        }
    }

    print_board(board);

    bool play_again = false;
    while (!play_again) {
        std::cout << "Do you want to play again? (yes/no): ";
        char response[10];
        std::cin.getline(response, 10);
        play_again = (response[0] == 'y' || response[0] == 'Y');
        if (play_again) {
            board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
        }
    }

    return 0;
}
