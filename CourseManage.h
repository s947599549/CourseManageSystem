#pragma once

#ifndef _COURSE_MANAGE_H
#define _COURSE_MANAGE_H

#include <memory>
#include <vector>
#include <fstream>
#include "Course.h"

/*
 * ʹ��vector����γ�
 * Ϊ�˷���ɾ����һ��vector���ݳ�Ա����Ϳγ�������Ӧ�����ĳ�ſγ̱�ɾ���ˣ�����Ϊ0
 * Ҫ��֤�ڴ治��й¶������ʹ��shared_ptr��Ϊ�γ�������Ա
 * ʵ�ֵĲ���������ɾ������ӣ���ӡ�γ̱���ӡ�γ���ϸ��Ϣ
 */
 
class CourseManage
{
public:
	//���������ԱĬ�ϵľ͹���
	CourseManage(std::ifstream& infile);

	//��ӿγ�
	inline void AddCourse(std::shared_ptr<Course> spCourse) {
		courses.push_back(spCourse);
		flag.push_back(true);
	}

	//����IDɾ���γ̣�����ɾ���Ŀγ���
	int DeleteCourse(int courseID);

	//���ݿγ���ɾ���γ̣������ж��ſγ̻ᱻɾ��
	int DeleteCourse(const std::string& courseName);

	//��ӡ�γ̱����ش�ӡ�γ���
	int PrintCourseTable() const;

	//����ID��ӡ�γ���ϸ��Ϣ�����ش�ӡ�Ŀγ���
	int PrintCourseInfo(int courseID) const;

	//���ݿγ����ִ�ӡ�γ���Ϣ
	int PrintCourseInfo(const std::string& courseName) const;

	//������������Ҫ

private:
	std::vector<std::shared_ptr<Course> > courses;
	std::vector<bool> flag;

	void init(std::ifstream& infile);
};

#endif