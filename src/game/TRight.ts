import { TSide } from './TSide';
import { TBoard } from './TBoard';
import { GAME_CONSTANTS } from '../constants/GameConstants';

export class TRight extends TSide {
    constructor(hDC: CanvasRenderingContext2D, game: TBoard) {
        super(game, GAME_CONSTANTS.DR);
        
        // Initialize position matching the original
        this.sColor = this.hGame.getCell(0, this.hGame.getW() - 1) - 1;
        this.hGame.setCell(0, this.hGame.getW() - 1, this.playerCode);
        this.score = 1;
        this.check(hDC, 0);
        this.sColor = 0;
        this.change(hDC, 0);
    }

    check(hDC: CanvasRenderingContext2D, forbid: number): number {
        let i: number, j: number, ii: number;
        let backi: boolean, backj: boolean;

        if (this.sColor !== this.fieldColor - 1 && this.sColor !== forbid - 1) {
            this.fieldColor = this.sColor + 1;
        } else {
            return 0;
        }

        i = 0;
        while (i < this.hGame.getH()) {
            backi = false;
            j = this.hGame.getW() - 1;
            while (j >= 0) {
                backj = false;
                ii = i - 1 + (2 * (j % 2));
                
                if (this.hGame.getCell(i, j) & this.playerCode) {
                    this.drawRomb(hDC, i, j, this.fieldColor - 1);
                    
                    if (ii >= 0 && ii < this.hGame.getH()) {
                        if (j + 1 < this.hGame.getW()) {
                            if (this.hGame.getCell(ii, j + 1) === this.fieldColor) {
                                this.hGame.setCell(ii, j + 1, this.playerCode);
                                this.score++;
                                if (ii < i) backi = true;
                                backj = true;
                            }
                        }
                        if (j - 1 >= 0) {
                            if (this.hGame.getCell(ii, j - 1) === this.fieldColor) {
                                this.hGame.setCell(ii, j - 1, this.playerCode);
                                this.score++;
                                if (ii < i) backi = true;
                            }
                        }
                    }
                    
                    if (j + 1 < this.hGame.getW()) {
                        if (this.hGame.getCell(i, j + 1) === this.fieldColor) {
                            this.hGame.setCell(i, j + 1, this.playerCode);
                            this.score++;
                            backj = true;
                        }
                    }
                    if (j - 1 >= 0) {
                        if (this.hGame.getCell(i, j - 1) === this.fieldColor) {
                            this.hGame.setCell(i, j - 1, this.playerCode);
                            this.score++;
                        }
                    }
                    
                    this.hGame.resetCell(i, j, this.playerCode + this.fieldColor);
                }
                
                if (!backj) j--;
                else if (j < this.hGame.getW() - 2) j++;
            }
            if (!backi) i++;
            else if (i) i--;
        }

        this.printScore(hDC);
        
        if (this.score > (this.hGame.getW() * this.hGame.getH() - this.hGame.getW() / 2) / 2) {
            this.animation(hDC);
            return -1;
        } else {
            return 1;
        }
    }

    printScore(hDC: CanvasRenderingContext2D): void {
        hDC.fillStyle = 'rgb(255,255,255)';
        hDC.font = '16px Arial';
        const scoreText = `${this.score}    `;
        hDC.fillText(scoreText, 3 * GAME_CONSTANTS.WIDTH / 4 - GAME_CONSTANTS.RECT_S, GAME_CONSTANTS.HEIGHT - 70);
    }

    selectColor(hDC: CanvasRenderingContext2D, forbid: number): void {
        // AI color selection logic
        // This would implement the computer opponent logic
        this.sColor = Math.floor(Math.random() * GAME_CONSTANTS.NUMBER_COLORS);
        while (this.sColor === forbid - 1) {
            this.sColor = Math.floor(Math.random() * GAME_CONSTANTS.NUMBER_COLORS);
        }
    }

    animation(hDC: CanvasRenderingContext2D): void {
        // Implementation for win animation
        // This would match the original animation logic
    }

    // Override positioning methods for right side
    protected getRectColLeft(): number {
        return 3 * GAME_CONSTANTS.WIDTH / 4 - GAME_CONSTANTS.RECT_S * 2;
    }

    protected getRectColTop(): number {
        return GAME_CONSTANTS.HEIGHT - 93;
    }

    protected getRectColRight(): number {
        return this.getRectColLeft() + GAME_CONSTANTS.RECT_S / 2;
    }

    protected getRectColBottom(): number {
        return this.getRectColTop() + GAME_CONSTANTS.RECT_S / 2;
    }
} 