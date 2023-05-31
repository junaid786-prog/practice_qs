#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 
// => tower of hinnoi => backtracking => n-queen => knight's tour => maze problem => determinent
// => infix to postfix => n-queen problem => rat in maze => cities destination

// =============================================================================== //
// =============================== recursion applications ======================== //
// =============================================================================== //

// 1. knapsack problem :
	// base case if no element (size = 0) or bag is full or not available (capacity = 0)
	// if last elem has weight > capacity of bag then find from remaining array (not include that) 
	// if not then select max of element having index (size-1) with and without including item into bag 

int knapsack(int weights[], int prices[], int size, int capacity) {
	if (capacity == 0 || size == 0)	return 0;
	else if (weights[size - 1] > capacity)	return knapsack(weights, prices, size - 1, capacity);
	else return max(knapsack(weights, prices, size - 1, capacity), knapsack(weights, prices, size - 1, capacity - weights[size - 1]) + prices[size - 1]);
}

// 2. flood fill algo
#define rows 3
#define cols 3
void floodfill(int arr[rows][cols], int x_axis, int y_axis, int prevcolor, int newcolor) {
	// base case : coordinates of newly point (x, y) should be inside 2d array => (x, y) < (rows, cols)
	if (x_axis < 0 || y_axis < 0 || x_axis >= rows || y_axis >= cols) return;
	if (arr[x_axis][y_axis] != prevcolor) return; // if selected destination has not color as given prev then skip it

	arr[x_axis][y_axis] = newcolor; // change color of selected dest.

	floodfill(arr, x_axis + 1, y_axis, prevcolor, newcolor);
	floodfill(arr, x_axis, y_axis + 1, prevcolor, newcolor);
	floodfill(arr, x_axis - 1, y_axis, prevcolor, newcolor);
	floodfill(arr, x_axis, y_axis - 1, prevcolor, newcolor);
	floodfill(arr, x_axis + 1, y_axis + 1, prevcolor, newcolor);
	floodfill(arr, x_axis - 1, y_axis - 1, prevcolor, newcolor);
	floodfill(arr, x_axis - 1, y_axis + 1, prevcolor, newcolor);
	floodfill(arr, x_axis + 1, y_axis - 1, prevcolor, newcolor);
}

void floodfill(int arr[][cols], int x, int y, int newc) {
	int prevc = arr[x][y];
	if (prevc == newc) return;
	floodfill(arr, x, y, prevc, newc);
}

// 3. tower of hinnoi
void toh(int size, char from_rod, char to_rod, char aux_rod) {
	if (size == 0) return;

	toh(size - 1, from_rod, aux_rod, to_rod);
	cout << "move disk " << size << " from " << from_rod << " to " << to_rod << endl;
	toh(size - 1, aux_rod, to_rod, from_rod);
}

// 4. printing binary octal

#define nmb 8
void print(int number) {
	if (number < nmb) {
		cout << number;
		return;
	}
	print(number / nmb);
	cout << number % nmb;
}

int sumofdigits(int n) {
	if (n < 10) return n;
	int rem = n % 10;
	return sumofdigits(n / 10) + rem;
}

// 5. n-queen problem
#define n 4
bool issafe(int board[n][n], int r, int c) {
	// check if that row don't contain any other queen
	for (int i = 0; i < n; i++)
		if (board[r][i] == 1) return false;
	// check left diagonals
	int i = r, j = c;
	while (i >= 0 && j >= 0) {
		if (board[i][j] == 1) return false;
		i--; j--;
	}

	// check right diagonals 
	i = r; j = c;
	while (i >= 0 && j <= n - 1) {
		if (board[i][j] == 1) return false;
		i--; j++;
	}

	return true;
}
bool nq(int board[n][n], int col) {
	if (col >= n) // all queens are placed
		return true;
	for (int i = 0; i < n; i++) {
		if (issafe(board, i, col)) {
			// do
			board[i][col] = 1;
			// proceed to next col (recur)
			if (nq(board, col + 1)) return true;
			// backtracking (undo)
			board[i][col] = 0;
		}	
	}
	return false;
}

// 6. rat in maze
#define size 4
bool isratsave(int  maze[size][size], int x, int y) {
	if (x < size && y < size && x >= 0 && y >= 0 && maze[x][y] == 1) return true;
	return false;
}
bool ratinmaze(int maze[size][size], int x, int y, int soln[size][size]) {
	if (x == size - 1 && y == size - 1 ) {
		soln[x][y] = 1;
		return true;
	}
	if (isratsave(maze, x, y)) {
		// do
		soln[x][y] = 1;
		// recur
		if (ratinmaze(maze, x + 1, y, soln)) return true;
		if (ratinmaze(maze, x, y + 1, soln)) return true;
		// backtrack
		soln[x][y] = 0;
		return false;
	}
	return false;
}
// 2: end  -1: start 1: able to move 0: not able to move 5: path
bool ratinmaze2(int maze[size][size], int st_x, int st_y, int soln[size][size]) {
	if (st_x == size - 1 && st_y == size - 1 && soln[st_x][st_y] == 5) {
		soln[st_x][st_y] = 5;
		return true;
	}
	
	if (isratsave(maze, st_x, st_y)) {
		// do
		soln[st_x][st_y] = 5;
		// recur
		if (ratinmaze2(maze, st_x + 1, st_y, soln)) return true;
		if (ratinmaze2(maze, st_x, st_y + 1, soln)) return true;
		//if (ratinmaze2(maze, st_x - 1, st_y, soln)) return true;
		//if (ratinmaze2(maze, st_x, st_y - 1, soln)) return true;
		// undo
		soln[st_x][st_y] = 0;
		return false;
	}
	return false;
}
// =============================================================================== //
// =============================== stack applications ============================ //
// =============================================================================== //

