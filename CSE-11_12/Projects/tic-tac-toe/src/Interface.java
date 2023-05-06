import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Objects;

public class Interface extends JFrame implements ActionListener {
    Board gameBoard = new Board();
    String userName = "";
    char board[][] = {{ '_', '_', '_' },
            { '_', '_', '_' },
            { '_', '_', '_' }};
    Container c = new Container();
    JButton button[] = new JButton[9];
    Font defaultFont = new Font("Rubik-Bold",Font.PLAIN,60);
    Interface(String title) {
        // JFrame config
        this.setTitle(title);
        this.setVisible(true);
        this.setBounds(1200, 250, 500, 500);
//        this.setResizable(false);


        // adding container
        c.setBounds(10, 10,280, 490);
        c.setVisible(true);
        c.setForeground(Color.RED);
        c.setLayout(new GridLayout(3,3));
        this.add(c);

        for (int i = 0 ; i < 9; i ++) {
            JButton btn = new JButton();
            btn.setText("");
            btn.setFont(defaultFont);
            btn.addActionListener(this);
            button[i] = btn;
            c.add(button[i]);
        }

        userName = JOptionPane.showInputDialog(this, "Enter your name to start the game:");
        JOptionPane.showMessageDialog(this, "Game Starts Now!\nYou move first.");
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        for (int i = 0; i < 9; i++) {
            if (actionEvent.getSource() == button[i]) {
                if(button[i].getText() == "") {
                    button[i].setText("X");
                    int r = i/3;
                    int c = i%3;
                    gameBoard.placeMark(r, c);
                }
                else JOptionPane.showMessageDialog(this, "You are not supposed to click this one!\nTry another.");
            }
            if (button[i].getText() != "") board[i/3][i%3] = button[i].getText().charAt(0);
        }

        // game over handling
        if(gameBoard.isGameOver()) {
            char winnerMark = gameBoard.getWinningMark().getMark();
            String winner = "";
            if (winnerMark == 'X')  winner = userName +  ", you have won!";
            else winner = "Sorry, " + userName + ", you failed.\nTry again.";
            JOptionPane.showMessageDialog(this, "Game Over!\n" + winner );

            for (int i = 0; i < 9; i++) {
                button[i].setText("");
                board = new char[][]{{'_', '_', '_'},
                        {'_', '_', '_'},
                        {'_', '_', '_'}};
            }
            gameBoard = new Board();

        }

        // playing AI
        else {
            int[] bestMove = MiniMaxImproved.getBestMove(gameBoard);
            board[bestMove[0]][bestMove[1]] = 'O';
            gameBoard.placeMark(bestMove[0], bestMove[1]);

            for (int i = 0; i < 9; i++) {
                if (board[i / 3][i % 3] != '_') button[i].setText(String.valueOf(board[i / 3][i % 3]));
            }
        }
    }
}