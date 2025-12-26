# Chess Game - User Manual
## Introduction
Welcome to rahma's and jana's Chess Game! This is a terminal-based chess program written in C that allows two players to play a complete game of chess with standard rules. The game includes move validation, check and checkmate detection, undo/redo moves, and the ability to save and load games.

## System Requirements
**Operating System:** Windows, Linux, or macOS
- **Compiler:** GCC or any C compiler
- **Terminal/Command Prompt:** Required to run the game
## Installation and Setup

### Compilation
1. Download all the source files (`.c` and `.h` files) and Makefile
2. Open your terminal
3. Navigate to the folder containing the source files
4. Compile the program using:
```
   make
```
   ## How to Play

### Starting the Game
When you run the program, you'll see the chess board displayed in the terminal with pieces represented by characters.

### Understanding the Board
- **Uppercase letters** represent black pieces (K=King, Q=Queen, R=Rook, B=Bishop, N=Knight, P=Pawn)
- **Lowercase letters** represent white pieces (k=king, q=queen, r=rook, b=bishop, n=knight, p=pawn)
- The board uses standard chess notation with columns labeled A-H and rows labeled 1-8
### Making Moves
1. When it's your turn,enter a move
2. Enter moves using coordinate notation: `[source][destination]`
   - Example: `E2E4` moves the piece from E2 to E4
   - Example: `G1F3` moves the knight from G1 to F3
3. Press Enter to execute the move
4. The game validates your move automatically and will reject illegal moves

### Special Moves
- **Pawn Promotion:** choose a piece when a pawn reaches the opposite end(either: queen , knight, rook or bishop)
### Move Validation
The game automatically checks if your move is legal according to chess rules:
- Prevents moves that leave your king in check
- Ensures pieces move according to their movement rules
- Validates turn order (White moves first, then alternates)

### Check and Checkmate Detection
- The game alerts you when a king is in check
- Automatically detects checkmate and declares the winner
- Detects stalemate and lets you know.
### Undo and Redo Moves
- **Undo:** Type `undo` to take back the last move
- **Redo:** Type `redo` to restore a move that was undone
- You can undo moves till the first move
### Save and Load Games
- **Save Game:** Type `save` to save the game
- **Load Game:** Type `load` to load the saved game
- Saved games preserve the entire board state and move history and player's turn
### Draw Conditions
The game automatically detects Stalemate
## Commands

| Command | Description |
|---------|-------------|
| `E2E4` | Make a move from E2 to E4 |
| `undo` | Undo the last move |
| `redo` | Redo an undone move |
| `save` | Save current game |
| `load` | Load a saved game |
| `quit` | Exit the game |

## Credits
Developed by [jana and rahma]

Course: [programming 1]

Date: [24/12/2024]
---
Enjoy your game of chess!
