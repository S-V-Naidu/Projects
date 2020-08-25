#include<iostream>
//#include<bits/stdc++.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

namespace games {
	#define x 3
	class tic_tac_toe {
	public:
		int a, b, d, e, f;
		char q[x][x];
		int c[10];
		void display() {
			system("CLS");
			cout << endl;
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < x; j++) {
					cout << "| ";
					cout << q[i][j];
					cout << " |";
				}
				cout << endl << "_______________" << endl;
			}
		}
		void initialize() {
			f = 49;
			for (int i = 0; i < 9; i++)
				c[i] = 0;
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < x; j++) {
					q[i][j] = f;
					f++;
				}
			}
			d = -1;
			e = 0;
			f = 0;
		}
		void getdata1() {
			cout << "Player 1 turn: (Enter your box of choice)\n";
			cin >> a;

				//cin >> a;
		}
		void getdata2() {
			cout << "Player 2 turn: (Enter your box of choice)\n";
			cin >> b;
		}
		void traverse1() {
			for (int i = 0; i <= d; i++) {
				if (a == c[i]) {
					cout << "Cannot use the same number\n";
					e = 1;
				}
				else
					continue;
			}
			if (e != 1) {
				c[++d] = a;
				f++;
				switch (a) {
				case 1:
					q[0][0] = 120;
					break;
				case 2:
					q[0][1] = 120;
					break;
				case 3:
					q[0][2] = 120;
					break;
				case 4:
					q[1][0] = 120;
					break;
				case 5:
					q[1][1] = 120;
					break;
				case 6:
					q[1][2] = 120;
					break;
				case 7:
					q[2][0] = 120;
					break;
				case 8:
					q[2][1] = 120;
					break;
				case 9:
					q[2][2] = 120;
					break;
				default:
					cout << "Thank you for playing tic-tac-toe!!/n";
					exit(0);
				}
			}
			else {
				e = 0;
				display();
				getdata1();
				traverse1();
			}
		}
		void traverse2() {
			for (int i = 0; i <= d; i++) {
				if (b == c[i]) {
					cout << "Cannot use the same number\n";
					e = 1;
				}
				else
					continue;
			}
			if (e != 1) {
				c[++d] = b;
				f++;
				switch (b) {
				case 1:
					q[0][0] = 111;
					break;
				case 2:
					q[0][1] = 111;
					break;
				case 3:
					q[0][2] = 111;
					break;
				case 4:
					q[1][0] = 111;
					break;
				case 5:
					q[1][1] = 111;
					break;
				case 6:
					q[1][2] = 111;
					break;
				case 7:
					q[2][0] = 111;
					break;
				case 8:
					q[2][1] = 111;
					break;
				case 9:
					q[2][2] = 111;
					break;
				default:
					cout << "Thank you for playing tic-tac-toe!!/n";
					_getch();
					exit(0);
				}
			}
			else {
				e = 0;
				display();
				getdata2();
				traverse2();
			}
		}
		void checking1() {
			int h = 0;
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < x; j++) {
					if (q[i][j] == 120) {
						h = 1;
					}
					else {
						h = 0;
						break;
					}
				}
				if (h == 1) {
					cout << "\nPlayer 1 wins!!\n";
					_getch();
					exit(0);
				}
			}
			h = 0;
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < x; j++) {
					if (q[j][i] == 120) {
						h = 1;
					}
					else {
						h = 0;
						break;
					}
				}
				if (h == 1) {
					cout << "\nPlayer 1 wins!!\n";
					_getch();
					exit(0);
				}
			}
			h = 0;
			for (int i = 0; i < x; i++) {
				if (q[i][i] == 120) {
					h = 1;
				}
				else {
					h = 0;
					break;
				}
			}
			if (h == 1) {
				cout << "\nPlayer 1 wins!!\n";
				_getch();
				exit(0);
			}
			h = 0;
			int v = 2;
			for (int i = 0; i < x; i++) {
				if (q[i][v] == 120) {
					h = 1;
				}
				else {
					h = 0;
					break;
				}
				v--;
			}
			if (h == 1) {
				cout << "\nPlayer 1 wins!!\n";
				_getch();
				exit(0);
			}
			if (f == 9) {
				cout << "\nMatch draw!!\n";
				_getch();
				exit(0);
			}
		}
		void checking2() {
			int l = 0;
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < x; j++) {
					if (q[i][j] == 111) {
						l = 1;
					}
					else {
						l = 0;
						break;
					}
				}
				if (l == 1) {
					cout << "\nPlayer 2 wins!!\n";
					_getch();
					exit(0);
				}
			}
			l = 0;
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < x; j++) {
					if (q[j][i] == 111) {
						l = 1;
					}
					else {
						l = 0;
						break;
					}
				}
				if (l == 1) {
					cout << "\nPlayer 2 wins!!\n";
					_getch();
					exit(0);
				}
			}
			l = 0;
			for (int i = 0; i < x; i++) {
				if (q[i][i] == 111) {
					l = 1;
				}
				else {
					l = 0;
					break;
				}
			}
			if (l == 1) {
				cout << "\nPlayer 2 wins!!\n";
				_getch();
				exit(0);
			}
			l = 0;
			int y = 2;
			for (int i = 0; i < x; i++) {
				if (q[i][y] == 111) {
					l = 1;
				}
				else {
					l = 0;
					break;
				}
				y--;
			}
			if (l == 1) {
				cout << "\nPlayer 2 wins!!\n";
				_getch();
				exit(0);
			}
			if (f == 9) {
				cout << "\nMatch draw!!\n";
				_getch();
				exit(0);
			}
		}
	};

}
