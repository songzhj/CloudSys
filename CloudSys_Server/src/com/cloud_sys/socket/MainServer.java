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
				info("#L# :: " + client.toString());
				new LoginServer(dataIn, dataOut).start();
				info(":: Finished");
				break;
			case "#R#":
				info("#R# :: " + client.toString());
				new RegisterServer(dataIn, dataOut).start();
				info(":: Finished");
				break;		
			case "#D#":
				info("#D# :: " + client.toString());
				new DownloadServer(dataIn, dataOut).start();
				info(":: Finished");
				break;
			case "#U#":
				info("#U# :: " + client.toString());
				new UpdataServer(dataIn, dataOut).start();
				info(":: Finished");
				break;
			case "#E#":
				info("#E# :: " + client.toString());
				new Remove(dataIn, dataOut).start();
				info(":: Finished");
			case "#F#":
				//执行文件获取操作
				info("#F# :: " + client.toString());
				new FileGetterServer(dataIn, dataOut).start();
				info(":: Finished");
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
