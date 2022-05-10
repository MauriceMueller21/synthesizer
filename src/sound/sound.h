#pragma once

#include "wav.h"

typedef struct SoundFunctions {
	WavFunctions wav;
} SoundFunctions;

extern SoundFunctions sound;

void sound_initialize();
