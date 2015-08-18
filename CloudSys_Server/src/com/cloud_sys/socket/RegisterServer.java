package com.cloud_sys.socket;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

import com.cloud_sys.dao.UserDao;
import com.cloud_sys.entity.User;

public class RegisterServer extends Thread {
	private BufferedReader dataIn;
	private BufferedWriter dataOut;
	private ArrayList<String> info = new ArrayList<String>();
	
	
	/**
	 * @param dataIn
	 * @param dataOut
	 */
	public RegisterServer(BufferedReader dataIn, BufferedWriter dataOut) {
		this.dataIn = dataIn;
		this.dataOut = dataOut;
		System.out.println(111);
	}

	/**
	 * 添加用户
	 * @return boolean
	 */
    private boolean addUser() {
    	UserDao us = new UserDao();
    	User user = new User();
    	if(1 == us.addUser(user)){
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
	            if(addUser()) {
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
