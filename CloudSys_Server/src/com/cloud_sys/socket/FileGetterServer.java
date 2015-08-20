package com.cloud_sys.socket;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;

public class FileGetterServer {
	private BufferedReader dataIn;
	private BufferedWriter dataOut;
	
	public FileGetterServer(BufferedReader dataIn, BufferedWriter dataOut) {
		// TODO Auto-generated constructor stub
		this.dataIn = dataIn;
		this.dataOut = dataOut;
	}
	
	/**通过文件路径获得所有文件名
	 * @param folderPath
	 * @return
	 */
	public String getFolderFile(String folderPath) {
		File file = new File(folderPath);
		String[] fileNamesArray = file.list();
		String fileName = "";
		for (int i = 0; i < fileNamesArray.length - 1; ++i) {
			fileName += fileNamesArray[i] + "*";
		}
		fileName += fileNamesArray[fileNamesArray.length - 1];
		return fileName;
	}

}
