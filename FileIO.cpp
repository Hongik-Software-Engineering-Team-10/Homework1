#include "FileIO.h"

FileIO::FileIO(const char* inputFile, const char* outputFile)
{
	in = fopen(inputFile, "r+");
	out = fopen(outputFile, "w+");
};
FileIO::~FileIO()
{
	fclose(in);
	fclose(out);
};

FileIO* FileIO::instance = nullptr;

FileIO* FileIO::getInstance()
{
	if (instance == nullptr)
	{
		instance = new FileIO(INPUT_FILE_NAME, OUTPUT_FILE_NAME);
	}
	return instance;
}

int FileIO::scanf(const char* format, ...)
{
	int ret;
	va_list args;
	va_start(args, format);
	ret = vfscanf(in, format, args);
	va_end(args);
	return ret;
}

int FileIO::printf(const char* format, ...)
{
	int ret;
	va_list args;
	va_start(args, format);
	ret = vfprintf(out, format, args);
	va_end(args);
	return ret;
}