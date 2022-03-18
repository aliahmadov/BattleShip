#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

void mysetcolor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

int count_rival = 20;
int count_gamer = 20;
int X = 0;
int Y = 0;
int X_rival = 0;
int Y_rival = 0;
int X_copy = X;
int Y_copy = Y;




const int s = 12;
int game[s][s] = {};

int game_opponent[s][s] = {};

enum Letters { A, B, C, D, E, F, G, H, I, J };

enum Directions { UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75 };

enum Variables { Ship = 12, Wall = 11, Hit = 13, Miss_Point = 14, Burst = 15 };



void GameAreaPlayer(int game_play[s][s], int count) {

	bool isTurn = 0;
	if (game_play == game) {
		isTurn = 1;
	}
	else {
		isTurn = 0;
	}
	int number = 0;
	mysetcolor(6, 0);
	cout << "                                              Ship Count: " << count << endl;
	mysetcolor(1, 0);

	for (size_t i = 0; i < s; i++)
	{

		for (size_t k = 0; k < s; k++)
		{

			if (i == A + 1 && k == A + 1) {
				mysetcolor(1, 0);
				cout << "A  ";
			}
			else if (i == B + 1 && k == B + 1) {
				mysetcolor(1, 0);
				cout << "B  ";
			}
			else if (i == C + 1 && k == C + 1) {
				mysetcolor(1, 0);
				cout << "C  ";
			}
			else if (i == D + 1 && k == D + 1) {
				mysetcolor(1, 0);
				cout << "D  ";

			}
			else if (i == E + 1 && k == E + 1) {
				mysetcolor(1, 0);
				cout << "E  ";
			}
			else if (i == F + 1 && k == F + 1) {
				mysetcolor(1, 0);
				cout << "F  ";
			}
			else if (i == G + 1 && k == G + 1) {
				mysetcolor(1, 0);
				cout << "G  ";
			}
			else if (i == H + 1 && k == H + 1) {
				mysetcolor(1, 0);
				cout << "H  ";

			}
			else if (i == I + 1 && k == I + 1) {
				mysetcolor(1, 0);
				cout << "I  ";
			}
			else if (i == J + 1 && k == J + 1) {
				mysetcolor(1, 0);
				cout << "J  ";
			}

		}
		int number = 1;
		for (size_t k = 0; k < s; k++)
		{
			if (i == 0 || i == s - 1) {
				if (number > 10) {
					continue;
				}
				if (number == 1) {
					cout << "  ";
				}
				if (number == 10) {
					cout << "   " << number;
					break;
				}
				cout << "   " << number;
				number++;
			}
			else if (k == 0) {
				mysetcolor(1, 0);
				cout << "| ";
			}
			else if (k == s - 1) {
				mysetcolor(1, 0);
				cout << "|\n";
			}
			else if (game_play[i][k] == Ship && isTurn == 0) {

				mysetcolor(0, 0);
				cout << char(178) << "   ";
				mysetcolor(7, 0);
			}
			else if (game_play[i][k] == Ship && isTurn == 1) {

				mysetcolor(5, 0);
				cout << char(178) << "   ";
				mysetcolor(7, 0);
			}
			else if (game_play[i][k] == Hit) {
				mysetcolor(2, 0);
				cout << char(178) << "   ";
				mysetcolor(7, 0);
			}
			else if (game_play[i][k] == Burst) {
				mysetcolor(4, 0);
				cout << char(178) << "   ";
				mysetcolor(7, 0);
			}

			else if (game_play[i][k] == Miss_Point) {
				mysetcolor(1, 0);
				cout << char(178) << "   ";
				mysetcolor(7, 0);
			}

			else if (isTurn == 1) {
				mysetcolor(6, 0);
				cout << char(178) << "   ";
				mysetcolor(7, 0);
			}
			else if (isTurn == 0) {
				mysetcolor(0, 0);
				cout << char(178) << "   ";
				mysetcolor(7, 0);
			}


		}

		cout << endl;
	}cout << endl;;
}




void ShowMenu() {
	cout << "MANUAL 1" << endl;
	cout << "AUTO   2" << endl;
}

