package sys;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class Frodo extends BasicRobot {

	public Frodo(String jsonString) {
		super(jsonString);
		// TODO Auto-generated constructor stub
	}

	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		Graphics2D g2=(Graphics2D)g;
		
		
		g2.setColor(new Color(181,136,51));
		g2.fillRect(X, Y, width, height);

		g2.setColor(new Color(0,0,0));
		g2.drawRect(X, Y, width, height);
		
 		
		g2.setColor(new Color(181,136,51));
		g2.setStroke(new BasicStroke(armSize));
		g2.drawLine(leftShoulder.x, leftShoulder.y, leftElbow.x, leftElbow.y);
		g2.drawLine(leftElbow.x, leftElbow.y, leftHand.x, leftHand.y);
		
		g2.drawLine(rightShoulder.x, rightShoulder.y, rightElbow.x, rightElbow.y);
		g2.drawLine(rightElbow.x, rightElbow.y, rightHand.x, rightHand.y);
		g2.setColor(new Color(192,27,21));
		g2.drawLine(head.x-20, head.y+5, head.x+20, head.y+5);
		g2.setColor(new Color(157,156,152));
		g2.fillOval(head.x-5, head.y+10, 8, 8);
		g2.setColor(new Color(181,136,51));
		
		g2.setStroke(new BasicStroke(legSize));
		g2.drawLine(leftLeg.x, leftLeg.y, leftKnee.x, leftKnee.y);
		g2.drawLine(leftKnee.x, leftKnee.y, leftFoot.x, leftFoot.y);
		g2.drawLine(rightLeg.x, rightLeg.y, rightKnee.x, rightKnee.y);
		g2.drawLine(rightKnee.x, rightKnee.y, rightFoot.x, rightFoot.y);
		
		
		g2.setColor(new Color(181,136,51));
		g2.rotate(headangle, head.x, head.y);
		g2.fillOval(head.x-(int)(headWidth/1.9), head.y-headHeight+5, headWidth, headHeight);
		g2.fillOval(head.x+5, head.y-headHeight, 15, 15);
		g2.fillOval(head.x-(int)(headWidth/2.5), head.y-headHeight, 15, 15);
		g2.setColor(new Color(0,0,0));
		g2.setStroke(new BasicStroke(2));
		g2.drawLine(head.x-5, head.y-2,head.x+5, head.y-2);
		//g2.fillOval(head.x-headWidth,head.y-(headHeight/2),headWidth,headHeight/2);
				
	}
	
}