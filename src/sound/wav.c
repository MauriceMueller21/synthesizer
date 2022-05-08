#include "wav.h"

#include "../core/core.h"

#include <stdio.h>
#include <stdlib.h>

Wav wav;

int sound_wav_parse_wave_data(WAVFile* wav);
int sound_wav_parse_wave_chunk(WAVFile* wav, int offset);

WAVFile* sound_wav_read_wav_file(char* path, char* name) {
	WAVFile* wav = malloc(sizeof(WAVFile));
	BinaryFile* file = core.file.read_binary_file(path, name);
	wav->file = file;
	int success = sound_wav_parse_wave_data(wav);
	if (success) {
		return wav;
	} else {
		return NULL;
	}
}

int sound_wav_parse_wave_data(WAVFile* wav) {
	wav->found_format = 0;
	wav->found_data = 0;
	unsigned char* bytes = wav->file->bytes;
	if (bytes[0] != 'R' || bytes[1] != 'I' || bytes[2] != 'F' || bytes[3] != 'F') {
		printf("WARNING: WAV fils is no RIFF file!\n");
		return 0;
	}
	//printf("WAV file is a RIFF file!\n");
	if (bytes[8] != 'W' || bytes[9] != 'A' || bytes[10] != 'V' || bytes[11] != 'E') {
		printf("WARNING: WAV fils is no WAVE file!\n");
		return 0;
	}
	//printf("WAV file is a WAVE file!\n");
	//printf("file size: %d\n", wav->file->size);
	//printf("wave size: %d\n", get_4byte_little_endian(bytes, 4));
	int offset = 12;
	while (offset < wav->file->size) {
		//printf("Using offset %d\n", offset);
		int chunk_size = sound_wav_parse_wave_chunk(wav, offset);
		if (chunk_size == -2) {
			return 0;
		} else if (chunk_size <= 0) {
			break;
		}
		offset += chunk_size;
	}
	if (wav->found_format == 0) {
		printf("WARNING: Did not find \"fmt \" chunk!\n");
	}
	if (wav->found_data == 0) {
		printf("WARNING: Did not find \"data\" chunk!\n");
	}
	return wav->found_format && wav->found_data;
}

int sound_wav_parse_wave_chunk(WAVFile* wav, int offset) {
	unsigned char* bytes = wav->file->bytes;
	char name[] = "    ";
	name[0] = bytes[offset];
	name[1] = bytes[offset + 1];
	name[2] = bytes[offset + 2];
	name[3] = bytes[offset + 3];
	int chunk_size = core.string.get_4_byte_little_endian(bytes, offset + 4);
	//printf("chunk name: %s\n", name);
	//printf("chunk size: 8+%d\n", chunk_size);
	//printf("Using offset: %d/%d\n", offset, offset + 8);
	offset += 8;
	if (core.string.are_strings_equal(name, "fmt ") == 1) {
		wav->found_format = 1;
		if (chunk_size != 16) {
			printf("WARNING: 'fmt ' block has wrong size!\n");
			return -2;
		}
		wav->mode = core.string.get_2_byte_little_endian(bytes, offset);
		if (wav->mode != 1) {
			printf("WARNING: Unsupported PCM mode (%d)!\n", wav->mode);
			return -2;
		}
		wav->channels = core.string.get_2_byte_little_endian(bytes, offset + 2);
		wav->sampling_rate = core.string.get_4_byte_little_endian(bytes, offset + 4);
		wav->bytes_per_second = core.string.get_4_byte_little_endian(bytes, offset + 8);
		wav->bytes_per_sample = core.string.get_2_byte_little_endian(bytes, offset + 12);
		wav->bit_depth = core.string.get_2_byte_little_endian(bytes, offset + 14);
	} else if (core.string.are_strings_equal(name, "data") == 1) {
		wav->found_data = 1;
		//printf("Setting offset to %d\n", offset);
		wav->data_offset = offset;
		wav->data_size = chunk_size;
	} else if (chunk_size >= 0) {
		//printf("WARNING: Unknown wave chunk: %s\n", name);
	}
	return chunk_size + 8;
}

void sound_wav_print_format_information(WAVFile* wav) {
	printf("File Path:\t%s\n", wav->file->path);
	printf("File Name:\t%s\n", wav->file->name);
	printf("File Size:\t%d\n", wav->file->size);
	printf("Wave Codec:\t%d\n", wav->mode);
	printf("Channels:\t%d\n", wav->channels);
	printf("Sample Rate:\t%d\n", wav->sampling_rate);
	printf("Bytes/Second:\t%d\n", wav->bytes_per_second);
	printf("Bytes/Sample:\t%d\n", wav->bytes_per_sample);
	printf("Bit Depth:\t%d\n", wav->bit_depth);
	printf("Data Offset:\t%d\n", wav->data_offset);
	printf("Data Size:\t%d\n", wav->data_size);
}

void sound_wav_destroy_wav_file(WAVFile* wav) {
	core.file.destroy_binary_file(wav->file);
	free(wav);
}

void sound_wav_initialize() {
	wav.read_wav_file = &sound_wav_read_wav_file;
	wav.print_format_information = &sound_wav_print_format_information;
	wav.destroy_wav_file = &sound_wav_destroy_wav_file;
}
