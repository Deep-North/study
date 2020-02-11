/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_rmi_client;

import RMI_Date_Time.RMI_Date_Time;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Deep-North
 */
public class Lab_2_RMI_Client {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws NotBoundException {
        boolean running = true;
        try {
            Registry registry = LocateRegistry.getRegistry(Registry.REGISTRY_PORT);
            RMI_Date_Time stub = (RMI_Date_Time) registry.lookup("RMI_Server");

            while (running) {
                Scanner in = new Scanner(System.in);
                System.out.print("Enter command: date, time or stop \n");
                String command = in.nextLine().toLowerCase();
                
                switch (command) {
                    case "date":
                        System.out.println(stub.getDate());
                        break;
                    case "time":
                        System.out.println(stub.getTime());
                        break;
                    case "stop":
                        while (stub.stop() == false) {
                            stub.stop();
                            System.out.println("Trying to stop server");
                        }
                        System.out.println("Server stopped");
                        running = false;
                        break;
                    default:
                        System.out.println("Error!\nEnter correct choice...");
                        break;
                }
            }
        } catch (RemoteException ex) {
            Logger.getLogger(Lab_2_RMI_Client.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}