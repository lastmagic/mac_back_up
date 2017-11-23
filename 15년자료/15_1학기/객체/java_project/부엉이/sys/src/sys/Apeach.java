package sys;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class Apeach extends BasicRobot {

	public Apeach(String jsonString) {
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
		g2.setColor(new Color(254,254,254));
		
		g2.setStroke(new BasicStroke(legSize));
		g2.drawLine(leftLeg.x, leftLeg.y, leftKnee.x, leftKnee.y);
		g2.drawLine(leftKnee.x, leftKnee.y, leftFoot.x, leftFoot.y);
		g2.drawLine(rightLeg.x, rightLeg.y, rightKnee.x, rightKnee.y);
		g2.drawLine(rightKnee.x, rightKnee.y, rightFoot.x, rightFoot.y);
		// �߱׸���
//		g2.setColor(new Color(250,187,0));
//		g2.fillOval(rightFoot.x-5, rightFoot.y+3, 15, 8);
//		g2.fillOval(leftFoot.x-5, leftFoot.y+3, 15, 8);
		
		g2.setColor(new Color(249,208,214));
		g2.rotate(headangle, head.x, head.y);
		//g2.fillOval(head.x-(int)(headWidth/1.9), head.y-headHeight+25, headWidth+5, headHeight);
//		g2.drawRoundRect(head.x-(int)(headWidth/1.9), head.y-headHeight+25, headWidth+5, headHeight, 60, 60);
		//�Ӹ����±׸���
		g2.fillRoundRect(head.x-(int)(headWidth/1.9), head.y-headHeight+25, headWidth+5, headHeight-20, 60, 60);
		int px[] = new int[3];
		int py[] = new int[3];
		px[0] = head.x-25;
		px[1] = head.x;
		px[2] = head.x+25;
		py[0] = head.y-48;
		py[1] = head.y-70;
		py[2] = head.y-48;
		g2.fillPolygon(px,py,3);
		g2.setColor(new Color(0,0,0));
		g2.setStroke(new BasicStroke(2));
		//ȫ���׸���
		g2.setColor(new Color(239,133,135));
		g2.fillOval(head.x-27,head.y-23,17,7);
		g2.fillOval(head.x+13,head.y-23,17,7);
		//�Լ��׸���
		g2.setColor(new Color(43,27,27));
		g2.drawArc(head.x-5, head.y-10, 10, 5, 235, 90);

		//�� ���ڱ׸���
		g2.setColor(new Color(248,250,247));
		g2.fillArc(head.x-27, head.y-34, 20, 7, 0, 360);
		g2.fillArc(head.x+10, head.y-34, 20, 7, 0, 360);
		
		g2.setColor(new Color(43,27,27));
		g2.setStroke(new BasicStroke(2));
		//�� �׵θ�
		g2.drawArc(head.x-27, head.y-34, 20, 7, 0, 360);
		g2.drawArc(head.x+10, head.y-34, 20, 7, 0, 360);
		//������
		g2.fillOval(head.x-20, head.y-32, 5, 5);
		g2.fillOval(head.x+17, head.y-32, 5, 5);
		g2.setStroke(new BasicStroke(2));
		//������ ���ǿ��� �߰� �ϰ� ������쿡 �߰��Ұ� _apeach�� ����.
//		//���ʴ���
//		g2.drawLine(head.x-20, head.y-36, head.x-20, head.y-38);
//		g2.drawLine(head.x-25, head.y-36, head.x-26, head.y-38);
//		g2.drawLine(head.x-15, head.y-36, head.x-14, head.y-38);
//		//�����ʴ���
//		g2.drawLine(head.x+20, head.y-36, head.x+20, head.y-38);
//		g2.drawLine(head.x+25, head.y-36, head.x+26, head.y-38);
//		g2.drawLine(head.x+15, head.y-36, head.x+14, head.y-38);
				
	}
	
}