/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package udp_exchange;

import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Deep-North
 */
public class RunTask_1 {
    public void exec() {
        try {
            initServer();
            sendClient();
        } catch (SocketException | UnknownHostException ex) {
            Logger.getLogger(RunTask_1.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    private void initServer() throws SocketException {
        MyServer server =  new MyServer();
        server.start();
        System.out.println("Server started...");
    }
    
    private void sendClient() throws SocketException, UnknownHostException{
        MyClient client = new MyClient();
        
        for(int i = 0; i < 10; i ++) {
            Demo res = client.sendDemo(new Demo("Test name " + i, "Test message", new Date(), 1));
            System.out.println("Client: " + res); 
        }
        System.out.println("Client started...");
        Demo res = client.sendDemo(new Demo("End of sending", "End message", new Date(), 1));
        System.out.println("Client: " + res);
    }
}
