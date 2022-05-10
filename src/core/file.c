#include "file.h"

#include "core.h"

#include <stdio.h>
#include <stdlib.h>

FileFunctions file_functions;

CharList* core_file_get_text_file_as_char_list(char* path, char* name);
void core_file_normalize_line_breaks(CharList* list);
StringList* core_file_extract_lines(CharList* characters);
void core_file_read_bytes(BinaryFile* file);
int core_file_get_size(char* path, char* name);

TextFile* core_file_read_text_file(char* path, char* name) {
	TextFile* file = malloc(sizeof(TextFile));
	file->path = path;
	file->name = name;
	CharList* bytes = core_file_get_text_file_as_char_list(path, name);
	core_file_normalize_line_breaks(bytes);
	file->line_list = core_file_extract_lines(bytes);
	file->lines = core.stringlist.to_array(file->line_list);
	file->number_of_lines = core.stringlist.get_length(file->line_list);
	file->size = core.stringlist.get_length_sum(file->line_list);
	return file;
}

CharList* core_file_get_text_file_as_char_list(char* path, char* name) {
	char* full_name = core.string.concatenate_strings(path, name);
	FILE *real_file = fopen(full_name, "r");
	CharList* list = core.charlist.create();
	char current = 0;
	while (current != EOF) {
		current = fgetc(real_file);
		if (current != EOF) {
			core.charlist.add(list, current);
		}
	}
	return list;
}

void core_file_normalize_line_breaks(CharList* list) {
	int length = core.charlist.get_length(list);
	int index = 0;
	while (index < length) {
		char current = core.charlist.get(list, index);
		bool is_last = index == length - 1;
		if (current == 13) {
			if (!is_last && core.charlist.get(list, index + 1) == 10) {
				core.charlist.remove(list, index);
				length--;
				continue;
			} else {
				core.charlist.set(list, index, 10);
			}
		}
		index++;
	}
	if (core.charlist.get(list, length - 1) != 10) {
		core.charlist.add(list, 10);
	}
}

StringList* core_file_extract_lines(CharList* characters) {
	int length = core.charlist.get_length(characters);
	StringList* lines = core.stringlist.create();
	CharList* line = core.charlist.create();
	int index = 0;
	while (index < length) {
		char current = core.charlist.get(characters, index);
		if (current == 10) {
			core.stringlist.add(lines, core.charlist.to_string(line));
			core.charlist.destroy(line);
			line = core.charlist.create();
		} else {
			core.charlist.add(line, current);
		}
		index++;
	}
	core.charlist.destroy(line);
	return lines;
}

void core_file_destroy_text_file(TextFile* file) {
	core.stringlist.destroy(file->line_list);
	free(file->lines);
	free(file);
}

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
	FILE* real_file = fopen(full_name, "r");
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
	FILE* file = fopen(full_name, "r");
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
	file_functions.read_text_file = &core_file_read_text_file;
	file_functions.destroy_text_file = &core_file_destroy_text_file;
	file_functions.read_binary_file = &core_file_read_binary_file;
	file_functions.get_size = &core_file_get_size;
	file_functions.destroy_binary_file = core_file_destroy_binary_file;
}
