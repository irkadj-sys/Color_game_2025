from flask import Flask, render_template, request, jsonify, session, redirect, url_for, send_from_directory
import random
import os

app = Flask(__name__, static_folder='static')
app.config['SECRET_KEY'] = 'your-secret-key-here'

# Game configuration - matching original C++ structure
APP_TITLE = "Color"
APP_VERSION = "1, 0, 0, 1"
COPYRIGHT_YEAR = "1999"
FILE_DESCRIPTION = "Color MFC Application"
PRODUCT_NAME = "Color Application"
INTERNAL_NAME = "Color"
ORIGINAL_FILENAME = "Color.EXE"

# Game constants from original C++
WIDTH = 89
HEIGHT = 25
NUMBER_COLORS = 5
DL = 64
DR = 128

# Game colors from original C++ (RGB values)
COLORS = [
    [0, 65, 246],    # Blue
    [0, 164, 0],     # Green  
    [197, 0, 0],     # Red
    [255, 160, 0],   # Yellow
    [255, 131, 255]  # Purple
]

# Game state
class GameState:
    def __init__(self):
        print("=== GAMESTATE INIT DEBUG ===")
        print(f"Creating board with dimensions: {HEIGHT}x{WIDTH} ({HEIGHT} rows, {WIDTH} columns)")
        
        self.board = [[0 for _ in range(WIDTH)] for _ in range(HEIGHT)]
        print(f"Board created: {len(self.board)} rows, {len(self.board[0]) if self.board else 0} columns")
        
        self.left_color = 0  # Current color for left player
        self.right_color = 0  # Current color for right player
        self.left_score = 1  # Start with score 1 (matching original)
        self.right_score = 1  # Start with score 1 (matching original)
        self.game_state = "gsGameL"  # gsGameL, gsGameR, gsGameOver
        self.computer_mode = True
        self.human_mode = False
        
        # Initialize game field like original TBoard constructor
        # Fill entire board with random colors (1-5)
        print("Filling board with random colors...")
        cells_filled = 0
        for i in range(HEIGHT):
            for j in range(WIDTH):
                # Random color 1-5 (matching original: 5.0 * rand() / RAND_MAX + 1)
                self.board[i][j] = random.randint(1, 5)
                cells_filled += 1
                # Special case: bottom row, odd columns are empty (matching original)
                if i == HEIGHT - 1 and j % 2:
                    self.board[i][j] = 0
                    cells_filled -= 1
        
        print(f"Cells filled with random colors: {cells_filled}")
        
        # Place player starting pieces
        # Left player starts at bottom-left corner (HEIGHT-1, 0)
        self.board[HEIGHT-1][0] = DL  # playerCode = 64 for left player
        print(f"Left player piece placed at ({HEIGHT-1}, 0) = {DL}")
        
        # Right player starts at top-right corner (0, WIDTH-1)
        self.board[0][WIDTH-1] = DR  # playerCode = 128 for right player
        print(f"Right player piece placed at (0, {WIDTH-1}) = {DR}")
        
        # Debug: show first few rows
        print("First 5 rows of board:")
        for i in range(min(5, HEIGHT)):
            row_data = self.board[i][:10]  # First 10 columns
            print(f"Row {i}: {row_data}")
        
        print("Last 5 rows of board:")
        for i in range(max(0, HEIGHT-5), HEIGHT):
            row_data = self.board[i][:10]  # First 10 columns
            print(f"Row {i}: {row_data}")
        
        print("=== GAMESTATE INIT COMPLETE ===")

# Global game instance
game = GameState()

@app.route('/')
def index():
    """Main window - matches original C++ main window exactly"""
    return render_template('index.html', 
                         app_title=APP_TITLE,
                         copyright_year=COPYRIGHT_YEAR,
                         game=game)

@app.route('/options')
def options():
    """Options dialog - matches original C++ IDD_OPTDIALOG exactly"""
    return render_template('options.html',
                         dialog_title="Dialog",
                         groupbox_title="Choose second player",
                         human_option="Human",
                         computer_option="Computer",
                         ok_button="OK",
                         cancel_button="Cancel",
                         selected_option=0 if game.computer_mode else 1)

@app.route('/about')
def about():
    """About dialog - matches original C++ IDD_ABOUTBOX exactly"""
    return render_template('about.html',
                         app_title=APP_TITLE,
                         copyright_year=COPYRIGHT_YEAR)

@app.route('/api/new_game')
def new_game():
    """Create a new game - matches File -> New menu item"""
    global game
    game = GameState()
    return jsonify({
        'success': True,
        'message': 'New game started',
        'game_state': {
            'board': game.board,
            'left_color': game.left_color,
            'right_color': game.right_color,
            'left_score': game.left_score,
            'right_score': game.right_score,
            'game_state': game.game_state
        }
    })