bool isEmptyAuto(int Y, int X, int number_ship, int no, int game[s][s]) {
	int letter = int(Y) - 65 + 1;

	if (no == DOWN) {

		for (size_t i = 0; i < number_ship + 1; i++)
		{
			if (game[letter + i][X - 1] == Ship || game[letter + i][X + 1] == Ship ||
				game[letter + i][X] == Ship || game[letter - 1][X] == Ship || game[letter - 1][X - 1] == Ship ||
				game[letter - 1][X + 1] == Ship) {
				return false;
			}

		}
	}

	else if (no == UP) {

		for (size_t i = 0; i < number_ship + 1; i++)
		{
			if (game[letter - i][X - 1] == Ship || game[letter - i][X + 1] == Ship ||
				game[letter - i][X] == Ship || game[letter + 1][X] == Ship || game[letter + 1][X - 1] == Ship ||
				game[letter + 1][X + 1] == Ship) {
				return false;
			}
		}
	}
	else if (no == LEFT) {

		for (size_t i = 0; i < number_ship + 1; i++)
		{
			if (game[letter - 1][X - i] == Ship || game[letter + 1][X - i] == Ship ||
				game[letter][X - i] == Ship || game[letter][X + 1] == Ship || game[letter - 1][X + 1] == Ship ||
				game[letter + 1][X + 1] == Ship) {
				return false;
			}
		}
	}

	else if (no == RIGHT) {

		for (size_t i = 0; i < number_ship + 1; i++)
		{
			if (game[letter - 1][X + i] == Ship || game[letter + 1][X + i] == Ship ||
				game[letter][X + i] == Ship || game[letter][X - 1] == Ship || game[letter + 1][X - 1] == Ship ||
				game[letter - 1][X + 1] == Ship || game[letter - 1][X - 1] == Ship) {
				return false;
			}
		}
	}

	return true;

}





void SetShip(int c, char l, int no, int number_ship, int& k, int game[s][s]) {
	int letter = int(l) - 65 + 1;
	if (no == RIGHT) {
		if (c + number_ship <= 11) {
			for (size_t i = 0; i < number_ship; i++)
			{
				game[letter][c] = Ship;
				c++;
			}
		}
		else {
			k--;
		}
	}
	else if (no == LEFT) {
		if (c - number_ship >= 0) {
			for (size_t i = 0; i < number_ship; i++)
			{
				game[letter][c] = Ship;
				c--;
			}
		}
		else {
			k--;
		}
	}

	else if (no == DOWN) {
		if (letter + number_ship <= 11) {
			for (size_t i = 0; i < number_ship; i++)
			{
				game[letter][c] = Ship;
				letter++;
			}
		}
		else {
			k--;
		}
	}
	else if (no == UP) {
		if (letter - number_ship >= 0) {

			for (size_t i = 0; i < number_ship; i++)
			{
				game[letter][c] = Ship;
				letter--;
			}
		}
		else {
			k--;
		}
	}

};


bool hasWonGamer(int count1) {
	if (count1 == 0) {
		return true;
	}
	return false;
}

bool hasWonRival(int count1) {
	if (count1 == 0) {
		return true;
	}
	return false;
}

