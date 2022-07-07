# ReactiveAT

[![PlatformIO Registry](https://badges.registry.platformio.org/packages/ddododvic/library/ReactiveRelay.svg)](https://registry.platformio.org/libraries/ddododvic/ReactiveRelay)
[![GitHub issues](https://img.shields.io/github/issues/TD-FL/ReactiveRelay.svg)](https://github.com/TD-FL/ReactiveRelay/issues)
[![License](https://img.shields.io/badge/licence-Apache%202.0-blue)](https://github.com/TD-FL/ReactiveRelay/blob/master/LICENSE)


Reactive Non Blocking Relay Library for Arduino Framework.

## Features

- Reactive non blocking code (no more sleep/delay or interrupts)
- Custom click duration
- It's a relay library

## Example

```c++
#include <Arduino.h>
#include <ReactiveRelay.h>

Relay relay(LED_BUILTIN, false);

void setup() {
  relay.on();
  relay.off();
  relay.click();
  relay.click(300);
}

void loop() {
  relay.poll();
}
```