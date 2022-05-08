#include "file.h"

#include "core.h"

#include <stdio.h>
#include <stdlib.h>

File file;

void core_file_read_bytes(BinaryFile* file);
int core_file_get_size(char* path, char* name);

BinaryFile* core_file_read_binary_file(char* path, char* name) {
	BinaryFile* file = malloc(sizeof(BinaryFile));
	file->path = path;
	file->name = name;
	file->size = core_file_get_size(file->path, file->name);
	if (file->size == -1) {
		printf("The file \"%s%s\" does not exist!\n", path, name);
		return NULL;
	}
	file->bytes = malloc(file->size);
	core_file_read_bytes(file);
	return file;
}

void core_file_read_bytes(BinaryFile* file) {
	char* full_name = core.string.concatenate_strings(file->path, file->name);
	FILE *real_file = fopen(full_name, "r");
	int index = -1;
	do {
		index++;
		file->bytes[index] = fgetc(real_file);
	} while (index + 1 < file->size);
	if (real_file) {
		fclose(real_file);
	}
}

int core_file_get_size(char* path, char* name) {
	char* full_name = core.string.concatenate_strings(path, name);
	FILE *file = fopen(full_name, "r");
	if (file == NULL) {
		return -1;
	}
	fseek(file, 0, SEEK_END);
	int length = ftell(file);
	fseek(file, 0, SEEK_SET);
	fclose(file);
	return length;
}

void core_file_destroy_binary_file(BinaryFile* file) {
	free(file->bytes);
	free(file);
}

void core_file_initialize() {
	file.read_binary_file = &core_file_read_binary_file;
	file.get_size = &core_file_get_size;
	file.destroy_binary_file = core_file_destroy_binary_file;
}
