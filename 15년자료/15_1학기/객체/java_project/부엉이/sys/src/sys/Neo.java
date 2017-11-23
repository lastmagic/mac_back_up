package sys;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.text.ParseException;

import myJSON.JSONObject;
import myJSON.JSONParser;

public class Neo extends BasicRobot {

//	
//	private int headWidth = 50;
//	private int headHeight = 40;
	private int faceWidth = 30;
	private int faceHeight = 30;

	private point leftEar;
	private point rightEar;
	private int earWidth;
	private int earHeight;
	
	public Neo(String jsonString) {
		super(jsonString);
		
		
		// System.out.println(jsonString);
		JSONObject json = null;
		json = (JSONObject) new JSONParser().parse(jsonString);
		this.jsonRead(json);
		this.calcPoint();

	}

	public void jsonRead(JSONObject json){
		super.jsonRead(json);
//		System.out.println(json);
		try{
			earWidth = ((Long) json.get("earWidth")).intValue();
		}catch(NullPointerException e){}
		try{
			earHeight = ((Long) json.get("earHeight")).intValue();
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
		Graphics2D g2=(Graphics2D)g;
		
		g2.setColor(new Color(116,150,187));
		g2.fillRoundRect(X, Y, width, height, 5, 5);
		
		g2.setStroke(new BasicStroke(armSize));
		g2.fillOval(leftShoulder.x - (armSize / 2), leftShoulder.y
				- (armSize / 2), armSize, armSize);
		g2.drawLine(leftShoulder.x , leftShoulder.y,
				leftElbow.x, leftElbow.y);
		g2.drawLine(leftElbow.x, leftElbow.y, leftHand.x, leftHand.y);
		g2.fillOval(rightShoulder.x - (armSize / 2), rightShoulder.y
				- (armSize / 2), armSize, armSize);
		g2.drawLine(rightShoulder.x , rightShoulder.y,
				rightElbow.x, rightElbow.y);
		g2.drawLine(rightElbow.x, rightElbow.y, rightHand.x, rightHand.y);
		
		
		g2.setStroke(new BasicStroke(legSize));

		g2.drawLine(leftLeg.x, leftLeg.y, leftKnee.x,
				leftKnee.y);
		g2.drawLine(leftKnee.x, leftKnee.y, leftFoot.x, leftFoot.y);
	
		g2.drawLine(rightLeg.x, rightLeg.y, rightKnee.x,
				rightKnee.y);
		g2.drawLine(rightKnee.x, rightKnee.y, rightFoot.x, rightFoot.y);
		
		
		
		g2.setColor(Color.WHITE);
		g2.fillRoundRect(X+3, Y+10, width-6, height-15, 30, 40);

		g2.fillOval(leftHand.x-(armSize), leftHand.y-(armSize/2), armSize, armSize);
		g2.fillOval(rightHand.x, rightHand.y-(armSize/2), armSize, armSize);
		g2.fillOval(leftFoot.x-(legSize/2), leftFoot.y, legSize, legSize);
		g2.fillOval(rightFoot.x-(legSize/2), rightFoot.y, legSize, legSize);
		
		
		
		g2.rotate(headangle, head.x, head.y);
		g2.setColor(new Color(116,150,187));
		g2.fillRoundRect(head.x - (headWidth / 2), head.y - (headHeight),
				headWidth, headHeight + 10, 50, 100);
		
		g2.setColor(Color.BLACK);
		g2.fillArc(head.x- (int)(headWidth*0.6), head.y-(int)(headHeight*1.2), (int)(headWidth*1.2), (int)(headHeight*1.2), 0, 180);
		g2.fillRect(head.x- (int)(headWidth*0.6),  head.y-(int)(headHeight*0.6), (int)(headWidth*0.3), (int)(headHeight*0.4));
		g2.fillRect(head.x+ (int)(headWidth*0.3),  head.y-(int)(headHeight*0.6), (int)(headWidth*0.3), (int)(headHeight*0.4));
		
		g2.setColor(new Color(70,70,70));
		g2.setStroke(new BasicStroke(2));
		int[] leftNX={head.x- (int)(headWidth*0.5),head.x- (int)(headWidth*0.5),head.x- (int)(headWidth*0.4),head.x- (int)(headWidth*0.4)};
		int[] leftNY={head.y-(int)(headHeight*0.4),head.y-(int)(headHeight*0.5),head.y-(int)(headHeight*0.4),head.y-(int)(headHeight*0.5)};
		int[] rightNX={head.x+ (int)(headWidth*0.4),head.x+ (int)(headWidth*0.4),head.x+ (int)(headWidth*0.5),head.x+ (int)(headWidth*0.5)};
		int[] rightNY={head.y-(int)(headHeight*0.4),head.y-(int)(headHeight*0.5),head.y-(int)(headHeight*0.4),head.y-(int)(headHeight*0.5)};
		
		int[] mtX={head.x- (int)(headWidth*0.3),head.x- (int)(headWidth*0.246),head.x- (int)(headWidth*0.192),head.x- (int)(headWidth*0.138),head.x- (int)(headWidth*0.084),head.x- (int)(headWidth*0.03),head.x+ (int)(headWidth*0.024),head.x+ (int)(headWidth*0.078),head.x+ (int)(headWidth*0.132),head.x+ (int)(headWidth*0.186),head.x+ (int)(headWidth*0.24),head.x+ (int)(headWidth*0.3)};
		int[] mtY={head.y-(int)(headHeight*0.75),head.y-(int)(headHeight*0.8),head.y-(int)(headHeight*0.75),head.y-(int)(headHeight*0.85),head.y-(int)(headHeight*0.75),head.y-(int)(headHeight*0.9),head.y-(int)(headHeight*0.75),head.y-(int)(headHeight*0.85),head.y-(int)(headHeight*0.75),head.y-(int)(headHeight*0.8),head.y-(int)(headHeight*0.75)};
		
		
		g2.drawPolyline(leftNX, leftNY, leftNX.length);
		g2.drawPolyline(rightNX, rightNY, rightNX.length);
		g2.drawPolyline(mtX, mtY, mtY.length);
		
		
		
		g2.setColor(new Color(116,150,187));
		
		int[] leftEarPointx={leftEar.x-9,leftEar.x-8,leftEar.x+5};
		int[] leftEarPointy={leftEar.y+3,leftEar.y-11,leftEar.y-3};
		g2.fillPolygon(leftEarPointx, leftEarPointy, 3);
		
		int[] rightEarPointx={rightEar.x+9,rightEar.x+8,rightEar.x-5};
		int[] rightEarPointy={rightEar.y+3,rightEar.y-11,rightEar.y-3};
		g2.fillPolygon(rightEarPointx, rightEarPointy, 3);
		
		g2.setColor(new Color(200,145,152));
		int[] leftEar2Pointx={leftEar.x-5,leftEar.x-5,leftEar.x+3};
		int[] leftEar2Pointy={leftEar.y+1,leftEar.y-7,leftEar.y-2};
		g2.fillPolygon(leftEar2Pointx, leftEar2Pointy, 3);
		
		int[] rightEar2Pointx={rightEar.x+6,rightEar.x+6,rightEar.x-2};
		int[] rightEar2Pointy={rightEar.y+1,rightEar.y-7,rightEar.y-2};
		g2.fillPolygon(rightEar2Pointx, rightEar2Pointy, 3);
		
		
		
//		g2.setColor(Color.WHITE);
//		g2.fillRoundRect(leftEar.x - (earWidth / 2), leftEar.y - earHeight + 5,
//				earWidth, earHeight, 20, 10);
//		g2.fillRoundRect(rightEar.x - (earWidth / 2), rightEar.y - earHeight
//				+ 5, earWidth, earHeight, 20, 10);
//
//		g2.setColor(Color.PINK);
//		g2.fillRoundRect(leftEar.x - (int) (earWidth / 2.6), leftEar.y
//				- earHeight + 10, (int) (earWidth * 0.7),
//				(int) (earHeight * 0.7), 20, 10);
//		g2.fillRoundRect(rightEar.x - (int) (earWidth / 2.6), rightEar.y
//				- earHeight + 10, (int) (earWidth * 0.7),
//				(int) (earHeight * 0.7), 20, 10);

		
		g2.setColor(Color.WHITE);
		g2.fillOval(head.x - 9, head.y - (int) (headHeight / 2.5), 8, 6);
		g2.fillOval(head.x, head.y - (int) (headHeight / 2.5), 8, 6);
		
		
		g2.setColor(Color.BLACK);
		g2.fillOval(head.x - 3, head.y - (int) (headHeight / 2.5) -2, 6, 6);
		g2.setStroke(new BasicStroke(0));
		g2.drawOval(head.x - 9, head.y - (int) (headHeight / 2.5), 8, 6);
		g2.drawOval(head.x, head.y - (int) (headHeight / 2.5), 8, 6);

		g2.setColor(Color.WHITE);
		
		g2.fillArc(head.x-22, head.y-(int)(headHeight/2.5)-12, 18, 9, 210, 110);
		g2.fillArc(head.x-22, head.y-(int)(headHeight/2.5)-7, 18, 9, 30, 110);
		
		g2.fillArc(head.x+4, head.y-(int)(headHeight/2.5)-12, 18, 9, 210, 110);
		g2.fillArc(head.x+4, head.y-(int)(headHeight/2.5)-7, 18, 9, 30, 110);

//
		g2.setColor(Color.BLACK);
		g2.drawArc(head.x-22, head.y-(int)(headHeight/2.5)-12, 18, 9, 210, 110);
		g2.drawArc(head.x-22, head.y-(int)(headHeight/2.5)-7, 18, 9, 30, 110);
		
		g2.drawArc(head.x+4, head.y-(int)(headHeight/2.5)-12, 18, 9, 210, 110);
		g2.drawArc(head.x+4, head.y-(int)(headHeight/2.5)-7, 18, 9, 30, 110);

		

		g2.setStroke(new BasicStroke(1));
		g2.drawLine(head.x - 13, head.y - (int) (headHeight / 2.5) - 6,
				head.x - 13, head.y - (int) (headHeight / 2.5) - 10);

		g2.drawLine(head.x - 10, head.y - (int) (headHeight / 2.5) - 7,
				head.x - 7, head.y - (int) (headHeight / 2.5) - 10);
		g2.drawLine(head.x - 16, head.y - (int) (headHeight / 2.5) - 6,
				head.x - 19, head.y - (int) (headHeight / 2.5) - 10);
		g2.drawLine(head.x + 13, head.y - (int) (headHeight / 2.5) - 6,
				head.x + 13, head.y - (int) (headHeight / 2.5) - 10);

		g2.drawLine(head.x + 10, head.y - (int) (headHeight / 2.5) - 7,
				head.x + 7, head.y - (int) (headHeight / 2.5) - 10);
		g2.drawLine(head.x + 16, head.y - (int) (headHeight / 2.5) - 6,
				head.x + 19, head.y - (int) (headHeight / 2.5) - 10);
		
		g2.setStroke(new BasicStroke(2));
		g2.drawLine(head.x - 13, head.y - (int) (headHeight / 2.5) - 6, head.x - 13, head.y - (int) (headHeight / 2.5) - 3);
		g2.drawLine(head.x + 13, head.y - (int) (headHeight / 2.5) - 6, head.x + 13, head.y - (int) (headHeight / 2.5) - 3);
		
//		g2.drawOval(head.x - 14, head.y - (int) (headHeight / 2.5) - 7, 1, 2);
//		g2.drawOval(head.x + 13, head.y - (int) (headHeight / 2.5) - 7, 1, 2);
		

		
		
	}
	
	
	
	
}
