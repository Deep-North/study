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
public class Employee {
    public static int id_starter = 0;
    private int id_number;
    private String name;
    private String position;
    private int salary;       
        
    public Employee(String name){
        this.id_number = ++ id_starter;
        this.name = name;
        this.position = "worker";
        this.salary = 5000;
    }
        
    public Employee( String name, String position) {
        this.id_number = ++ id_starter;
        this.name = name;
        this.position = position;
        this.salary = "worker".equals(position.toLowerCase()) ? 5000 : 6000;   
    }
        
    public Employee( String name, String position, int salary) {
        this.id_number = ++ id_starter;
        this.name = name;
        this.position = position;
        this.salary = salary;
    }
        
    @Override
    public String toString() {
        return "Сотрудник №"+id_number+" Имя: "+name+", Должность: "+position+", Зарплата: "+salary;
    }
    
    public static void printEmp(Employee[] value){
        int sal_sum = 0;
        int tmp_sal = 0;
        int tmp_id = 0;
        for (int i=0; i<value.length; i++){
            System.out.println(value[i].toString());
            sal_sum += value[i].salary;
            if (tmp_sal<value[i].salary){
                tmp_id = i;
            }
        }
        System.out.println("\nСуммарная зарплата всех сотрудников: "+sal_sum);
        System.out.println("\nМаксимальную зарплату ("+value[tmp_id].salary+
                ") получает "+value[tmp_id].position+"\n");
    }
}
