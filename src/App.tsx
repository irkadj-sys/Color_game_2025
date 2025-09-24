
import React, { useState, useEffect } from 'react';
import { GameCanvas } from './components/GameCanvas';
import { PlayerColorSelector } from './components/PlayerColorSelector';
import './App.css';

function App() {
    const [isHumanOpponent, setIsHumanOpponent] = useState<boolean>(false);
    const [gameStarted, setGameStarted] = useState<boolean>(false);
    const [availableColors, setAvailableColors] = useState<number[]>([0, 1, 2]);
    const [leftPlayerColor, setLeftPlayerColor] = useState<number>(0);
    const [rightPlayerColor, setRightPlayerColor] = useState<number>(0);
    const [gameState, setGameState] = useState<string>('gsGameL');
    const [gameOver, setGameOver] = useState<boolean>(false);
    const [winner, setWinner] = useState<string>('');

    // Store a ref to call GameCanvas control handler
    const gameCanvasRef = React.useRef<any>(null);
    
    // Update game state periodically
    useEffect(() => {
        const interval = setInterval(() => {
            if (gameCanvasRef.current) {
                const currentGameState = gameCanvasRef.current.getGameState();
                const currentLeftColor = gameCanvasRef.current.getLeftPlayerColor();
                const currentRightColor = gameCanvasRef.current.getRightPlayerColor();
                const currentAvailableColors = gameCanvasRef.current.getAvailableColors();
                
                setGameState(currentGameState);
                setLeftPlayerColor(currentLeftColor);
                setRightPlayerColor(currentRightColor);
                setAvailableColors(currentAvailableColors);
                
                // Check for game over
                if (currentGameState === 'gsGameOver') {
                    setGameOver(true);
                    // Determine winner based on scores
                    const leftScore = gameCanvasRef.current.getLeftScore?.() || 0;
                    const rightScore = gameCanvasRef.current.getRightScore?.() || 0;
                    if (leftScore > rightScore) {
                        setWinner('Left Player');
                    } else if (rightScore > leftScore) {
                        setWinner('Right Player');
                    } else {
                        setWinner('Tie Game');
                    }
                }
            }
        }, 100); // Update every 100ms
        
        return () => clearInterval(interval);
    }, []);

    const handleLeftColorSelect = (colorIndex: number) => {
        if (gameCanvasRef.current && gameState === 'gsGameL') {
            gameCanvasRef.current.setLeftPlayerColor(colorIndex);
            // Immediately confirm the selection
            gameCanvasRef.current.handleControl(32); // Space key
        }
    };

    const handleRightColorSelect = (colorIndex: number) => {
        if (gameCanvasRef.current && gameState === 'gsGameR') {
            gameCanvasRef.current.setRightPlayerColor(colorIndex);
            // Immediately confirm the selection
            gameCanvasRef.current.handleControl(13); // Enter key
        }
    };


    return (
        <div className="App" style={{ minHeight: '100vh', width: '100vw', display: 'flex', flexDirection: 'column', background: '#111' }}>
            <header style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'center', padding: '10px 16px', background: '#222', color: '#fff', width: '100vw' }}>
                <button onClick={() => setGameStarted(true)} style={{ fontSize: '1rem', padding: '8px 16px', borderRadius: '6px', background: '#4caf50', color: '#fff', border: 'none' }}>Game Start</button>
                <button
                    onClick={() => setIsHumanOpponent(prev => !prev)}
                    style={{ fontSize: '1rem', padding: '8px 16px', borderRadius: '6px', background: '#2196f3', color: '#fff', border: 'none' }}
                >
                    Opponent: {isHumanOpponent ? 'Human' : 'Computer'}
                </button>
            </header>
            <main style={{ flex: 1, display: 'flex', flexDirection: 'column', justifyContent: 'center', alignItems: 'center', width: '100vw', height: '100%', overflow: 'hidden' }}>
                <GameCanvas ref={gameCanvasRef} isHumanOpponent={isHumanOpponent} gameStarted={gameStarted} />
                
                {/* Game Over Screen */}
                {gameOver && (
                    <div style={{
                        position: 'absolute',
                        top: '50%',
                        left: '50%',
                        transform: 'translate(-50%, -50%)',
                        background: 'rgba(0, 0, 0, 0.9)',
                        color: '#fff',
                        padding: '40px',
                        borderRadius: '16px',
                        textAlign: 'center',
                        zIndex: 2000,
                        border: '2px solid #4caf50'
                    }}>
                        <h2 style={{ margin: '0 0 20px 0', fontSize: '2rem', color: '#4caf50' }}>
                            Game Over!
                        </h2>
                        <p style={{ margin: '0 0 20px 0', fontSize: '1.5rem' }}>
                            Winner: {winner}
                        </p>
                        <button
                            onClick={() => {
                                setGameOver(false);
                                setWinner('');
                                setGameStarted(false);
                                // Reset the game
                                if (gameCanvasRef.current) {
                                    const canvas = document.querySelector('canvas');
                                    if (canvas) {
                                        const ctx = canvas.getContext('2d');
                                        if (ctx) {
                                            gameCanvasRef.current.reset(ctx);
                                        }
                                    }
                                }
                            }}
                            style={{
                                fontSize: '1rem',
                                padding: '12px 24px',
                                borderRadius: '8px',
                                background: '#4caf50',
                                color: '#fff',
                                border: 'none',
                                cursor: 'pointer'
                            }}
                        >
                            Play Again
                        </button>
                    </div>
                )}
                
                <div style={{ width: '100vw', background: '#222', color: '#fff', display: 'flex', justifyContent: 'space-around', alignItems: 'center', padding: '12px 0', marginTop: '2px', borderRadius: '0 0 16px 16px', position: 'relative', zIndex: 1000 }}>
                    <PlayerColorSelector
                        player="left"
                        availableColors={availableColors}
                        selectedColor={leftPlayerColor}
                        onColorSelect={handleLeftColorSelect}
                        disabled={gameState !== 'gsGameL' || gameOver}
                    />
                    <PlayerColorSelector
                        player="right"
                        availableColors={availableColors}
                        selectedColor={rightPlayerColor}
                        onColorSelect={handleRightColorSelect}
                        disabled={gameState !== 'gsGameR' || gameOver}
                    />
                </div>
            </main>
        </div>
    );
}

export default App;