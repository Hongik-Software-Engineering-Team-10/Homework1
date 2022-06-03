#pragma once
#include <cstdio>
#include <cstdarg>

#define	INPUT_FILE_NAME		"input.txt"
#define	OUTPUT_FILE_NAME	"output.txt"

class FileIO
{
private:
	FileIO(const char* inputFile, const char* outputFile);
	~FileIO();

	static FileIO* instance;

	FILE* in;
	FILE* out;

public:
	static FileIO* getInstance();

	void scanf(const char* format, ...);
	void printf(const char* format, ...);
	void close();
};