bool hasHit = 0;
bool hasHit_rival = 0;
void HitShipGamer(int game[s][s], int game_opponent[s][s], int X, char letter, bool& hasHit) {
	int Y = (int)letter - 65 + 1;

	int count = 0;
	if (game_opponent[Y][X] == Ship) {
		cout << "\a";
		game_opponent[Y][X] = Hit;
		hasHit = 1;
		count_rival--;
		if (hasWonGamer(count_rival)) {
			mysetcolor(4, 0);
			cout << "                YOU HAVE HAVE COMPLETED THE GAME ---> ALL SHIPS HAVE SUCCESSFULLY BEEN BURST !!!" << endl;
			mysetcolor(7, 0);
		}


		if (game_opponent[Y + 1][X] == Ship || game_opponent[Y + 1][X] == Hit || game_opponent[Y + 1][X] == Miss_Point) {
			for (size_t i = 0; i < 10; i++)
			{

				if (game_opponent[Y + i + 1][X] == 0 || game_opponent[Y + i + 1][X] == Miss_Point) {
					break;
				}
				if (game_opponent[Y + i + 1][X] == Ship) {
					count++;
				}
			}
		}


		if (game_opponent[Y][X + 1] == Ship || game_opponent[Y][X + 1] == Hit || game_opponent[Y][X + 1] == Miss_Point) {
			for (size_t i = 0; i < 10; i++)
			{
				if (game_opponent[Y][X + 1 + i] == 0 || game_opponent[Y][X + 1 + i] == Miss_Point) {
					break;
				}
				if (game_opponent[Y][X + i + 1] == Ship) {
					count++;
				}
			}
		}

		if (game_opponent[Y - 1][X] == Ship || game_opponent[Y - 1][X] == Hit || game_opponent[Y - 1][X] == Miss_Point) {
			for (size_t i = 0; i < 10; i++)
			{
				if (game_opponent[Y - 1 - i][X] == 0 || game_opponent[Y - 1 - i][X] == Miss_Point) {
					break;
				}
				if (game_opponent[Y - i - 1][X] == Ship) {
					count++;
				}
			}
		}


		if (game_opponent[Y][X - 1] == Ship || game_opponent[Y][X - 1] == Hit || game_opponent[Y][X - 1] == Miss_Point) {
			for (size_t i = 0; i < 10; i++)
			{
				if (game_opponent[Y][X - 1 - i] == 0 || game[Y][X - 1 - i] == Miss_Point) {
					break;
				}
				if (game_opponent[Y][X - i - 1] == Ship) {
					count++;
				}
			}
		}
		if (count == 0) {
			cout << "                        Success For Gamer -->> SHIP HAS BEEN BURST ";
			Beep(600, 555); // 523 hertz (C5) for 500 milliseconds     
			cin.get(); // wait 
			int j = 0;
			while (true) {
				bool isFalse = 0;

				if (game_opponent[Y + j][X] == Hit) {
					if (game_opponent[Y + j][X] == 0 || game_opponent[Y + j][X] == Miss_Point) {
						break;
					}
					isFalse = 1;
					game_opponent[Y + j][X] = Burst;
				}
				if (game_opponent[Y - j][X] == Hit) {
					if (game_opponent[Y - j][X] == 0 || game_opponent[Y - j][X] == Miss_Point) {
						break;
					}
					isFalse = 1;
					game_opponent[Y - j][X] = Burst;
				}
				if (game_opponent[Y][X + j] == Hit) {
					if (game_opponent[Y][X + j] == 0 || game_opponent[Y][X + j] == Miss_Point) {
						break;
					}
					isFalse = 1;
					game_opponent[Y][X + j] = Burst;
				}
				if (game_opponent[Y][X - j] == Hit) {
					if (game_opponent[Y][X - j] == 0 || game_opponent[Y][X - j] == Miss_Point) {
						break;
					}
					isFalse = 1;
					game_opponent[Y][X - j] = Burst;
				}

				if (isFalse == 0) {
					break;
				}
				j++;
			}
			system("pause");
		}
	}
	else {
		game_opponent[Y][X] = Miss_Point;
		hasHit = 0;
	}



}

const int s2 = 12;
int arr_move[s2][s2] = {};
int count_down = 0;
int count_up = 0;
int count_right = 0;
int count_left = 0;

bool isdown = 0;
bool isup = 0;
bool isright = 0;
bool isleft = 0;

void CheckHit(bool& isFalse) {
	for (size_t i = 0; i < s2; i++)
	{
		for (size_t k = 0; k < s2; k++)
		{
			if (arr_move[i][k] == Hit) {
				isFalse = 1;
				break;
			}
		}
	}

}

