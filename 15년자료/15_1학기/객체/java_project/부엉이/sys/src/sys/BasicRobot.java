package sys;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.Random;

import javax.swing.JComponent;

import myJSON.JSONObject;
import myJSON.JSONParser;


public class BasicRobot extends JComponent {

	class point {
		public int x;
		public int y;

		public point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	};

	protected int originY=0;
	
	protected int X = 0;
	protected int Y = 0;

	protected int offset = 0;

	protected point neck;
	protected point head;
	protected double headangle = 0;
	
	protected int headWidth = 0;
	protected int headHeight = 0;
	

	protected int width = 0;
	protected int height = 0;

	protected int armSize = 0;
	protected int legSize = 0;

	protected point leftShoulder;
	protected point leftElbow;
	protected point leftHand;

	protected point rightShoulder;
	protected point rightElbow;
	protected point rightHand;

	protected point leftLeg;
	protected point leftKnee;
	protected point leftFoot;

	protected point rightLeg;
	protected point rightKnee;
	protected point rightFoot;

	protected int neckLength;
	protected double neckangle;
	protected int leftArm;
	protected double leftArm1angle;
	protected int leftArm1Length;
	protected double leftArm2angle;
	protected int leftArm2Length;

	protected int rightArm;
	protected double rightArm1angle;
	protected int rightArm1Length;
	protected double rightArm2angle;
	protected int rightArm2Length;

	protected int leftLegStart;
	protected double leftLeg1angle;
	protected int leftLeg1Length;
	protected double leftLeg2angle;
	protected int leftLeg2Length;

	protected int rightLegStart;
	protected double rightLeg1angle;
	protected int rightLeg1Length;
	protected double rightLeg2angle;
	protected int rightLeg2Length;

	protected boolean gravity = true;
	protected boolean diffFlag=false;
	protected double diff;

	public void setLocation(int x,int y){
		X=x;
		Y=y;
		originY=y;
		this.calcPoint();
	}
	
	public BasicRobot(String jsonString) {
		Random rand=new Random();
		JSONObject json = null;
		json = (JSONObject) new JSONParser().parse(jsonString);
		jsonRead(json);
		if (gravity) {
			int height = this.height;
			int leftKnee = (int) (height + (leftLeg1Length * Math
					.cos(leftLeg1angle)));
			int leftFoot = (int) (leftKnee + (leftLeg2Length * Math
					.cos(leftLeg2angle)));
			int rightKnee = (int) (height + (rightLeg1Length * Math
					.cos(rightLeg1angle)));
			int rightFoot = (int) (rightKnee + (rightLeg2Length * Math
					.cos(rightLeg2angle)));
			offset = Math.max(
					Math.max(Math.max(leftFoot, leftKnee),
							Math.max(rightFoot, rightKnee)), height);
		}
		diff=rand.nextDouble()+0.5;
		if(!diffFlag){
			diff=1;
		}
		this.calcPoint();
	}

