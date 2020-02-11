/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_tcp_ip_rmi;

import java.net.SocketException;
import java.net.UnknownHostException;
import java.rmi.AlreadyBoundException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Deep-North
 */
public class RMI_TASK {
        
    public void exec() throws AlreadyBoundException, NotBoundException {
        try {
            initServer();
            initClient();
        } catch (SocketException ex) {
            Logger.getLogger(RMI_TASK.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    private void initServer() throws SocketException, AlreadyBoundException {
        try {
            RMI_Server s = new RMI_Server();
            Registry registry = LocateRegistry.createRegistry(11111);
            registry.bind("RMI_Server", s);
            System.out.println("Server has been started...");

        } catch (RemoteException ex) {
            Logger.getLogger(RMI_TASK.class.getName()).log(Level.SEVERE, null, ex);
        }       
    }
    
    private void initClient() throws NotBoundException{
        boolean running = true;
        try {
            Registry registry = LocateRegistry.getRegistry(11111);
            RMI_Date_Time stub = (RMI_Date_Time) registry.lookup("RMI_Server");

            while (running) {
                Scanner in = new Scanner(System.in);
                System.out.print("Enter command: date, time or stop \n");
                String command = in.nextLine().toLowerCase();
                
                switch (command) {
                    case "date":
                        System.out.println("Current date: " + stub.getDate());
                        break;
                    case "time":
                        System.out.println("Current time: " + stub.getTime());
                        break;
                    case "stop":
                        try{
                            stub.stop();
                            if (stub.stop()){
                                running = false;    
                                System.out.println("SERVER STOPPED");
                            }
                            } catch (RemoteException ex) {
                                Logger.getLogger(RMI_TASK.class.getName()).log(Level.SEVERE, null, ex);
                                }
                        break;
                    default:
                        System.out.println("Error!\nEnter correct choice...");
                        break;
                }
            }
        } catch (RemoteException ex) {
            Logger.getLogger(RMI_TASK.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
