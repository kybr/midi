#include <iostream>
#include <vector>
#include "RtMidi.h"

using namespace std;

void process(double delta, vector<unsigned char> *message, void *) {
  unsigned int nBytes = message->size();
  for (unsigned int i = 0; i < nBytes; i++)
    cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
  if (nBytes > 0) cout << "stamp = " << delta << endl;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << argv[0] << " \"midi port name\"" << endl;
    exit(1);
  }

  string portName(argv[1]);
  RtMidiIn *in = nullptr;

  try {
    in = new RtMidiIn();
  } catch (RtMidiError &error) {
    error.printMessage();
    exit(1);
  }

  bool success = false;
  for (unsigned i = 0; i < in->getPortCount(); i++) {
    cout << "port: " << in->getPortName(i);
    if (portName == in->getPortName(i)) {
      in->openPort(i);
      cout << " <==========";
    }
    cout << endl;
  }
  if (!success)  //
    exit(1);

  cout << "----(ENTER to quit)---------------------" << endl;

  // Don't ignore sysex, timing, or active sensing messages.
  in->ignoreTypes(false, true, true);

  in->setCallback(&process);

  getchar();

  return 0;
}
