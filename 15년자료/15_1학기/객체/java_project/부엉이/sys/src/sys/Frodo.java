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
		//빨간 목걸이
		g2.setColor(new Color(192,27,21));
		g2.drawLine(head.x-20, head.y+5, head.x+20, head.y+5);
		//회색 방울
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
		g2.fillRoundRect(head.x-(int)(headWidth/1.9), head.y-headHeight+5, headWidth, headHeight, 45, 45);
		g2.fillRoundRect(head.x+8, head.y-headHeight, 15, 15, 40, 40);
		g2.fillRoundRect(head.x-27, head.y-headHeight, 15, 15, 40, 40);
		g2.setColor(new Color(0,0,0));
		g2.setStroke(new BasicStroke(2));
		// 입
		g2.setColor(Color.white);
		g2.fillArc(head.x-20, head.y-26,40,20,180,180);
		g2.setColor(Color.black);
		g2.drawArc(head.x-20, head.y-26,40,20,180,180);
		g2.drawLine(head.x-20, head.y-16, head.x+20, head.y-16);
		g2.drawLine(head.x-18, head.y-11, head.x+18, head.y-11);
		g2.drawLine(head.x, head.y-16, head.x, head.y-6);
		g2.drawLine(head.x-10,head.y-16,head.x-10,head.y-9);
		g2.drawLine(head.x+10,head.y-16,head.x+10,head.y-9);
		//g2.drawLine(head.x-5, head.y-2,head.x+5, head.y-2);
		// 코
		g2.fillOval(head.x-7, head.y-26, 11, 6);
//		// 아래는 눈 테두리용
//		g2.fillOval(head.x-19, head.y-31, 15, 6);
//		g2.fillOval(head.x+5, head.y-31, 15, 6);
//		// 아래는 눈 흰자용
		g2.setColor(Color.white);
//		g2.fillOval(head.x-19, head.y-30, 13, 4);
//		g2.fillOval(head.x+5, head.y-30, 13, 4);
		g2.fillArc(head.x-25, head.y-38, 18, 20, 0, 180);
		g2.fillArc(head.x+5, head.y-38, 18, 20, 0, 180);
//		// 아래는 눈 검은자위용
//		g2.setColor(Color.black);
//		g2.setStroke(new BasicStroke(3));
		g2.setColor(Color.black);
		g2.fillOval(head.x-18, head.y-35, 4, 4);
		g2.fillOval(head.x+12, head.y-35, 4, 4);
//		g2.drawLine(head.x-14, head.y-30, head.x-14, head.y-28);
//		g2.drawLine(head.x+10, head.y-30, head.x+10, head.y-28);
	}
	
}