void MakeMissPoint() {
	int a = 0;
	if (game[Y + 1][X] == Hit || game[Y - 1][X] == Hit) {
		a = 1;
	}
	else if (game[Y][X + 1] == Hit || game[Y][X - 1] == Hit) {
		a == 2;
	}
	else {
		a = 3;
	}
	int l = 0;

	bool isFalse = 0;


	if (a == 1) {

		while (true) {

			if (game[Y + l][X] == Miss_Point || game[Y + l][X] == 0) {
				game[Y + l][X] = Miss_Point;
				game[Y + l][X + 1] = Miss_Point;
				game[Y + l][X - 1] = Miss_Point;
				l = 0;
				break;
			}
			game[Y + l][X + 1] = Miss_Point;
			game[Y + l][X - 1] = Miss_Point;
			l++;
		}
	}
	if (a == 1) {
		while (true) {

			if (game[Y - l][X] == Miss_Point || game[Y - l][X] == 0) {
				game[Y - l][X] = Miss_Point;
				game[Y - l][X + 1] = Miss_Point;
				game[Y - l][X - 1] = Miss_Point;
				l = 0;
				break;
			}
			game[Y - l][X + 1] = Miss_Point;
			game[Y - l][X - 1] = Miss_Point;
			l++;
		}
	}

	if (a == 2) {

		while (true) {

			if (game[Y][X - l] == Miss_Point || game[Y][X - l] == 0) {
				game[Y][X - l] = Miss_Point;
				game[Y + 1][X - l] = Miss_Point;
				game[Y - 1][X - l] = Miss_Point;
				l = 0;
				break;
			}
			game[Y + 1][X - l] = Miss_Point;
			game[Y - 1][X - l] = Miss_Point;
			l++;
		}

	}

	if (a == 2) {

		while (true) {

			if (game[Y][X + l] == Miss_Point || game[Y][X + l] == 0) {
				game[Y][X + l] = Miss_Point;
				game[Y + 1][X + l] = Miss_Point;
				game[Y - 1][X + l] = Miss_Point;
				l = 0;
				break;
			}
			game[Y + 1][X + l] = Miss_Point;
			game[Y - 1][X + l] = Miss_Point;
			l++;
		}

	}
	if (a == 3) {
		game[Y][X + 1] = Miss_Point;
		game[Y][X - 1] = Miss_Point;
		game[Y + 1][X] = Miss_Point;
		game[Y - 1][X] = Miss_Point;
		game[Y + 1][X + 1] = Miss_Point;
		game[Y + 1][X - 1] = Miss_Point;
		game[Y - 1][X - 1] = Miss_Point;
		game[Y - 1][X + 1] = Miss_Point;

	}

}



