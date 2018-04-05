#include "CourseManage.h"
#include <sstream>
using namespace std;

//文件内每行保存一门课程数据，第一个字符指明课程的种类,第二个单词是name，接下来是tag或time
void CourseManage::init(ifstream& infile) {
	string line;
	while (getline(infile, line)) {
		istringstream inStr(line);
		string courseKind;
		inStr >> courseKind;
		int num = stoi(courseKind);
		string strName;
		inStr >> strName;
		shared_ptr<Course> spCourse;
		if (num == 0)
			spCourse = make_shared<Course>(Course(strName));
		else if (num == 1) {
			string strTag;
			inStr >> strTag;
			spCourse = make_shared<ProjectCourse>(ProjectCourse(strName, stoi(strTag)));
		}
		else {
			string strTime;
			inStr >> strTime;
			spCourse = make_shared<JudgeCourse>(JudgeCourse(strName, stoi(strTime)));
		}
		courses.push_back(spCourse);
	}
}

CourseManage::CourseManage(ifstream& infile) {
	init(infile);
	flag = vector<bool>(courses.size(), true);
}

int CourseManage::DeleteCourse(int ID) {
	if (ID > courses.size() || ID <= 0||flag[ID-1]==false)
		return 0;
	flag[ID - 1] = false;
	return 1;
}

int CourseManage::DeleteCourse(const string& courseName) {
	int count = 0;
	int sz = courses.size();
	for (int i = 0; i < sz; ++i) {
		if (courses[i]->GetName() == courseName&&flag[i]) {
			++count;
			flag[i] = false;
		}
	}
	return count;
}

int CourseManage::PrintCourseTable() const {
	int sz = courses.size(), count = 0;
	for (int i = 0; i < sz; ++i) {
		if (flag[i]) {
			cout << "Course ID:" << i + 1 << " " << "Course Name:" << courses[i]->GetName() << endl;
			++count;
		}
	}
	return count;
}

int CourseManage::PrintCourseInfo(int courseID) const {
	if (courseID <= 0 || courseID > courses.size() || flag[courseID - 1] == false)
		return 0;
	courses[courseID - 1]->PrintInfo();
	return 1;
}

int CourseManage::PrintCourseInfo(const string& courseName) const {
	int sz = courses.size(), count = 0;
	for (int i = 0; i < sz; ++i) {
		if (courses[i]->GetName() == courseName&&flag[i]) {
			courses[i]->PrintInfo();
			++count;
		}
	}
	return count;
}

