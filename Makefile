
_: midi-listen midi-send

midi-listen:
	c++ -std=c++11 midi-listen.cpp RtMidi.cpp -o midi-listen -D__MACOSX_CORE__ -framework CoreMIDI -framework CoreAudio -framework CoreFoundation

midi-send:
	c++ -std=c++11 midi-send.cpp RtMidi.cpp -o midi-send -D__MACOSX_CORE__ -framework CoreMIDI -framework CoreAudio -framework CoreFoundation
