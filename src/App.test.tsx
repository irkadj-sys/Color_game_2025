
import { render, screen } from '@testing-library/react';
import '@testing-library/jest-dom';
import App from './App';

// Mock HTMLCanvasElement.getContext to prevent jsdom errors
beforeAll(() => {
    HTMLCanvasElement.prototype.getContext = jest.fn(() => ({
        fillRect: jest.fn(),
        fillStyle: '',
        strokeStyle: '',
        lineWidth: 0,
        strokeRect: jest.fn(),
        fillText: jest.fn(),
        font: '',
        canvas: {
            width: 0,
            height: 0
        }
    })) as any;
});

test('renders the app header', () => {
  render(<App />);
  // Check for the Game Start button
  expect(screen.getByText(/Game Start/i)).toBeInTheDocument();
});
