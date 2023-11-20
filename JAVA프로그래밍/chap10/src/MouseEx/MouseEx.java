package MouseEx;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MouseEx extends JFrame 
{
	private JLabel la = new JLabel("No Mouse Event");
	
	public MouseEx()
	{
		setTitle("MouseListener와 MouseMotionListener 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		MyMouseListener listener = 
				new MyMouseListener();
		c.addMouseListener(listener);
		c.addMouseMotionListener(listener);
	}
	
	class MyMouseListener implements MouseListener, MouseMotionListener
	{
		public void mousePressed(MouseEvent e)
		{
			la.setText("mousePressed(" + e.getX()+ "," + e.getY() + ")");
		}

		@Override
		public void mouseDragged(MouseEvent e) 
		{
			la.setText("mouseDragged(" + e.getX()+ "," + e.getY() + ")");
		}

		@Override
		public void mouseMoved(MouseEvent e) 
		{
			la.setText("mouseMoved(" + e.getX()+ "," + e.getY() + ")");
		}

		@Override
		public void mouseClicked(MouseEvent e) 
		{
			if(e.getClickCount() == 2)
			{
				int r = (int)(Math.random()*256);
				int g = (int)(Math.random()*256);
				int b = (int)(Math.random()*256);
				Component c = (Component)e.getSource();
				c.setBackground(new Color(r,b,g));
			}
			
		}

		@Override
		public void mouseReleased(MouseEvent e) 
		{
			la.setText("mouseReleased(" + e.getX()+ "," + e.getY() + ")");
		}

		@Override
		public void mouseEntered(MouseEvent e) 
		{
			Component c = ((Component)e.getSource());
			c.setBackground(Color.CYAN);
		}

		@Override
		public void mouseExited(MouseEvent e) 
		{
			Component c = ((Component)e.getSource());
			c.setBackground(Color.YELLOW);
		}
	}
}
	