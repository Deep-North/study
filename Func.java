/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_rmi_server;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;

/**
 *
 * @author Deep-North
 */
public class Func {
    public static String getStrTime() {
        DateFormat df = new SimpleDateFormat("HH:mm:ss");
        String time = "";
        GregorianCalendar calendar = new GregorianCalendar();
        time = "Время: " + df.format(calendar.getTime());
        return (time);
    }
    
    public static String getStrDate() {
        DateFormat df = new SimpleDateFormat("dd MMM yyyy");
        GregorianCalendar calendar = new GregorianCalendar();
        String date = "";
        date = "Дата: " + df.format(calendar.getTime());
        return (date);
    }
}
