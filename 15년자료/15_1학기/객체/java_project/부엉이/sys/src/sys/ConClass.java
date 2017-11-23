package sys;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class ConClass extends BasicRobot {

	public ConClass(String jsonString) {
		super(jsonString);
		// TODO Auto-generated constructor stub
	}

	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		Graphics2D g2=(Graphics2D)g;
		
		
		g2.setColor(new Color(46,153,59));
		
		g2.fillRect(X, Y, width, height);
		g2.setStroke(new BasicStroke(armSize));
		g2.drawLine(leftShoulder.x, leftShoulder.y, leftElbow.x, leftElbow.y);
		g2.drawLine(leftElbow.x, leftElbow.y, leftHand.x, leftHand.y);
		
		g2.drawLine(rightShoulder.x, rightShoulder.y, rightElbow.x, rightElbow.y);
		g2.drawLine(rightElbow.x, rightElbow.y, rightHand.x, rightHand.y);
		
		
		g2.setStroke(new BasicStroke(legSize));
		g2.drawLine(leftLeg.x, leftLeg.y, leftKnee.x, leftKnee.y);
		g2.drawLine(leftKnee.x, leftKnee.y, leftFoot.x, leftFoot.y);
		g2.drawLine(rightLeg.x, rightLeg.y, rightKnee.x, rightKnee.y);
		g2.drawLine(rightKnee.x, rightKnee.y, rightFoot.x, rightFoot.y);
		
		
		
		g2.rotate(headangle, head.x, head.y);
		g2.fillOval(head.x-(int)(headWidth/1.7), head.y-headHeight, headWidth, headHeight);
		g2.fillOval(head.x-headWidth,head.y-(headHeight/2),headWidth,headHeight/2);
		

		g2.setStroke(new BasicStroke(0));
		
		
		g2.setColor(Color.YELLOW);
		
		g2.fillRoundRect(head.x-(int)(headWidth/3.4), head.y-(int)(headHeight/1.4), headWidth/3, headHeight/3, 100, 2);
		
		g2.setColor(Color.BLACK);
		
		
		g2.drawRoundRect(head.x-(int)(headWidth/3.4), head.y-(int)(headHeight/1.4), headWidth/3, headHeight/3, 100, 2);
		
		g2.drawLine(head.x-(int)(headWidth/6.2),head.y-(int)(headHeight/1.4),head.x-(int)(headWidth/6.2),head.y-(int)(headHeight/2));
		
		g2.drawLine(head.x-headWidth, head.y-(headHeight/4), head.x-(headWidth/2), head.y-(headHeight/4));
		
		
		g2.setColor(Color.WHITE);
		g2.drawLine(head.x-(int)(headWidth/1.5), head.y-(headHeight/4), head.x-(int)(headWidth/1.5), head.y-(headHeight/3));
		
		
		
		
		
	}

	
	
	
	
}
