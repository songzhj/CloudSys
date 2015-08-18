package com.cloud_sys.socket;

import java.net.ServerSocket;
import java.net.Socket;

public class MainServer {
    public static final int SERVER_PORT=23333; //服务监听端口号
    static ServerSocket Server;
    
    public static void main(String[] args) {
		try {
			Server = new ServerSocket(SERVER_PORT);
			while(true) {
				Socket client = Server.accept();
				//TODO: 一个方法来判断选择请求的是什么服务,并启动.
			} catch (Exception e) {
				System.err.println(e.toString());
			}
		}
	}
}
