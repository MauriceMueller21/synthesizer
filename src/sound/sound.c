#include "sound.h"

Sound sound;

void sound_initialize() {
	sound_wav_initialize();
	sound.wav = wav;
}