void HitShipRival(int game[s][s], int game_opponent[s][s], bool& hasHit_rival) {
	srand(time(0));
	int count = 0;
	while (true) {
		bool isFalse = 0;
		CheckHit(isFalse);
		if (isFalse == 0) {

			int random_x = 1 + rand() % (11 - 1);
			int random_y = 1 + rand() % (11 - 1);

			Y = random_y;
			X = random_x;
		}

		else {
			while (true) {

				if (arr_move[Y][X] == Hit && isdown == false) {
					Y = Y + 1;
					count_down++;
					break;
				}
				else {
					Y = Y - count_down;
					count_down = 0;
					isdown = true;
				}

				if (arr_move[Y][X] == Hit && isup == false) {
					Y = Y - 1;
					count_up++;
					break;
				}
				else {
					Y = Y + count_up;
					count_up = 0;
					isup = true;

				}

				if (arr_move[Y][X] == Hit && isleft == false) {
					X = X - 1;
					count_left++;
					break;
				}
				else {
					X = X + count_left;
					count_left = 0;
					isleft = true;

				}

				if (arr_move[Y][X] == Hit && isright == false) {
					X = X + 1;
					count_right++;
					break;
				}
				else {
					X = X - count_right;
					count_right = 0;
					isright = true;
					break;
				}

			}

		}

		if (game[Y][X] != Hit && game[Y][X] != Miss_Point && game[Y][X] != Burst) {


			if (game[Y][X] == Ship) {
				cout << "\a";
				game[Y][X] = Hit;
				arr_move[Y][X] = Hit;
				hasHit_rival = 1;
				count_gamer--;
				if (hasWonRival(count_gamer)) {
					mysetcolor(4, 0);
					cout << "                THE RIVAL HAS COMPLETED THE GAME ---> ALL SHIPS HAVE SUCCESSFULLY BEEN BURST !!!" << endl;
					mysetcolor(7, 0);
				}

				if (game[Y + 1][X] == Ship || game[Y + 1][X] == Hit || game[Y + 1][X] == Miss_Point) {
					for (size_t i = 0; i < 10; i++)
					{

						if (game[Y + i + 1][X] == 0 || game[Y + i + 1][X] == Miss_Point) {
							break;
						}
						if (game[Y + i + 1][X] == Ship) {
							count++;
						}
					}
				}


				if (game[Y][X + 1] == Ship || game[Y][X + 1] == Hit || game[Y][X + 1] == Miss_Point) {
					for (size_t i = 0; i < 10; i++)
					{
						if (game[Y][X + 1 + i] == 0 || game[Y][X + 1 + i] == Miss_Point) {
							break;
						}
						if (game[Y][X + i + 1] == Ship) {
							count++;
						}
					}
				}

				if (game[Y - 1][X] == Ship || game[Y - 1][X] == Hit || game[Y - 1][X] == Miss_Point) {
					for (size_t i = 0; i < 10; i++)
					{
						if (game[Y - 1 - i][X] == 0 || game[Y - 1 - i][X] == Miss_Point) {
							break;
						}
						if (game[Y - i - 1][X] == Ship) {
							count++;
						}
					}
				}


				if (game[Y][X - 1] == Ship || game[Y][X - 1] == Hit || game[Y][X - 1] == Miss_Point) {
					for (size_t i = 0; i < 10; i++)
					{
						if (game[Y][X - 1 - i] == 0 || game[Y][X - 1 - i] == Miss_Point) {
							break;
						}
						if (game[Y][X - i - 1] == Ship) {
							count++;
						}
					}
				}
				cout << count;
				if (count == 0) {
					count_down = 0;
					count_up = 0;
					count_right = 0;
					count_left = 0;
					isdown = 0;
					isup = 0;
					isright = 0;
					isleft = 0;
					MakeMissPoint();
					for (size_t i = 0; i < s2; i++)
					{
						for (size_t k = 0; k < s2; k++)
						{
							arr_move[i][k] = 0;
						}
					}
					cout << "                        Success For Rival -->> SHIP HAS BEEN BURST ";
					Beep(600, 555); // 523 hertz (C5) for 500 milliseconds     
					cin.get(); // wait 
					system("pause");
					int j = 0;
					while (true) {
						bool isFalse = 0;

						if (game[Y + j][X] == Hit) {
							if (game[Y + j][X] == 0 || game[Y + j][X] == Miss_Point) {
								break;
							}
							isFalse = 1;
							game[Y + j][X] = Burst;
						}
						if (game[Y - j][X] == Hit) {
							if (game[Y - j][X] == 0 || game[Y - j][X] == Miss_Point) {
								break;
							}
							isFalse = 1;
							game[Y - j][X] = Burst;
						}
						if (game[Y][X + j] == Hit) {
							if (game[Y][X + j] == 0 || game[Y][X + j] == Miss_Point) {
								break;
							}
							isFalse = 1;
							game[Y][X + j] = Burst;
						}
						if (game[Y][X - j] == Hit) {
							if (game[Y][X - j] == 0 || game[Y][X - j] == Miss_Point) {
								break;
							}
							isFalse = 1;
							game[Y][X - j] = Burst;
						}

						if (isFalse == 0) {
							break;
						}
						j++;
					}
				}


				break;
			}
			else {
				game[Y][X] = Miss_Point;
				arr_move[Y][X] = Miss_Point;
				hasHit_rival = 0;
				break;
			}
		}
		else {
			continue;
		}
	}

}





void StartLoop() {

	while (true) {

		while (true) {
			Sleep(1000);
			system("cls");
			GameAreaPlayer(game, count_gamer);
			GameAreaPlayer(game_opponent, count_rival);

			int cordination = 0;
			cout << "Enter number position: ";
			cin >> cordination;

			char letter = 0;
			cout << "Enter letter position: ";
			cin >> letter;

			HitShipGamer(game, game_opponent, cordination, letter, hasHit);
			if (hasHit == 1) {
				continue;
			}
			else {
				break;
			}

		}
		while (true) {
			Sleep(1200);
			system("cls");
			GameAreaPlayer(game, count_gamer);
			GameAreaPlayer(game_opponent, count_rival);
			HitShipRival(game, game_opponent, hasHit_rival);
			if (hasHit_rival == 1) {
				continue;
			}
			else {
				break;
			}

		}
	}
}

int ship_size = 4;
int iteration = 1;

int ship_size1 = 4;
int iteration1 = 1;

int ship_size_rival = 4;
int iteration_rival = 1;

