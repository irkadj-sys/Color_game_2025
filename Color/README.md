# Color Game 1995 - Web Edition

A modern web adaptation of the classic color strategy game, built with Flask and WebSocket technology.

## 🎮 Quick Start

### Option 1: Using the Launcher Scripts (Recommended)
From the parent directory, run one of these:

**Windows (Command Prompt):**
```cmd
run_color_game.bat
```

**Windows (PowerShell):**
```powershell
.\run_color_game.ps1
```

**Cross-platform (Python):**
```bash
python run_color_game.py
```

### Option 2: Direct Execution
```bash
cd color
pip install -r requirements.txt
python color_game_app.py
```

Then open your browser to: http://localhost:5000

## 🎯 Game Overview

Color Game 1995 is a turn-based strategy game where players compete to score points by selecting colored cells on an 8x8 grid. The game features multiple modes including Human vs Computer, Human vs Human, and Computer vs Computer gameplay.

## ✨ Features

- **Multiple Game Modes**: Play against AI, another human, or watch AI vs AI
- **Real-time Multiplayer**: WebSocket support for live multiplayer games
- **Interactive UI**: Modern, responsive design with smooth animations
- **Score Tracking**: Real-time score updates and move history
- **AI Opponent**: Intelligent computer player with strategic decision making
- **Game Statistics**: Track wins, losses, and game history
- **Mobile Responsive**: Works on desktop, tablet, and mobile devices

## 🎮 How to Play

1. **Choose Game Mode**:
   - **Human vs Computer**: Play against AI
   - **Human vs Human**: Play with another person (same device)
   - **Computer vs Computer**: Watch AI play against itself

2. **Game Rules**:
   - Click on any unvisited colored cell
   - Points are awarded based on matching adjacent colors
   - Base score: 1 point per cell
   - Bonus: +1 point for each adjacent cell with the same color
   - Game ends when all 64 cells are visited
   - Player with highest score wins

## 🏗️ Project Structure

```
color/
├── color_game_app.py      # Main Flask application
├── requirements.txt       # Python dependencies
├── templates/            # HTML templates
│   ├── index.html        # Landing page
│   └── game.html         # Game interface
└── README.md            # This file
```

## 🔧 Configuration

You can customize the game by modifying constants in `color_game_app.py`:

```python
BOARD_SIZE = 8  # Change board size
COLORS = ['#FF0000', '#00FF00', ...]  # Customize color palette
GAME_MODES = ['human_vs_computer', ...]  # Available game modes
```

## 🐛 Troubleshooting

**Port Already in Use:**
```python
# Change port in color_game_app.py
socketio.run(app, debug=True, host='0.0.0.0', port=5001)
```

**Dependencies Not Found:**
```bash
pip install --upgrade -r requirements.txt
```

## 📊 API Endpoints

- `GET /` - Main game page
- `GET /game/<game_id>` - Game interface
- `POST /api/new_game` - Create new game
- `GET /api/game/<game_id>/state` - Get game state
- `POST /api/game/<game_id>/move` - Make a move
- `GET /api/games` - List all games

## 🎨 Customization

### Adding New Colors
Edit the `COLORS` list in `color_game_app.py`:
```python
COLORS = ['#FF0000', '#00FF00', '#0000FF', '#FFFF00', '#FF00FF', '#00FFFF', '#FFA500', '#800080', '#NEW_COLOR']
```

### Changing Board Size
Modify `BOARD_SIZE` in `color_game_app.py`:
```python
BOARD_SIZE = 10  # Creates a 10x10 board
```

---

**Enjoy playing Color Game 1995 - Web Edition!** 🎮✨ 