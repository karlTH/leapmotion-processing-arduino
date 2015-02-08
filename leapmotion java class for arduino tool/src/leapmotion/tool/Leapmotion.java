package leapmotion.tool;

import java.io.File;
import java.io.IOException;

import processing.app.Editor;
import processing.app.tools.Tool;

public class Leapmotion implements Tool {

	public String getMenuTitle() {
		return "Leapmotion";
	}

	public void init(Editor arg0) {
		
		// TODO Auto-generated method stub
		
	}
	
	public void run() {
		// TODO Auto-generated method stub
		Runtime rt = Runtime.getRuntime();
		
		try {
			
			String dir = getClass().getClassLoader().getResource(".").getFile();
						
			 Process ps = rt.exec(dir.replaceAll("%20", " ") + "..\\tools\\Leapmotion\\tool\\leapmotion\\leapmotion.exe", null, new File(dir.replaceAll("%20", " ") + "..\\tools\\Leapmotion\\tool\\leapmotion"));
			  ps.waitFor();
		      
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
