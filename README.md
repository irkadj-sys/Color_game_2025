# Colors Game 1995 - Web Port

This is a web port of the original Colors Game 1995, maintaining the exact same game logic, scale, and visual elements as the original C++ Windows application.

## Features

- **Exact Scale**: Maintains the original 580x390 window size and all game elements at their original scale
- **Original Game Logic**: All game mechanics, color matching, and scoring system preserved exactly
- **Same Controls**: 
  - Left player: Z/X keys to change color, Space to confirm
  - Right player: Arrow keys to change color, Enter to confirm
- **Two Game Modes**: Human vs Human or Human vs Computer
- **Original Visual Style**: Diamond-shaped game pieces, color selection panels, and scoring display

## Game Rules

1. **Objective**: Capture territory by matching colors and expanding your area
2. **Board**: 89x25 hexagonal grid with 5 different colors
3. **Players**: Left player (bottom) vs Right player (top) or Computer
4. **Winning**: First player to capture more than 50% of the board wins
5. **Turn-based**: Players take turns selecting colors and expanding their territory

## Installation and Running

### Prerequisites

- Node.js (version 14 or higher)
- npm or yarn

### Setup

1. Clone the repository:
```bash
git clone <repository-url>
cd Colors_Game_1995
```

2. Install dependencies:
```bash
npm install
```

3. Start the development server:
```bash
npm start
```

4. Open your browser and navigate to `http://localhost:3000`

### Building for Production

To create a production build:

```bash
npm run build
```

The built files will be in the `build` directory.

## Technical Details

### Architecture

- **Frontend**: React 18 with TypeScript
- **Rendering**: HTML5 Canvas for pixel-perfect graphics
- **Game Logic**: Direct port of original C++ classes
- **State Management**: React hooks for game state

### Key Components

- `TBoard`: Game board management (89x25 grid)
- `TSide`: Base class for player sides
- `TLeft`: Left player implementation
- `TRight`: Right player implementation
- `TGameWin`: Main game controller
- `GameCanvas`: React component for rendering

### Original vs Web Port

| Aspect | Original (C++) | Web Port (React) |
|--------|----------------|------------------|
| Platform | Windows MFC | Web Browser |
| Graphics | GDI Direct Drawing | HTML5 Canvas |
| Window Size | 580x390 | 580x390 |
| Game Board | 89x25 | 89x25 |
| Colors | 5 colors | 5 colors |
| Controls | Keyboard | Keyboard |
| Multiplayer | Local only | Local only |

## Development

### Project Structure

```
src/
├── components/
│   └── GameCanvas.tsx      # Main game rendering component
├── constants/
│   └── GameConstants.ts    # Game constants and color definitions
├── game/
│   ├── TBoard.ts          # Game board class
│   ├── TSide.ts           # Base player class
│   ├── TLeft.ts           # Left player implementation
│   ├── TRight.ts          # Right player implementation
│   └── TGameWin.ts        # Main game controller
├── App.tsx                # Main application component
└── index.tsx             # Application entry point
```

### Key Implementation Details

1. **Exact Scale Preservation**: All positioning and sizing matches the original exactly
2. **Color System**: RGB values match the original C++ color definitions
3. **Diamond Pattern**: Romb pattern array preserved exactly
4. **Game Logic**: Turn-based system with identical scoring and win conditions
5. **Input Handling**: Keyboard events mapped to original key codes

## Future Enhancements

- Mobile touch controls
- Online multiplayer support
- Enhanced AI opponent
- Game history and statistics
- Sound effects and music
- Accessibility improvements

## License

This project is a port of the original Colors Game 1995. Please respect the original copyright. 