#pragma once

/*
typedef struct TextFile {
} TextFile;
*/

typedef struct BinaryFile {
	char* path;
	char* name;
	int size;
	unsigned char* bytes;
} BinaryFile;

typedef struct File {
	BinaryFile* (*read_binary_file)(char* path, char* name);
	int (*get_size)(char* path, char* name);
	void (*destroy_binary_file)(BinaryFile* file);
} File;

extern File file;

void core_file_initialize();
