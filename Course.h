#pragma once

#ifndef _COURSE_H
#define _COURSE_H

#include <iostream>
#include <string>

/*
 * ÿ�ſγ���Ψһ��ID
 * ��ֹ�����븳ֵ
 * �����ƶ������븳ֵ��Ա
 */

class Course
{
public:
	Course();
	Course(const std::string& _name);
	virtual ~Course() = default;

	//���������캯���͸�ֵ����������ɾ����
	Course(const Course&) = delete;
	Course& operator=(const Course&) = delete;

	//�ƶ����캯�����ƶ���ֵ�����
	Course(Course&& course) noexcept;
	Course& operator=(Course&& course) noexcept;

	//���������麯�������಻�ø�д
	virtual void SetName(const std::string& newName);

	virtual std::string GetName() const;

	virtual void PrintInfo() const;

protected:

	int id;
	std::string name;

	static int currentID;
};

//��Ŀ��
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

//������
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