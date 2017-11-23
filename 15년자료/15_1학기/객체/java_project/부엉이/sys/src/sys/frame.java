package sys;

import java.applet.Applet;
import java.applet.AudioClip;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Image;
import java.awt.KeyEventDispatcher;
import java.awt.KeyboardFocusManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.io.File;
import java.util.ArrayList;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;
import javax.swing.border.BevelBorder;

import myJSON.JSONObject;



public class frame {
	
	
	final int frameWidth=1300;
	final int frameHeight=760;
	
	JSONObject test;
	JSONObject dancetest;
	JFrame f;
	JLabel stage;

	final String[] musicList={"I do I do","酒抚促款 广","Let it be","Cute","Marry you","Treasure","Stop"};
	final String[] danceList={"defalut","I do I do","酒抚促款 广","Muzi","Neo","Con","Frodo","Tube","Apeach","JayG"};
	
	JPanel ComboBoxPan;
	
	JPanel musicPan;
	JLabel musicLab;
	JComboBox musicBox;
	
	JPanel dancePan;
	JLabel danceLab;
	JComboBox danceBox;
	
	JButton muziImgBtn;
	JButton neoImgBtn;
	JButton frodoImgBtn;
	JButton conImgBtn;
	JButton tubeImgBtn;
	JButton jayGImgBtn;
	JButton apeachImgBtn;
	
	JPanel smallBtnGrp;
	JButton playBtn;
	JButton pauseBtn;
	JButton trashBtn;
	
	
	JRadioButton muziBtn;
	JRadioButton neoBtn;
	JRadioButton basicRobotBtn;
	JRadioButton frodoBtn;
	JRadioButton conBtn;
	JRadioButton tubeBtn;
	JRadioButton jayGBtn;
	JRadioButton apeachBtn;
	JRadioButton powerRangerBtn;
	
	AudioClip clip;
	
	boolean flag=false;
	boolean dancingFlag=true;
	BasicRobot dragbot=null;
	int offsetX=0;
	int offsetY=0;
	
	String dancePath=null;
	
	ArrayList<BasicThread> threadList=new ArrayList<BasicThread>();
	
	

