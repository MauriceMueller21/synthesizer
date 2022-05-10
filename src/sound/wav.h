#pragma once

#include "../core/file.h"

typedef struct WAVFile {
	BinaryFile* file;
	int mode;
	int channels;
	int sampling_rate;
	int bytes_per_second;
	int bytes_per_sample;
	int bit_depth;
	int data_offset;
	int data_size;
	int found_format;
	int found_data;
} WAVFile;

typedef struct WavFunctions {
	WAVFile* (*read_wav_file)(char* path, char* name);
	void (*print_format_information)(WAVFile* wav);
	void (*destroy_wav_file)(WAVFile* wav);
} WavFunctions;

extern WavFunctions wav_functions;

void sound_wav_initialize();
