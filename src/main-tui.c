#include "core/core.h"
#include "sound/sound.h"
#include "tui/tui.h"

#include <ncurses.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t input_thread;
bool is_running;
int lines;
int columns;

void initialize();
void update();
void render();
void terminate();
void main_loop();
void* input_loop();

int main(int argc, char** argv) {
	core_initialize();
	sound_initialize();
	tui_initialize();
	char* string1 = core.string.boolean_to_string(true);
	char* string2 = core.string.boolean_to_string(false);
	char* type = "%s";
	char* pattern = core.string.concatenate_strings(type, "\n");
	printf(pattern, string1);
	printf("%s\n", string2);
	int a = 2;
	void* ap = &a;
	ap = &core;
	int* bp = (int*)(ap);
	int b = *bp;
	printf("Pointer: %p\n", ap);
	printf("Integer: %d\n", b);
	printf("Size:    %lu\n", sizeof(ap));
	printf("%s\n", tui.arguments.is_flag(argc, argv, 'a') ? "true" : "false");
	bool isASet = tui.arguments.is_flag(argc, argv, 'a');
	printf("%s\n", core.string.boolean_to_string(isASet));
	printf("Hello World! (%d parameters, %p is the pointer)\n", argc, argv);
	char* path = "../windows95_sounds/";
	char* name = "TADA.WAV";
	printf("Information about %s%s:\n", path, name);
	WAVFile* wav = sound.wav.read_wav_file(path, name);
	sound.wav.print_format_information(wav);
	printf("number of arguments: %d\n", argc);
	if (argc == 1) {
		main_loop();
	} else {
		printf("first argument: %s\n", argv[1]);
	}
	return 0;
}

void main_loop() {
	initialize();
	while (is_running) {
		update();
		render();
		core.time.sleep(1000);
	}
	terminate();
}

void initialize() {
	initscr();
	if (has_colors() == false) {
		printf("Your terminal does not support colors!\r\n");
		exit(1);
	}
	start_color();
	noecho();
	curs_set(1);
	timeout(-1);
	is_running = true;
	pthread_create(&input_thread, NULL, input_loop, NULL);
	lines = LINES;
	columns = COLS;
	printf("Lines:   %d\r\n", LINES);
	printf("Columns: %d\r\n", COLS);
}

void update() {
}

void render() {
	//clear();
	//refresh();
	// draw custom things here
	//refresh();
}

void terminate() {
	pthread_join(input_thread, NULL);
	endwin();
}

int x = 4;
int y = 4;
void* input_loop() {
	while (is_running) {
		int character = getch();
		bool key_pressed = true;
		switch (character) {
		case 't':
			is_running = false;
			break;
		case ' ':
			printf("Hello World!\r\n");
			break;
		case 'w':
			y--;
			move(y, x);
			printf("#");
			refresh();
			break;
		case 'a':
			x--;
			move(y, x);
			printf("#");
			refresh();
			break;
		case 's':
			y++;
			move(y, x);
			printf("#");
			refresh();
			break;
		case 'd':
			x++;
			move(y, x);
			printf("#");
			refresh();
			break;
		default:
			key_pressed = false;
		}
		if (key_pressed) {
			render();
		}
	}
	return NULL;
}
