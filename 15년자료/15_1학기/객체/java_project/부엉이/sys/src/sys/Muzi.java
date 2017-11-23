package sys;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

import myJSON.JSONObject;
import myJSON.JSONParser;



public class Muzi extends BasicRobot {

	
	private int faceWidth = 30;
	private int faceHeight = 30;

	private point leftEar;
	private point rightEar;
	private int earWidth;
	private int earHeight;
	private int look=0;

	public Muzi(String jsonString) {
		super(jsonString);
		

	//	System.out.println(jsonString);
		JSONObject json = null;
		json = (JSONObject) new JSONParser().parse(jsonString);
		this.jsonRead(json);
		this.calcPoint();
		
	}

	public void jsonRead(JSONObject json){
		super.jsonRead(json);
//		System.out.println(json);
		try{
			faceWidth = ((Long) json.get("faceWidth")).intValue();
		}catch(NullPointerException e){}
		try{
			faceHeight = ((Long) json.get("faceHeight")).intValue();
		}catch(NullPointerException e){}
		try{
			earWidth = ((Long) json.get("earWidth")).intValue();
		}catch(NullPointerException e){}
		try{
			earHeight = ((Long) json.get("earHeight")).intValue();
		}catch(NullPointerException e){}
		try{
			look=((Long)json.get("look")).intValue();
		}catch(NullPointerException e){}

	}
	public void calcPoint(){
		super.calcPoint();

		leftEar = new point(
				(int) (head.x - ((headWidth / 2) - (earWidth * 1.3))), head.y
						- headHeight);
		rightEar = new point(
				(int) (head.x + ((headWidth / 2) - (earWidth * 1.3))), head.y
						- headHeight);
		

	}
	public void setRobot(String jsonString) {
		
		JSONObject json = null;
		json = (JSONObject) new JSONParser().parse(jsonString);
		setRobot(json);
	}
	public void setRobot(JSONObject json) {
		super.setRobot(json);
		jsonRead(json);
		calcPoint();
	}

	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		Graphics2D g2 = (Graphics2D) g;

		g2.setColor(Color.BLACK);
		g2.setStroke(new BasicStroke(legSize+2));
		g2.fillOval(leftLeg.x - (legSize / 2), leftLeg.y - (legSize / 2),
				legSize, legSize);
		g2.drawLine(leftLeg.x, leftLeg.y , leftKnee.x,
				leftKnee.y);
		g2.drawLine(leftKnee.x, leftKnee.y, leftFoot.x, leftFoot.y);
		g2.fillOval(rightLeg.x - (legSize / 2), rightLeg.y - (legSize / 2),
				legSize, legSize);
		g2.drawLine(rightLeg.x, rightLeg.y, rightKnee.x,
				rightKnee.y);
		g2.drawLine(rightKnee.x, rightKnee.y, rightFoot.x, rightFoot.y);
		
		g2.setStroke(new BasicStroke(legSize));
		g2.setColor(Color.YELLOW);
		g2.fillOval(leftLeg.x - (legSize / 2), leftLeg.y - (legSize / 2),
				legSize, legSize);
		g2.drawLine(leftLeg.x, leftLeg.y , leftKnee.x,
				leftKnee.y);
		g2.drawLine(leftKnee.x, leftKnee.y, leftFoot.x, leftFoot.y);
		g2.fillOval(rightLeg.x - (legSize / 2), rightLeg.y - (legSize / 2),
				legSize, legSize);
		g2.drawLine(rightLeg.x, rightLeg.y, rightKnee.x,
				rightKnee.y);
		g2.drawLine(rightKnee.x, rightKnee.y, rightFoot.x, rightFoot.y);
		
		g2.setColor(Color.WHITE);
		g2.fillRoundRect(X, Y, width, height, 10, 10);
		g2.setColor(Color.BLACK);
		g2.setStroke(new BasicStroke(0));
		g2.drawRoundRect(X, Y, width, height, 10, 10);
		g2.setColor(Color.YELLOW);
		// System.out.println(leftShoulder.x+" "+leftShoulder.y);
		// System.out.println(leftElbow.y+" "+leftElbow.y);
		
