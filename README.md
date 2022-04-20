# whammy-arduino

A MIDI controller for the Digitech Whammy IV effects pedal.

<span>
  <img src="https://user-images.githubusercontent.com/12682046/164094312-056a5869-a076-41b6-8458-f2a05f56958b.jpg" width="300" alt="Pedal externals" />
  <img src="https://user-images.githubusercontent.com/12682046/164094408-1f04eb69-766c-47b1-8ecb-b9c5890650ef.jpg" width="300" alt="Pedal guts" />
</span>

The implementation currently provides these modes:

- Saw up: / / / / / / /
- Saw down: \ \ \ \ \ \ \
- Triangle: / \ / \ / \ /
- Sine: like triangle but curvier.
- Square: _ - _ - _ - _
- "Map of the Problematique" sequencer.
- Randomisers:
  - Quantized to a musical mode e.g. Phrygian, Lydian...
  - Unquantized, any pedal position. Bleep bloop.
  - Unquantized, any pedal position, any patch.
  - Chaos randomiser, applying any of the other modes randomly.

### Hardware

- Arduino Nano clone
- 3 momentary buttons
- One linear potentiometer
- MIDI port
- LED
- A few resistors, wire, case, etc.

### Controls

**On/off**: activate the pedal.  
**Modifier + On/off**: Toggle between momentary and latching activation. Default: momentary.

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
