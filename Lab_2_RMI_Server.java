/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_rmi_server;

import RMI_Date_Time.RMI_Date_Time;
import java.net.SocketException;
import java.rmi.AlreadyBoundException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Deep-North
 */
public class Lab_2_RMI_Server extends UnicastRemoteObject  implements RMI_Date_Time{
    
    public Lab_2_RMI_Server() throws RemoteException {}
    
    @Override
    public String getDate() throws RemoteException {
        return Func.getStrDate();
    }

    @Override
    public String getTime() throws RemoteException {
        return Func.getStrTime();
    }

    @Override
    public boolean stop() throws RemoteException {
        try {
            Registry registry = LocateRegistry.getRegistry(Registry.REGISTRY_PORT);
            registry.unbind("RMI_Server");
            return UnicastRemoteObject.unexportObject(this, true);
            
        } catch (NotBoundException ex) {
            Logger.getLogger(Lab_2_RMI_Server.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }
    
    public String getServiceName() {
        return "RMI_Server";
    }

    /**
     * @param args the command line arguments
     * @throws java.net.SocketException
     * @throws java.rmi.AlreadyBoundException
     */
    public static void main(String[] args) throws SocketException, AlreadyBoundException {
        try {
            //Lab_2_RMI_Server s = new Lab_2_RMI_Server();
            Registry registry = LocateRegistry.createRegistry(Registry.REGISTRY_PORT);
            RMI_Date_Time dt = new Lab_2_RMI_Server();
            registry.bind("RMI_Server", dt);
            System.out.println("Server has been started...");

        } catch (RemoteException ex) {
            Logger.getLogger(Lab_2_RMI_Server.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
