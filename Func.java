/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_tcp_ip_rmi;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Calendar;
import java.util.GregorianCalendar;

/**
 *
 * @author Deep-North
 */
public class Func {
    
    public static final int PORT = 15678;    
    public static final int MAX_SIZE = 2048;
    
//    public static byte[] intToByteAr(int i ) {
//        byte[] b = new byte[4];
//        b[0] = (byte)(i & 0xff);
//        b[1] = (byte)((i >> 8) & 0xff);
//        b[2] = (byte)((i >> 16) & 0xff);
//        b[3] = (byte)((i >> 24) & 0xff);
//        return b;
//    }
//
//    public static int byteArToInt(byte[] b) {
//        int i = ((0xFF & b[3]) << 24) | ((0xFF &  b[2]) << 16) | ((0xFF & b[1]) << 8) | (0xFF & b[0]); 
//        return i;
//    }
//    
//    public static void sendDemo(Demo demo, DatagramSocket socket, InetAddress address) throws IOException, InterruptedException {
//        final ByteArrayOutputStream baos = new ByteArrayOutputStream(6400);
//        final ObjectOutputStream oos = new ObjectOutputStream(baos);
//        oos.writeObject(demo);
//        final byte[] data = baos.toByteArray();
//
//        DatagramPacket packetData = new DatagramPacket(data, data.length, address, Func.PORT);
//        socket.send(packetData);
//    }
//    
//    public static Demo readDemo(DatagramSocket socket) throws IOException, ClassNotFoundException {
//        byte[] sizeBuf = new byte[4];
//        DatagramPacket packetSize = new DatagramPacket(sizeBuf, 4);
//        socket.receive(packetSize);
//        int size = Func.byteArToInt(sizeBuf);
//                
//        byte[] dataBuf = new byte[size];
//        DatagramPacket packetData = new DatagramPacket(dataBuf, size);
//        socket.receive(packetData);
//                
//        ByteArrayInputStream in = new ByteArrayInputStream(dataBuf);
//        ObjectInputStream is = new ObjectInputStream(in);
//                
//        Demo dem = (Demo)is.readObject();
//        return dem;
//    }
    
    public static String getStrTime() {
        GregorianCalendar c = new GregorianCalendar();
        return  calendarGet(c, GregorianCalendar.HOUR) + ":" + 
                                  calendarGet(c,  GregorianCalendar.MINUTE);
    }
    
    public static String getStrDate() {
        GregorianCalendar c = new GregorianCalendar();
        return  calendarGet(c, GregorianCalendar.YEAR) + "." + 
                                  calendarGet(c, GregorianCalendar.MONTH, 1) + "." + 
                                  calendarGet(c, GregorianCalendar.DATE)
                                ;
    }

    private static String  calendarGet(Calendar c, int type) { 
        return calendarGet(c, type, 0);
    }
         
    private static String  calendarGet(Calendar c, int type, int append) {
        int i =  c.get(type) + append;
        return i <= 9 ? "0" + i : i + "";
    }
}
