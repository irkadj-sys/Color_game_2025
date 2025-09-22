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

    // Concrete methods matching the original implementation
    bigRect(hDC: CanvasRenderingContext2D): void {
        // Draw the big rectangle around the currently selected color
        const selectedColorX = this.getRectColLeft() + this.sColor * 16;
        const selectedColorY = this.getRectColTop();
        const colorSize = 8; // RECT_S/2
        
        const rectLeft = selectedColorX - GAME_CONSTANTS.RECT_S / 4;
        const rectTop = selectedColorY - GAME_CONSTANTS.RECT_S / 4;
        const rectRight = selectedColorX + colorSize + GAME_CONSTANTS.RECT_S / 4;
        const rectBottom = selectedColorY + colorSize + GAME_CONSTANTS.RECT_S / 4;

        hDC.strokeStyle = 'rgb(255,255,255)';
        hDC.lineWidth = 2;
        hDC.strokeRect(rectLeft, rectTop, rectRight - rectLeft, rectBottom - rectTop);
    }

    panel(hDC: CanvasRenderingContext2D): void {
        // Draw the color selection panel
        for (let i = 0; i < GAME_CONSTANTS.NUMBER_COLORS; i++) {
            const color = COLORS[i][1];
            hDC.fillStyle = `rgb(${color[0]},${color[1]},${color[2]})`;
            hDC.fillRect(
                this.getRectColLeft() + i * 16,
                this.getRectColTop(),
                8, // RECT_S/2
                8  // RECT_S/2
            );
        }
    }

    change(hDC: CanvasRenderingContext2D, delta: number): void {
        // Update color selection
        this.sColor += delta;
        if (this.sColor === GAME_CONSTANTS.NUMBER_COLORS) {
            this.sColor = 0;
        } else if (this.sColor === -1) {
            this.sColor = GAME_CONSTANTS.NUMBER_COLORS - 1;
        }
        
        // Redraw the large selection rectangle for the new color
        this.bigRect(hDC);
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

    // Abstract positioning methods that must be implemented by subclasses
    protected abstract getRectColLeft(): number;
    protected abstract getRectColTop(): number;
    protected abstract getRectColRight(): number;
    protected abstract getRectColBottom(): number;
} 