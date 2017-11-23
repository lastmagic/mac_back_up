package sys;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.ParseException;
import java.util.ArrayList;

import javax.swing.JPanel;

import myJSON.JSONArray;
import myJSON.JSONObject;
import myJSON.JSONParser;

public class BasicThread extends Thread implements dancingrobots {

	private BasicRobot robot;

	
	private JSONObject begin;
	
	private boolean dancing = true;
	
	public static JPanel panel=null;

	private ArrayList<JSONObject> dance = new ArrayList<JSONObject>();
	private int delay = 0;

	public BasicThread(String FileName) {
		String jsonText = FileRead(FileName);
		

		robot = new Muzi(jsonText);

	}
	public BasicThread(BasicRobot robot) {
		this.robot = robot;

	}
	
	
	public static String FileRead(String FileName){
		String jsonText="";
		try {
			BufferedReader in = new BufferedReader(new FileReader(FileName));
			String s;

			while ((s = in.readLine()) != null) {
				jsonText += s + "\n";
			}
			in.close();

		} catch (IOException e) {
		}
		
		return jsonText;
		
	}
	
	
	public void setDance(String jsonString) {
		JSONObject json = null;
		try{
			json=(JSONObject) new JSONParser().parse(FileRead(jsonString));
		}catch(Exception e2){
			json = (JSONObject) new JSONParser().parse(jsonString);
		}
//		delay = ((Long) json.get("delay")).intValue();
		begin=(JSONObject)json.get("set");
		JSONArray array = (JSONArray) json.get("dance");
		for (int i = 0; i < array.size(); i++) {
			dance.add((JSONObject) array.get(i));
		}
	}

	public boolean getDance() {
		return dancing;
	}

	public void run() {
		while (true) {
			
			
			robot.setRobot(begin);
			
			// System.out.println("t");
			int size = dance.size();
			for (int i = 0; i < size; i++) {
				robot.dancing(dance.get(i));
//				robot.setRobot(dance.get(i));
				robot.repaint();
//				try {
//					Thread.sleep(delay);
//				} catch (Exception e) {
//				}

			}
		}
	}

	public void setLocation(int x,int y){
		robot.setLocation(x, y);
	}
	
	public BasicRobot getComponent() {
		return robot;
	}

	//@SuppressWarnings("deprecation")
	public void startdancing() {
		// TODO Auto-generated method stub
		dancing = true;
		this.resume();
	}

	//@SuppressWarnings("deprecation")
	public void stopdancing() {
		// TODO Auto-generated method stub
		dancing = false;
		this.suspend();
	}

}
