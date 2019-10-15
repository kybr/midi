_:
	c++ -std=c++11 midi-listen.cpp RtMidi.cpp -o midi-listen -D__MACOSX_CORE__ -framework CoreMIDI -framework CoreAudio -framework CoreFoundation
