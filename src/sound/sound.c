#include "sound.h"

SoundFunctions sound;

void sound_initialize() {
	sound_wav_initialize();
	sound.wav = wav_functions;
}
