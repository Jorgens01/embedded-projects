# Electrical chessboard project

🚧 **Project status: Ongoing development** 🚧  
This project is actively being developed, with work in progress on core features such as move detection, embedded engine logic, and sensor integration. Expect frequent updates as functionality is implemented and refined.

---

An interactive, sensor-driven chessboard with an embedded chess engine to provide real-time game logic and player guidance. This project combines hardware and software to create a unique, hands-on chess experience that can serve as a foundation for future AI or machine learning integrations.

## Features

- **Move detection and validation**  
  Utilizes Hall effect sensors to detect piece movements and update the game state accordingly.

- **Embedded chess engine**  
  A custom-built chess engine, designed to run efficiently on the Raspberry Pi Zero W, processes move validation, and basic game rules.

- **Raspberry Pi for Game Logic and Connectivity**  
  The Raspberry Pi Zero W manages the main game engine and connects to external systems (optional online play or AI features).

- **STM32 Microcontroller for Sensor Management**  
  The STM32 Nucleo F303RE handles sensor inputs, capturing piece movements on the board in real-time and relaying this data to the game engine on the Raspberry Pi.

## Hardware and software

- **Hardware components**
  - **Raspberry Pi Zero W**: Will run the primary chess engine and manages connectivity.
  - **STM32 Nucleo F303RE**: Processes sensor data and communicates with the Pi for move updates.
  - **Hall Effect Sensors**: Detect the positions of chess pieces and relay data to the STM32.
  - **Magnetic Chess Pieces**: Used to trigger hall effect sensors beneath the board.

- **Software stack**
  - **C/C++ Chess Engine**: Designed to handle move validation and game rules.
  - **Sensor Calibration and Data Handling**: Runs on STM32 to process analog sensor data accurately.
  - **Inter-device Communication**: Serial communication between STM32 and Raspberry Pi.

