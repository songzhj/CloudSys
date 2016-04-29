package com.cloud_sys.socket;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class Remove extends Thread {
	private BufferedReader dataIn;
	private BufferedWriter dataOut;
	private ArrayList<String> info = new ArrayList<String>();
	private String path = "G:/CloudServer/";
		
	/**
	 * @param dataIn
	 * @param dataOut
	 */
	public Remove(BufferedReader dataIn, BufferedWriter dataOut) {
		this.dataIn = dataIn;
		this.dataOut = dataOut;
	}
	
	/**
	 * run
	 */
	public void run() {
		try {
			in();
			delete();
			dataIn.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * 删除文件
	 */
	private void delete() {
		File file = new File(path + info.get(0) + "/" + info.get(1));
		file.delete();
		if(file.exists()) {
			out("N");
		} else {
			out("Y");
		}
	}

	/**
	 * 套接字取数据
	 * @throws IOException
	 */
	private void in() throws IOException {
		String str = "";
		while(true) {
			str = dataIn.readLine();
			if ("#END#".equals(str)) {
				break;
			} else {
				info.add(str);
			}
		}
	}
	
	/**
	 * 回传数据
	 * @param res
	 * @return
	 */
    private boolean out(String res) {
    	try {
        	dataOut.write(res);
        	dataOut.close();
    	} catch(IOException e) {
    		return false;
    	}
    	return true;
    }	
}
