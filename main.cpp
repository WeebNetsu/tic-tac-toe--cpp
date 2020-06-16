#include <iostream>
#include <stdio.h>

using namespace std;

class Board{
	private:
		char row[3][3] = {
			{'1', '2', '3'},
			{'4', '5', '6'},
			{'7', '8', '9'}
		};

		bool openRow[3][3] = {
			{true, true, true},
			{true, true, true},
			{true, true, true}
		};

		int turn = 0;
		bool inGame = true;

	public:
		//accessor
		char getRow(int aRow, int aColumn){
			return row[aRow][aColumn];
		}

		//mutator
		void setRow(int num, char player){
			if(num == 1){
				if(openRow[0][0]){
					row[0][0] = player;
					openRow[0][0] = false;
				}else{
					inGame = false;
				}
			}else if(num == 2){
				if(openRow[0][1]){
					row[0][1] = player;
					openRow[0][1] = false;
				}else{
					inGame = false;
				}
			}else if(num == 3){
				if(openRow[0][2]){
					row[0][2] = player;
					openRow[0][2] = false;
				}else{
					inGame = false;
				}
			}else if(num == 4){
				if(openRow[1][0]){
					row[1][0] = player;
					openRow[1][0] = false;
				}else{
					inGame = false;
				}
			}else if(num == 5){
				if(openRow[1][1]){
					row[1][1] = player;
					openRow[1][1] = false;
				}else{
					inGame = false;
				}
			}else if(num == 6){
				if(openRow[1][2]){
					row[1][2] = player;
					openRow[1][2] = false;
				}else{
					inGame = false;
				}
			}else if(num == 7){
				if(openRow[2][0]){
					row[2][0] = player;
					openRow[2][0] = false;
				}else{
					inGame = false;
				}
			}else if(num == 8){
				if(openRow[2][1]){
					row[2][1] = player;
					openRow[2][1] = false;
				}else{
					inGame = false;
				}
			}else if(num == 9){
				if(openRow[2][2]){
					row[2][2] = player;
					openRow[2][2] = false;
				}else{
					inGame = false;
				}
			}
		}

		void drawBoard(){
			for (int i = 0; i < 4; i++){
				cout << "---";
			}

			cout << endl;
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					if(j % 2 == 0){
						cout << "| " << getRow(i, j) << " |";
					}else{
						cout << " " << getRow(i, j) << " ";
					}
				}

				cout << endl;
				for (int i = 0; i < 4; i++){
					cout << "---";
				}
				cout << endl;
			}
		}

		void init(){
			if(getIngame()){
				drawBoard();

				if(getWinner() == 1){
					cout << "Player 1 wins!!" << endl;
					inGame = false;
				}else if(getWinner() == 2){
					cout << "Player 2 wins!!" << endl;
					inGame = false;
				}else if(getWinner() == 3){
					cout << "It's a draw!";
				}
			}else{
				cout << "An error occured!" << endl;
			}
		}

		void playGame(int num){
			turn++;

			if(turn % 2 == 0){ // if it's player 2's turn
				setRow(num, 'O');
			}else{
				setRow(num, 'X');
			}

			init();
		}

		bool getIngame(){
			return inGame;
		}

		int getWinner(){
			char player;
			bool openSpaces = false;
			int playerNumber;
			for (int j = 1; j < 3; j++){
				if(j == 1){
					player = 'X';
					playerNumber = 1;
				}else{
					player = 'O';
					playerNumber = 2;
				}

				for (int i = 0; i < 3; i++){
					if(!openRow[j][i] && !openSpaces){
						openSpaces = false;
					}else{
						openSpaces = true;
					}

					//checks horizontally 
					if(getRow(i, 0) == player && getRow(i, 1) == player && getRow(i, 2) == player){
						return playerNumber;
					}

					//checks vertically
					if(getRow(0, i) == player && getRow(1, i) == player && getRow(2, i) == player){
						return playerNumber;
					}
				}

				//checks sideways-right
				if(getRow(0, 1) == player && getRow(1, 1) == player && getRow(2, 2) == player){
					return playerNumber;
				}

				//checks sideways-left
				if(getRow(0, 2) == player && getRow(1, 1) == player && getRow(2, 0) == player){
					return playerNumber;
				}
			}

			if(!openSpaces){
				inGame = false;
				return 3;
			}

			return 0;
		}

		int getTurn(){
			return turn + 1;
		}
};

int main(){
	Board board;
	int currentPlayer = 1;
	int userInp;
	board.drawBoard();

	while(board.getIngame()){
		if(board.getTurn() % 2 == 0 && board.getTurn() != 0){
			currentPlayer = 2;
		}else{
			currentPlayer = 1;
		}

		cout << "Player " << currentPlayer << ", choose a block: ";
		scanf("%d", &userInp);


		cout << endl;
			cout << endl;
		board.playGame(userInp);
	}

	return 0;
}