	public void calcPoint(){
		if (gravity) {
			int height = this.height;
			int leftKnee = (int) (height + (leftLeg1Length * Math
					.cos(leftLeg1angle)));
			int leftFoot = (int) (leftKnee + (leftLeg2Length * Math
					.cos(leftLeg2angle)));
			int rightKnee = (int) (height + (rightLeg1Length * Math
					.cos(rightLeg1angle)));
			int rightFoot = (int) (rightKnee + (rightLeg2Length * Math
					.cos(rightLeg2angle)));
			Y =originY+offset
					- Math.max(
							Math.max(Math.max(leftFoot, leftKnee),
									Math.max(rightFoot, rightKnee)), height);
		}

		this.leftShoulder = new point(X + 0, Y + armSize / 2 + leftArm);

		// tempX=-l1L tempY=armSize/2
		this.leftElbow = new point(
				(int) (this.leftShoulder.x + ((-leftArm1Length * Math
						.cos(leftArm1angle)))),
				(int) (this.leftShoulder.y + ((-leftArm1Length * Math
						.sin(leftArm1angle)))));

		this.leftHand = new point(
				(int) (this.leftElbow.x + ((-leftArm2Length * Math
						.cos(leftArm2angle)))),
				(int) (this.leftElbow.y + ((-leftArm2Length * Math
						.sin(leftArm2angle)))));

		this.rightShoulder = new point(X + this.width, Y + armSize / 2
				+ rightArm);
		// tempX=width+l1L tempY=armSize/2
		this.rightElbow = new point(
				(int) (this.rightShoulder.x + (((rightArm1Length) * Math
						.cos(rightArm1angle)))),
				(int) (this.rightShoulder.y + (((rightArm1Length) * Math
						.sin(rightArm1angle)))));
		this.rightHand = new point(
				(int) (this.rightElbow.x + ((rightArm2Length * Math
						.cos(rightArm2angle)))),
				(int) (this.rightElbow.y + ((rightArm2Length * Math
						.sin(rightArm2angle)))));

		this.leftLeg = new point(X + (legSize / 2) + leftLegStart, Y + height);

		this.leftKnee = new point(
				(int) (this.leftLeg.x + (-leftLeg1Length * Math
						.sin(leftLeg1angle))),
				(int) (this.leftLeg.y + (leftLeg1Length * Math
						.cos(leftLeg1angle))));
		this.leftFoot = new point(
				(int) (this.leftKnee.x + (-leftLeg2Length * Math
						.sin(leftLeg2angle))),
				(int) (this.leftKnee.y + (leftLeg2Length * Math
						.cos(leftLeg2angle))));

		this.rightLeg = new point(X + width - (legSize / 2) - rightLegStart, Y
				+ height);

		this.rightKnee = new point(
				(int) (this.rightLeg.x + (-rightLeg1Length * Math
						.sin(rightLeg1angle))),
				(int) (this.rightLeg.y + (rightLeg1Length * Math
						.cos(rightLeg1angle))));
		this.rightFoot = new point(
				(int) (this.rightKnee.x + (-rightLeg2Length * Math
						.sin(rightLeg2angle))),
				(int) (this.rightKnee.y + (rightLeg2Length * Math
						.cos(rightLeg2angle))));

		this.neck = new point(X + (width / 2), Y);
		this.head = new point(
				(int) (this.neck.x + (neckLength * Math.sin(neckangle))),
				(int) (this.neck.y + (-neckLength * Math.cos(neckangle))));

	}
	
	public void setRobot(String jsonString) {
		JSONObject json = null;
		json =JSONParser.parse(jsonString);
		this.setRobot(json);
	}

