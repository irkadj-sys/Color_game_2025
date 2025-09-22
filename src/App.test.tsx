
import { render, screen } from '@testing-library/react';
import '@testing-library/jest-dom';
import App from './App';

// Mock HTMLCanvasElement.getContext to prevent jsdom errors
beforeAll(() => {
  HTMLCanvasElement.prototype.getContext = jest.fn();
});

test('renders the app header', () => {
  render(<App />);
  // Check for the main header text
  expect(screen.getByText(/Colors Game 1995/i)).toBeInTheDocument();

    // Check for the Game Start button
    expect(screen.getByText(/Game Start/i)).toBeInTheDocument();

   
});
