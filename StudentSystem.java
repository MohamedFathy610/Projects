/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.studentmanagementsystem;

/**
 *
 * @author Mohamed Fathy
 */
import java.util.ArrayList;
import java.util.List;
public class StudentSystem {
    private List<Student> students;
    private List<Course> courses;
    private List<Grade> grades;
    
    public StudentSystem() {
        students = new ArrayList<>();
        courses = new ArrayList<>();
        grades = new ArrayList<>();
    }
    // student 
     public void addStudent(Student student) {
        students.add(student);
    }
         public void updateStudent(int studentId, String name, int age) {
        for (int i = 0; i < students.size(); i++) {
            
            if (students.get(i).getStudentId() == studentId) {
                students.get(i).setName(name);
                students.get(i).setAge(age);
                break;
            }
        }
    }
     
    public void deleteStudent(int studentId) {
        for (int i = 0; i < students.size(); i++) {
            if (students.get(i).getStudentId() == studentId) {
                students.remove(i);
                break;
            }
        }
    }
    
    // courses 
    public void addCourse(Course course) {
        courses.add(course);
    }

    public void updateCourse(String courseId, String courseName) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses.get(i).getCourseId()== courseId ) {
                courses.get(i).setCourseName(courseName);
                break;
            }
        }
    }

    public void deleteCourse(String courseId) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses.get(i).getCourseId().equals(courseId)) {
                courses.remove(i);
                break;
            }
        }
    }
    
    //grades 
    public void addGrade(Grade grade) {
        grades.add(grade);
    }
    public void updateGrade(Student student, Course course, double grade) {
        for (int i = 0; i < grades.size(); i++) {
           
            if (grades.get(i).getStudent()==student && grades.get(i).getCourse()==course) {
                grades.get(i).setGrade(grade);
                break;
            }
        }
    }
     public void deleteGrade(Student student, Course course) {
        for (int i = 0; i < grades.size(); i++) {
           
            if (grades.get(i).getStudent()==student && grades.get(i).getCourse()==course) {
                grades.remove(i);
                break;
            }
        }
    }
     
     public void displayAll() {
        System.out.println("Students:");
        for (int i = 0; i < students.size(); i++) {
            students.get(i).display();
        }

        System.out.println("\nCourses:");
        for (int i = 0; i < courses.size(); i++) {
            courses.get(i).display();
        }

        System.out.println("\nGrades:");
        for (int i = 0; i < grades.size(); i++) {
            grades.get(i).display();
        }
    }
}

