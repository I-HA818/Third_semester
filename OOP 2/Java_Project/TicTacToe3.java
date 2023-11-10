import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;

public class TicTacToe3 implements ActionListener{
	
		int x,o;
		boolean winnerfound=false;
		String check;
		JFrame frame = new JFrame();
		JPanel title_panel = new JPanel();
		JPanel button_panel = new JPanel();
		JLabel textfield = new JLabel();
		JButton[] buttons = new JButton[9];
		JButton restartButton;
		boolean player1_turn;
		boolean is_Draw;
	
		TicTacToe3(){
			
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.setSize(800,800);
			frame.getContentPane().setBackground(new Color(50,50,50));
			frame.setLayout(new BorderLayout());
			frame.setVisible(true);
			
			textfield.setBackground(new Color(25,25,25));
			textfield.setForeground(new Color(25,230,0));
			textfield.setFont(new Font("Helvatica",Font.BOLD,75));
			textfield.setHorizontalAlignment(JLabel.CENTER);
			textfield.setText("Tic Tac Toe");
			textfield.setOpaque(true);
			
			title_panel.setLayout(new BorderLayout());
			title_panel.setBounds(0,0,800,100);
			
			button_panel.setLayout(new GridLayout(3,3));
			button_panel.setBackground(new Color(25,25,25));
			
			for(int i=0;i<9;i++) {
				buttons[i] = new JButton();
				button_panel.add(buttons[i]);
				buttons[i].setFocusable(false);
				buttons[i].setFont(new Font("Helvatica",Font.BOLD,120));
				buttons[i].setBackground(new Color(25,25,25));
				
				buttons[i].addActionListener(this);
			}
			
			 restartButton = new JButton("Restart");
		        restartButton.setFocusable(false);
		        restartButton.setFont(new Font("Helvetica", Font.BOLD, 30));
		        restartButton.setBackground(new Color(25, 25, 25));
		        restartButton.setForeground(new Color(255, 255, 255));
		        restartButton.addActionListener(new ActionListener() {
		            @Override
		            public void actionPerformed(ActionEvent e) {
		                restartGame();
		            }
		        });
		        
			title_panel.add(textfield);
			frame.add(title_panel,BorderLayout.NORTH);
			frame.add(button_panel);
			frame.add(restartButton, BorderLayout.SOUTH);
			try {
				Thread.sleep(1300);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			firstTurn();
			
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			int i;
			for( i=0;i<9;i++) {
				if(e.getSource()==buttons[i]) {
					if(player1_turn) {
						if(buttons[i].getText()=="" ) {
							buttons[i].setForeground(new Color(255,0,0));
							buttons[i].setText("X");
							player1_turn=false;
							textfield.setText("O turn");
							textfield.setForeground(new Color(0,0,255));
							check();
							
						}
					}
					else {
						if(buttons[i].getText()=="" ) {
							buttons[i].setForeground(new Color(0,0,255));
							buttons[i].setText("O");
							player1_turn=true;
							textfield.setText("X turn");
							textfield.setForeground(new Color(255,0,0));
							check();
							
						}
					}
				}
				
			}
				 if(buttons[0].getText()!="" &&
					buttons[1].getText()!="" &&
					buttons[2].getText()!="" &&
					buttons[3].getText()!="" &&
					buttons[4].getText()!="" && 
					buttons[5].getText()!="" && 
					buttons[6].getText()!="" && 
					buttons[7].getText()!="" && 
					buttons[8].getText()!="" && 
					winnerfound==false) 
				draw();
		}
		
		public void firstTurn() {
			
			Random random = new Random();
			if(random.nextInt(2)==0) {
				player1_turn=true;
				textfield.setForeground(new Color(255,0,0));
				textfield.setText("X turn");
			
			}
			else {
				player1_turn=false;
				textfield.setText("O turn");
				textfield.setForeground(new Color(0,0,255));

			}
		}
		
		public void check() {
			if((buttons[0].getText()=="X") && 
						(buttons[1].getText()=="X") &&
						(buttons[2].getText()=="X")) {
						xWins(0,1,2);
						
					}
			if((buttons[3].getText()=="X") && 
					   (buttons[4].getText()=="X") &&
					   (buttons[5].getText()=="X")) {
						xWins(3,4,5);
					}
			if((buttons[6].getText()=="X") && 
					   (buttons[7].getText()=="X") &&
					   (buttons[8].getText()=="X")) {
						xWins(6,7,8);
					}
			if((buttons[0].getText()=="X") && 
					   (buttons[3].getText()=="X") &&
					   (buttons[6].getText()=="X")) {
						xWins(0,3,6);
					}
			if((buttons[0].getText()=="X") && 
					   (buttons[1].getText()=="X") &&
					   (buttons[2].getText()=="X")) {
						xWins(0,1,2);
					}
			if((buttons[1].getText()=="X") && 
					   (buttons[4].getText()=="X") &&
					   (buttons[7].getText()=="X")) {
						xWins(1,4,7);
					}
			if((buttons[2].getText()=="X") && 
					   (buttons[5].getText()=="X") &&
					   (buttons[8].getText()=="X")) {
						xWins(2,5,8);
					}
			if((buttons[0].getText()=="X") && 
					   (buttons[4].getText()=="X") &&
					   (buttons[8].getText()=="X")) {
						xWins(0,4,8);
					}
			
			
			
			if((buttons[0].getText()=="O") && 
					   (buttons[1].getText()=="O") &&
					   (buttons[2].getText()=="O")) {
						oWins(0,1,2);
					}
			if((buttons[2].getText()=="O") && 
					   (buttons[4].getText()=="O") &&
					   (buttons[6].getText()=="O")) {
						oWins(2,4,6);
					}
			if((buttons[0].getText()=="O") && 
					(buttons[1].getText()=="O") &&
					(buttons[2].getText()=="O")) {
					oWins(0,1,2);
					}
			if((buttons[3].getText()=="O") && 
				   (buttons[4].getText()=="O") &&
				   (buttons[5].getText()=="O")) {
					oWins(3,4,5);
				}
			if((buttons[6].getText()=="O") && 
					(buttons[7].getText()=="O") &&
				   (buttons[8].getText()=="O")) {
					oWins(6,7,8);
				}
			if((buttons[0].getText()=="O") && 
				   (buttons[3].getText()=="O") &&
				   (buttons[6].getText()=="O")) {
					oWins(0,3,6);
				}
			if((buttons[0].getText()=="O") && 
				   (buttons[1].getText()=="O") &&
				   (buttons[2].getText()=="O")) {
					oWins(0,1,2);
				}
			if((buttons[1].getText()=="O") && 
				   (buttons[4].getText()=="O") &&
				   (buttons[7].getText()=="O")) {
					oWins(1,4,7);
				}
			if((buttons[2].getText()=="O") && 
				   (buttons[5].getText()=="O") &&
				   (buttons[8].getText()=="O")) {
					oWins(2,5,8);
				}
			if((buttons[0].getText()=="O") && 
				   (buttons[4].getText()=="O") &&
				   (buttons[8].getText()=="O")) {
					oWins(0,4,8);
				}
			if((buttons[0].getText()=="O") && 
				(buttons[1].getText()=="O") &&
				   (buttons[2].getText()=="O")) {
					oWins(0,1,2);
				}
			if((buttons[2].getText()=="O") && 
				   (buttons[4].getText()=="O") &&
				   (buttons[6].getText()=="O")) {
					oWins(2,4,6);
				}
		}
		
		public void xWins(int a, int b, int c) {
			buttons[a].setBackground(Color.GREEN);
			buttons[b].setBackground(Color.GREEN);
			buttons[c].setBackground(Color.GREEN);
			
			for(int i=0;i<9;i++) {
				buttons[i].setEnabled(false);
			}
			
			textfield.setText("X wins!");
			textfield.setForeground(new Color(250,250,250));
			winnerfound=true;
			
		}
		
		public void oWins(int a ,int b, int c) {
			buttons[a].setBackground(Color.GREEN);
			buttons[b].setBackground(Color.GREEN);
			buttons[c].setBackground(Color.GREEN);
			
			for(int i=0;i<9;i++) {
				buttons[i].setEnabled(false);
			}
			
			textfield.setText("O wins!");
			textfield.setForeground(new Color(250,250,250));
			winnerfound=true;
			
		}
		
		public void draw() {
			textfield.setText("It's a draw!");
			textfield.setForeground(new Color(250,250,250));
			is_Draw=true;
			
		}
		
		public void restartGame() {
	
	        for (int i = 0; i < 9; i++) {
	            buttons[i].setText("");
	            buttons[i].setBackground(new Color(25, 25, 25));
	            buttons[i].setEnabled(true);
	        }
	        winnerfound = false;
	        is_Draw = false;
	        firstTurn();
	    }
		
}
