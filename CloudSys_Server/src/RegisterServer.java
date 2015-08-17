import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class RegisterServer {

    public static final int SERVER_PORT=23333;
    static ServerSocket vntServer;
    
    public static void main(String[] args) {
        try{
            vntServer= new ServerSocket(SERVER_PORT);
            while(true){
                Socket vntClient=vntServer.accept();
                new GetGpsThreadFun(vntClient).run();
            }

        }catch (Exception e) {
            e.printStackTrace();
        }
    }
}

class GetGpsThreadFun extends Thread{
    private Socket vntThreadClient;
    
    private ArrayList<String> info = new ArrayList<String>();
    
    public GetGpsThreadFun(Socket vntThreadSocket){
        vntThreadClient=vntThreadSocket;
    }
    
    private boolean register() {
//    	TODO: if()判断数据库中是否存在user (info.index(0)).
//    				存在则返回false, 否则将信息添加进数据库, 完成注册.
    	if(false) { 
    		return false;
    	} else {
    		for(String s : info) {
    			System.out.println(s);
    		}
    		return true;
    	}
    }
    
    private boolean out(String res) {
    	try {
        	OutputStreamWriter opw = new OutputStreamWriter(vntThreadClient.getOutputStream());
        	opw.write(res);
        	opw.close();
    	} catch(IOException e) {
    		return false;
    	}
    	return true;
    }
    
    public void run(){
        try {
        	BufferedReader dataIn = new BufferedReader(new InputStreamReader(vntThreadClient.getInputStream()));
            String str = "";
            while(true) {
            	str = dataIn.readLine();
            	if ("#END#".equals(str)) {
            		break;
            	} else {
            		info.add(str);
            	}
            }
            if(register()) {
            	while(!out("Y")){}
            } else {
            	while(!out("N")){}
            }
            dataIn.close();
        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        }
    }
}