		g2.fillOval(leftShoulder.x - (armSize / 2), leftShoulder.y
				- (armSize / 2), armSize, armSize);
		g2.setColor(Color.BLACK);
		g2.drawOval(leftShoulder.x - (armSize / 2), leftShoulder.y
				- (armSize / 2), armSize, armSize);
		g2.fillOval(rightShoulder.x - (armSize / 2), rightShoulder.y
				- (armSize / 2), armSize, armSize);
		g2.setColor(Color.BLACK);
		g2.setStroke(new BasicStroke(armSize+2));
		g2.drawLine(leftShoulder.x , leftShoulder.y,
				leftElbow.x, leftElbow.y);
		g2.drawLine(leftElbow.x, leftElbow.y, leftHand.x, leftHand.y);
		g2.drawLine(rightShoulder.x, rightShoulder.y,
				rightElbow.x, rightElbow.y);
		g2.drawLine(rightElbow.x, rightElbow.y, rightHand.x, rightHand.y);
		
		
		
		
		
		
		g2.setStroke(new BasicStroke(armSize));
		g2.setColor(Color.YELLOW);
		g2.drawLine(leftShoulder.x , leftShoulder.y,
				leftElbow.x, leftElbow.y);
		g2.drawLine(leftElbow.x, leftElbow.y, leftHand.x, leftHand.y);

		
		
		
		g2.setStroke(new BasicStroke(armSize));
		g2.setColor(Color.YELLOW);
		g2.fillOval(rightShoulder.x - (armSize / 2), rightShoulder.y
				- (armSize / 2), armSize, armSize);
		g2.drawLine(rightShoulder.x, rightShoulder.y,
				rightElbow.x, rightElbow.y);
		g2.drawLine(rightElbow.x, rightElbow.y, rightHand.x, rightHand.y);

		g2.setStroke(new BasicStroke(legSize));

		
		// g2.drawLine(neck.x,neck.y,head.x,head.y);

		g2.rotate(headangle, head.x, head.y);
		g2.setColor(Color.WHITE);
		g2.fillOval(head.x - (headWidth / 2), head.y - (headHeight),
				headWidth, headHeight + 10);
		g2.setColor(Color.YELLOW);
		g2.fillOval(head.x - (faceWidth / 2), head.y - (faceHeight) + 2,
				faceWidth, faceHeight);
		
//		g2.setStroke(new BasicStroke(0));
//		g2.setColor(Color.BLACK);
//		g2.drawOval(head.x - (headWidth / 2), head.y - (headHeight),
//				headWidth, headHeight + 10);
//		g2.drawOval(head.x - (faceWidth / 2), head.y - (faceHeight) + 2,
//				faceWidth, faceHeight);
		
		
		g2.setColor(Color.WHITE);
		g2.fillRoundRect(leftEar.x - (earWidth / 2), leftEar.y - earHeight + 10,
				earWidth, earHeight, 20, 10);
		g2.fillRoundRect(rightEar.x - (earWidth / 2), rightEar.y - earHeight
				+ 10, earWidth, earHeight, 20, 10);

		g2.setColor(Color.PINK);
		g2.fillRoundRect(leftEar.x - (int) (earWidth / 2.6), leftEar.y
				- earHeight + 15, (int) (earWidth * 0.7),
				(int) (earHeight * 0.7), 20, 10);
		g2.fillRoundRect(rightEar.x - (int) (earWidth / 2.6), rightEar.y
				- earHeight + 15, (int) (earWidth * 0.7),
				(int) (earHeight * 0.7), 20, 10);
		g2.setColor(Color.BLACK);
		
//		g2.drawRoundRect(leftEar.x - (earWidth / 2), leftEar.y - earHeight + 5,
//				earWidth, earHeight, 20, 10);
//		g2.drawRoundRect(rightEar.x - (earWidth / 2), rightEar.y - earHeight
//				+ 5, earWidth, earHeight, 20, 10);
//		g2.drawRoundRect(leftEar.x - (int) (earWidth / 2.6), leftEar.y
//				- earHeight + 10, (int) (earWidth * 0.7),
//				(int) (earHeight * 0.7), 20, 10);
//		g2.drawRoundRect(rightEar.x - (int) (earWidth / 2.6), rightEar.y
//				- earHeight + 10, (int) (earWidth * 0.7),
//				(int) (earHeight * 0.7), 20, 10);
		

