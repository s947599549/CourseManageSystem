# CourseManageSystem

一个简单课程管理系统，实验楼网站上面的一个小项目


https://www.shiyanlou.com/courses/1052

#暂时不会写makefile，等学会了补上

#编译命令

g++ -std=c++0x -c Course.cpp
g++ -std=c++0x -c CourseManage.cpp
g++ -std=c++0x -c CMD.cpp
g++ -std=c++0x -c main.cpp
g++ -o main main.o CMD.o Course.o CourseManage.o

#运行
./main