// 1. solving infix notation 

int postfixsoln(string exp) {
	stack<int> s;
	
	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == '*' || exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '%') {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			int res = 0;

			switch (exp[i])
			{
			case '*':
				res = a * b;
				break;
			case '+':
				res = a + b;
				break;
			case '-':
				res = a - b;
				break;
			case '/':
				res = a / b;
				break;
			case '%':
				res = a % b;
				break;
			default:
				break;
			}

			s.push(res);
		}
		else {
			int a = static_cast<int>(exp[i]) - 48;
			s.push(a);
		}
	}
	int res = s.top();
	s.pop();
	return res;
}

// 2. conversion of infix to pstfix

int returnprecidence(char op) {
	if (op == '^') return 3;
	else if (op == '/' || op == '*') return 2;
	else if (op == '+' || op == '-') return 1;
	else return -1;
}

string infixtopostfix(string expression) {
	stack<int> s;
	string res;
	
	for (int i = 0; i < expression.length(); i++) {
		char r = expression[i];
		if ((r >= '0' && r <= '9') || (r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z')) {
			res += (expression[i]);
		}
		else if (r == '(') s.push(r);
		else if (r == ')') {
			while (s.top() != '(' && !s.empty()) {
				char top = s.top();
				res += top;
				s.pop();
			}
			s.pop();
		}
		else {
			while (!s.empty() && returnprecidence(expression[i])<= returnprecidence(s.top())) {
				if (r == '^' && s.top() == '^') break;
				else {
					res += s.top();
					s.pop();
				}
			}
			s.push(r);
		}
	}
	while (!s.empty()) {
		res += s.top();
		s.pop();
	}
	return res;
}

// 3. maze problem

#define maze_width 23
#define maze_height 50
class location {
public:
	int x, y;
	location(int a = 0, int b = 0) {
		x = a; y = b;
	}
	bool isvalid() {
		if (this->x >= 0 && this->y >= 0 && x < maze_width && y < maze_height)return true;
		return false;
	}
};

void mazestack(string maze[], location lc) {
	stack<location> loc;
	loc.push(lc);

	while (!loc.empty()) {
		location top_loc = loc.top();
		loc.pop();

		if (maze[top_loc.x][top_loc.y] == 'e')
			break;
		if (maze[top_loc.x][top_loc.y] != 's')
			maze[top_loc.x][top_loc.y] = '<';

		location top(top_loc.x - 1, top_loc.y);
		location down(top_loc.x + 1, top_loc.y);
		location right(top_loc.x, top_loc.y + 1);
		location left(top_loc.x, top_loc.y - 1);

		if(top.isvalid() && (maze[top.x][top.y] == ' ' || maze[top.x][top.y] == 'e'))
			loc.push(top);
		if (down.isvalid() && (maze[down.x][down.y] == ' ' || maze[down.x][down.y] == 'e'))
			loc.push(down);
		if (right.isvalid() && (maze[right.x][right.y] == ' ' || maze[right.x][right.y] == 'e'))
			loc.push(right);
		if (left.isvalid() && (maze[left.x][left.y] == ' ' || maze[left.x][left.y] == 'e'))
			loc.push(left);
	}
}

// 4. balancing parenthisis
bool balancedParen(string exp) {
	stack<char> st;

	for (int i = 0; i < exp.length(); i++) {
		if (st.empty()) {
			st.push(exp[i]);
		}
		else if ((st.top() == '(' && exp[i] == ')') || (st.top() == '{' && exp[i] == '}') || (st.top() == '[' && exp[i] == ']')) {
			st.pop();
		}
		else {
			st.push(exp[i]);
		}
	}
	return st.empty() ? true : false;
}

int main() {
	string maze[23] = { 
		"**************************************************",
		"*******                              ******** ****",
		"******* ************* ************** ******** ****",
		"******* ************* ***          * ***      ****",
		"        ************* **  *******  * *** **** ****",
		"******* *** ***    ** *  ********        **** ****",
		"******* *** ****** ** *  ******************** ****",
		"******* *** ****** **    ******************** ****",
		"******* *** ****** ************************** ****",
		"******* *** **                      ********* ****",
		"***     *** ** **** **** ******************** ****",
		"*** ********** **** ****                ***** ****",
		"*** ********** **** ************************* ****",
		"*** ********** **** ************************* ****",
		"***            **** ************ ************ ****",
		"******** ********** ************ ************ ****",
		"******** ********** ************      ******* ****",
		"********     ****** ************ **** ******* ****",
		"*******************              **** ******* ****",
		"************************************* *******s****",
		"************************************* ************",
		"*************************************            e",
		"**************************************************"
	};

	location stloc;
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (maze[i][j] == 's')
			{
				stloc = location( i, j );
			}
		}
	}

	//mazestack(maze, stloc);

	/*for (int i = 0; i < 23; i++)
	{
		cout << maze[i] << "\n";
	}*/

	int rmaze[n][n] = {
		{1, 1, 1, 0},
		{0, 0, 1, 0},
		{1, 1, 1, 0},
		{0, 1, 2, 1}
	};
	int sol[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) sol[i][j] = 0;
	cout << ratinmaze2(rmaze, 0, 0, sol) << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << sol[i][j] << " ";
		cout << endl;
	}
		

	return 0;
}