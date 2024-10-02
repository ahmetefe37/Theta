# Theta Visual Scripting Engine

---

## About the Project

Theta Visual Scripting Engine is a platform that simplifies the software development process for electronic control boards used in industrial automation projects by utilizing a visual programming approach. With this project, users can easily design complex algorithms through visual blocks and then compile and upload these algorithms to the target board to run.

This program allows you to create code flows by connecting visual blocks and, in the end, compiles the design and prepares it to be transferred to the electronic board.

---

### Key Features

- **Drag-and-Drop Interface:** Easily create algorithms by dragging and dropping visual blocks with a user-friendly interface.
- **Block-Based Programming:** Use predefined control and process blocks to build your algorithms.
- **Automatic Compilation:** The designed algorithms are automatically compiled and made ready for deployment.
- **Hardware Integration:** Compiled code can be directly uploaded to the electronic control board.
- **Flexible Design:** Extensive block library allows for designing both simple and complex algorithms.
- **Cross-Platform:** The program can be used on various platforms and is compatible with different control boards.

---

## Getting Started

Follow these steps to set up and run the project on your local environment.

### Prerequisites

You will need the following software and tools to run the project:

- Operating System: Windows, macOS, Linux
- A C/C++ compiler such as GCC/Clang
- Theta Visual Scripting Engine supported electronic control board (later)

### Installation Steps

1. Clone the project from GitHub:
   ```bash
   git clone https://github.com/ahmetefe37/theta.git

---

## Usage

### Interface Usage

- **Select Blocks:** Choose various process and control blocks from the application interface.
- **Connect Blocks:** Establish connections between blocks to create a flow for the algorithm.
- **Compile the Algorithm:** Once the flow is ready, click the "Compile" button to compile the design.
- **Upload to Device:** If an electronic control board is connected, use the "Upload" option to transfer the compiled code to the board.

### Example Flow Creation

1. **Input Block:** First, add an input block, representing sensor data or other input sources.
2. **Process Block:** Add a process block to process the input data, such as filtering, calculation, or decision-making.
3. **Output Block:** Connect the processed data to an output block, which could trigger actions like controlling a motor or displaying data.
4. **Simulation:** Before compiling, use the simulation feature to verify that the flow works as expected.

---

## Block Library

The project provides an extensive block library with various functions:

- **Control Blocks:** IF, WHILE, FOR conditional control structures.
- **Input/Output Blocks:** Sensor and actuator blocks.
- **Mathematical Operations:** Basic operations like addition, subtraction, multiplication, and division.
- **Timing Blocks:** Timers, delay functions.
- **Data Blocks:** Structures for storing and processing data.

---

## Developer Information

This project is open to community contributions. If you would like to add new features, fix bugs, or improve the documentation, you can contribute by following the steps below.

### Contribution Steps

1. Fork this repository.
2. Create a new branch (`git checkout -b feature-XXXXXXX`).
3. Commit your changes (`git commit -m 'Add a new feature'`).
4. Push your branch (`git push origin feature-XXXXXXX`).
5. Open a Pull Request.

---

## Frequently Asked Questions (FAQ)

1. **What boards are supported by this project?**
   - Currently, the project supports XXXXXXX, XXXXXXX, and XXXXXXX boards. More board support is planned for future updates.

2. **What programming languages are supported?**
   - The visual programming language is used to create flows, which are automatically translated into C/C++ and compiled.

3. **How can I report issues?**
   - If you encounter any issues, you can open an `Issue` on GitHub to report it.

---

## License

This project is licensed under the Apache-2.0 License. Please refer to the `LICENSE` file for more details.

---

## Contact
If you have any questions or suggestions regarding the project, feel free to contact us via the following channels:

Email: ahmetefezorali@gmail.com
GitHub: www.gitHub.com/ahmetefe37
Forum: [Project Issues](https://github.com/ahmetefe37/Theta/issues)