		if (look == 0) {

			g2.setColor(Color.BLACK);
			g2.fillOval(head.x - 3, head.y - (int) (headHeight / 2.5) +1, 6, 6);
			g2.setStroke(new BasicStroke(0));
			g2.drawArc(head.x - 9, head.y - (int) (headHeight / 2.5)+3, 8, 8,
					180, 180);
			g2.drawArc(head.x, head.y - (int) (headHeight / 2.5)+3, 8, 8, 180,
					180);

			g2.setColor(Color.WHITE);
			g2.fillOval(head.x - 20, head.y - (int) (headHeight / 2.5) - 10, 16,
					12);
			g2.fillOval(head.x + 4, head.y - (int) (headHeight / 2.5) - 10, 16, 12);

			g2.setColor(Color.BLACK);
			g2.drawOval(head.x - 20, head.y - (int) (headHeight / 2.5) - 10, 16,
					12);
			g2.drawOval(head.x + 4, head.y - (int) (headHeight / 2.5) - 10, 16, 12);

			g2.fillOval(head.x - 13, head.y - (int) (headHeight / 2.5) - 5, 3, 4);
			g2.fillOval(head.x + 11, head.y - (int) (headHeight / 2.5) - 5, 3, 4);
		}
		else if(look == 1){
			g2.setColor(Color.BLACK);
			g2.fillOval(head.x - 3, head.y - (int) (headHeight / 2.5) +1, 6, 6);
			g2.setStroke(new BasicStroke(0));
			g2.drawArc(head.x - 9, head.y - (int) (headHeight / 2.5)+3, 8, 8,
					180, 180);
			g2.drawArc(head.x, head.y - (int) (headHeight / 2.5)+3, 8, 8, 180,
					180);

			
			g2.drawLine(head.x - 5, head.y - (int) (headHeight / 2.1), head.x-17, head.y - (int) (headHeight / 2.1));
			g2.drawLine(head.x - 5, head.y - (int) (headHeight / 2.1), head.x-17, head.y - (int) (headHeight / 1.8));
			g2.drawLine(head.x - 5, head.y - (int) (headHeight / 2.1), head.x-17, head.y - (int) (headHeight / 2.6));
		
			g2.drawLine(head.x + 5, head.y - (int) (headHeight / 2.1), head.x+17, head.y - (int) (headHeight / 2.1));
			g2.drawLine(head.x + 5, head.y - (int) (headHeight / 2.1), head.x+17, head.y - (int) (headHeight / 1.8));
			g2.drawLine(head.x + 5, head.y - (int) (headHeight / 2.1), head.x+17, head.y - (int) (headHeight / 2.6));
			

//			g2.setColor(Color.BLACK);
//			g2.drawOval(head.x - 10, head.y - (int) (headHeight / 2.5) - 7, 6,
//					4);
//			g2.drawOval(head.x + 4, head.y - (int) (headHeight / 2.5) - 7, 6, 4);
//
//			g2.drawOval(head.x - 8, head.y - (int) (headHeight / 2.5) - 6, 1, 1);
//			g2.drawOval(head.x + 6, head.y - (int) (headHeight / 2.5) - 6, 1, 1);
		}

	}

	public void dancing(JSONObject json) {
		// TODO Auto-generated method stub

		int look=0;
		try{
			look=((Long)json.get("look")).intValue();
		}catch(NullPointerException e){}
		this.look=look;
		
		super.dancing(json);
	
		
		
		
		
		
		
	}

}
