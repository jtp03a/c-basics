#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool detect_win(char current_game_board[9], char player);
void display_board(char current_game_board[9]);
int find_board_position(int x, int y);
bool position_empty(char current_game_board[9], int player_move);
bool valid_range(int x, int y);

// Check that user input is between 1 and 3
bool valid_range(int x, int y) {
  if (x >=1 & x <= 3 & y >=1 & y <= 3) {
    return true;
  } else {
    return false;
  }
}

// check if the board position is empty or already played
bool position_empty(char current_game_board[9], int player_move) {
  if (current_game_board[player_move] == 'E') {
    return true;
  } else {
    printf("You cant play there!!\n");
    return false;
  }
}

// convert to the player input row/column to the valid array position
int find_board_position(int x, int y) {
  int board_position;
  if (x == 1) {
    board_position = 0 + (y - 1);
  } else if (x == 2) {
    board_position = 3 + (y - 1);
  } else if (x == 3) {
    board_position = 6 + (y - 1);
  }
  return board_position;
}

// display the current game board
void display_board(char current_game_board[9]) {
  for(int i = 0; i < 9; i = i + 3) {
    printf("| ");
    for (int j = 0; j < 3; j++) {
      printf("%c ", current_game_board[i + j]);
    }
    printf("|\n");
  }
  printf("\n");
}

// Detecting winning or tie conditions
bool detect_win(char current_game_board[9], char player) {
  for(int i = 0; i < 9; i = i + 3) {
    // horizontal win or diagonal win
    if (current_game_board[i] == player & current_game_board[i + 1] == player & current_game_board[i + 2] == player) {
      printf("%c you won!!!!", player);
      return true;
    } else if (current_game_board[i] == player & current_game_board[i + 4] == player & current_game_board[i + 8] == player) {
      printf("%c you won!!!!", player);
      return true;
    } else if (current_game_board[i + 2] == player & current_game_board[i + 4] == player & current_game_board[i + 6] == player) {
      printf("%c you won!!!!", player);
      return true;
    }
  }
  // vertical win
  for (int i = 0; i < 3; i++) {
    if (current_game_board[i] == player & current_game_board[i + 3] == player & current_game_board[i + 6] == player) {
      printf("%c you won!!!!", player);
      return true;
    }
  }
  // check for a tie
  int e_count = 0;
  for (int i = 0; i < 9; i++) {
    if (current_game_board[i] == 'E'){
      e_count++;
    }
  }
  if (e_count == 0) {
    printf("It's a tie!!!\n");
    return true;
  }
}

int main() {
  // initial board layout
  char game_board[9] = {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'};
  bool game_won = false;
  // starting player
  char current_player = 'X';

  // main game loop
  while (!game_won) {
    int x;
    int y;
    int player_move;
    bool valid_move = false;
    printf("It's your turn %c!\n", current_player);
    while (!valid_move) {
      printf("Enter Row: ");
      scanf("%d", &x);
      printf("Enter Column: ");
      scanf("%d", &y);
      if (valid_range(x, y)) {
        player_move = find_board_position(x, y);
        if (position_empty(game_board, player_move)) {
          valid_move = true;
          game_board[player_move] = current_player;
        }
      } else {
        printf("Enter a Row and Column between 1 and 3\n");
      }
    }    
    display_board(game_board);
    game_won = detect_win(game_board, current_player);
    current_player = current_player == 'X' ? 'O' : 'X';
    valid_move = false;
  }

  return 0;
}