	public frame() {
		f = new JFrame();

		f.setTitle("KaKao Friends");
		f.setSize(frameWidth, frameHeight);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		test = new JSONObject();
		test.put("X", new Integer(100));
		test.put("Y", new Integer(100));
		test.put("armSize", new Integer(10));
		test.put("legSize", new Integer(10));
		test.put("width", new Integer(50));
		test.put("height", new Integer(50));
		test.put("neckLength", new Integer(0));
		test.put("neckangle", new Double(0));
		test.put("headangle", new Double(0));
		test.put("leftArm", new Integer(5));
		test.put("leftArm1angle", new Double(0));
		test.put("leftArm1Length", new Integer(15));
		test.put("leftArm2angle", new Double(90));
		test.put("leftArm2Length", new Integer(15));
		test.put("rightArm", new Integer(5));
		test.put("rightArm1angle", new Double(0));
		test.put("rightArm1Length", new Integer(15));
		test.put("rightArm2angle", new Double(60));
		test.put("rightArm2Length", new Integer(15));
		test.put("leftLegStart", new Integer(5));
		test.put("leftLeg1angle", new Double(0));
		test.put("leftLeg1Length", new Integer(15));
		test.put("leftLeg2angle", new Double(0));
		test.put("leftLeg2Length", new Integer(15));
		test.put("rightLegStart", new Integer(5));
		test.put("rightLeg1angle", new Double(0));
		test.put("rightLeg1Length", new Integer(15));
		test.put("rightLeg2angle", new Double(0));
		test.put("rightLeg2Length", new Integer(15));

//		System.out.println(test.toJSONString());
		test.put("headWidth", new Integer(50));
		test.put("headHeight", new Integer(40));
		test.put("faceWidth", new Integer(35));
		test.put("faceHeight", new Integer(35));
		test.put("earWidth", new Integer(10));
		test.put("earHeight", new Integer(30));

		
		ArrayList<JSONObject> dance = new ArrayList<JSONObject>();

		JSONObject frame1 = new JSONObject();
		frame1.put("leftLeg1angle", new Double(45));
		frame1.put("leftLeg2angle", new Double(-45));
		frame1.put("rightLeg1angle", new Double(-45));
		frame1.put("rightLeg2angle", new Double(45));
		dance.add(frame1);

		JSONObject frame2 = new JSONObject();
		frame2.put("leftLeg1angle", new Double(0));
		frame2.put("leftLeg2angle", new Double(0));
		frame2.put("rightLeg1angle", new Double(0));
		frame2.put("rightLeg2angle", new Double(0));
		dance.add(frame2);

		JSONObject frame3 = new JSONObject();
		frame3.put("leftLeg1angle", new Double(-45));
		frame3.put("leftLeg2angle", new Double(45));
		frame3.put("rightLeg1angle", new Double(45));
		frame3.put("rightLeg2angle", new Double(-45));
		dance.add(frame3);

		JSONObject frame4 = new JSONObject();
		frame4.put("leftLeg1angle", new Double(0));
		frame4.put("leftLeg2angle", new Double(0));
		frame4.put("rightLeg1angle", new Double(0));
		frame4.put("rightLeg2angle", new Double(0));
		dance.add(frame1);

		dancetest = new JSONObject();
		dancetest.put("frameNum", dance.size());
		dancetest.put("delay", 100);
		dancetest.put("dance", dance);

//		System.out.println(dancetest.toJSONString());

		
		// robot.setRobot(test.toJSONString());
		// robot.setRobot(50, 50, Math.PI/3, 0, 30, 30, 0, 0, 30);

	
		
		f.setLayout(new GridBagLayout());
	//	f.setBounds(0, 0, 1300, 760);
		ImageIcon backgroundImage=new ImageIcon("res/image/talk.png");
		Image img=backgroundImage.getImage();
		backgroundImage=new ImageIcon(img.getScaledInstance(f.getWidth(), (int)(f.getHeight()*4.0/5), Image.SCALE_SMOOTH));
		
		
		stage = new JLabel(backgroundImage);
		GridBagConstraints stage_GBC = new GridBagConstraints();

		stage_GBC.gridx=0;
		stage_GBC.gridy=0;
		//stage_GBC.ipadx = frameWidth;
		//stage_GBC.ipady = 100;
		stage_GBC.anchor=GridBagConstraints.CENTER;
		//stage_GBC.weightx=0.3;
		stage.setLayout(new BorderLayout());
//		stage.setBounds(0, 0, 1200, 760);
		stage.setBorder(BorderFactory.createBevelBorder(BevelBorder.RAISED));
//		stage.setBackground(new Color(0,0,0,0));

		JLabel btn = new JLabel();
//		btn.setLayout(new BoxLayout(btn, BoxLayout.LINE_AXIS));
		btn.setLayout(new FlowLayout());
	//	btn.setBounds(0, 0, 500, 760);
		// btn.setBackground(Color.GREEN);
		GridBagConstraints btn_GBC = new GridBagConstraints();
//		btn_GBC.weightx = 0.1;
//		btn_GBC.gridheight=2;
		btn_GBC.gridx=0;
		btn_GBC.gridy=1;
	//	btn_GBC.fill=GridBagConstraints.HORIZONTAL;
		btn_GBC.ipadx=frameWidth;
		btn_GBC.ipady=(int)(f.getHeight()*1.0/5);
		//btn_GBC.anchor=GridBagConstraints.SOUTH;
		
		JTextField hidden=new JTextField();
		hidden.setVisible(false);
		f.add(hidden);
//        System.out.println("test");
        KeyboardFocusManager manager = KeyboardFocusManager.getCurrentKeyboardFocusManager();
        manager.addKeyEventDispatcher(new KeyEventDispatcher() {
			
			public boolean dispatchKeyEvent(KeyEvent e) {
				// TODO Auto-generated method stub
				if(e.getID()==KeyEvent.KEY_PRESSED){
//					System.out.println(e.getKeyChar());
				}
				return false;
			}
		});
		
		
		ComboBoxPan=new JPanel();
		ComboBoxPan.setLayout(new BoxLayout(ComboBoxPan, BoxLayout.Y_AXIS));
		
		musicPan=new JPanel();
		musicLab=new JLabel("music");
		musicBox=new JComboBox(musicList);
		
		musicPan.add(musicLab);
		musicPan.add(musicBox);
		musicBox.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				File file=null;
				if(musicBox.getSelectedItem().equals("Cute"))
				{
					file = new File("res/music/cute.wav");
				}
				else if(musicBox.getSelectedItem().equals("Marry you"))
				{
					file = new File("res/music/marryyou.wav");
				}
				else if(musicBox.getSelectedItem().equals("I do I do"))
				{
					file = new File("res/music/idoido.wav");
				}
				else if(musicBox.getSelectedItem().equals("酒抚促款 广"))
				{
					file = new File("res/music/abam.wav");
				}
				else if(musicBox.getSelectedItem().equals("Let it be"))
				{
					file = new File("res/music/letitbe.wav");
				}
				else if(musicBox.getSelectedItem().equals("Treasure"))
				{
					file = new File("res/music/treasure.wav");
				}
				clip.stop();
				try {
				    clip = Applet.newAudioClip(file.toURL());
					clip.loop();
				}catch(Exception a){
				}
			}
		});
		
		dancePan=new JPanel();
		danceLab=new JLabel("dance");
		danceBox=new JComboBox(danceList);
		
		danceBox.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(danceBox.getSelectedItem().equals("defalut"))
				{
					dancePath=null;
				}
				else if(danceBox.getSelectedItem().equals("I do I do"))
				{
					dancePath="IdoIdo.json";
				}
				else if(danceBox.getSelectedItem().equals("酒抚促款 广"))
				{
					dancePath="abam.json";
				}
				else if(danceBox.getSelectedItem().equals("Muzi"))
				{
					dancePath="muziDance.json";
				}
				else if(danceBox.getSelectedItem().equals("Neo"))
				{
					dancePath="neoDance.json";
				}
				
			}
		});
		
		dancePan.add(danceLab);
		dancePan.add(danceBox);
		
		
		
		
		ComboBoxPan.add(musicPan);
		ComboBoxPan.add(dancePan);
		
		btn.add(ComboBoxPan);		
		
		
		
		ButtonGroup btnGroup = new ButtonGroup();
		muziBtn = new JRadioButton("Muzi");
		neoBtn = new JRadioButton("Neo");
		conBtn = new JRadioButton("Con");
		frodoBtn=new JRadioButton("Frodo");
		tubeBtn = new JRadioButton("Tube");
		apeachBtn = new JRadioButton("Apeach");
		jayGBtn=new JRadioButton("JayG");
		powerRangerBtn=new JRadioButton("PowerRanger");
		basicRobotBtn = new JRadioButton("BasicRobot");
		
		btnGroup.add(muziBtn);
		btnGroup.add(neoBtn);
		btnGroup.add(conBtn);
		btnGroup.add(frodoBtn);
		btnGroup.add(tubeBtn);
		btnGroup.add(apeachBtn);
		btnGroup.add(jayGBtn);
		btnGroup.add(powerRangerBtn);
		btnGroup.add(basicRobotBtn);
		basicRobotBtn.setSelected(true);

		muziImgBtn = new JButton(new ImageIcon("res/image/Muzi.png"));
		muziImgBtn.setBackground(new Color(255,255,255,255));
		muziImgBtn.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				muziBtn.setSelected(true);
			}
		});
		neoImgBtn = new JButton(new ImageIcon("res/image/Neo.png"));
		neoImgBtn.setBackground(new Color(255,255,255,255));
		neoImgBtn.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				neoBtn.setSelected(true);
			}
		});
		conImgBtn = new JButton(new ImageIcon("res/image/Con_.png"));
		conImgBtn.setBackground(new Color(255,255,255,255));
		conImgBtn.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				conBtn.setSelected(true);
			}
		});
		frodoImgBtn = new JButton(new ImageIcon("res/image/Frodo.png"));
		frodoImgBtn.setBackground(new Color(255,255,255,255));
		frodoImgBtn.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				frodoBtn.setSelected(true);
			}
		});
		tubeImgBtn = new JButton(new ImageIcon("res/image/Tube.png"));
		tubeImgBtn.setBackground(new Color(255,255,255,255));
		tubeImgBtn.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				tubeBtn.setSelected(true);
			}
		});
		apeachImgBtn = new JButton(new ImageIcon("res/image/Apeach.png"));
		apeachImgBtn.setBackground(new Color(255,255,255,255));
		apeachImgBtn.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				apeachBtn.setSelected(true);
			}
		});
		jayGImgBtn = new JButton(new ImageIcon("res/image/Jay-G.png"));
		jayGImgBtn.setBackground(new Color(255,255,255,255));
		jayGImgBtn.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				jayGBtn.setSelected(true);
			}
		});
		btn.add(muziImgBtn);
		btn.add(neoImgBtn);
		btn.add(conImgBtn);
		btn.add(frodoImgBtn);
		btn.add(tubeImgBtn);
		btn.add(apeachImgBtn);
		btn.add(jayGImgBtn);
		
		
		
		smallBtnGrp=new JPanel();
		smallBtnGrp.setLayout(new BoxLayout(smallBtnGrp,BoxLayout.Y_AXIS));
		
		playBtn=new JButton(new ImageIcon("res/image/play.png"));
		playBtn.setBackground(new Color(255,255,255,255));
		playBtn.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent arg0) {
				dancingFlag=true;
				for(int i=0;i<threadList.size();i++){
					threadList.get(i).startdancing();
				}
			}
		});
		pauseBtn=new JButton(new ImageIcon("res/image/pause.png"));
		pauseBtn.setBackground(new Color(255,255,255,255));
		pauseBtn.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				dancingFlag=false;
				for(int i=0;i<threadList.size();i++){
					threadList.get(i).stopdancing();
				}
			}
		});
		
		trashBtn=new JButton(new ImageIcon("res/image/trash.png"));
		trashBtn.setBackground(new Color(255,255,255,255));
		trashBtn.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				for(int i=0;i<threadList.size();i++){
					threadList.get(i).stop();
					stage.remove(threadList.get(i).getComponent());
				}
				threadList.clear();
				stage.repaint();
			}
		});
		
		
		smallBtnGrp.add(playBtn);
		smallBtnGrp.add(pauseBtn);
		smallBtnGrp.add(trashBtn);
		
		
		btn.add(smallBtnGrp);
		
		
