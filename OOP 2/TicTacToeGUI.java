import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TicTacToeGUI extends JFrame implements ActionListener {
    private final int BOARD_SIZE = 3;
    private JButton[][] buttons = new JButton[BOARD_SIZE][BOARD_SIZE];
    private char currentPlayer = 'X';
    private JButton resetButton;

    public TicTacToeGUI() {
        setTitle("Tic-Tac-Toe");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 350); // Increased the height for the reset button
        setLayout(new GridLayout(BOARD_SIZE + 1, BOARD_SIZE));

        initializeBoard();
        addButtonsToFrame();
        initializeResetButton();

        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void initializeBoard() {
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                buttons[row][col] = new JButton("");
                buttons[row][col].setFont(new Font("Arial", Font.PLAIN, 60));
                buttons[row][col].setFocusPainted(false);
                buttons[row][col].addActionListener(this);
            }
        }
    }

    private void addButtonsToFrame() {
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                add(buttons[row][col]);
            }
        }
    }

    private void initializeResetButton() {
        resetButton = new JButton("Reset Game");
        resetButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                resetGame();
            }
        });

        // Add reset button to the frame
        add(resetButton);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton clickedButton = (JButton) e.getSource();

        if (clickedButton.getText().equals("")) {
            clickedButton.setText(Character.toString(currentPlayer));
            clickedButton.setEnabled(false);

            if (checkWin()) {
                JOptionPane.showMessageDialog(this, "Player " + currentPlayer + " wins!");
                resetGame();
            } else if (isBoardFull()) {
                JOptionPane.showMessageDialog(this, "It's a draw!");
                resetGame();
            } else {
                togglePlayer();
            }
        }
    }

    private boolean checkWin() {
        String[] lines = new String[8];

        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < BOARD_SIZE; i++) {
            lines[i] = "";
            lines[i + BOARD_SIZE] = "";
            for (int j = 0; j < BOARD_SIZE; j++) {
                lines[i] += buttons[i][j].getText();
                lines[i + BOARD_SIZE] += buttons[j][i].getText();
            }
        }

        // Check diagonals
        lines[6] = "";
        lines[7] = "";
        for (int i = 0; i < BOARD_SIZE; i++) {
            lines[6] += buttons[i][i].getText();
            lines[7] += buttons[i][BOARD_SIZE - 1 - i].getText();
        }

        for (String line : lines) {
            if (line.equals("XXX") || line.equals("OOO")) {
                return true;
            }
        }

        return false;
    }

    private boolean isBoardFull() {
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                if (buttons[row][col].getText().equals("")) {
                    return false;
                }
            }
        }
        return true;
    }

    private void togglePlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    private void resetGame() {
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                buttons[row][col].setText("");
                buttons[row][col].setEnabled(true);
            }
        }
        currentPlayer = 'X';
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new TicTacToeGUI());
    }
}
