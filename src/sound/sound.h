#pragma once

#include "wav.h"

typedef struct Sound {
	Wav wav;
} Sound;

extern Sound sound;

void sound_initialize();
