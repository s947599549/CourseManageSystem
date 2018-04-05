#include "CMD.h"
using namespace std;

int main()
{
	ifstream infile("courses.txt");
	CMD cmd(infile);
	
	cmd.ProcessCommand();
}