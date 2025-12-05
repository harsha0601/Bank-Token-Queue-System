# Bank Token Queue System 🚀

[![GitHub License](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/harsha0601/Bank-Token-Queue-System/blob/main/LICENSE)
[![Language](https://img.shields.io/badge/language-C-blue.svg)]()
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS-orange.svg)]()

A comprehensive **C implementation** of FIFO Queue using **Linked List** with a **Terminal-based GUI** powered by ncurses. This project demonstrates practical application of data structures in real-world banking scenarios.

## Features ✨

- ✅ **FIFO Queue Implementation** using Linked List
- ✅ **Real-time Visual Display** with ncurses GUI
- ✅ **Auto Token Generation** (numeric token assignment)
- ✅ **Menu-driven Interface** (keyboard navigation)
- ✅ **Queue Statistics** (size, served count, next token)
- ✅ **Customer Management** (enqueue, dequeue, display)
- ✅ **Clean Memory Management** (no memory leaks)

## Project Structure

```
Bank-Token-Queue-System/
├── main.c              # Main program with ncurses GUI
├── queue.h             # Header file with function declarations
├── Makefile            # Build configuration
├── .gitignore          # Git ignore patterns
├── README.md           # This file
└── LICENSE             # MIT License
```

## Technologies Used

| Component | Technology |
|-----------|------------|
| **Language** | C (ANSI C99) |
| **GUI Library** | ncurses |
| **Data Structure** | Singly Linked List |
| **Compiler** | GCC |
| **Build Tool** | Make |

## Installation & Setup

### Prerequisites

- GCC compiler (or any C99 compatible compiler)
- ncurses development library
- Linux/macOS system

### Quick Start (Linux/Ubuntu)

```bash
# Install dependencies
sudo apt-get update
sudo apt-get install libncurses5-dev gcc make

# Clone repository
git clone https://github.com/harsha0601/Bank-Token-Queue-System.git
cd Bank-Token-Queue-System

# Build
make

# Run
./bank_queue
```

### Using Makefile Commands

```bash
make          # Compile the program
make run      # Compile and run
make clean    # Remove executable
```

## Usage Guide

### Main Menu Options

When you run the program, you'll see a two-panel interface:

**Left Panel - Counter Control:**
- Press `1` - Issue new token to next customer
- Press `2` - Serve current customer (dequeue)
- Press `3` - Display queue statistics
- Press `4` - Clear all queue
- Press `5` - Exit program

**Right Panel - Queue Display:**
- Shows current customer at counter
- Displays all waiting customers
- Real-time queue size updates

### Example Session

```
1. Press '1' → Token #1 issued
2. Press '1' → Token #2 issued
3. Press '1' → Token #3 issued
4. Press '2' → Token #1 served (removed from queue)
5. Press '3' → Shows: Size:2, Served:1, Next:4
```

## Code Architecture

### Data Structure (Node)

```c
struct Node {
    int tokenNo;        // Unique token number
    struct Node *next;  // Pointer to next node
};
```

### Key Functions

| Function | Purpose |
|----------|----------|
| `enqueue()` | Add customer to queue end |
| `dequeue()` | Remove and serve customer |
| `queueSize()` | Get number of waiting customers |
| `currentCustomer()` | Get token of customer at counter |
| `displayQueue()` | Render GUI display |
| `cleanup()` | Free all memory |

## Learning Outcomes

This project demonstrates:

1. **Data Structure Implementation**
   - Linked List basics
   - FIFO queue principles
   - Memory allocation/deallocation

2. **C Programming Concepts**
   - Pointers and dynamic memory
   - Structs and function pointers
   - File I/O (potential extension)

3. **GUI Programming**
   - ncurses library usage
   - Window management
   - Real-time display updates

4. **System Design**
   - Real-world problem modeling
   - User-friendly interface design
   - Resource management

## Potential Enhancements

- [ ] **Priority Queue** - Add priority levels (VIP, seniors, etc.)
- [ ] **File Persistence** - Save queue to file
- [ ] **Statistics Report** - Generate performance reports
- [ ] **Multi-counter** - Simulate multiple service counters
- [ ] **Time Tracking** - Track wait times
- [ ] **Database Integration** - Store customer data
- [ ] **Network Mode** - Remote queue management

## Compilation Troubleshooting

### Error: `ncurses.h: No such file or directory`

```bash
# Ubuntu/Debian
sudo apt-get install libncurses5-dev

# macOS
brew install ncurses
```

### Error: `undefined reference to 'addstr'`

Make sure to link ncurses: Use `-lncurses` flag in compiler

## Performance Characteristics

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Enqueue | O(1) | O(1) |
| Dequeue | O(1) | O(1) |
| Display | O(n) | O(1) |
| Queue Size | O(n) | O(1) |

*Note: Display and size are O(n) due to traversal requirements*

## File Descriptions

### `main.c`
- ncurses GUI implementation
- Event loop and user input handling
- Queue operations and display logic
- ~180 lines of well-commented code

### `queue.h`
- Node structure definition
- Function prototypes
- Comprehensive documentation comments

### `Makefile`
- Automated build process
- Clean targets
- Compiler flags for optimization

## License

This project is licensed under the **MIT License** - see [LICENSE](LICENSE) file for details.

## Author & Contact

- **Author**: Harsha (harsha0601)
- **GitHub**: [@harsha0601](https://github.com/harsha0601)
- **Email**: Contact via GitHub

## Contributions

Contributions are welcome! Please feel free to:
- Report bugs via Issues
- Suggest enhancements
- Submit pull requests

## Acknowledgments

- Data Structures course materials
- ncurses documentation
- The open-source community

---

**Made with ❤️ for learning data structures and C programming**
