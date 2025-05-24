class Student:
    def __init__(self, studentID):
        self.studentID = studentID
        self.courses = set()

class Course:
    def __init__(self, className, students):
        self.courseName = className
        self.studentGrades = {}
        for student in students:
            self.studentGrades[student.studentID] = {}  # assignment: [weight, grade]

    def addStudent(self, studentID):
        if studentID not in self.studentGrades:
            self.studentGrades[studentID] = {}

    def delStudent(self, studentID):
        self.studentGrades.pop(studentID, None)

    def addGrade(self, studentID, assignmentName, weight, grade):
        if studentID in self.studentGrades:
            self.studentGrades[studentID][assignmentName] = [weight, grade]
        else:
            print("Student not enrolled in course.")

    def changeGrade(self, studentID, assignmentName, weight, grade):
        if studentID in self.studentGrades and assignmentName in self.studentGrades[studentID]:
            self.studentGrades[studentID][assignmentName] = [weight, grade]

    def removeAssignmentForStudent(self, studentID, assignmentName):
        if studentID in self.studentGrades:
            self.studentGrades[studentID].pop(assignmentName, None)

    def removeAssignmentAll(self, assignmentName):
        for grades in self.studentGrades.values():
            grades.pop(assignmentName, None)

    def studentAverage(self, studentID):
        if studentID not in self.studentGrades:
            return 0.0
        total_weight = 0.0
        weighted_sum = 0.0
        for weight, grade in self.studentGrades[studentID].values():
            weighted_sum += weight * grade
            total_weight += weight
        return weighted_sum / total_weight if total_weight > 0 else 0.0

class GradingSystem:
    def __init__(self):
        self.classes = {}  # className: Course
        self.students = {}  # studentID: Student

    def addStudent(self, studentID):
        if studentID not in self.students:
            self.students[studentID] = Student(studentID)

    def addClass(self, className, studentIDs):
        for sid in studentIDs:
            if sid not in self.students:
                print(f"Student {sid} not in system.")
                return
        course = Course(className, [self.students[sid] for sid in studentIDs])
        self.classes[className] = course
        for sid in studentIDs:
            self.students[sid].courses.add(className)

    def averageOfStudent(self, studentID):
        if studentID not in self.students:
            return 0.0
        student = self.students[studentID]
        total = 0.0
        count = 0
        for courseName in student.courses:
            avg = self.classes[courseName].studentAverage(studentID)
            total += avg
            count += 1
        return total / count if count > 0 else 0.0
