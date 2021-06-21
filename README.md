# Biofeedback Gaming
This project is designed to play Wii games using the electrical signals generated from muscle contractions. 
It has so far been tested with Super Mario Bros and Super Smash Bros Brawl.

## Motivation
The initial motivation behind this project was to develop a workshop to provide first and second year students at McMaster University the opportunity to work on a hands-on biomedical engineering project which is not typically introduced until fourth year. After speaking to graduates and current fourth year students in the biomedical and electrical engineering program, there is a consensus on wanting more exposure to technical projects earlier in their degree. Having experience with the hardware and software components introduced in this workshop will give students a leg up during their co-op term as well as motivate them to explore other projects on their own.

## Project Details
The EMG* signal is measured using electrodes attached to the arm and processed and filtered using an  OpenBCI Ganglion Board. OpenBCI is an open-source braincomputer interface platform that provides anyone  with a computer, the tools necessary to sample the electrical activity of their body. The OpenBCI Ganglion Board is a four channel biosensing device compatible with their open source software. The EMG data collected from the boards is sent to a PC through Bluetooth and serially transmitted to the Arduino via a COM port. By programming the Arduino, the board will “press a button” by generating voltage to the digital output pin connected to the Wii remote when a muscle is flexed.

The project can either be built with one user controlling all 4 inputs or 4 users controlling a single input. The later can be done by making sure there is a shared common ground electrode. 

## Materials
 4 LEDs (for testing)

 4x3 Electrodes + pads

 10 Male to male wires (4xArduino, 2x Ground, 4x Ground for Open BCI)

 4 Resistors (10k)

 1 Breadboard

 1 OpenBCI Ganglion Board

 1 Bluetooth Dongle

 1 Arduino Uno Rev 3

 1 USB 2.0 CABLE TYPE A/B

 1 Wiimote

## Future Applications
Since the OpenBCI Boards are capable of EMG, ECG* and EEG* readings, the workshop can be modified to control other devices with the electrical signals from our muscle, heart or brain. For example, the workshop can be modified with the same OpenBCI board and Arduino to control RC cars with our thoughts (EEG) or monitor our exercise intensity by measuring our heart rate (ECG). 

## Definitions*
Electromyography (EMG) - is a biomedical signal that measures electrical currents generated in muscles during its contraction representing neuromuscular activities.

Electrocardiography (ECG) - is the process of producing an electrocardiogram, a recording – a graph of voltage versus time of the electrical activity of the heart using electrodes placed on the skin

Electroencephalography (EEG) - is an electrophysiological monitoring method to record electrical activity of the brain.
