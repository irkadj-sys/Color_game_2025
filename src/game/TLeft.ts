import { TSide } from './TSide';
import { TBoard } from './TBoard';
import { GAME_CONSTANTS } from '../constants/GameConstants';

export class TLeft extends TSide {
    constructor(hDC: CanvasRenderingContext2D, game: TBoard) {
        super(game, GAME_CONSTANTS.DL);
        
        // Initialize position matching the original
        this.sColor = this.hGame.getCell(this.hGame.getH() - 1, 0) - 1;
        this.hGame.setCell(this.hGame.getH() - 1, 0, this.playerCode);
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

        i = this.hGame.getH() - 1;
        while (i >= 0) {
            backi = false;
            j = 0;
            while (j < this.hGame.getW()) {
                backj = false;
                ii = i - 1 + (2 * (j % 2));
                
                if (this.hGame.getCell(i, j) & this.playerCode) {
                    this.drawRomb(hDC, i, j, this.fieldColor - 1);
                    
                    if (ii >= 0 && ii < this.hGame.getH()) {
                        if (j + 1 < this.hGame.getW()) {
                            if (this.hGame.getCell(ii, j + 1) === this.fieldColor) {
                                this.hGame.setCell(ii, j + 1, this.playerCode);
                                this.score++;
                                if (ii > i) backi = true;
                            }
                        }
                        if (j - 1 >= 0) {
                            if (this.hGame.getCell(ii, j - 1) === this.fieldColor) {
                                this.hGame.setCell(ii, j - 1, this.playerCode);
                                this.score++;
                                backj = true;
                                if (ii > i) backi = true;
                            }
                        }
                    }
                    
                    if (j + 1 < this.hGame.getW()) {
                        if (this.hGame.getCell(i, j + 1) === this.fieldColor) {
                            this.hGame.setCell(i, j + 1, this.playerCode);
                            this.score++;
                        }
                    }
                    if (j - 1 >= 0) {
                        if (this.hGame.getCell(i, j - 1) === this.fieldColor) {
                            this.hGame.setCell(i, j - 1, this.playerCode);
                            this.score++;
                            backj = true;
                        }
                    }
                    
                    this.hGame.resetCell(i, j, this.playerCode + this.fieldColor);
                }
                
                if (!backj) j++;
                else if (j) j--;
            }
            if (!backi) i--;
            else if (i < this.hGame.getH() - 1) i++;
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
        hDC.fillText(scoreText, GAME_CONSTANTS.WIDTH / 4 - GAME_CONSTANTS.RECT_S, GAME_CONSTANTS.HEIGHT + 50);
    }

    animation(hDC: CanvasRenderingContext2D): void {
        // Implementation for win animation
        // This would match the original animation logic
    }

    // Override positioning methods for left side
    protected getRectColLeft(): number {
        return GAME_CONSTANTS.WIDTH / 4 - GAME_CONSTANTS.RECT_S * 2;
    }

    protected getRectColTop(): number {
        return GAME_CONSTANTS.HEIGHT + 20; // Position in the extra space we added
    }

    protected getRectColRight(): number {
        return this.getRectColLeft() + GAME_CONSTANTS.RECT_S / 2;
    }

    protected getRectColBottom(): number {
        return this.getRectColTop() + GAME_CONSTANTS.RECT_S / 2;
    }
} 