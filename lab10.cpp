#include <iostream>
#include <string>
using namespace std;
class Point {
private: // class 안에서만 사용가능
	int x; // 멤버 변수
	int y;
public: // class 안/밖에서 사용가능
// Point() {}
	Point(int _x, int _y) { //constructor: class와 이름이 같다,
	x = _x;
	y = _y;
}
	/*X,Y set함수 구현(함수 1개)*/
	void setXY(int _x, int _y) {
		x = _x;
		y = _y;
	}
	/*X,Y get 함수 각각 구현(함수 2개)*/
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void print() {
		cout << x << ", " << y << endl;
	}
};
int main() {
	Point pt1(1, 2), pt2(3, 4);
	pt1.setXY(10, 20);
	pt1.print();
	pt2.print();
	cout << pt1.getX() << endl;
	cout << pt2.getY() << endl;
	return 0;
}



#include <string>
#include <iostream>
using namespace std;
class Account {
	//private: //멤버변수
	string name;
	string id;
	double balance;
public: // 멤버함수(method)
// 3개의 생성자 구현
	Account() {
		name = "";
		id = "";
		balance = 0;
	}; // 기본생성자. name : "", id : "", balance : 0 으로 초기화
	Account(string _name, string _id) {
		name = _name;
		id = _id;
		balance = 0;
} // name, id 받아오고, balance는 0으로 초기화
	Account(string _name, string _id, int _balance) :name(_name), id(_id)
		, balance(_balance) {};// name, id , balance 받아와서 초기화, balance < 0 인 경우 0으로 초기화
	void deposit(double _amt) { balance += _amt; }
	bool withdraw(double _amt) {
		if (balance - _amt < 0)
			return false;
		balance -= _amt;
		return true;
	}
	void print() {
		cout << name << ", " << id << ", " << balance << endl;
	}
};
int main() {
	Account ac1("배성호", "1002", 5000);
	Account ac2;
	ac2.print();
	ac1.print();
	int depo;
	cout << "예금할 금액을 입력하세요 : ";
	cin >> depo;
	ac1.deposit(depo);
	ac1.print(); // print() 함수로 ac1 출력
	int wdrw;
	cout << "출금할 금액을 입력하세요 : ";
	cin >> wdrw;
	if (!ac1.withdraw(wdrw))
		cout << "잔액이 부족합니다." << endl;
	ac1.print();
	return 0;
}



#include <iostream>
using namespace std;

class CStudent {
private:
	int id;
	string name;
	string major;
public:
	CStudent() :id(2018000000), name("홍길동"), major("컴퓨터공학과") {};
	CStudent(int _id, string _name, string _major) :id(_id), name(_name), major(_major) {};
	void setNumber(int num) {
		id = num;
}
	void setName(string _name) {
		name = _name;
	}
	void setMajor(string _major) {
		major = _major;
	}

	void Display() {
		cout << "학번 :" << id << endl 
		<< "이름 :" << name << endl 
		<< "전공 :" << major << endl<<endl;
	}

	int getNumber() {
		return id;
	}
	string getName() {
		return name;
	}
	string getMajor() {
		return major;
	}
};

int main() {
	CStudent s1; // A
	s1.Display();
	CStudent s2(1999000000, "공지철", "연극영화과"); // B
	s2.Display();
	// C
	s1.setNumber(2006000000);
	s1.setName("민경훈");
	s1.setMajor("포스트모던");
	cout << "학번 :" << s1.getNumber() << endl;
	cout << "이름 :" << s1.getName() << endl;
	cout << "전공 :" << s1.getMajor() << endl;
	return 0;
}



#include <iostream>
using namespace std;

class CStudent {
private:
	int id;
	string name;
	string major;
public:
	CStudent() :id(2018000000), name("홍길동"), major("컴퓨터공학과") {};
	CStudent(int _id, string _name, string _major) :id(_id), name(_name), major(_major) {};
	void setNumber(int num) {
		id = num;
}
	void setName(string _name) {
		name = _name;
	}
	void setMajor(string _major) {
		major = _major;
	}

	void Display() {
		cout << "학번 :" << id << endl 
		<< "이름 :" << name << endl 
		<< "전공 :" << major << endl<<endl;
	}

	int getNumber() {
		return id;
	}
	string getName() {
		return name;
	}
	string getMajor() {
		return major;
	}
};

int main() {
	CStudent s[3]; // 3명의 학생정보를 저장할 class 배열
	int inputNumber; // 키보드로 학번을 입력 받을 변수
	string inputName, inputMajor; // 키보드로 이름, 전공을 입력 받을 변수
	int length = 0; // 현재 입력된 학생의 수
	while (1) { 
		cout << length+1 << " 번째 학생 입력" << endl;
		cout << "학번 : ";
		cin >> inputNumber;
		cout << "이름 : ";
		cin >> inputName;
		cout << "전공 : ";
		cin >> inputMajor;

		if (length != 0) {
			int sum = 0;
			for (int k = 0; k < length; k++) {
				if (s[k].getNumber() == inputNumber) {
					cout << "중복된 학번이 존재합니다" << endl;
					sum++;
				}
			}
			if (sum == 0) {
				s[length].setNumber(inputNumber);
				s[length].setName(inputName);
				s[length].setMajor(inputMajor);
				length++;
			}
		}
		else {
			s[length].setNumber(inputNumber);
			s[length].setName(inputName);
			s[length].setMajor(inputMajor);
			length++;
		}
		if (length == 3) {
			cout << "----모든입력이 완료되었습니다----" << endl;
			for (int k = 0; k < 3; k++) {
				cout << k + 1 << "학생정보" << endl;
				s[k].Display();
			}
			break;

		}
	}
	return 0;
}



#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
	string name;
	int id;
	string major;
	vector<string> subject;
	vector<char> grade;
public:
	Student():name("default"),id(0),major("depart") {}
	Student(string _name, int _id, string _major) {
		name = _name;
		id = _id;
		major = _major;
	}
	void setID(int _id) {
		id = _id;
	}
	void setName(string _name) {
		name = _name;
	}
	void setDpt(string _major) {
		major = _major;
	}
	void print() {
		cout << name << " " << id << " " << major<<endl;
	}

	void addGrade(string _subject, char _grade) {
		grade.push_back(_grade);
		subject.push_back(_subject);
	}
	void printGrades() {
		for (int k = 0; k < (subject.size()); k++) {
			cout << subject[k] << " " << grade[k] << endl;
		}
		cout << "GPA : " << getGPA() << endl;;
	}
	float getGPA() {
		float sum = 0.0;
		int length = grade.size();
		for (auto elem : grade) {
			switch (elem) {
			case 'A':
				sum += 4.0;
				break;
			case 'B':
				sum += 3.0;
				break;
			case 'C':
				sum += 2.0;
				break;
			case 'D':
				sum += 1.0;
				break;
			case 'F':
				sum += 0.0;
				break;

			}
		}
		return sum / (length);
	}
	void getYear(int year) {
	int stuyear = id / 1000000;
	switch (year-stuyear)
		case 0: {
		cout << "Freshman(1학년)" << endl;
		break;
		case 1:
			cout << "Sophomore(2학년)" << endl;
			break;
		case 2:
			cout << "Junior(3학년)" << endl;
			break;
		case 3:
			cout << "Senior(4학년)" << endl;
			break;
		default:
			cout << "About to graduate(5학년)" << endl;
			break;
	}
	}
};


int main() {
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";
	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setID(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Maching Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";
	return 0;
	
}
