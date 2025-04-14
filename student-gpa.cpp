#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <map>
using namespace std;

struct Subject {
	float mark;
	int hours;
	float weight;
	Subject() {};
	Subject(float m, int h) {
		mark = m;
		hours = h;
		weight = markAsGPA() * hours;
	}
	string markAsChar() {
		string mChar;
		if (mark >= 95) mChar = "A+";
		else if (mark >= 85) mChar = "A";
		else if (mark >= 80) mChar = "A-";
		else if (mark >= 77) mChar = "B+";
		else if (mark >= 73) mChar = "B";
		else if (mark >= 70) mChar = "B-";
		else if (mark >= 67) mChar = "C+";
		else if (mark >= 63) mChar = "C";
		else if (mark >= 60) mChar = "C-";
		else if (mark >= 57) mChar = "D+";
		else if (mark >= 53) mChar = "D";
		else if (mark >= 50) mChar = "D-";
		else if (mark >= 0) mChar = "F";
		return mChar;
	}
	float markAsGPA() {
		float mGPA;
		if (mark >= 95) mGPA = 4.2;
		else if (mark >= 85) mGPA = 4;
		else if (mark >= 80) mGPA = 3.75;
		else if (mark >= 77) mGPA = 3.5;
		else if (mark >= 73) mGPA = 3.25;
		else if (mark >= 70) mGPA = 3;
		else if (mark >= 67) mGPA = 2.75;
		else if (mark >= 63) mGPA = 2.5;
		else if (mark >= 60) mGPA = 2.25;
		else if (mark >= 57) mGPA = 2;
		else if (mark >= 53) mGPA = 1.75;
		else if (mark >= 50) mGPA = 1.5;
		else if (mark >= 0) mGPA = 0.5;
		return mGPA;
	}
};

class Student {
	string name;
	map<string, Subject> marks;
	public:
		Student(string n) {
			name = n;
		}
		string getName() { return name; }
		void addMark(string subject_name, float mark, int hours) {
			Subject s(mark, hours);
			marks[subject_name] = s;
		}
		void deleteMark(string subject_name) {
			marks.erase(subject_name);
		}
		void printDetails() {
			float totalWeight = 0;
			float totalHours = 0;
			cout << "=================================================" << endl;
			for(auto pair : marks) {
				string n = pair.first;
				Subject s = pair.second;
				totalWeight += s.weight;
				totalHours += s.hours;
				cout <<"Name: " << n << " \t\t# Mark: " << s.mark << "\t" << s.markAsChar() << " -> " << s.markAsGPA() << endl;
			}
			cout << "=================================================" << endl;
			cout << fixed << setprecision(2) << "GPA: " << ((totalHours == 0) ? 0.0 : (totalWeight/totalHours)) << endl;
		}
};
int main()
{
	string name;
	cout << "Enter your name: ";
	cin >> name;
	cout << endl;
	Student st(name);
	while (true) {
		int choice;
		string n;
		float m;
		int h;
		cout << "Hello "<<st.getName() << "!, Choose:\n1. Add mark\n2. Remove mark\n3. Details\n4. Exit" << endl;
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "Enter subject name: ";
				cin >> n;
				cout << "Enter subject mark: ";
				cin >> m;
				cout << "Enter subject hours: ";
				cin >> h;
				st.addMark(n, m, h);
				break;
			case 2:
				cout << "Enter subject name: ";
				cin >> n;
				st.deleteMark(n);
				break;
			case 3:
				st.printDetails();
				cout << endl << "Enter anything to continue: ";
				cin >> choice;
				break;
			case 4:
				return 0;
		}
		system("cls");
	}
}
