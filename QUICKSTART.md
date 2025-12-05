# Quick Start Guide - Bank Token Queue System

## ⚡ Run in 3 Simple Steps

### Option 1: Linux/Ubuntu (Terminal)

```bash
# Step 1: Install dependencies (one time)
sudo apt-get install libncurses5-dev gcc make

# Step 2: Clone & enter directory
git clone https://github.com/harsha0601/Bank-Token-Queue-System.git
cd Bank-Token-Queue-System

# Step 3: Compile and run
make run
```

### Option 2: Replit (Browser)

1. Go to **https://replit.com**
2. Click **"Create"** → Select **"C"**
3. In Terminal, run:
```bash
git clone https://github.com/harsha0601/Bank-Token-Queue-System.git .
make run
```
4. Click **"Run"** button

### Option 3: macOS

```bash
# Install dependencies
brew install ncurses gcc make

# Clone and run
git clone https://github.com/harsha0601/Bank-Token-Queue-System.git
cd Bank-Token-Queue-System
make run
```

---

## 🎮 How to Use

Once running, you'll see a terminal GUI:

```
┌─ Bank Counter Menu ─┐  ┌─ Queue Display ─┐
│ 1. Issue Token      │  │ Current: #1     │
│ 2. Serve Next       │  │ Waiting: #2,#3  │
│ 3. Statistics       │  │ Size: 2         │
│ 4. Clear Queue      │  │                 │
│ 5. Exit             │  │ Served: 1       │
└─────────────────────┘  └─────────────────┘
```

**Menu Controls:**
- Press **1** → Issue new token
- Press **2** → Serve next customer
- Press **3** → Show stats
- Press **4** → Clear queue
- Press **5** → Exit

---

## 📝 Example Interaction

```
1. Press '1'  →  "Token #1 issued!"
2. Press '1'  →  "Token #2 issued!"
3. Press '1'  →  "Token #3 issued!"
4. Press '2'  →  "Served Token #1!"
5. Press '3'  →  "Size:2 Served:1 Next:4"
6. Press '5'  →  Program exits
```

---

## 🔧 Troubleshooting

**Error: "ncurses.h: No such file"**
```bash
sudo apt-get install libncurses5-dev
```

**Error: "command not found: make"**
```bash
sudo apt-get install build-essential  # Ubuntu/Debian
brew install make                       # macOS
```

**Program doesn't compile**
```bash
make clean
make
```

---

## 📚 Learn More

Read the full documentation: [README.md](README.md)

**Key Topics:**
- Data Structure: Singly Linked List
- Algorithm: FIFO Queue
- GUI: ncurses Terminal Interface
- Language: C (ANSI C99)

---

## 🚀 Advanced Options

```bash
make          # Just compile
make run      # Compile and run
make clean    # Remove executable
```

---

**Ready to learn data structures? Run it now!** 🎯
