#include <iostream>
using namespace std;

char board[3][3] = {
                  {'1', '2', '3'},
                  {'4', '5', '6'},
                  {'7', '8', '9'}
                  };

char current_shape;
int current_player;

void draw_board(){
  cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
  cout << "-----------\n";
  cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
  cout << "-----------\n";
  cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool position_locator(int position){
  int row = position/3;
  int col;

  if(position % 3 == 0){
      row -= 1;
      col = 2;
  }
  
  else col = (position % 3) - 1;
  
  if(board[row][col] != 'X' && board[row][col] != 'O'){ 
    board[row][col] = current_shape;
    return true;
  }
  else{
    return false;
  }
}

char winner(){
  for(int i = 0; i < 3; i++){
    //row win
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
    //column win
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
  }
  // diagnoal win
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

  return 0;
}

void swap(){
  if (current_player == 1) current_player = 2;
  else current_player = 1;

  if (current_shape == 'X') current_shape = 'O';
  else current_shape = 'X';
}

void game(){
  cout << "Player one, choose your shape: \n";
  char p1_shape;
  cin >> p1_shape;
  
  if (p1_shape == 'X' || p1_shape == 'O') {cout << "ok";}
  else if (p1_shape == 'x') p1_shape = 'X';
  else if (p1_shape == 'o') p1_shape = 'O';
  else { cout << "Invalid marker. Please choose either 'X' or 'O'";}

  current_player = 1;
  current_shape = p1_shape;

  draw_board();

  int possible_winner;

  for (int i = 0; i < 9; i++){
    cout << "It's player " << current_player <<"'s turn. Enter your position : ";
    int position;
    cin >> position;

    if (position < 1 || position > 9){
      cout << "That is not a valid position. Try again.";
      i--;
      continue;
      
    }
    if (!position_locator(position)){
      cout << "This position is already occupied. Try another position.";
      i--;
      continue;
    }

    draw_board();
    
    possible_winner = winner();
    if(possible_winner == 1) {
        cout << "Player 1 wins! Better luck next time, Player 2."; 
        break;
    }
    else if(possible_winner == 2) {
        cout << "Player 2 wins! Better luck next time, Player 1."; 
        break;
    }
    else swap();
  }
  if(possible_winner == 0) cout << "The game has ended in a tie.";
  }
  

int main()
{
  game();
}
