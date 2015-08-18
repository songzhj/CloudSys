package com.cloud_sys.socket;

import java.net.ServerSocket;

public class MainServer {
	public static final int SERVER_PORT = 23333; // 鏈嶅姟鐩戝惉绔彛鍙�
	static ServerSocket Server;

	public static void main(String[] args) {
		try {
			Server = new ServerSocket(SERVER_PORT);
			while (true) {
			//	Socket client = Server.accept();
				// TODO: 涓�涓柟娉曟潵鍒ゆ柇閫夋嫨璇锋眰鐨勬槸浠�涔堟湇鍔�,骞跺惎鍔�.
			}
		} catch (Exception e) {
			System.err.println(e.toString());
		}
	}
}
