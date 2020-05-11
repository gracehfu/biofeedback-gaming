# biofeedback gaming
The project is designed to play Wii games using the electrical signal generated from muscle contractions.
It has so far been tested with Super Mario Bros and Super Smash Bros Brawl.

The EMG signal is be measured using electrodes attached to the arm and processed and filtered using an 
OpenBCI Ganglion Board. OpenBCI is an open-source braincomputer interface platform that provides anyone 
with a computer, the tools necessary to sample the electrical activity of their body. The OpenBCI Ganglion 
Board is a four channel biosensing device compatible with their open source software. The EMG data collected
from the boards is sent to a PC through Bluetooth and serially transmitted to the Arduino via a COM port. 
By programming the Arduino, the board will “press a button” by generating voltage to the digital output pin 
connected to the Wii remote when a muscle is flexed.

The project can either be built with one user controlling all 4 inputs or 4 users controlling a single input. 
The later can be done by grounding making sure there is a shared common ground electrode. 
