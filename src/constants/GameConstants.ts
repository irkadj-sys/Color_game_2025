// Game constants matching the original C++ code exactly
export const GAME_CONSTANTS = {
    // Board dimensions
    W: 89,  // Board width
    H: 25,  // Board height
    
    // Player codes
    DL: 64,  // Left player code
    DR: 128, // Right player code
    
    // Colors
    NUMBER_COLORS: 5,
    
    // Window dimensions (from original)
    WIDTH: 580,
    HEIGHT: 390,
    RECT_S: 16,
    
    // Game states
    GAME_STATES: {
        GAME_OVER: 'gsGameOver',
        GAME_L: 'gsGameL',
        GAME_R: 'gsGameR'
    }
} as const;

// Color definitions matching the original C++ Color array
export const COLORS: [number, number, number][][] = [
    // Blue colors
    [
        [0, 65, 246],   // 4
        [0, 98, 255],   // 5
        [0, 164, 255],  // 9
        [0, 0, 255]     // 0, 32, 255
    ],
    // Green colors
    [
        [0, 164, 0],    // 7
        [32, 197, 65],  // 11
        [32, 255, 65],  //
        [0, 131, 0]     //
    ],
    // Red colors
    [
        [197, 0, 0],    //
        [255, 32, 0],   // 6
        [255, 131, 131],//
        [197, 0, 0]     //
    ],
    // Yellow colors
    [
        [255, 160, 0],  //
        [255, 197, 0],  //
        [255, 255, 102],//
        [197, 131, 0]   //
    ],
    // Violet colors
    [
        [255, 131, 255],//
        [197, 96, 255], //
        [255, 131, 255],//
        [197, 96, 255]  //
    ]
];

// Romb (diamond) pattern matching the original C++ Romb array
export const ROMB_PATTERN: number[] = [
    0,0,0,0,1,1,0,0,0,0,
    0,0,0,1,3,2,1,0,0,0,
    0,0,1,3,3,2,2,1,0,0,
    0,1,3,3,3,2,2,2,1,0,
    1,3,3,3,3,2,2,2,2,1,
    1,2,2,2,2,4,4,4,4,1,
    0,1,2,2,2,4,4,4,1,0,
    0,0,1,2,2,4,4,1,0,0,
    0,0,0,1,2,4,1,0,0,0,
    0,0,0,0,1,1,0,0,0,0
]; 