package com.cloud_sys.socket;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class MainServer {
	public static final int SERVER_PORT = 23333; // 服务端端口
	static ServerSocket Server;

	public static void main(String[] args) {
		try {
			Server = new ServerSocket(SERVER_PORT);
			while (true) {
				Socket client = Server.accept();
				dispatchServer(client);
			}
		} catch (Exception e) {
			System.err.println(e.toString());
		}
	}
	
	/**
	 * 判断指令, 分配服务
	 * @param client
	 */
	private static void dispatchServer(Socket client) {
		try {
        	BufferedReader dataIn = new BufferedReader(new InputStreamReader(client.getInputStream()));
        	BufferedWriter dataOut = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));
            String str = dataIn.readLine();
            switch (str) {
			case "#L#":
				new LoginServer(dataIn, dataOut).start();
				info("#L# :: " + client.toString());
				break;
			case "#R#":
				new RegisterServer(dataIn, dataOut).start();
				info("#R# :: " + client.toString());
				break;		
			case "#D#":
				new DownloadServer(dataIn, dataOut).start();
				info("#D# :: " + client.toString());
				break;
			case "#U#":
				new UpdataServer(dataIn, dataOut).start();
				info("#U# :: " + client.toString());
				break;
			case "#F#":
				new FileGetServer(dataIn, dataOut).start();
				info("#F# :: " + client.toString());
			case "#E#":
				new Remove(dataIn, dataOut).start();
				info("#E# :: " + client.toString());
			case "#F#":
				//执行文件获取操作
				new FileGetterServer(dataIn, dataOut);
				
				info("#F# :: " + client.toString());
			default:
				break;
			}
		} catch(Exception e) {
			System.err.println(e.toString());
		}
	}
	
	/**
	 * infomation
	 * @param info
	 */
	static private void info(String info) {
		System.err.println("Client :: " + info + "  @dispatchServer(Socket)");
	}
}
