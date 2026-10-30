#include <iostream>
using namespace std;

/* Task 1

struct Points {
	int x;
	int y;
};


int distance(Points a, Points b) {
	double dx = b.x - a.x;
	double dy = b.y - a.y;
	return sqrt(dx * dx + dy * dy);
}
*/


/* Task 2 

struct Fraction {
	int num;   
	int den;   
};

int simplfraction(int a, int b) {
	if (a < 0) a = -a;
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}


Fraction reduce(Fraction c) {
	int reduct = simplfraction(c.num, c.den);
	c.num /= reduct;
	c.den /= reduct;
	return c;
}

Fraction add(Fraction a, Fraction b) {
	return reduce({ a.num * b.den + b.num * a.den, a.den * b.den });
}

Fraction sub(Fraction a, Fraction b) {
	return reduce({ a.num * b.den - b.num * a.den, a.den * b.den });
}

Fraction mul(Fraction a, Fraction b) {
	return reduce({ a.num * b.num, a.den * b.den });
}

Fraction divide(Fraction a, Fraction b) {
	return reduce({ a.num * b.den, a.den * b.num });
}


void print(Fraction c) {
	if (c.num % c.den == 0) {
		cout << c.num / c.den;                
	}
	else if (c.num > c.den) {
		cout << c.num / c.den << " " << c.num % c.den << "/" << c.den;  
	}
	else {
		cout << c.num << "/" << c.den; 
	}
	cout << endl;
}
*/


/* Task 3 
struct WashingMachine {
	char brand[40];
	char color[40];
	int width;         
	int length;       
	int height;       
	int power;        
	int speed;   
	int temperature; 
};

void printMachine(WashingMachine c) {
	cout << "Brand: " << c.brand << endl;
	cout << "Color: " << c.color << endl;
	cout << "Width: " << c.width << " cm" << endl;
	cout << "Length: " << c.length << "cm" << endl;
	cout << "Height: " << c.height << "cm" << endl;
	cout << "Power: " << c.power << " W" << endl;
	cout << "Spin speed: " << c.speed << " rpm" << endl;
	cout << "Temperature: " << c.temperature << " C" << endl;
}
*/



/* Task 4 

struct Animal {
	char name[50]; 
	char species[50];  
	char nickname[50];  
};

void fillAnimal(Animal& a) {
	cout << "Name: ";
	cin >> a.name;
	cout << "Species (cat, dog, bird): ";
	cin >> a.species;
	cout << "Nickname: ";
	cin >> a.nickname;
}

void printAnimal(Animal a) {
	cout << "Name: " << a.name << endl;
	cout << "Species: " << a.species << endl;
	cout << "Nickname: " << a.nickname << endl;
}

void voice(Animal a) {
	if (strcmp(a.species, "cat") == 0) {
		cout << "Meow!" << endl;
	}
	else if (strcmp(a.species, "dog") == 0) {
		cout << "Woof!" << endl;
	}
	else if (strcmp(a.species, "bird") == 0) {
		cout << "Tweet!" << endl;
	}
}
*/



/* Task 5 


union Num {
	int a;
	unsigned int b;
};
*/

/* Task 6 */

struct Student {
	char name[100];
	unsigned int g1 : 4;
	unsigned int g2 : 4;
	unsigned int g3 : 4;
	unsigned int g4 : 4;
	unsigned int g5 : 4;
	unsigned int g6 : 4;
	unsigned int g7 : 4;
	unsigned int g8 : 4;
	unsigned int g9 : 4;
	unsigned int g10 : 4;
};

int getGrade(Student s, int i) {
	switch (i) {
	case 1: return s.g1;
	case 2: return s.g2;
	case 3: return s.g3;
	case 4: return s.g4;
	case 5: return s.g5;
	case 6: return s.g6;
	case 7: return s.g7;
	case 8: return s.g8;
	case 9: return s.g9;
	case 10: return s.g10;
	}
	return 0;
}

