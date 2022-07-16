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