//		btn.add(muziBtn);
//		btn.add(neoBtn);
//		btn.add(conBtn);
//		btn.add(frodoBtn);
//		btn.add(tubeBtn);
//		btn.add(apeachBtn);
//		btn.add(jayGBtn);
//		btn.add(powerRangerBtn);
//		btn.add(basicRobotBtn);
		// stage.setBackground(Color.GREEN);
		// stage.add(robot.getComponent());

	

		f.add(btn, btn_GBC);
		//f.setContentPane(new JLabel(new ImageIcon("res/back.png")));
		f.add(stage, stage_GBC);

		stage.addMouseMotionListener(new MouseMotionListener() {
			
			public void mouseMoved(MouseEvent e) {
				// TODO Auto-generated method stub

			}
			
			public void mouseDragged(MouseEvent e) {
				// TODO Auto-generated method stub
				if (flag) {
					dragbot.setLocation(e.getX()-offsetX, e.getY()-offsetY);
				}
				
			}
		});
		
		
		
		
		
		stage.addMouseListener(new MouseListener() {

			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub
				flag=false;
				dragbot=null;
			}

			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub
				Component[] array = stage.getComponents();
				for (int i = 0; i < array.length; i++) {
					if (BasicRobot.class.isInstance(array[i])
							&& inner((BasicRobot) array[i], e.getX(),
									e.getY())) {
						flag = true;
						dragbot = (BasicRobot) array[i];
						offsetX=e.getX()-dragbot.X;
						offsetY=e.getY()-dragbot.Y;
//						System.out.println(array[i]);
						break;
					}
				}
			}

			public void mouseExited(MouseEvent e) {
				// TODO Auto-generated method stub
			}

			public void mouseEntered(MouseEvent e) {
				// TODO Auto-generated method stub
			}

			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				String CharName=null;
				BasicThread robot = null;
				if (muziBtn.isSelected()) {
					robot = new BasicThread(new Muzi(BasicThread
							.FileRead("res/character/Muzi.txt")));
					CharName = "muzi";
				}
				if (conBtn.isSelected()) {
					robot = new BasicThread(new ConClass(BasicThread
							.FileRead("res/character/ConClass.txt")));
					CharName = "con";
				}
				if (neoBtn.isSelected()) {
					robot = new BasicThread(new Neo(BasicThread
							.FileRead("res/character/Neo.txt")));
					CharName = "neo";
				}
				if (basicRobotBtn.isSelected()) {
					robot = new BasicThread(new BasicRobot(BasicThread
							.FileRead("res/character/BasicRobot.txt")));
					CharName = "muzi";
				}
				if (frodoBtn.isSelected()) {
					robot = new BasicThread(new Frodo(BasicThread
							.FileRead("res/character/Frodo.txt")));
					CharName = "frodo";
				}
				if (tubeBtn.isSelected()) {
					robot = new BasicThread(new Tube(BasicThread
							.FileRead("res/character/Tube.txt")));
					CharName = "tube";
				}
				if (apeachBtn.isSelected()) {
					robot = new BasicThread(new Apeach(BasicThread
							.FileRead("res/character/Apeach.txt")));
					CharName = "apeach";
				}
				if (jayGBtn.isSelected()) {
					robot = new BasicThread(new JayG(BasicThread
							.FileRead("res/character/JayG.txt")));
					CharName = "jayg";
				}
				if(dancePath!=null){
					robot.setDance("res/dance/"+dancePath);				
				}
				else{
					robot.setDance("res/dance/"+CharName+"Dance.json");
					
				}

				robot.setLocation(e.getX(), e.getY());
				robot.start();
				if(dancingFlag){
					robot.startdancing();
				}
				else{
					robot.stopdancing();
				}
				threadList.add(robot);
//				System.out.println("create Basic");
				stage.add(robot.getComponent(), BorderLayout.CENTER);
				clip.play();
				f.setVisible(true);

			}
		});
		// f.add(stage);

		// f.pack();
		f.setVisible(true);
		// robot.startdancing();
		// robot.start();
		
//		BasicThread.panel=stage;
		try {
		    File file = new File("res/music/idoido.wav");
		    clip = Applet.newAudioClip(file.toURL());
		}catch(Exception e){
		}
		

	}
	public static boolean inner(BasicRobot bot,int x,int y){
		int width=bot.getWidthC();
		int height=bot.getHeightC();
		int X=bot.getXC()+width/2;
		int Y=bot.getYC()+height/2;
		if(x>X-(width/1.8) && x<X+(width/1.8) && y>Y-(height*2) && y<Y+height){
			return true;
		}
		
		
		return false;
	}
	
}
