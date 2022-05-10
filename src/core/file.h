#pragma once

#include "string_list.h"

typedef struct TextFile {
	char* path;
	char* name;
	int size;
	int number_of_lines;
	char** lines;
	StringList* line_list;
} TextFile;

typedef struct BinaryFile {
	char* path;
	char* name;
	int size;
	unsigned char* bytes;
} BinaryFile;

typedef struct FileFunctions {
	TextFile* (*read_text_file)(char* path, char* name);
	void (*destroy_text_file)(TextFile* file);
	BinaryFile* (*read_binary_file)(char* path, char* name);
	int (*get_size)(char* path, char* name);
	void (*destroy_binary_file)(BinaryFile* file);
} FileFunctions;

extern FileFunctions file_functions;

void core_file_initialize();
