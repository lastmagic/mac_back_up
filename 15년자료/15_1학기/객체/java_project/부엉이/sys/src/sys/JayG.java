package sys;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class JayG extends BasicRobot {

	public JayG(String jsonString) {
		super(jsonString);
		// TODO Auto-generated constructor stub
	}

	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		Graphics2D g2=(Graphics2D)g;
		g2.setColor(new Color(103,83,29));
		g2.fillOval(leftHand.x-(armSize/2)-(int)(Math.cos(leftArm2angle)*armSize/2), leftHand.y-(armSize/2)-(int)(Math.sin(leftArm2angle)*armSize/2), armSize, armSize);
		g2.fillOval(rightHand.x-(armSize/2)+(int)(Math.cos(rightArm2angle)*armSize/2), rightHand.y-(armSize/2)+(int)(Math.sin(rightArm2angle)*armSize/2), armSize, armSize);
//		
		g2.setColor(Color.BLACK);
		g2.fillRect(X, Y, width, height);
		int[] shirtX={X+(width/2)-(width/6),X+(width/2),X+(width/2)+(width/6)};
		int[] shirtY={Y,Y+(height/3),Y};
		g2.setColor(Color.WHITE);
		g2.fillPolygon(shirtX, shirtY, shirtX.length);
		g2.setColor(Color.BLACK);
		int[] neckTiX={X+(width/2)-(width/12),X+(width/2)-1,X+(width/2)-5,X+(width/2),X+(width/2)+5,X+(width/2)+1,X+(width/2)+(width/12)};
		int[] neckTiY={Y,Y+(height/6)-1,Y+(height/3),Y+(height/2),Y+(height/3),Y+(height/6)-1,Y};
		g2.fillPolygon(neckTiX, neckTiY, neckTiX.length);
		g2.setStroke(new BasicStroke(2));
		g2.drawLine(X+(width/2), Y, X+(width/2)-(width/6), Y+(height/4));
		g2.drawLine(X+(width/2), Y, X+(width/2)+(width/6), Y+(height/4));
		
		g2.setStroke(new BasicStroke(armSize));
		g2.drawLine(leftShoulder.x, leftShoulder.y, leftElbow.x, leftElbow.y);
		g2.drawLine(leftElbow.x, leftElbow.y, leftHand.x, leftHand.y);
		
		g2.drawLine(rightShoulder.x, rightShoulder.y, rightElbow.x, rightElbow.y);
		g2.drawLine(rightElbow.x, rightElbow.y, rightHand.x, rightHand.y);
		
		g2.setColor(new Color(192,27,21));
//		g2.drawLine(head.x-20, head.y+5, head.x+20, head.y+5);
//		g2.setColor(new Color(157,156,152));
//		g2.fillOval(head.x-5, head.y+10, 8, 8);
//		g2.setColor(new Color(181,136,51));
		
		g2.setColor(Color.BLACK);
		g2.setStroke(new BasicStroke(legSize));
		g2.drawLine(leftLeg.x, leftLeg.y, leftKnee.x, leftKnee.y);
		g2.drawLine(leftKnee.x, leftKnee.y, leftFoot.x, leftFoot.y);
		g2.drawLine(rightLeg.x, rightLeg.y, rightKnee.x, rightKnee.y);
		g2.drawLine(rightKnee.x, rightKnee.y, rightFoot.x, rightFoot.y);
		
		g2.setStroke(new BasicStroke(0));
		if (leftLeg2angle < 0) {
			int leftshoesX[] = { leftFoot.x + 3, leftFoot.x + 3,
					leftFoot.x , leftFoot.x , leftFoot.x - 8,
					leftFoot.x - 3 };
			int leftshoesY[] = { leftFoot.y + 1,
					leftFoot.y + (int) (legSize / 1),
					leftFoot.y + (int) (legSize / 1),
					leftFoot.y + (int) (legSize / 1.8),
					leftFoot.y + (int) (legSize / 1), leftFoot.y + 1 };

			g2.fillPolygon(leftshoesX, leftshoesY, leftshoesX.length);

		}
		else  {
			int leftshoesX[] = { leftFoot.x - 5, leftFoot.x - 5,
					leftFoot.x-2 , leftFoot.x-2 , leftFoot.x + 6,
					leftFoot.x + 1 };
			int leftshoesY[] = { leftFoot.y + 1,
					leftFoot.y + (int) (legSize / 1),
					leftFoot.y + (int) (legSize / 1),
					leftFoot.y + (int) (legSize / 1.8),
					leftFoot.y + (int) (legSize / 1), leftFoot.y + 1 };

			g2.fillPolygon(leftshoesX, leftshoesY, leftshoesX.length);

		}
		
		if (rightLeg2angle < 0) {
			int rightshoesX[] = { rightFoot.x + 3, rightFoot.x + 3,
					rightFoot.x , rightFoot.x , rightFoot.x - 8,
					rightFoot.x - 3 };
			int rightshoesY[] = { rightFoot.y + 1,
					rightFoot.y + (int) (legSize / 1),
					rightFoot.y + (int) (legSize / 1),
					rightFoot.y + (int) (legSize / 1.8),
					rightFoot.y + (int) (legSize / 1), rightFoot.y + 1 };

			g2.fillPolygon(rightshoesX, rightshoesY, rightshoesX.length);

		}
		else  {
			int rightshoesX[] = { rightFoot.x - 5, rightFoot.x - 5,
					rightFoot.x-2 , rightFoot.x-2 , rightFoot.x + 6,
					rightFoot.x + 1 };
			int rightshoesY[] = { rightFoot.y + 1,
					rightFoot.y + (int) (legSize / 1),
					rightFoot.y + (int) (legSize / 1),
					rightFoot.y + (int) (legSize / 1.8),
					rightFoot.y + (int) (legSize / 1), rightFoot.y + 1 };

			g2.fillPolygon(rightshoesX, rightshoesY, rightshoesX.length);

		}
		
		
	
	
		g2.rotate(headangle, head.x, head.y);
		
		g2.setColor(new Color(254,213,1));
		g2.fillOval(head.x-(int)(headWidth*1.6)/2, head.y-(int)(headHeight*1.6), (int)(headWidth*1.6), (int)(headHeight*1.6));
		
		
		
		g2.setColor(new Color(103,83,29));
		g2.fillOval(head.x-(headWidth/2), head.y-headHeight+5, headWidth, headHeight);
		
		
		
		g2.setColor(Color.WHITE);
		g2.fillOval(head.x - 9, head.y - (int) (headHeight / 3.5), 8, 6);
		g2.fillOval(head.x, head.y - (int) (headHeight / 3.5), 8, 6);
		
		
		g2.setColor(Color.BLACK);
		g2.fillOval(head.x - 3, head.y - (int) (headHeight / 3.5) -2, 6, 6);
		g2.setStroke(new BasicStroke(0));
		g2.drawOval(head.x - 9, head.y - (int) (headHeight / 3.5), 8, 6);
		g2.drawOval(head.x, head.y - (int) (headHeight / 3.5), 8, 6);

		g2.fillRoundRect(head.x-25, head.y-(int)((headHeight)/1.7), 22, 17,5,5);
		g2.fillRoundRect(head.x+3, head.y-(int)((headHeight)/1.7), 22, 17,5,5);
		g2.setStroke(new BasicStroke(2));
		g2.drawLine(head.x-10, head.y-(int)((headHeight)/1.7)+8, head.x+13, head.y-(int)((headHeight)/1.7)+8);
//		g2.setColor(Color.WHITE);
		
		
		
		
		
//		g2.fillArc(head.x-22, head.y-(int)(headHeight/2.5)-12, 18, 9, 210, 110);
//		g2.fillArc(head.x-22, head.y-(int)(headHeight/2.5)-7, 18, 9, 30, 110);
//		
//		g2.fillArc(head.x+4, head.y-(int)(headHeight/2.5)-12, 18, 9, 210, 110);
//		g2.fillArc(head.x+4, head.y-(int)(headHeight/2.5)-7, 18, 9, 30, 110);
//
////
//		g2.setColor(Color.BLACK);
//		g2.drawArc(head.x-22, head.y-(int)(headHeight/2.5)-12, 18, 9, 210, 110);
//		g2.drawArc(head.x-22, head.y-(int)(headHeight/2.5)-7, 18, 9, 30, 110);
//		
//		g2.drawArc(head.x+4, head.y-(int)(headHeight/2.5)-12, 18, 9, 210, 110);
//		g2.drawArc(head.x+4, head.y-(int)(headHeight/2.5)-7, 18, 9, 30, 110);

		

		
		
		g2.setColor(new Color(254,213,1));
		int num=28;
		g2.rotate(Math.toRadians(-145),head.x,head.y-(int)(headHeight*1.6)/2);
		for(int i=0;i<num;i++){
			g2.rotate(Math.toRadians(10),head.x,head.y-(int)(headHeight*1.6)/2);
			g2.fillOval(head.x-5,head.y-(int)(headHeight*1.6)-5,10,10);
		}
		
//		g2.fillOval(head.x-(int)(headWidth*1.6)/2, head.y-(int)(headHeight*1.6), (int)(headWidth*1.6), (int)(headHeight*1.6));
				
	}
	
}