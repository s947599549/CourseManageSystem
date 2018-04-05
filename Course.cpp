#include "Course.h"
using namespace std;

int Course::currentID = 1;

Course::Course() :id(currentID++) {

}

Course::Course(const string& _name) : Course() {
	name = _name;
}

Course::Course(Course&& course) noexcept:id(course.id),name(course.name) {
	course.id = 0;
	course.name = "";
}

Course& Course::operator=(Course&& course) noexcept {
	if (this != &course) {
		id = course.id;
		name = course.name;
		course.id = 0;
		course.name = "";
	}
	return *this;
}

void Course::SetName(const string& newName) {
	name = newName;
}

string Course::GetName() const {
	return name;
}

void Course::PrintInfo() const {
	cout << "Basic Course:" << " " << id << " " << name << endl;
}

ProjectCourse::ProjectCourse() :Course() {

}

ProjectCourse::ProjectCourse(const string& _name, int _tag) : Course(_name), tag(_tag) {

}

ProjectCourse::ProjectCourse(ProjectCourse&& course) noexcept {
	id = course.id;
	name = course.name;
	tag = course.tag;
	course.id = 0;
	course.name = "";
	course.tag = 0;
}

ProjectCourse& ProjectCourse::operator=(ProjectCourse&& course) noexcept {
	if (this != &course) {
		id = course.id;
		name = course.name;
		tag = course.tag;
		course.id = 0;
		course.name = "";
		course.tag = 0;
	}
	return *this;
}

void ProjectCourse::PrintInfo() const {
	cout << "Project Course:" << " " << id << " " << tag << " " << name << endl;
}

JudgeCourse::JudgeCourse() :Course() {

}

JudgeCourse::JudgeCourse(const string& _name, int _time) : Course(_name), time(_time) {

}

JudgeCourse::JudgeCourse(JudgeCourse&& course) noexcept {
	id = course.id;
	name = course.name;
	time = course.time;
	course.id = 0;
	course.name = "";
	course.time = 0;
}

JudgeCourse& JudgeCourse::operator=(JudgeCourse&& course) noexcept {
	if (this != &course) {
		id = course.id;
		name = course.name;
		time = course.time;
		course.id = 0;
		course.name = "";
		course.time = 0;
	}
	return *this;
}

void JudgeCourse::PrintInfo() const {
	cout << "Judge Course:" << " " << id << " " << time << " " << name << endl;
}