void main() {
	system("cls");

	mysetcolor(2, 0);
	ShowMenu();

	int select = 0;
	cout << "Enter option: ";
	cin >> select;

	if (select == 1) {

		while (ship_size < 5) {

			for (int k = 0; k < iteration; k++)
			{
				system("cls");
				GameAreaPlayer(game, count_gamer);

				cout << "For " << ship_size << "-sized ship " << endl;

				int cordination = 0;
				cout << "Enter number position: ";
				cin >> cordination;


				char letter = ' ';
				cout << "Enter letter position: ";
				cin >> letter;

				char direction = _getch();
				direction = _getch();
				int no = direction;
				if (isEmptyAuto(letter, cordination, ship_size, no, game)) {

					SetShip(cordination, letter, direction, ship_size, k, game);
				}
				else {
					k--;
					cout << "Please Try Again " << endl;
					system("pause");
					continue;
				}

			}
			iteration++;
			ship_size--;

			if (ship_size == 0) {
				break;
			}
		}

		srand(time(0));
		int random_x_rival = 0;
		char random_letter_rival = 0;

		while (ship_size_rival != 0) {
			for (int j = 0; j < iteration_rival; j++)
			{

				random_x_rival = 1 + rand() % (11 - 1);

				random_letter_rival = 65 + rand() % (74 - 65);
				X_rival = random_x_rival;

				int arr[4] = { UP,DOWN,LEFT,RIGHT };
				int random_rival = 0 + rand() % (3 - 0);
				int random_no_rival = arr[random_rival];

				if (isEmptyAuto(random_letter_rival, X_rival, ship_size_rival, random_no_rival, game_opponent)) {

					SetShip(X_rival, random_letter_rival, random_no_rival, ship_size_rival, j, game_opponent);
				}
				else {
					j--;
					continue;
				}
			}
			iteration_rival++;
			ship_size_rival--;
			if (ship_size_rival == 0) {
				break;
			}
		}

	}
	else if (select == 2) {
		system("pause");
		GameAreaPlayer(game, count_gamer);


		srand(time(0));
		int random_x = 0;
		int random_y = 0;
		char random_letter = 0;

		while (ship_size != 0) {
			for (int k = 0; k < iteration1; k++)
			{
				system("cls");
				GameAreaPlayer(game, count_gamer);
				random_x = 1 + rand() % (11 - 1);

				random_letter = 65 + rand() % (74 - 65);
				X_copy = random_x;

				int arr[4] = { UP,DOWN,LEFT,RIGHT };
				int random = 0 + rand() % (3 - 0);
				int random_no = arr[random];

				if (isEmptyAuto(random_letter, X_copy, ship_size1, random_no, game)) {

					SetShip(X_copy, random_letter, random_no, ship_size1, k, game);
				}
				else {
					k--;
					continue;
				}
			}
			iteration1++;
			ship_size1--;
			if (ship_size1 == 0) {
				system("cls");
				GameAreaPlayer(game, count_gamer);
				break;
			}
		}

	}
	else {
		cout << "Please, enter valid number !" << endl;
	}

	// OPPONENT AREA
	srand(time(0));
	int random_x_rival = 0;
	char random_letter_rival = 0;

	while (ship_size_rival != 0) {
		for (int j = 0; j < iteration_rival; j++)
		{

			random_x_rival = 1 + rand() % (11 - 1);

			random_letter_rival = 65 + rand() % (74 - 65);
			X_rival = random_x_rival;

			int arr[4] = { UP,DOWN,LEFT,RIGHT };
			int random_rival = 0 + rand() % (3 - 0);
			int random_no_rival = arr[random_rival];

			if (isEmptyAuto(random_letter_rival, X_rival, ship_size_rival, random_no_rival, game_opponent)) {

				SetShip(X_rival, random_letter_rival, random_no_rival, ship_size_rival, j, game_opponent);
			}
			else {
				j--;
				continue;
			}
		}
		iteration_rival++;
		ship_size_rival--;
		if (ship_size_rival == 0) {
			break;
		}
	}
	system("cls");
	GameAreaPlayer(game, count_gamer);
	GameAreaPlayer(game_opponent, count_rival);

	int option = 0;
	cout << "Enter 1 to play: ";
	cin >> option;
	if (option == 1) {

		StartLoop();
	}
}