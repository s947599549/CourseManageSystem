#include "CMD.h"
using namespace std;

vector<string> CMD::information = { "Print help information",
								    "List all courses",
								    "Print detailed course information by ID",
								    "Print detailed course information by name",
								    "Delete course by ID",
								    "Delete course by name",
								    "Add course",
								    "Exit" };

CMD::CMD(ifstream& infile) :cm(infile) {

}

void CMD::PrintHelpInfor() const {
	int sz = information.size();
	for (int i = 0; i < sz; ++i) {
		cout << " " << i << " " << information[i] << endl;
	}
}

void CMD::AddCourseKind() {
	cout << " 0 " << "Basic course" << endl;
	cout << " 1 " << "Project course" << endl;
	cout << " 2 " << "Judge course" << endl;
	cout << "Choose the kind of course:";
	int num;
	cin >> num;
	string name;
	cout << "Input course name:";
	cin >> name;
	cout << "    ";
	shared_ptr<Course> sp;
	if (num == 0) {
		sp = make_shared<Course>(Course(name));
	}
	else if (num == 1) {
		cout << "Input course tag:";
		int tag;
		cin >> tag;
		sp = make_shared<ProjectCourse>(ProjectCourse(name, tag));
	}
	else if (num == 2) {
		cout << "Input course time:";
		int time;
		cin >> time;
		sp = make_shared<JudgeCourse>(JudgeCourse(name, time));
	}
	cm.AddCourse(sp);
}

void CMD::ProcessCommand() {
	cout << "--------------------------------" << endl;
	PrintHelpInfor();
	cout << "--------------------------------" << endl;
	while (true) {
		int number;
		cout << "Command Number:";
		cin >> number;
		cout << endl;
		if (number == 0)
			PrintHelpInfor();
		else if (number == 1)
			cm.PrintCourseTable();
		else if (number == 2) {
			int id;
			cout << "Input course ID:";
			cin >> id;
			if (cm.PrintCourseInfo(id) == 0)
				cout << "Course ID not exist" << endl;
		}
		else if (number == 3) {
			string name;
			cout << "Input course name:";
			cin >> name;
			if (cm.PrintCourseInfo(name) == 0)
				cout << "Course name not exist" << endl;
		}
		else if (number == 4) {
			int id;
			cout << "Input course ID:";
			cin >> id;
			if (cm.DeleteCourse(id) == 0)
				cout << "Course ID not exist" << endl;
		}
		else if (number == 5) {
			string name;
			cout << "Input course name:";
			cin >> name;
			if (cm.DeleteCourse(name) == 0)
				cout << "Course name exist" << endl;
		}
		else if (number == 6) {
			AddCourseKind();
		}
		else if (number == 7)
			return;
		else
			cout << "Input wrong" << endl;
		cout << "---------------------------------" << endl;
	}
}