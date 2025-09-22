import React, { useState } from 'react';
import { GameCanvas } from './components/GameCanvas';
import './App.css';

function App() {
    const [isHumanOpponent, setIsHumanOpponent] = useState<boolean>(true);

    return (
        <div className="App">
            <header className="App-header">
                <h1>Colors Game 1995</h1>
                <div style={{ marginBottom: '20px' }}>
                    <label>
                        <input
                            type="radio"
                            name="opponent"
                            checked={isHumanOpponent}
                            onChange={() => setIsHumanOpponent(true)}
                        />
                        Human
                    </label>
                    <label style={{ marginLeft: '20px' }}>
                        <input
                            type="radio"
                            name="opponent"
                            checked={!isHumanOpponent}
                            onChange={() => setIsHumanOpponent(false)}
                        />
                        Computer
                    </label>
                </div>
            </header>
            <main>
                <GameCanvas isHumanOpponent={isHumanOpponent} />
            </main>
        </div>
    );
}

export default App; 