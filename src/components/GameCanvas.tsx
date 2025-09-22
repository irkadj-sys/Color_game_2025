import React, { useRef, useEffect, useState, useCallback, forwardRef, useImperativeHandle } from 'react';
import { TGameWin } from '../game/TGameWin';
import { GAME_CONSTANTS } from '../constants/GameConstants';

interface GameCanvasProps {
    isHumanOpponent: boolean;
    gameStarted: boolean;
}

export const GameCanvas = forwardRef<any, GameCanvasProps>(({ isHumanOpponent, gameStarted }, ref) => {
    const canvasRef = useRef<HTMLCanvasElement>(null);
    const gameRef = useRef<TGameWin | null>(null);
    const [gameState, setGameState] = useState<string>('gsGameL');

    // Draw game function
    const drawGame = useCallback((ctx: CanvasRenderingContext2D) => {
        if (!gameRef.current) return;
        ctx.fillStyle = 'rgb(0,0,0)';
        ctx.fillRect(0, 0, ctx.canvas.width, ctx.canvas.height);
        gameRef.current.drawField(ctx);
        setGameState(gameRef.current.getGameState());
    }, []);

    // Expose handleControl to parent via ref
    useImperativeHandle(ref, () => ({
        handleControl: (keyCode: number) => {
            if (!gameRef.current || !canvasRef.current) return;
            const ctx = canvasRef.current.getContext('2d');
            if (!ctx) return;
            gameRef.current.checkKey(ctx, keyCode, isHumanOpponent);
            drawGame(ctx);
        }
    }));

    // Initialize game
    useEffect(() => {
        const canvas = canvasRef.current;
        if (!canvas) return;
        const ctx = canvas.getContext('2d');
        if (!ctx) return;
        // Responsive canvas sizing for landscape mobile
        function resizeCanvas() {
            const width = window.innerWidth;
            const height = Math.min(window.innerHeight * 0.7, GAME_CONSTANTS.HEIGHT + 100);
            canvas.width = width;
            canvas.height = height;
        }
        resizeCanvas();
        window.addEventListener('resize', resizeCanvas);
        gameRef.current = new TGameWin(ctx);
        drawGame(ctx);
        return () => {
            window.removeEventListener('resize', resizeCanvas);
        };
    }, [isHumanOpponent, drawGame, gameStarted]);
    return (
        <div style={{ width: '100vw', height: '100%', display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'center' }}>
            <canvas
                ref={canvasRef}
                style={{
                    border: '1px solid #333',
                    backgroundColor: 'black',
                    display: 'block',
                    margin: '0px auto',
                    width: '100vw',
                    height: '60vh',
                    touchAction: 'none',
                }}
                tabIndex={0}
            />
        </div>
    );
});
// End of forwardRef component