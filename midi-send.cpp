#include <iostream>
#include <vector>
#include "RtMidi.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << argv[0] << " \"midi port name\"" << endl;
    exit(1);
  }

  string portName(argv[1]);
  RtMidiOut *out = nullptr;

  try {
    out = new RtMidiOut();
  } catch (RtMidiError &error) {
    error.printMessage();
    exit(1);
  }

  bool success = false;
  for (unsigned i = 0; i < out->getPortCount(); i++) {
    cout << "port: " << out->getPortName(i);
    if (portName == out->getPortName(i)) {
      out->openPort(i);
      cout << " <==========";
    }
    cout << endl;
  }
  if (!success)  //
    exit(1);

  vector<unsigned char> message;
  message.clear();
  message.push_back(0xF6);
  out->sendMessage(&message);

  // while true read hex

  /// XXX this program is unfinished

  getchar();  // wait for ENTER

  return 0;
}
