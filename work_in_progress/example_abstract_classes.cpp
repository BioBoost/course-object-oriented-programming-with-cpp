#include <iostream>

using namespace std;

class Transceiver {
  public:
    virtual void send_message(std::string message) = 0;
};

class FakeTransceiver : public Transceiver {
  public:
    virtual void send_message(std::string message) {
      // DO nothing here, its all fake
    }
};

class TerminalTransceiver : public Transceiver {
  public:
    virtual void send_message(std::string message) {
      std::cout << "Message = " << message << std::endl;
    }
};

class SomeClassThatUsesTransceiver {
  public:
    SomeClassThatUsesTransceiver(Transceiver * transceiver) {
      this->transceiver = transceiver;
    }

  public:
    void update(void) {
      transceiver->send_message("Using some transceiver");
    }

  private:
    Transceiver * transceiver;
};

int main(void) {
  FakeTransceiver fake;
  TerminalTransceiver terminal;

  SomeClassThatUsesTransceiver sample1(&fake);
  sample1.update();
  sample1.update();
  sample1.update();

  SomeClassThatUsesTransceiver sample2(&terminal);
  sample2.update();
  sample2.update();
  sample2.update();

  return 0;
}
