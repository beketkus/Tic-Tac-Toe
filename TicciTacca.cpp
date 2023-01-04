#include <bits/stdc++.h>

using namespace std;

int PositionPut(int sign, int pos, int a[3][3]){

	if(1 <= pos and pos <= 3){
		for(int i = 0; i < 3; i++){
			a[0][(pos - 1)] = sign;
		}
	}
	else if(4 <= pos and pos <= 6){
		a[1][(pos - 4)] = sign;
	}
	else if(7 <= pos and pos <= 9){
		a[2][(pos - 7)] = sign;
	}


	return 0;
}

void TableDisplay(int a[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(a[i][j] == 1){
				cout << "|X|";
			}
			else if(a[i][j] == 2){
				cout << "|O|";
			}
			else{
				cout << "|.|";
			}
		}
		cout << endl;
	}
}

bool win_pos(int a[3][3], int c){
	if(a[0][0] == c && a[0][1] == c && a[0][2] == c){
		return true;
	}
	else if(a[1][0] == c && a[1][1] == c && a[1][2] == c){
		return true;
	}
	else if(a[2][0] == c && a[2][1] == c && a[2][2] == c){
		return true;
	}
	else if(a[0][0] == c && a[1][0] == c && a[2][0] == c){
		return true;
	}
	else if(a[0][1] == c && a[1][1] == c && a[2][1] == c){
		return true;
	}
	else if(a[0][2] == c && a[1][2] == c && a[2][2] == c){
		return true;
	}
	else if(a[0][0] == c && a[1][1] == c && a[2][2] == c){
		return true;
	}
	else if(a[0][2] == c && a[1][1] == c && a[2][0] == c){
		return true;
	}
	return false;
}
	

bool sig_check(int a[3][3], int c, int pos){
	int k = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(a[i][j] != 0 and k + 1 == pos) return true;
			k++;
		}
	}
	return false;
}



int main() {
	int a[3][3] = { 0 }; 
	
	int position;
	string player1, player2;
	printf("Make a notice: who goes first - puts 'X' and who goes second - puts 'O'\n");
	cout << endl;
	printf("And pay attention that you're pointing the number of position out\n");
	cout << endl;
	 
	 
	 //вывод позиций
	int cnt = 1;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << cnt++ << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	cnt = 9;
	printf("Please, player1 , write your name in\n");
	cin >> player1;
	printf("Please, player2 , write your name in\n");
	cin >> player2;	
	
	//игра
	while(true){
		
				//ХОД ПЕРВОГО ИГРОКА
				
				cout << "Your turn, " << player1 << endl;
				TableDisplay(a);
				cin >> position;
				
				//1)проверка на дурака
				while(sig_check(a,1, position)){
					printf("Position isn't valid, try again\n");
					cin >> position;
				}
				
				//2)вставка позиций
				PositionPut(1, position, a); 
				

				//3)проверка выигрышной позиции
				if(cnt <= 6){
					if(win_pos(a,1) == true){
					TableDisplay(a);
					cout << player1 << " wins" << endl;
					break;
				}
				}
				//4)счетчик действий
				cnt--; 
				if(cnt == 0){
					TableDisplay(a);
					printf("Draw");
					break;
				}
				
				//ХОД ВТОРОГО ИГРОКА
				
				cout << "Your turn, " << player2 << endl;
				TableDisplay(a);
				cin >> position;
				
				//1)проверка на дурака
				while(sig_check(a,2, position)){
					printf("Position isn't valid, try again\n");
					cin >> position;
				}
				
				//2)вставка позиций
				PositionPut(2, position, a);
				
				 //3)проверка выигрышной позиции
				if(cnt <= 6){
				if(win_pos(a,2) == true){
					TableDisplay(a);
					cout << player2 << " wins" << endl;
					break;
					}
				}
				
				//4)счетчик действий
				cnt--; 
				if(cnt == 0){
					TableDisplay(a);
					printf("Draw");
					break;
				}
	}		
}


































