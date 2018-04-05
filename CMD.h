#pragma once

#ifndef _CMD_H
#define _CMD_H

#include "CourseManage.h"

/*
 * 0 Print help information
 * 1 List all courses
 * 2 Print detailed course information by ID
 * 3 Print detailed course information by name
 * 4 Delete course by ID
 * 5 Delete course by name
 * 6 Add course
 * 7 Exit
 */
class CMD
{
public:
	CMD(std::ifstream& infile);

	void ProcessCommand();

private:
	CourseManage cm;
	
	static std::vector<std::string> information;

	void PrintHelpInfor() const;

	void AddCourseKind();
};

#endif