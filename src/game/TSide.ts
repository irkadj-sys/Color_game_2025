import { TBoard } from './TBoard';
import { COLORS, ROMB_PATTERN, GAME_CONSTANTS } from '../constants/GameConstants';

export abstract class TSide {
    protected sColor: number = 0;
    protected fieldColor: number = 0;
    protected score: number = 0;
    protected hGame: TBoard;
    protected playerCode: number;

    constructor(game: TBoard, playerCode: number) {
        this.hGame = game;
        this.playerCode = playerCode;
    }

    // Abstract methods that must be implemented by subclasses
    abstract check(hDC: CanvasRenderingContext2D, forbid: number): number;
    abstract printScore(hDC: CanvasRenderingContext2D): void;
    abstract animation(hDC: CanvasRenderingContext2D): void;

    change(hDC: CanvasRenderingContext2D, delta: number): void {
        // Update color selection
        this.sColor += delta;
        if (this.sColor === GAME_CONSTANTS.NUMBER_COLORS) {
            this.sColor = 0;
        } else if (this.sColor === -1) {
            this.sColor = GAME_CONSTANTS.NUMBER_COLORS - 1;
        }
    }

    drawRomb(hDC: CanvasRenderingContext2D, i: number, j: number, color: number): void {
        // Match the original positioning logic exactly
        const x = 20 + 6 * ((j % 2) + i * 2);
        const y = 20 + j * 6;

        // Draw the romb pattern
        for (let dx = 0; dx < 10; dx++) {
            for (let dy = 0; dy < 10; dy++) {
                const patternIndex = dx * 10 + dy;
                const patternValue = ROMB_PATTERN[patternIndex];
                
                if (patternValue > 0) {
                    const colorIndex = patternValue - 1;
                    const rgb = COLORS[color][colorIndex];
                    hDC.fillStyle = `rgb(${rgb[0]},${rgb[1]},${rgb[2]})`;
                    hDC.fillRect(y + dy, x + dx, 1, 1);
                }
            }
        }
    }

    paintField(hDC: CanvasRenderingContext2D): void {
        const H = this.hGame.getH();
        const W = this.hGame.getW();
        
        for (let i = 0; i < H; i++) {
            for (let j = 0; j < W; j++) {
                const color = this.hGame.getCell(i, j);
                if (color) {
                    this.drawRomb(hDC, i, j, (color & 63) - 1);
                }
            }
        }
    }

    nowColor(): number {
        return this.fieldColor;
    }

    // Public getter/setter for sColor
    getSColor(): number {
        return this.sColor;
    }

    setSColor(colorIndex: number): void {
        this.sColor = colorIndex;
    }

    // Public getter for score
    getScore(): number {
        return this.score;
    }
} 