	public void setRobot(JSONObject json) {
		this.jsonRead(json);
		
		this.calcPoint();
	}
	public void jsonRead(JSONObject json){
		try {
			X = ((Long) json.get("X")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			Y = ((Long) json.get("Y")).intValue();
			originY=Y;
		} catch (NullPointerException e) {
		}
		try {
			armSize = ((Long) json.get("armSize")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			legSize = ((Long) json.get("legSize")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			width = ((Long) json.get("width")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			height = ((Long) json.get("height")).intValue();
		} catch (NullPointerException e) {
		}
		try{
			headWidth = ((Long) json.get("headWidth")).intValue();
		}catch(NullPointerException e){}
		try{
			headHeight = ((Long) json.get("headHeight")).intValue();
		}catch(NullPointerException e){}
		try {
			headangle = Math.toRadians(((Double) json.get("headangle"))
					.doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			neckLength = ((Long) json.get("neckLength")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			neckangle = Math.toRadians(((Double) json.get("neckangle"))
					.doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			leftArm = ((Long) json.get("leftArm")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			leftArm1angle = Math.toRadians(((Double) json.get("leftArm1angle"))
					.doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			leftArm1Length = ((Long) json.get("leftArm1Length")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			leftArm2angle = Math.toRadians(((Double) json.get("leftArm2angle"))
					.doubleValue());
		} catch (NullPointerException e) {
		}

		try {
			leftArm2Length = ((Long) json.get("leftArm2Length")).intValue();
		} catch (NullPointerException e) {
		}

		try {
			rightArm = ((Long) json.get("rightArm")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			rightArm1angle = Math.toRadians(((Double) json
					.get("rightArm1angle")).doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			rightArm1Length = ((Long) json.get("rightArm1Length")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			rightArm2angle = Math.toRadians(((Double) json
					.get("rightArm2angle")).doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			rightArm2Length = ((Long) json.get("rightArm2Length")).intValue();
		} catch (NullPointerException e) {
		}

		try {
			leftLegStart = ((Long) json.get("leftLegStart")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			leftLeg1angle = Math.toRadians(((Double) json.get("leftLeg1angle"))
					.doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			leftLeg1Length = ((Long) json.get("leftLeg1Length")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			leftLeg2angle = Math.toRadians(((Double) json.get("leftLeg2angle"))
					.doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			leftLeg2Length = ((Long) json.get("leftLeg2Length")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			rightLegStart = ((Long) json.get("rightLegStart")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			rightLeg1angle = Math.toRadians(((Double) json
					.get("rightLeg1angle")).doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			rightLeg1Length = ((Long) json.get("rightLeg1Length")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			rightLeg2angle = Math.toRadians(((Double) json
					.get("rightLeg2angle")).doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			rightLeg2Length = ((Long) json.get("rightLeg2Length")).intValue();
		} catch (NullPointerException e) {
		}

	}
	
	public void dancing(JSONObject json){
		
		
		
		int FPS=0;
		int time=0;
		
		int X = 0;
		int Y = 0;

		double headangle = 0;
		
		int headWidth = 0;
		int headHeight = 0;
		

		int width = 0;
		int height = 0;

		int armSize = 0;
		int legSize = 0;


		int neckLength=0;
		double neckangle=0;
		int leftArm=0;
		double leftArm1angle=0;
		int leftArm1Length=0;
		double leftArm2angle=0;
		int leftArm2Length=0;

		int rightArm=0;
		double rightArm1angle=0;
		int rightArm1Length=0;
		double rightArm2angle=0;
		int rightArm2Length=0;

		int leftLegStart=0;
		double leftLeg1angle=0;
		int leftLeg1Length=0;
		double leftLeg2angle=0;
		int leftLeg2Length=0;

		int rightLegStart=0;
		double rightLeg1angle=0;
		int rightLeg1Length=0;
		double rightLeg2angle=0;
		int rightLeg2Length=0;
		
		
		try{
			time=((Long)json.get("time")).intValue();
		}catch(NullPointerException e){
		}
		try{
			FPS=((Long)json.get("FPS")).intValue();
		}catch(NullPointerException e){
		}
		
		try {
			X = ((Long) json.get("X")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			Y = ((Long) json.get("Y")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			armSize = ((Long) json.get("armSize")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			legSize = ((Long) json.get("legSize")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			width = ((Long) json.get("width")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			height = ((Long) json.get("height")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			headangle = Math.toRadians(((Double) json.get("headangle"))
					.doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			neckLength = ((Long) json.get("neckLength")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			neckangle = Math.toRadians(((Double) json.get("neckangle"))
					.doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			leftArm = ((Long) json.get("leftArm")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			leftArm1angle = Math.toRadians(((Double) json.get("leftArm1angle"))
					.doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			leftArm1Length = ((Long) json.get("leftArm1Length")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			leftArm2angle = Math.toRadians(((Double) json.get("leftArm2angle"))
					.doubleValue());
		} catch (NullPointerException e) {
		}

		try {
			leftArm2Length = ((Long) json.get("leftArm2Length")).intValue();
		} catch (NullPointerException e) {
		}

		try {
			rightArm = ((Long) json.get("rightArm")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			rightArm1angle = Math.toRadians(((Double) json
					.get("rightArm1angle")).doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			rightArm1Length = ((Long) json.get("rightArm1Length")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			rightArm2angle = Math.toRadians(((Double) json
					.get("rightArm2angle")).doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			rightArm2Length = ((Long) json.get("rightArm2Length")).intValue();
		} catch (NullPointerException e) {
		}

		try {
			leftLegStart = ((Long) json.get("leftLegStart")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			leftLeg1angle = Math.toRadians(((Double) json.get("leftLeg1angle"))
					.doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			leftLeg1Length = ((Long) json.get("leftLeg1Length")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			leftLeg2angle = Math.toRadians(((Double) json.get("leftLeg2angle"))
					.doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			leftLeg2Length = ((Long) json.get("leftLeg2Length")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			rightLegStart = ((Long) json.get("rightLeg")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			rightLeg1angle = Math.toRadians(((Double) json
					.get("rightLeg1angle")).doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			rightLeg1Length = ((Long) json.get("rightLeg1Length")).intValue();
		} catch (NullPointerException e) {
		}
		try {
			rightLeg2angle = Math.toRadians(((Double) json
					.get("rightLeg2angle")).doubleValue());
		} catch (NullPointerException e) {
		}
		try {
			rightLeg2Length = ((Long) json.get("rightLeg2Length")).intValue();
		} catch (NullPointerException e) {
		}
		
		for(int i=0;i<time/(1000/FPS);i++){
			this.X += X/FPS;
			this.Y += Y/FPS;

			this.headangle += headangle/FPS;
			
			this.headWidth += headWidth/FPS;
			this.headHeight += headHeight/FPS;
			

			this.width += width/FPS;
			this.height += height/FPS;

			this.armSize += armSize/FPS;
			this.legSize += legSize/FPS;


			this.neckLength+=neckLength/FPS;
			this.neckangle+=neckangle/FPS;
			this.leftArm+=leftArm/FPS;
			this.leftArm1angle+=leftArm1angle/FPS;
			this.leftArm1Length+=leftArm1Length/FPS;
			this.leftArm2angle+=leftArm2angle/FPS;
			this.leftArm2Length+=leftArm2Length/FPS;

			this.rightArm+=rightArm/FPS;
			this.rightArm1angle+=rightArm1angle/FPS;
			this.rightArm1Length+=rightArm1Length/FPS;
			this.rightArm2angle+=rightArm2angle/FPS;
			this.rightArm2Length+=rightArm2Length/FPS;

			this.leftLegStart+=leftLegStart/FPS;
			this.leftLeg1angle+=leftLeg1angle/FPS;
			this.leftLeg1Length+=leftLeg1Length/FPS;
			this.leftLeg2angle+=leftLeg2angle/FPS;
			this.leftLeg2Length+=leftLeg2Length/FPS;

			this.rightLegStart+=rightLegStart/FPS;
			this.rightLeg1angle+=rightLeg1angle/FPS;
			this.rightLeg1Length+=rightLeg1Length/FPS;
			this.rightLeg2angle+=rightLeg2angle/FPS;
			this.rightLeg2Length+=rightLeg2Length/FPS;
			this.calcPoint();
			this.repaint();
			try{
				Thread.sleep((int)((1000/FPS)*diff));
			}catch(Exception e){
			}
		}
		
		
		
		
	}
	
	
	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		Graphics2D g2 = (Graphics2D) g;

		g2.drawRect(X, Y, width, height);
		// System.out.println(leftShoulder.x+" "+leftShoulder.y);
		// System.out.println(leftElbow.y+" "+leftElbow.y);
		g2.drawLine(leftShoulder.x, leftShoulder.y, leftElbow.x, leftElbow.y);
		g2.drawLine(leftElbow.x, leftElbow.y, leftHand.x, leftHand.y);
		g2.drawLine(rightShoulder.x, rightShoulder.y, rightElbow.x,
				rightElbow.y);
		g2.drawLine(rightElbow.x, rightElbow.y, rightHand.x, rightHand.y);
		g2.drawLine(leftLeg.x, leftLeg.y, leftKnee.x, leftKnee.y);
		g2.drawLine(leftKnee.x, leftKnee.y, leftFoot.x, leftFoot.y);
		g2.drawLine(rightLeg.x, rightLeg.y, rightKnee.x, rightKnee.y);
		g2.drawLine(rightKnee.x, rightKnee.y, rightFoot.x, rightFoot.y);
		g2.drawLine(neck.x, neck.y, head.x, head.y);

		g2.rotate(headangle, head.x, head.y);
		g2.drawRect(head.x - (headWidth / 2), head.y - headHeight, headWidth, headHeight);

	}
	public int getWidthC(){
		return this.width;
	}
	public int getHeightC(){
		return this.height;
	}
	public int getXC(){
		return this.X;
	}
	public int getYC(){
		return this.Y;
	}
}
