#include <Arduino.h>
#include <ReactiveRelay.h>

Relay relay(LED_BUILTIN, false);

void setup() {
  relay.on();
  relay.off();
  relay.click();
}

void loop() {
  relay.poll();
}