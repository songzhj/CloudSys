package com.cloud_sys.socket;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

import org.apache.ftpserver.FtpServer;
import org.apache.ftpserver.FtpServerFactory;
import org.apache.ftpserver.ftplet.Authority;
import org.apache.ftpserver.ftplet.FtpException;
import org.apache.ftpserver.listener.ListenerFactory;
import org.apache.ftpserver.usermanager.impl.BaseUser;
import org.apache.ftpserver.usermanager.impl.WritePermission;

public class UpdataServer extends Thread {
	private static final int PORT = 23335;
	private BufferedReader dataIn;
	private BufferedWriter dataOut;
	private ArrayList<String> info = new ArrayList<String>();
	private String userName; //连接服务端的用户名
	private String pwd = "0"; //FTP默认密码
	private FtpServer fs; //FTP服务, 设置为成员变量为了结束时stop()
	String path = "D:/CloudServer/";
	
	
	/**
	 * @param dataIn
	 * @param dataOut
	 */
	public UpdataServer(BufferedReader dataIn, BufferedWriter dataOut) {
		this.dataIn = dataIn;
		this.dataOut = dataOut;
	}


	
	/* (non-Javadoc)
	 * @see java.lang.Thread#run()
	 */
	public void run() {
		in(); //读取用户名.
		userName = info.get(0);
		ftpServer();
		in(); //读取传输完成指令, 传输完成前阻塞状态
		if(info.get(1).equals("#OK#")) {
			fs.stop();
			try {
				dataIn.close();
				dataOut.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	/**
	 * FTP服务端
	 */
	private void ftpServer() {
		ListenerFactory lf = new ListenerFactory();
		lf.setPort(PORT);
		FtpServerFactory fsf = new FtpServerFactory();
		fsf.addListener(userName, lf.createListener()); //!!!!!!!!!!!!!!!!!!!!!!!!!!
		BaseUser user = new BaseUser();
		user.setName(userName);
		user.setPassword(pwd);
		path += userName;
		user.setHomeDirectory(path);
		List<Authority> authorities = new ArrayList<Authority>(); 
		authorities.add(new WritePermission());
		user.setAuthorities(authorities);
		
		try {
			fsf.getUserManager().save(user);
			fs = fsf.createServer();
			fs.start();
		} catch (FtpException e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * 套接字取数据
	 * @throws IOException
	 */
	private void in() {
		String str = "";
		while(true) {
			try {
				str = dataIn.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			if ("#END#".equals(str)) {
				break;
			} else {
				info.add(str);
			}
		}
	}
	
}
