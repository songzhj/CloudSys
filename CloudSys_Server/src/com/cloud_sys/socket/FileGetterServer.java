package com.cloud_sys.socket;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class FileGetterServer extends Thread{
	private BufferedReader dataIn;
	private BufferedWriter dataOut;
	private ArrayList<String> info = new ArrayList<String>();
	private String path = "G:/CloudServer/";
	
	/**
	 * @param dataIn
	 * @param dataOut
	 */
	public FileGetterServer(BufferedReader dataIn, BufferedWriter dataOut) {
		this.dataIn = dataIn;
		this.dataOut = dataOut;
	}
	
	public void run() {
		try {
			in();
			out(getFolderFile(path + info.get(0)));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	/**通过文件路径获得所有文件名
	 * @param folderPath
	 * @return
	 */
	public String getFolderFile(String folderPath) {
		File file = new File(folderPath);
		if(!file.exists()) {
			file.mkdir();
		}
		String[] fileNamesArray = file.list();
		String fileName = "";
		for (int i = 0; i < fileNamesArray.length; ++i) {
			fileName += fileNamesArray[i] + "*";
		}
		if(fileName.length() != 0){
			fileName = fileName.substring(0, fileName.length() - 1);
		}
		return fileName;
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
        	dataIn.close();
    	} catch(IOException e) {
    		return false;
    	}
    	return true;
    }	
}
