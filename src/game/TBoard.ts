export class TBoard {
    private board: number[][];
    private bHt: number;
    private bWt: number;

    constructor(Ht: number, Wt: number) {
        this.bHt = Ht;
        this.bWt = Wt;
        this.board = [];

        // Initialize board matching the original C++ logic
        for (let i = 0; i < Ht; i++) {
            this.board[i] = [];
            for (let j = 0; j < Wt; j++) {
                // Match the original logic: 5.0 * rand() / RAND_MAX + 1
                this.board[i][j] = Math.floor(5.0 * Math.random()) + 1;
                if (i === Ht - 1 && j % 2) {
                    this.board[i][j] = 0;
                }
            }
        }
    }

    getCell(i: number, j: number): number {
        return this.board[i][j];
    }

    setCell(i: number, j: number, playerCD: number): number {
        this.board[i][j] += playerCD;
        return this.board[i][j];
    }

    resetCell(i: number, j: number, cell: number): number {
        this.board[i][j] = cell;
        return this.board[i][j];
    }

    getH(): number {
        return this.bHt;
    }

    getW(): number {
        return this.bWt;
    }

    // Method to get the entire board for debugging/display
    getBoard(): number[][] {
        return this.board.map(row => [...row]);
    }
} 