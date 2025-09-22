# Color Game 1995 - Web Edition

A modern web adaptation of the classic color strategy game, built with Flask and WebSocket technology.

## 🎮 Game Overview

Color Game 1995 is a turn-based strategy game where players compete to score points by selecting colored cells on an 8x8 grid. The game features multiple modes including Human vs Computer, Human vs Human, and Computer vs Computer gameplay.

## ✨ Features

- **Multiple Game Modes**: Play against AI, another human, or watch AI vs AI
- **Real-time Multiplayer**: WebSocket support for live multiplayer games
- **Interactive UI**: Modern, responsive design with smooth animations
- **Score Tracking**: Real-time score updates and move history
- **AI Opponent**: Intelligent computer player with strategic decision making
- **Game Statistics**: Track wins, losses, and game history
- **Mobile Responsive**: Works on desktop, tablet, and mobile devices

## 🎯 Game Rules

1. **Objective**: Score the most points by selecting colored cells strategically
2. **Scoring**: Points are awarded based on matching adjacent colors
   - Base score: 1 point per cell
   - Bonus: +1 point for each adjacent cell with the same color
3. **Turns**: Players take turns selecting unvisited cells
4. **Game End**: Game ends when all 64 cells have been visited
5. **Winner**: Player with the highest score wins

## 🚀 Installation & Setup

### Prerequisites
- Python 3.7 or higher
- pip (Python package installer)

### Step 1: Clone or Download
```bash
# If you have the files locally, navigate to the project directory
cd path/to/color-game
```

### Step 2: Install Dependencies
```bash
pip install -r requirements.txt
```

### Step 3: Run the Application
```bash
python color_game_app.py
```

### Step 4: Access the Game
Open your web browser and navigate to:
```
http://localhost:5000
```

## 🎮 How to Play

### Starting a Game
1. **Choose Game Mode**:
   - **Human vs Computer**: Play against AI
   - **Human vs Human**: Play with another person (same device)
   - **Computer vs Computer**: Watch AI play against itself

2. **Game Interface**:
   - **Color Board**: 8x8 grid of colored cells
   - **Score Panel**: Shows current scores for both players
   - **Turn Indicator**: Shows whose turn it is
   - **Move History**: Recent moves and scores

### Making Moves
1. Click on any unvisited colored cell
2. Points are automatically calculated based on adjacent matching colors
3. Turn passes to the other player
4. Continue until all cells are visited

### Strategy Tips
- Look for clusters of the same color for higher scores
- Consider blocking opponent's high-scoring opportunities
- Plan ahead for future moves
- Balance between immediate points and long-term strategy

## 🏗️ Technical Architecture

### Backend (Flask)
- **Framework**: Flask with Flask-SocketIO
- **Database**: SQLite for game persistence
- **Real-time**: WebSocket communication for multiplayer
- **Game Logic**: Python classes for game state management

### Frontend (HTML/CSS/JavaScript)
- **UI Framework**: Vanilla JavaScript with modern CSS
- **Styling**: CSS Grid and Flexbox for responsive design
- **Animations**: CSS transitions and transforms
- **Real-time Updates**: Socket.IO client for live game updates

### Key Components
- `color_game_app.py`: Main Flask application
- `templates/index.html`: Landing page with game mode selection
- `templates/game.html`: Main game interface
- `GameState` class: Game logic and state management
- WebSocket handlers: Real-time multiplayer support

## 🔧 Configuration

### Environment Variables
You can customize the game by modifying these constants in `color_game_app.py`:

```python
# Game configuration
BOARD_SIZE = 8  # Change board size (affects game length)
COLORS = ['#FF0000', '#00FF00', ...]  # Customize color palette
GAME_MODES = ['human_vs_computer', ...]  # Available game modes
```

### Database
The game automatically creates a SQLite database (`color_game.db`) to store:
- Game history
- Player statistics
- Game results

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

### Styling
Customize the appearance by editing CSS in the HTML templates:
- Color schemes in `templates/index.html` and `templates/game.html`
- Layout adjustments for different screen sizes
- Animation timing and effects

## 🐛 Troubleshooting

### Common Issues

**Port Already in Use**
```bash
# Change port in color_game_app.py
socketio.run(app, debug=True, host='0.0.0.0', port=5001)
```

**Dependencies Not Found**
```bash
# Reinstall requirements
pip install --upgrade -r requirements.txt
```

**WebSocket Connection Issues**
- Ensure firewall allows connections on port 5000
- Check browser console for connection errors
- Verify Socket.IO client version compatibility

### Debug Mode
The application runs in debug mode by default. For production:
```python
socketio.run(app, debug=False, host='0.0.0.0', port=5000)
```

## 📊 Game Statistics

The application tracks various statistics:
- Total games played
- Active games
- Player 1 wins
- Player 2 wins
- Game completion rates

Access statistics via the API endpoint:
```
GET /api/games
```

## 🔮 Future Enhancements

Potential improvements and features:
- [ ] User accounts and authentication
- [ ] Leaderboards and rankings
- [ ] Tournament mode
- [ ] Advanced AI difficulty levels
- [ ] Custom game rules and scoring
- [ ] Sound effects and music
- [ ] Game replay functionality
- [ ] Export game statistics
- [ ] Mobile app version

## 🤝 Contributing

To contribute to the project:
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## 📄 License

This project is open source and available under the MIT License.

## 🙏 Acknowledgments

- Original C++ Color Game 1995 concept
- Flask and Socket.IO communities
- Modern web development best practices

---

**Enjoy playing Color Game 1995 - Web Edition!** 🎮✨ 