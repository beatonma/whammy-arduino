# whammy-arduino

A MIDI controller for the Digitech Whammy IV effects pedal.

[Demo on Youtube](https://www.youtube.com/watch?v=WNatA7jqHCU "Nauseating audio demo")

<span>
  <img src="https://user-images.githubusercontent.com/12682046/166830486-349c0bfd-688f-4219-9405-855be94ce52e.jpg" width="300" alt="Pedal externals" />
  <img src="https://user-images.githubusercontent.com/12682046/166830256-3dd194d0-3b77-40a5-a1a9-1d1ff3e3b783.jpg" width="300" alt="Pedal guts"/>
</span>


The implementation currently provides these modes:
- Active (LED blue): Ramp towards toe-down when active, ramp towards heel-down when inactive.
- Waves (LED white):
  - Sine: ramp up and down following a nice smooth sine wave `/‾\_/‾\_`
  - Sawtooth up: linear ramp up, immediate return to zero `//// `
  - Sawtooth down: linear ramp down, immediate return to maximum `\\\\ 
  - Triangle: linear ramp up and down `/\/\/`
- Sequencer (LED red):
  - Square `_‾_‾`
  - "Map of the Problematique"
  - Octaves `-2`, `-1`, `0`, `+1`, `+2`
  - Random sequence
- Scale (LED yellow): Random pedal positions quantised to a musical mode (Phrygian, Lydian, etc)
- Random position (LED green): unquantised, random pedal positions.
- 'Chaos' (LED cyan): random selection from the above modes.

### Hardware

- [Wiring diagram here](./wiring-diagram.svg)
- Arduino Nano clone
- 3 momentary buttons
- One linear potentiometer
- MIDI port
- RGB LED
- A few resistors, wire, case, etc.

### Controls

**On/off**: activate the pedal.  
**Modifier + On/off**: Toggle between momentary and latching activation. Momentary/latching mode persists in EEPROM between sessions so you don't need to change it every time.

**Mode**: move to the next pedal mode.  
**Modifier + Mode**: move to previous mode.

**Tempo potentiometer**: Turn to change speed of all pedal functions.  
**Modifier + Tempo potentiometer**: Limit the maximum range of the pedal position for _tasteful vibrato-like operation_ <sup>\[citation needed\]</sup>.

**Modifier**: Tap to change the musical mode used in 'quantized scale' mode.

In all modes, the LED brightness indicates the effective position of the pedal - brighter means toe-down, darker means heel-down.

### monitor.pd

If you want to work on this project without going mad from constant
atonal wee-woo noises, open `monitor.pd` with
[Pure Data](https://puredata.info/) to see a visualisation of the
MIDI messages instead.

<img src="https://user-images.githubusercontent.com/12682046/164093582-a64960d4-7681-49a6-aa1f-fbc980e40858.png" width="300" alt="Visualisation with Pure Data" />

---

This project kept me busy while isolating with Covid 19 in April 2022. The illness provided some gnarly headaches and this project did not help with that whatsoever. Fun though.