@app.route('/api/set_game_mode', methods=['POST'])
def set_game_mode():
    """Set the game mode from options dialog - matches original C++ OnOK()"""
    global game
    data = request.get_json()
    mode = data.get('mode')
    
    if mode == 'human':
        game.computer_mode = False
        game.human_mode = True
    else:
        game.computer_mode = True
        game.human_mode = False
    
    return jsonify({'success': True, 'mode': mode})

@app.route('/api/get_game_state')
def get_game_state():
    """Get current game state"""
    return jsonify({
        'board': game.board,
        'left_color': game.left_color,
        'right_color': game.right_color,
        'left_score': game.left_score,
        'right_score': game.right_score,
        'game_state': game.game_state,
        'computer_mode': game.computer_mode,
        'human_mode': game.human_mode
    })

@app.route('/api/make_move', methods=['POST'])
def make_move():
    """Make a move in the game"""
    global game
    data = request.get_json()
    player = data.get('player')  # 'left' or 'right'
    action = data.get('action')  # 'change_color', 'place', 'key'
    key = data.get('key')
    
    if action == 'change_color':
        color_index = data.get('color_index', 0)
        if 0 <= color_index < NUMBER_COLORS:
            if player == 'left':
                game.left_color = color_index
            else:
                game.right_color = color_index
    
    elif action == 'place':
        row = data.get('row')
        col = data.get('col')
        if 0 <= row < HEIGHT and 0 <= col < WIDTH and game.board[row][col] == 0:
            # Check if the placement is valid (adjacent to existing pieces of the same player)
            if can_place_piece(row, col, player):
                color_value = (game.left_color + 1) if player == 'left' else (game.right_color + 1 + 64)
                game.board[row][col] = color_value
                
                # Check for matches and update score
                score = check_matches(row, col, color_value)
                if player == 'left':
                    game.left_score += score
                else:
                    game.right_score += score
                
                # Switch turns
                if game.game_state == "gsGameL":
                    if game.human_mode:
                        game.game_state = "gsGameR"
                    else:
                        # Computer turn
                        make_computer_move()
                else:
                    game.game_state = "gsGameL"
    
    elif action == 'key':
        handle_key_press(key)
    
    return jsonify({
        'success': True,
        'game_state': {
            'board': game.board,
            'left_color': game.left_color,
            'right_color': game.right_color,
            'left_score': game.left_score,
            'right_score': game.right_score,
            'game_state': game.game_state
        }
    })

def can_place_piece(row, col, player):
    """Check if a piece can be placed at the given position"""
    player_code = DL if player == 'left' else DR
    
    # Check adjacent positions (up, down, left, right)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    for dr, dc in directions:
        new_row, new_col = row + dr, col + dc
        if (0 <= new_row < HEIGHT and 0 <= new_col < WIDTH):
            cell_value = game.board[new_row][new_col]
            # Check if adjacent cell belongs to the same player
            if cell_value == player_code or (cell_value > 64 and cell_value % 64 == player_code):
                return True
    
    return False

def check_matches(row, col, color_value):
    """Check for matching colors around the placed piece"""
    score = 1
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    for dr, dc in directions:
        new_row, new_col = row + dr, col + dc
        if (0 <= new_row < HEIGHT and 0 <= new_col < WIDTH and 
            game.board[new_row][new_col] == color_value):
            score += 1
    
    return score

def make_computer_move():
    """Make computer move - simple AI"""
    # Find a random empty position
    empty_positions = []
    for row in range(HEIGHT):
        for col in range(WIDTH):
            if game.board[row][col] == 0:
                empty_positions.append((row, col))
    
    if empty_positions:
        row, col = random.choice(empty_positions)
        color_value = game.right_color + 1 + 64
        game.board[row][col] = color_value
        
        # Update score
        score = check_matches(row, col, color_value)
        game.right_score += score
        
        # Switch back to left player
        game.game_state = "gsGameL"

def handle_key_press(key):
    """Handle key presses like in original C++"""
    if game.game_state == "gsGameR":
        if key in ['ArrowLeft', 'Numpad4']:
            game.right_color = (game.right_color - 1) % NUMBER_COLORS
            if game.right_color < 0:
                game.right_color = NUMBER_COLORS - 1
        elif key in ['ArrowRight', 'Numpad6']:
            game.right_color = (game.right_color + 1) % NUMBER_COLORS
        elif key == 'Enter':
            # Place piece for right player
            pass  # Would need position from UI
    elif game.game_state == "gsGameL":
        if key == 'KeyZ':
            game.left_color = (game.left_color - 1) % NUMBER_COLORS
            if game.left_color < 0:
                game.left_color = NUMBER_COLORS - 1
        elif key == 'KeyX':
            game.left_color = (game.left_color + 1) % NUMBER_COLORS
        elif key == 'Space':
            # Place piece for left player
            pass  # Would need position from UI

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000) 