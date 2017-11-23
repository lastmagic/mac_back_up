package myJSON;

import java.util.Stack;

public class JSONParser {
	
	private static String jsonString;
	private static int i;
	
	public static JSONObject parse(String jsonText){
		Stack<JSONObject> stack=new Stack<JSONObject>();

		jsonString=jsonText.replaceAll("[ \n\r\t]","");
//		System.out.println(jsonString);
		i=0;
		return parseJsonObject();
	}
	private static JSONObject parseJsonObject(){
		JSONObject jsonObject=new JSONObject();
		i=jsonString.indexOf("{",i)+1;
		while(jsonString.charAt(i)!='}'){
			String key;
			Object value;
			i=jsonString.indexOf("\"",i)+1;
			key=jsonString.substring(i, jsonString.indexOf("\"",i));
			i=jsonString.indexOf(":",i)+1;
			value=parseObject();
		//	System.out.println(key+"  "+value);
			jsonObject.put(key, value);
		}
		i++;
		return jsonObject;
	}
	
	private static JSONArray parseJsonList(){
		JSONArray array=new JSONArray();
		
		i=jsonString.indexOf("[",i)+1;
		while(jsonString.charAt(i)!=']'){
			Object value;
			value=parseObject();
			int index=0x7fffffff;
			int index1=jsonString.indexOf(",",i)+1;
			int index2=jsonString.indexOf("]",i);
			if(index>index1 && index1!=0){
				index=index1;
			}
			if(index>index2 && index2!=-1){
				index=index2;
			}
			i=index;
			array.add(value);
		}
		i++;
		return array;
	}
	
	
	private static Object parseObject(){
		Object value=null;
		
		
		if(jsonString.charAt(i)=='{'){
			value=parseJsonObject();
		}
		else if(jsonString.charAt(i)=='['){
			value=parseJsonList();
		}
		else if(jsonString.charAt(i)=='"'){
			i=jsonString.indexOf("\"",i)+1;
			value=jsonString.substring(i, jsonString.indexOf("\"",i));
			i=jsonString.indexOf("\"",i)+1;
		}
		else{
			int index=0x7fffffff;
			int index1=jsonString.indexOf(",",i);
			int index2=jsonString.indexOf("}",i);
			int index3=jsonString.indexOf("]",i);
			
			
			if(index>index1 && index1!=-1){
				index=index1;
			}
			if(index>index2 && index2!=-1){
				index=index2;
			}
			if(index>index3 && index3!=-1){
				index=index3;
			}
			value=jsonString.substring(i, index);
			i=index;
			try{
				value=Long.parseLong((String)value);
			}catch(NumberFormatException e){
				value=Double.parseDouble((String)value);
			}
			
			
		}
		
		
		return value;
	}
}
