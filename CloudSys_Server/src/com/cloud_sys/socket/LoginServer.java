package com.cloud_sys.socket;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

import com.cloud_sys.dao.UserDao;

public class LoginServer extends Thread{
	private BufferedReader dataIn;
	private BufferedWriter dataOut;
	private ArrayList<String> info = new ArrayList<String>();
	
	/**
	 * 构造
	 * @param client
	 */
	public LoginServer(BufferedReader dataIn, BufferedWriter dataOut) {
		this.dataIn = dataIn;
		this.dataOut = dataOut;
	}
	
	
	/**
	 * 核对用户信息
	 * @return boolean
	 */
    private boolean checkUser() {
    	UserDao us = new UserDao();
    	if(us.findUserPwdByUserName(info.get(0)).equals(info.get(1))){
    		return true;
    	} else {
    		return false;
    	}
    }

    /**
     * 线程start
     */
	public void run() {
		 try {
	            in();
	            if(checkUser()) {
	            	while(!out("Y")){}
	            } else {
	            	while(!out("N")){}
	            }
	            dataIn.close();
	        } catch (Exception e) {
	            System.err.println(e.toString());
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