void setGrade(Student& s, int i, int value) {
	switch (i) {
	case 1: s.g1 = value; break;
	case 2: s.g2 = value; break;
	case 3: s.g3 = value; break;
	case 4: s.g4 = value; break;
	case 5: s.g5 = value; break;
	case 6: s.g6 = value; break;
	case 7: s.g7 = value; break;
	case 8: s.g8 = value; break;
	case 9: s.g9 = value; break;
	case 10: s.g10 = value; break;
	}
}

void inputGrade(Student& s) {
	cout << "Enter 10 grades (1-12): ";
	for (int i = 1; i <= 10; i++) {
		int value;
		cin >> value;
		if (value < 1 || value > 12) {
			value = 1; 
		}
		setGrade(s, i, value);
	}
}
bool ifDebtor(Student s) {
	for (int i = 1; i <= 10; i++) {
		if (getGrade(s, i) == 1) return true;
	}
	return false;
}

void fillStudent(Student& s) {
	cout << "Enter name: \n";
	cin.getline(s.name, 100);
	inputGrade(s);
}

void printGrades(Student s) {
	cout << "Grades: \n";
	for (int i = 1; i <= 10; i++) {
		cout << getGrade(s, i) << " ";
	}
	cout << endl;
}

void printStudent(Student s) {
	cout << "Name: " << s.name << endl;
	printGrades(s);
}

double average(Student s) {
	int sum = 0;
	for (int i = 1; i <= 10; i++) {
		sum += getGrade(s, i);
	}
	return sum / 10.0;
}

void addStudent(Student arr[], int& count) {
	cout << "Enter full name: ";
	cin.getline(arr[count].name, 100);
	for (int i = 1; i <= 10; i++) {
		setGrade(arr[count], i, 0);   
	}
	count++;
}

void printList(Student arr[], int count) {
	for (int i = 0; i < count; i++) {
		cout << i << ". " << arr[i].name << endl;
	}
}

void printDebtors(Student arr[], int count) {
	cout << "Debtors:" << endl;
	for (int i = 0; i < count; i++) {
		if (ifDebtor(arr[i])) {
			cout << arr[i].name << endl;
		}
	}
}


















int main(){
	/* Task 1 

	Points p1 = { 0, 0 };
	Points p2 = { 3, 4 };

	cout << distance(p1, p2) << endl;
	*/

	/* Task 2 

	Fraction a = { 2, 6 };
	Fraction b = { 12, 4 };

	cout << "Sum: ";        
	print(add(a, b));     
	cout << "Difference: ";
	print(sub(a, b));     
	cout << "Product: ";
	print(mul(a, b));    
	cout << "Quotient: ";
	print(divide(a, b));  

	*/

	/* Task 3 

	WashingMachine c = { "TechMachine", "Grey", 55, 55, 65, 100, 100, 100 };

	cout << "Washing machine:" << endl;
	printMachine(c);

	*/

	/* Task 4 

	Animal a;
	fillAnimal(a);

	cout << "Animal info: \n" << endl;
	printAnimal(a);

	cout << endl;
	voice(a);
	*/

	/* Task 5 

	Num c;
	c.a = -3;

	cout << c.a << endl;   
	cout << c.b << endl;
	*/

	/* Task 6 */

	Student s;
	fillStudent(s);

	cout << "Student info: " << endl;
	printStudent(s);
	cout << "Average: " << average(s) << endl;

	Student group[20];
	int count = 0;

	cin.ignore();

	cout << "Add 2 students:" << endl;
	addStudent(group, count);
	addStudent(group, count);

	cout << "Student list:" << endl;
	printList(group, count);

	for (int i = 0; i < count; i++) {
		cout << "Grades for " << group[i].name << ":" << endl;
		inputGrade(group[i]);
	}

	int num;
	cout << "Enter student number to show grades: \n";
	cin >> num;
	printStudent(group[num]);

	cout << endl;
	printDebtors(group, count);






}

 