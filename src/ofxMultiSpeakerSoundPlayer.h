#pragma once

using namespace std;

#include "ofConstants.h"
#include "ofMath.h"
#include "ofLog.h"

#include "ofSoundBaseTypes.h"

extern "C" {
#include "fmod.h"
#include "fmod_errors.h"
}


class ofxMultiSpeakerSoundPlayer : public ofBaseSoundPlayer {

	public:

		ofxMultiSpeakerSoundPlayer();

		bool load(const std::filesystem::path& fileName, bool stream = false);
		void unload();
		void play();
		void playTo(int speaker);
		void stop();

		void setVolume(float vol);
		void setPan(float vol);
		void setSpeed(float spd);
		void setPaused(bool bP);
		void setLoop(bool bLp);
		void setMultiPlay(bool bMp);
		void setPosition(float pct); // 0 = start, 1 = end;
		void setPositionMS(int ms);

		float getPosition() const ;
		int getPositionMS() const ;
		bool isPlaying() const ;
		float getSpeed() const ;
		float getPan() const ;
		float getVolume() const ;
		bool isLoaded() const ;

		static void initializeFmod();
		static void closeFmod();

		bool isStreaming;
		bool bMultiPlay;
		bool bLoop;
		bool bLoadedOk;
		bool bPaused;
		float pan; // -1 to 1
		float volume; // 0 - 1
		float internalFreq; // 44100 ?
		float speed; // -n to n, 1 = normal, -1 backwards
		unsigned int length; // in samples;

		FMOD_RESULT result;
		FMOD_CHANNEL * channel;
		FMOD_SOUND * sound;

		string currentLoaded;
};
