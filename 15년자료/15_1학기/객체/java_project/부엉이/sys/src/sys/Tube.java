package sys;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class Tube extends BasicRobot {

	public Tube(String jsonString) {
		super(jsonString);
		// TODO Auto-generated constructor stub
	}

	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		Graphics2D g2=(Graphics2D)g;
		
		
		g2.setColor(new Color(254,254,254));
		g2.fillRect(X, Y, width, height);

		g2.setColor(new Color(0,0,0));
		g2.drawRect(X, Y, width, height);
		
 		
		g2.setColor(new Color(254,254,254));
		g2.setStroke(new BasicStroke(armSize));
		g2.drawLine(leftShoulder.x, leftShoulder.y, leftElbow.x, leftElbow.y);
		g2.drawLine(leftElbow.x, leftElbow.y, leftHand.x, leftHand.y);
		
		g2.drawLine(rightShoulder.x, rightShoulder.y, rightElbow.x, rightElbow.y);
		g2.drawLine(rightElbow.x, rightElbow.y, rightHand.x, rightHand.y);
//		g2.setColor(new Color(192,27,21));
//		g2.drawLine(head.x-20, head.y+5, head.x+20, head.y+5);
//		g2.setColor(new Color(157,156,152));
//		g2.fillOval(head.x-5, head.y+10, 8, 8);
		g2.setColor(new Color(254,254,254));
		
		g2.setStroke(new BasicStroke(legSize));
		g2.drawLine(leftLeg.x, leftLeg.y, leftKnee.x, leftKnee.y);
		g2.drawLine(leftKnee.x, leftKnee.y, leftFoot.x, leftFoot.y);
		g2.drawLine(rightLeg.x, rightLeg.y, rightKnee.x, rightKnee.y);
		g2.drawLine(rightKnee.x, rightKnee.y, rightFoot.x, rightFoot.y);
		
		
		g2.setColor(new Color(254,254,254));
		g2.rotate(headangle, head.x, head.y);
		g2.fillOval(head.x-(int)(headWidth/1.9), head.y-headHeight+20, headWidth+10, headHeight);
//		g2.fillOval(head.x+5, head.y-headHeight, 15, 15);
//		g2.fillOval(head.x-(int)(headWidth/2.5), head.y-headHeight, 15, 15);
		
		g2.setColor(new Color(0,0,0));
		g2.setStroke(new BasicStroke(2));
//		// 입
//		g2.drawLine(head.x-5, head.y-2,head.x+5, head.y-2);
//		// 코
//		g2.fillOval(head.x-7, head.y-20, 11, 6);
//		// 아래는 눈 테두리용
//		g2.fillOval(head.x-19, head.y-31, 15, 6);
//		g2.fillOval(head.x+5, head.y-31, 15, 6);
//		// 아래는 눈 흰자용
//		g2.setColor(Color.white);
//		g2.fillOval(head.x-19, head.y-30, 13, 4);
//		g2.fillOval(head.x+5, head.y-30, 13, 4);
		// 아래는 눈 검은자위용
		//코 부분 노란색용
		g2.setColor(new Color(250,187,0));
		g2.setStroke(new BasicStroke(10));
		g2.fillOval(head.x-8, head.y-22, 25, 20);
		g2.fillRoundRect(head.x-40, head.y-15, 80, 30, 35, 35);
		g2.setColor(Color.black);
		//입술부분
		g2.fillOval(head.x-6, head.y-18, 5, 5);
		g2.fillOval(head.x+6, head.y-18, 5, 5);
		g2.setStroke(new BasicStroke(2));
		g2.drawArc(head.x-35, head.y, 60, 5, 180, 180);
		//눈 부분
		g2.fillOval(head.x-20, head.y-25, 6, 6);
		g2.fillOval(head.x+18, head.y-25, 6, 6);
		g2.setStroke(new BasicStroke(5));
		//눈썹 부분
		g2.drawArc(head.x-20, head.y-37, 10, 10, 45, 90);
		g2.drawArc(head.x+18, head.y-37, 10, 10, 45, 90);
		//g2.fillOval(head.x-headWidth,head.y-(headHeight/2),headWidth,headHeight/2);
				
	}
	
}