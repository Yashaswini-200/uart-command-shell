UART Command Shell

An interrupt-driven UART command shell built in Embedded C using modular driver architecture, ring buffers, and event-driven firmware design.

📌 Project Goal

Build a reusable UART communication framework capable of:

asynchronous UART reception
interrupt-driven data handling
buffered communication
command parsing
event-driven processing

This project focuses on:

firmware architecture + embedded systems design

instead of Arduino-style monolithic code.

🧠 Features
✅ Interrupt-Driven UART RX

UART receive interrupt captures incoming bytes asynchronously.

✅ Ring Buffer Based RX Queue

Incoming UART data safely buffered using producer-consumer FIFO design.

✅ Blocking UART TX

Simple blocking transmit path for reliable serial output.

✅ Modular Driver Architecture

Project separated into:

core layer
driver layer
application layer
✅ Event-Driven Main Loop

Main loop reacts to UART events instead of polling hardware registers directly.

🏗️ Project Structure
project/
│
├── core/
│   ├── ring_buffer.c
│   └── ring_buffer.h
│
├── drivers/
│   ├── uart.c
│   ├── uart.h
│   └── uart_isr.c
│
├── app/
│   ├── command_parser.c
│   ├── command_parser.h
│   ├── command_handler.c
│   └── command_handler.h
│
├── main.c
└── README.md
⚙️ System Architecture
UART Hardware
      ↓
UART RX ISR
      ↓
RX Ring Buffer
      ↓
Main Event Loop
      ↓
Command Parser
      ↓
Command Handler
🧠 Core Embedded Concepts Used
Interrupt Service Routines (ISR)
UART serial communication
Ring buffer / circular queue
Producer-consumer architecture
Event-driven firmware
Modular driver abstraction
Nonblocking RX handling
Hardware register interaction
📦 Ring Buffer Design
Empty Condition
head == tail
Full Condition
next_head == tail

One buffer slot intentionally sacrificed to distinguish:

full state
empty state
⚡ UART RX Flow
UART receives byte
↓
RX interrupt triggers
↓
ISR reads UDR0
↓
ISR pushes byte into RX ring buffer
↓
main loop processes byte
🧪 Current Functionality
UART Echo Test

System currently:

receives UART byte
stores in RX buffer
main loop reads byte
transmits same byte back

Purpose:

verify complete UART communication pipeline
🎯 Planned Features
command parser
newline-based command handling
LED control commands
status commands
timer-based scheduling
nonblocking command execution
TX interrupt buffering
🛠️ Target Platform

Currently designed around:

AVR ATmega328P

(Arduino Uno compatible architecture)

Uses:

AVR-GCC
avr-libc
🚀 Learning Objectives

This project was built to practice:

low-level embedded C
firmware architecture
modular system design
interrupt-driven programming
communication drivers
asynchronous event handling