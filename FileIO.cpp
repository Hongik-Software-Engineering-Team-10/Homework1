#include "FileIO.h"

FileIO::FileIO(const char* inputFile, const char* outputFile)
{
	in = fopen(inputFile, "r+");
	out = fopen(outputFile, "w+");
};
FileIO::~FileIO() {}

FileIO* FileIO::instance = nullptr;

FileIO* FileIO::getInstance()
{
	if (instance == nullptr)
	{
		instance = new FileIO(INPUT_FILE_NAME, OUTPUT_FILE_NAME);
	}
	return instance;
}

void FileIO::scanf(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vfscanf(in, format, args);
	va_end(args);
}

void FileIO::printf(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vfprintf(out, format, args);
	va_end(args);
}

void FileIO::close()
{
	fclose(in);
	fclose(out);
	in = out = NULL;

	delete instance;
	instance = nullptr;
}