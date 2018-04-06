#pragma once

#ifndef _COURSE_H
#define _COURSE_H

#include <iostream>
#include <string>

/*
 * 每门课程有唯一的ID
 * 禁止拷贝与赋值
 * 采用移动拷贝与赋值成员
 */

//基础课
class Course
{
public:
	Course();
	Course(const std::string& _name);
	virtual ~Course() = default;

	//将拷贝构造函数和赋值运算符定义成删除的
	Course(const Course&) = delete;
	Course& operator=(const Course&) = delete;

	//移动构造函数和移动赋值运算符
	Course(Course&& course) noexcept;
	Course& operator=(Course&& course) noexcept;

	//下面两个虚函数派生类不用改写
	virtual void SetName(const std::string& newName);

	virtual std::string GetName() const;

	virtual void PrintInfo() const;

protected:

	int id;
	std::string name;

	static int currentID;
};

//项目课
class ProjectCourse :public Course
{
public:
	ProjectCourse();
	ProjectCourse(const std::string& _name, int _tag);
	~ProjectCourse() = default;

	ProjectCourse(ProjectCourse&& course) noexcept;
	ProjectCourse& operator=(ProjectCourse&& course) noexcept;

	virtual void PrintInfo() const;

private:
	int tag;
};

//评估课
class JudgeCourse :public Course
{
public:
	JudgeCourse();
	JudgeCourse(const std::string& _name, int _time);
	~JudgeCourse() = default;

	JudgeCourse(JudgeCourse&& course) noexcept;
	JudgeCourse& operator=(JudgeCourse&& course) noexcept;

	virtual void PrintInfo() const;
	
private:
	int time;
};


#endif
