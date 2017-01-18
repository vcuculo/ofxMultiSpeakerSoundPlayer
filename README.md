ofxMultiSpeakerSoundPlayer
==========================

8 channel audio output for openFrameworks

Updated to openFrameworks 0.9+

Remember to configure your windows system to 7.1 audio output.

Example:
		
	ofxMultiSpeakerSoundPlayer * audioPlayer;

	audioPlayer = new ofxMultiSpeakerSoundPlayer();

	audioPlayer.load("audio.wav");

	audioPlayer.playTo(0); //rear speakers
	audioPlayer.playTo(1); //side speakers
	audioPlayer.playTo(2); //frontal speakers
	audioPlayer.playTo(3); //central speakers


Tested with openFrameworks 0.9.3 on Windows 10 64bit.

-------------------------

An implementation of ofSoundPlayer using FMod to handle each single speaker connected to a surround sound card.  
For example, with this addon, is possible to send one sound file to the frontal speakers, another sound file to the side speakers etc.  
It provides the following method:

    void playTo(int speaker);

where `speaker` is a value between 0 and 3, with the following meaning:

* **0** send to rear speakers (R+L)
* **1** send to side speakers (R+L)
* **2** send to frontal speakers (R+L)
* **3** send to central speaker

It is designed for a 7.1 surround setup, but can be changed editing the value of `speakerMode` variable from `FMOD_SPEAKERMODE_7POINT1` to one of the `FMOD_SPEAKERMODE` values.  
Another value to configure, is the device index (`deviceNumber`) referring to the used sound card, that can be found with the `FMOD_System_GetDriverInfo` method.

Tested with openFrameworks 0.8.1 on Linux Debian 64bit.
