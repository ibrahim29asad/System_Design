# Prompt
# 12. Create a student grading system to compute and display GPA from a list of grades.

# My Answer
# what we need is 

# A class for a course, The Identifier will bet the class name so like ECON101 COMP203
# Within it there should be the Assignment Numbers, the weighting and what each student got wuth a 0 in case
# Wieght will be a number so you can have say 1 ,100,.001


# A class for Students with the course they are taking 

class Student:
    def Student(self, StudentID):
        self.studentID = StudentID
        self.OverallGrades = 0.0
        self.Courses = set() # Since you can only be in one class and is faster lookUp so its constant and space is 
                             # always going to be n number of Courses

class Course:
    # Course Name and Student ID
    def Course(self, className, Students):
        self.CourseName= className
        self.Student_Grades = {}
        for x in Students:
            self.Student_Grades[x.studentID] = {}

    def addStudent(self, StudentID):
        # Checks to see if there is any students
        if self.Student_Grades:
            if StudentID not in self.Student_Grades:
                self.Student_Grades[StudentID] = {}

    def delStudent(self, StudentID):
        # Checks to see if there is any students
        if self.Student_Grades:
            if StudentID in self.Student_Grades:
                self.Student_Grades.pop(StudentID)

    # In the case of neededing to upload it all 
    # what I need is StudentID, Assignment Name(Unique), Weighting and grades (not tiple ) as a percentage 
    def addGrades(self, StudentID, AssignemtName, weight, Grade):
        if self.Student_Grades:
            if StudentID in self.Student_Grades:
                self.Student_Grades[StudentID] = {AssignemtName, [weight, Grade]}
            else: 
                print("That Student does Not Exist")

    def ChangeGrade(self, StudentID, AssignemtName, weight, Grade):
        if self.Student_Grades:
            if StudentID in self.Student_Grades:
                if AssignemtName in self.Student_Grades[StudentID]:
                    self.Student_Grades[StudentID][AssignemtName] = [weight, Grade]
    
    def removeAssignmentOneStudent(self, StudentID, AssignemtName):
        if self.Student_Grades:
            if StudentID in self.Student_Grades:
                if AssignemtName in self.Student_Grades[StudentID]:
                    self.Student_Grades[StudentID].pop(AssignemtName)
    
    def removeAssignmentAllStudents(self, AssignemtName):
        for x in self.Student_Grades:
            if AssignemtName in self.Student_Grades[x]:
                self.Student_Grades[x].pop(AssignemtName)

    def StudentAverage(self, StudentID):
        weight_vals = 0.0
        current_weight = 0.0
        
        if self.Student_Grades:
            if StudentID in self.Student_Grades:
                for x in self.Student_Grades[StudentID]:
                    current_weight += (x[0] * x[1])
                    weight_vals += x[0]

        return current_weight / weight_vals
        
    
class GradingSystem:

    def __init__(self):
        self.Classes = set()
        self.Students_InSystem = set()
        pass
     
    def add_Student(self, ID):
        new_Student = Student.Student(ID)
        self.Students_InSystem.append(new_Student)

    
    def add_class(self, className, Students):
        check_students = set(Students) 
        for x in check_students:
            if x not in self.Students_InSystem:
                print(f"Student {x} is not in the System")
                return
        
        new_class = Course.Course(className, Students)
        for x in self.Classes:
            if x.CourseName == className:
                print(f"Class {x} is already in the System")
                return
        self.Classes.append(new_class) # added the Class
        #Need to add the Class now into the studentCoruse
        for x in self.Student:
            self.Students_InSystem[x].Courses.append("className")
    
    def Average_Of_Student(self, StudentID):
        pass


        #  for x in self.Students:
        #     x.Courses.append(className)



            





        

