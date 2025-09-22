
import React, { useState } from 'react';
import { GameCanvas } from './components/GameCanvas';
import './App.css';

function App() {
    const [isHumanOpponent, setIsHumanOpponent] = useState<boolean>(false);
    const [gameStarted, setGameStarted] = useState<boolean>(false);

    // Store a ref to call GameCanvas control handler
    const gameCanvasRef = React.useRef<any>(null);
    const handleControl = (keyCode: number) => {
        if (gameCanvasRef.current && typeof gameCanvasRef.current.handleControl === 'function') {
            gameCanvasRef.current.handleControl(keyCode);
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
                <div style={{ width: '100vw', background: '#222', color: '#fff', display: 'flex', justifyContent: 'space-around', alignItems: 'center', padding: '4px 0 4px 0', marginTop: '2px', borderRadius: '0 0 16px 16px' }}>
                    <div style={{ display: 'flex', flexDirection: 'row', gap: '12px' }}>
                        <button onClick={() => handleControl(90)} style={{ fontSize: '1.2rem', padding: '8px 14px', borderRadius: '8px', background: '#e91e63', color: '#fff', border: 'none' }}>Z</button>
                        <button onClick={() => handleControl(88)} style={{ fontSize: '1.2rem', padding: '8px 14px', borderRadius: '8px', background: '#9c27b0', color: '#fff', border: 'none' }}>X</button>
                        <button onClick={() => handleControl(32)} style={{ fontSize: '1.2rem', padding: '8px 14px', borderRadius: '8px', background: '#4caf50', color: '#fff', border: 'none' }}>Space</button>
                    </div>
                    <div style={{ display: 'flex', flexDirection: 'row', gap: '12px' }}>
                        <button onClick={() => handleControl(37)} style={{ fontSize: '1.2rem', padding: '8px 14px', borderRadius: '8px', background: '#2196f3', color: '#fff', border: 'none' }}>←</button>
                        <button onClick={() => handleControl(39)} style={{ fontSize: '1.2rem', padding: '8px 14px', borderRadius: '8px', background: '#2196f3', color: '#fff', border: 'none' }}>→</button>
                        <button onClick={() => handleControl(13)} style={{ fontSize: '1.2rem', padding: '8px 14px', borderRadius: '8px', background: '#ff9800', color: '#fff', border: 'none' }}>Enter</button>
                    </div>
                </div>
            </main>
        </div>
    );
}

export default App;