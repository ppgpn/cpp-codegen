#ifndef STRING_EXEC_H
#define STRING_EXEC_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <dlfcn.h>
#include <streambuf>
#include <sstream>
//class StringCompile
class StringExec
{
	std::stringstream program;
	std::stringstream cmp_cmd;
	std::string sav_dir;
	std::string sav_name;

	public:
	StringExec(const char* cmpflagfile= "../cmpflags.txt", const char* sav_dir_arg = "/tmp/cpp-codegen", const char* sav_name_arg = "tmp" );
	~StringExec();
	void append_str(std::string str);
	void append_file(const char* file);
	void file2string(const char* file, std::string* string);
	void replace(const std::string& from, const std::string& to);
	void save();
	void print();
	void compile(int verbose=1);
	void clear();
//};
//class StringExec
//{
	void* fnhandle;

	public:
	void (*func)(...);
	void openlib(const char* filename = "/tmp/cpp-codegen/libtmp.so");
	void loadlib(const char* libname);
	void closelib();
};
#endif
