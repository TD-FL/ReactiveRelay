#include <ReactiveRelay.h>

Relay::Relay(uint8_t pin) {
    this->_pin = pin;
    pinMode(this->_pin, OUTPUT);
    digitalWrite(this->_pin, HIGH);
}

Relay::Relay(uint8_t pin, bool onIsLow) {
    this->_pin = pin;
    this->_onIsLow = onIsLow;
    pinMode(this->_pin, OUTPUT);
    digitalWrite(this->_pin, HIGH);
}

void Relay::click() {
    this->on();
    this->_timer.in(
        200, [](Relay *relay) -> bool { relay->off(); return false; }, this);
}

void Relay::click(unsigned long ms) {
    this->on();
    this->_timer.in(
        ms, [](Relay *relay) -> bool { relay->off(); return false; }, this);
}

void Relay::on() {
    digitalWrite(this->_pin, this->_onIsLow ? LOW : HIGH);
}

void Relay::off() {
    digitalWrite(this->_pin, this->_onIsLow ? HIGH : LOW);
}

void Relay::poll() {
    _timer.tick();
}

Relay::~Relay() {
    _timer.cancel();
}