#pragma once

#ifndef _COURSE_MANAGE_H
#define _COURSE_MANAGE_H

#include <memory>
#include <vector>
#include <fstream>
#include "Course.h"

/*
 * 使用vector保存课程
 * 为了方便删除加一个vector数据成员，其和课程容器对应，如果某门课程被删除了，其标记为0
 * 要保证内存不会泄露，我们使用shared_ptr作为课程容器成员
 * 实现的操作包括：删除，添加，打印课程表，打印课程详细信息
 */
 
class CourseManage
{
public:
	//拷贝构造成员默认的就够了
	CourseManage(std::ifstream& infile);

	//添加课程
	inline void AddCourse(std::shared_ptr<Course> spCourse) {
		courses.push_back(spCourse);
		flag.push_back(true);
	}

	//根据ID删除课程，返回删除的课程数
	int DeleteCourse(int courseID);

	//根据课程名删除课程，可能有多门课程会被删除
	int DeleteCourse(const std::string& courseName);

	//打印课程表，返回打印课程数
	int PrintCourseTable() const;

	//根据ID打印课程详细信息，返回打印的课程数
	int PrintCourseInfo(int courseID) const;

	//根据课程名字打印课程信息
	int PrintCourseInfo(const std::string& courseName) const;

	//析构函数不需要

private:
	std::vector<std::shared_ptr<Course> > courses;
	std::vector<bool> flag;

	void init(std::ifstream& infile);
};

#endif