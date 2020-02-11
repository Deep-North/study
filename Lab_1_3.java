/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_1_3;

/**
 *
 * @author Deep-North
 */
public class Lab_1_3 {

    /**
     * @param args the command line arguments
     */
    
        public static void main(String[] args) {
        // TODO code application logic here
        //Employee man = new Employee("Man");
        Employee[] staff = {
            new Employee("Вася"),
            new Employee("Петя"),
            new Employee("Коля"),
            new Employee("Маша", "secretary"),
            new Employee("Катя", "worker"),
            new Employee("Джамшут", "builder"),
            new Employee("Майкл Джексон", "singer", 100000),
            new Employee("Тина Тернер", "singer", 90000),
            new Employee("Путин", "mr_president", 10000),
            new Employee("Трамп", "mr_president", 10000)
        };
        
       Employee.printEmp(staff);
    }
    
}
