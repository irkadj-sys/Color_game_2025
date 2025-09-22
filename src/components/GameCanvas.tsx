import React, { useRef, useEffect, useState, useCallback } from 'react';
import { TGameWin } from '../game/TGameWin';
import { GAME_CONSTANTS } from '../constants/GameConstants';

interface GameCanvasProps {
    isHumanOpponent: boolean;
}

export const GameCanvas: React.FC<GameCanvasProps> = ({ isHumanOpponent }) => {
    const canvasRef = useRef<HTMLCanvasElement>(null);
    const gameRef = useRef<TGameWin | null>(null);
    const [gameState, setGameState] = useState<string>('gsGameL');

    // Draw game function
    const drawGame = useCallback((ctx: CanvasRenderingContext2D) => {
        if (!gameRef.current) return;

        // Clear canvas
        ctx.fillStyle = 'rgb(0,0,0)';
        ctx.fillRect(0, 0, GAME_CONSTANTS.WIDTH, GAME_CONSTANTS.HEIGHT);

        // Draw game field
        gameRef.current.drawField(ctx);
        
        // Update game state
        setGameState(gameRef.current.getGameState());
    }, []);

    // Initialize game
    useEffect(() => {
        const canvas = canvasRef.current;
        if (!canvas) return;

        const ctx = canvas.getContext('2d');
        if (!ctx) return;

        // Set canvas size to match original dimensions exactly
        canvas.width = GAME_CONSTANTS.WIDTH;
        canvas.height = GAME_CONSTANTS.HEIGHT;

        // Initialize game
        gameRef.current = new TGameWin(ctx);
        
        // Draw initial state
        drawGame(ctx);
    }, [isHumanOpponent, drawGame]);

    // Handle keyboard input
    const handleKeyDown = useCallback((event: KeyboardEvent) => {
        if (!gameRef.current || !canvasRef.current) return;

        const ctx = canvasRef.current.getContext('2d');
        if (!ctx) return;

        // Check if the game is over
        if (gameRef.current.getGameState() === 'gsGameOver') {
            return;
        }

        // Handle key press
        gameRef.current.checkKey(ctx, event.keyCode, isHumanOpponent);
        
        // Redraw the game
        drawGame(ctx);
    }, [isHumanOpponent, drawGame]);

    // Add keyboard event listener
    useEffect(() => {
        window.addEventListener('keydown', handleKeyDown);
        return () => {
            window.removeEventListener('keydown', handleKeyDown);
        };
    }, [handleKeyDown]);

    // Handle new game
    const handleNewGame = useCallback(() => {
        if (!gameRef.current || !canvasRef.current) return;

        const ctx = canvasRef.current.getContext('2d');
        if (!ctx) return;

        gameRef.current.reset(ctx);
        drawGame(ctx);
    }, [drawGame]);

    return (
        <div style={{ textAlign: 'center', padding: '20px' }}>
            <div style={{ marginBottom: '10px' }}>
                <button onClick={handleNewGame} style={{ marginRight: '10px' }}>
                    New Game
                </button>
                <span style={{ color: 'white' }}>
                    Game State: {gameState}
                </span>
            </div>
            <canvas
                ref={canvasRef}
                style={{
                    border: '1px solid #333',
                    backgroundColor: 'black',
                    display: 'block',
                    margin: '0 auto'
                }}
                tabIndex={0}
            />
            <div style={{ marginTop: '10px', color: 'white', fontSize: '12px' }}>
                <p>Left Player: Z/X to change color, Space to confirm</p>
                <p>Right Player: Arrow keys to change color, Enter to confirm</p>
            </div>
        </div>
    );
}; 