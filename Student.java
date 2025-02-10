/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.studentmanagementsystem;

/**
 *
 * @author Mohamed Fathy
 */
public class Student  extends Person   {
    private int ID ;
    
     public Student(int ID, String name, int age) {
        super(name, age);
        this.ID = ID;
    }
     
    // Getter and Setter
    public int getStudentId() {
        return ID;
    }

    public void setStudentId(int ID) {
        this.ID = ID;
    }

    @Override
    public void display() {
        System.out.println("Student ID: " + ID);
        System.out.println("Student name: " + getName());
        System.out.println("Student age: " + getAge());
    }
}
