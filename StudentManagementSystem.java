/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.studentmanagementsystem;

/**
 *
 * @author Mohamed Fathy
 */

public class StudentManagementSystem {

    public static void main(String[] args) {
                    StudentSystem system = new StudentSystem();

       
        Student student1 = new Student(1, "Mohamed ", 19);
        Student student2 = new Student(2, "Susanna", 19);
        Student student3 = new Student(3, "Ahmed ", 21);
        system.addStudent(student1);
        system.addStudent(student2);
        system.addStudent(student3);

        
        Course course1 = new Course("C101", "Mathematics");
        Course course2 = new Course("C102", "Physics");
        Course course3 = new Course("C103", "Chemistry");
        system.addCourse(course1);
        system.addCourse(course2);
        system.addCourse(course3);

        
        system.addGrade(new Grade(student1, course1, 95.5));
        system.addGrade(new Grade(student2, course2, 88.0));
        system.addGrade(new Grade(student3, course3, 92.3));

        
        System.out.println("===== Initial Data =====");
        system.displayAll();

        
        system.updateStudent(1, "Mohamed", 21);
        System.out.println("\n===== After Updating Student 1 =====");
        system.displayAll();

        
        system.updateCourse("C102", "Advanced Physics");
        System.out.println("\n===== After Updating Course C102 =====");
        system.displayAll();

        system.updateGrade(student2, course2, 90.0);
        System.out.println("\n===== After Updating Grade for Student 2 in Course C102 =====");
        system.displayAll();

      
        system.deleteStudent(3);
        System.out.println("\n===== After Deleting Student 3 =====");
        system.displayAll();

        
        system.deleteCourse("C103");
        System.out.println("\n===== After Deleting Course C103 =====");
        system.displayAll();

        
        system.deleteGrade(student1, course1);
        System.out.println("\n===== After Deleting Grade for Student 1 in Course C101 =====");
        system.displayAll();
    }
}

