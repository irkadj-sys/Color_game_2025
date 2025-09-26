import React from 'react';
import { COLORS } from '../constants/GameConstants';

interface ColorSquareProps {
    colorIndex: number;
    isSelected: boolean;
    onClick: () => void;
    disabled?: boolean;
}

const ColorSquare: React.FC<ColorSquareProps> = ({ colorIndex, isSelected, onClick, disabled = false }) => {
    const color = COLORS[colorIndex][1]; // Use the second color variant for consistency
    const rgb = `rgb(${color[0]},${color[1]},${color[2]})`;
    
    return (
        <div
            onClick={disabled ? undefined : onClick}
            style={{
                width: '20px',
                height: '20px',
                backgroundColor: rgb,
                border: isSelected ? '2px solid #fff' : '1px solid #333',
                borderRadius: '4px',
                cursor: disabled ? 'not-allowed' : 'pointer',
                opacity: disabled ? 0.5 : 1,
                transition: 'all 0.2s ease',
                boxShadow: isSelected ? '0 0 5px rgba(255,255,255,0.5)' : 'none'
            }}
        />
    );
};

interface PlayerColorSelectorProps {
    player: 'left' | 'right';
    availableColors: number[];
    selectedColor: number;
    onColorSelect: (colorIndex: number) => void;
    disabled?: boolean;
}

export const PlayerColorSelector: React.FC<PlayerColorSelectorProps> = ({ 
    player, 
    availableColors, 
    selectedColor, 
    onColorSelect,
    disabled = false 
}) => {
    return (
        <div style={{ 
            display: 'flex', 
            flexDirection: 'column', 
            alignItems: 'center', 
            gap: '4px' 
        }}>
            <div style={{ 
                color: '#fff', 
                fontSize: '0.7rem', 
                fontWeight: 'bold',
                textTransform: 'capitalize'
            }}>
                {player} Player
            </div>
            <div style={{ 
                display: 'flex', 
                flexDirection: 'row', 
                gap: '4px',
                justifyContent: 'center',
                flexWrap: 'wrap'
            }}>
                {availableColors.map((colorIndex) => (
                    <ColorSquare
                        key={colorIndex}
                        colorIndex={colorIndex}
                        isSelected={colorIndex === selectedColor}
                        onClick={() => onColorSelect(colorIndex)}
                        disabled={disabled}
                    />
                ))}
            </div>
        </div>
    );
};
