import { TBoard } from './TBoard';
import { TLeft } from './TLeft';
import { TRight } from './TRight';

export type GameState = 'gsGameOver' | 'gsGameL' | 'gsGameR';

export class TGameWin {
    private game: TBoard;
    private left: TLeft;
    private right: TRight;
    private gameState: GameState;
    private static readonly H = 25;
    private static readonly W = 89;

    constructor(hDC: CanvasRenderingContext2D) {
        this.game = new TBoard(TGameWin.H, TGameWin.W);
        this.left = new TLeft(hDC, this.game);
        this.right = new TRight(hDC, this.game);
        this.gameState = 'gsGameL';
    }

    drawField(hDC: CanvasRenderingContext2D): void {
        this.left.panel(hDC);
        this.right.panel(hDC);
        this.left.paintField(hDC);
        
        if (this.gameState !== 'gsGameOver') {
            this.left.bigRect(hDC);
            this.right.bigRect(hDC);
        }
        
        this.left.printScore(hDC);
        this.right.printScore(hDC);
    }

    checkKey(hDC: CanvasRenderingContext2D, key: number, human: boolean): void {
        let s: number;

        if (this.gameState === 'gsGameR') {
            // Right player turn
            switch (key) {
                case 37: // VK_LEFT
                case 100: // VK_NUMPAD4
                    this.right.change(hDC, -1);
                    break;
                case 39: // VK_RIGHT
                case 102: // VK_NUMPAD6
                    this.right.change(hDC, 1);
                    break;
                case 13: // 0x0D (Enter)
                    s = this.right.check(hDC, this.left.nowColor());
                    if (s === -1) {
                        this.gameState = 'gsGameOver';
                    } else if (s === 0) {
                        return;
                    } else {
                        this.gameState = 'gsGameL';
                    }
                    break;
                default:
                    return;
            }
        } else if (this.gameState === 'gsGameL') {
            // Left player turn
            switch (key) {
                case 90: // 0x5A (Z)
                    this.left.change(hDC, -1);
                    break;
                case 88: // 0x58 (X)
                    this.left.change(hDC, 1);
                    break;
                case 32: // 0x20 (Space)
                    s = this.left.check(hDC, this.right.nowColor());
                    if (s === -1) {
                        this.gameState = 'gsGameOver';
                    } else if (s === 0) {
                        return;
                    } else if (human) {
                        this.gameState = 'gsGameR';
                    } else {
                        // Computer opponent logic
                        let a = 0;
                        while (!a) {
                            this.right.selectColor(hDC, this.left.nowColor());
                            a = this.right.check(hDC, this.left.nowColor());
                        }
                    }
                    break;
            }
        }
    }

    getGameState(): GameState {
        return this.gameState;
    }

    setGameState(state: GameState): void {
        this.gameState = state;
    }

    // Method to reset the game
    reset(hDC: CanvasRenderingContext2D): void {
        this.game = new TBoard(TGameWin.H, TGameWin.W);
        this.left = new TLeft(hDC, this.game);
        this.right = new TRight(hDC, this.game);
        this.gameState = 'gsGameL';
    }
} 