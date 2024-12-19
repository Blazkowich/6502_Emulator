# CPU 6502 Emulator in C++

This project is an emulator for the classic MOS Technology 6502 microprocessor, written in C++. The emulator replicates core functionalities of the 6502, including basic instructions and a simple memory model.

---

## Features

- Emulates the 6502 CPU registers:
  - **A**: Accumulator
  - **X, Y**: Index registers
  - **SP**: Stack Pointer
  - **PC**: Program Counter
  - **P**: Status Flags
- Implements:
  - Memory addressing (64KB memory space)
  - Fetch, decode, and execute cycle
  - Basic instructions like `NOP` and `LDA`
- Provides a flexible structure to add more instructions.

---

## Prerequisites

- **C++ Compiler**: Compatible with C++11 or newer
- **Development Tools**: Any IDE or command-line tools that support C++ development (e.g., GCC, Clang, Visual Studio)

---

## Getting Started

### Clone the Repository

```bash
# Clone the repository
$ git clone https://github.com/Blazkowich/6502_Emulator.git

# Navigate to the project directory
$ cd cpu6502-emulator
```

### Build the Project

#### Using Command Line

1. Compile the code:

   ```bash
   g++ -o cpu6502_emulator main.cpp
   ```

2. Run the emulator:

   ```bash
   ./cpu6502_emulator
   ```

#### Using an IDE

1. Open the project in your preferred IDE.
2. Add `main.cpp` as the source file.
3. Build and run the project.

---

## Code Overview

### Registers

The emulator maintains the 6502's essential registers:

- **Accumulator (A)**: Used for arithmetic and logic operations.
- **X, Y Index Registers**: Support addressing modes and indexing.
- **Stack Pointer (SP)**: Points to the stack memory.
- **Program Counter (PC)**: Tracks the memory location of the next instruction.
- **Status Flags (P)**:
  - `N`: Negative
  - `Z`: Zero
  - `C`: Carry
  - `I`: Interrupt Disable
  - `D`: Decimal Mode

### Key Methods

- **`reset()`**:
  Resets the CPU state and loads the program counter from the reset vector (`0xFFFC`).

- **`fetchByte()`**:
  Fetches the next byte of the program and increments the program counter.

- **`fetchWord()`**:
  Fetches the next 16-bit word (two bytes) and increments the program counter by 2.

- **`executeInstruction()`**:
  Decodes and executes the current instruction based on the fetched opcode.

### Example Code

```cpp
CPU6502 cpu;
cpu.memory[0xFFFC] = 0x00;  // Set reset vector low byte
cpu.memory[0xFFFD] = 0x80;  // Set reset vector high byte
cpu.memory[0x8000] = 0xA9;  // LDA #immediate opcode
cpu.memory[0x8001] = 0x42;  // Immediate value (0x42)

cpu.reset();
cpu.executeInstruction();
cout << "Accumulator: " << static_cast<int>(cpu.A) << endl;
```

---

## Current Instructions

| Opcode | Mnemonic       | Description                   |
|--------|----------------|-------------------------------|
| `0xEA` | `NOP`          | No operation                  |
| `0xA9` | `LDA #immediate` | Load immediate value into `A` |

---

## Extending the Emulator

1. Add a new opcode in `executeInstruction()`:

   ```cpp
   case 0xXX: // New opcode
       // Implement logic here
       break;
   ```

2. Update the memory or registers as needed.
3. Test thoroughly to ensure correctness.

---

## License

This project is open source under the [MIT License](LICENSE).

---

## Contributions

Contributions are welcome! Feel free to submit issues, feature requests, or pull requests.

---

## References

- [MOS 6502 Documentation](https://www.masswerk.at/6502/)
- [6502 Instruction Set](https://www.masswerk.at/6502/6502_instruction_set.html)
- [Emulator Development Guide](https://www.emudev.org/)

---

## Author

[Otar Iluridze]
