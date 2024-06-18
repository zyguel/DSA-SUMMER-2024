/*
	REVIEW OF ADT STRUCT
	DSA SUMMER 2024
	STUDENT: ZYGUEL CABOGOY
	DATE OF CODE PRODUCTION: JUNE 10, 2024
	ACTIVITY# 1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define GET_CURRENT_YEAR_AND_MONTH(year, month) do { \
	time_t t = time(NULL); \
	struct tm *tm = localtime(&t); \
	year = tm->tm_year + 1900; \
	month = tm->tm_mon + 1; \
	} while (0) 

#define MAX_STUDENTS 20


typedef struct {
	char fName[20];
	char lName[20];
}studName;

typedef struct {
	int month;
	int year;
}bday;

typedef struct {
	studName name;
	bday birthdate;
	int age;
	int idNum;
}studentInfo;

typedef struct {
	studentInfo studList[20];
	int studCount;
}classRecord;

void initClassRecord(classRecord* cr) {
    // Initialize the classRecord structure
    cr->studCount = 0; // Reset the count of students

    // Initialize all studentInfo structures in the studList array
    for (int i = 0; i < 20; i++) {
        // Mark each student as uninitialized by setting age to 0
        cr->studList[i].age = 0;
    }
}
void getUserInput(studentInfo* student, int current_year, int current_month) {
	
	getchar(); //Catches newline
    printf("Enter First Name: ");
    fgets(student->name.fName, sizeof(student->name.fName), stdin);
    student->name.fName[strcspn(student->name.fName, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Last Name: ");
    fgets(student->name.lName, sizeof(student->name.lName), stdin);
    student->name.lName[strcspn(student->name.lName, "\n")] = '\0';
	
	
    printf("Enter birth year: ");
    scanf("%d", &(student->birthdate.year));
    getchar(); // Consume newline left by scanf
	
    printf("Enter birth month (by digits only): ");
    scanf("%d", &(student->birthdate.month));
    getchar(); // Consume newline left by scanf

    printf("Assign ID number: ");
    scanf("%d", &(student->idNum));
    getchar(); // Consume newline left by scanf
    
    // Validate birth year and month
    while(1){
	
	    if (student->birthdate.year < 1960 || student->birthdate.year > current_year ||
	        student->birthdate.month < 1 || student->birthdate.month > 12) {
	        printf("\n\nInvalid birth year or month!\n\n");
	        
	        printf("Enter birth year: ");
		    scanf("%d", &(student->birthdate.year));
		    getchar(); // Consume newline left by scanf
			
		    printf("Enter birth month (by digits only): ");
		    scanf("%d", &(student->birthdate.month));
		    getchar(); // Consume newline left by scanf
	    }else{
	    	break;
		}
	}

    // Calculate age
    int age = current_year - student->birthdate.year;
    if (student->birthdate.month > current_month) {
        age--;
    }
    student->age = age;
}



void insert_front(classRecord* cr, int current_year, int current_month) {
    if (cr->studCount >= MAX_STUDENTS) {
        printf("Class Record is already full!\n");
        return;
    }
	printf("***You have chosen insert_front!***\n\n");
    studentInfo newStudent;
    getUserInput(&newStudent, current_year, current_month);


    // Find the first empty slot from the end
    int i = MAX_STUDENTS - 1;
    while (i >= 0 && cr->studList[i].age != 0) {
        i--;
    }
    i++; // Move to the first empty slot

    // Shift existing elements to make room for the new one
    for (; i > 0; i--) {
        cr->studList[i] = cr->studList[i - 1];
        cr->studList[i - 1].age = 0;
    }

    // Insert new student at the front
    strcpy(cr->studList[0].name.fName, newStudent.name.fName);
    strcpy(cr->studList[0].name.lName, newStudent.name.lName);
    cr->studList[0].birthdate.year = newStudent.birthdate.year;
    cr->studList[0].birthdate.month = newStudent.birthdate.month;
    cr->studList[0].idNum = newStudent.idNum;
    cr->studList[0].age = newStudent.age;
    cr->studCount++;
}

void insert_rear (classRecord* cr, int current_year, int current_month){
	if (cr->studCount >= MAX_STUDENTS) {
        printf("Class Record is already full!\n");
        return;
    }
	printf("***You have chosen insert_rear!***\n\n");
   	studentInfo newStudent;
    getUserInput(&newStudent, current_year, current_month);
	
	
	// Find the most rear position 
	int i;
	int rear_ndx = -1;
	
	for(i = 0; i < MAX_STUDENTS; i++){
		if(cr->studList[i].age != 0){
			rear_ndx = i;
		}
	}
	
	// Process if most rear index (means if MAX - 1) is occupied but record is not full
	int j;
	if (rear_ndx >= MAX_STUDENTS - 1){
		for(i = 0; i < MAX_STUDENTS; i++){
			if(cr->studList[i].age == 0){
				cr->studList[i] = cr->studList[i + 1];
				cr->studList[i + 1].age == 0; 
			}else {
				continue;
			}
		}
			
	}
	rear_ndx++;

    // Insert new student at the rear
   
    strcpy(cr->studList[rear_ndx].name.fName, newStudent.name.fName);
    strcpy(cr->studList[rear_ndx].name.lName, newStudent.name.lName);
    cr->studList[rear_ndx].birthdate.month = newStudent.birthdate.month;
    cr->studList[rear_ndx].birthdate.year = newStudent.birthdate.year;
    cr->studList[rear_ndx].idNum = newStudent.idNum;
    cr->studList[rear_ndx].age = newStudent.age;
    cr->studCount++;
}

void insert_at_index(classRecord* cr, int current_year, int current_month){
	if (cr->studCount >= MAX_STUDENTS) {
        printf("Class Record is already full!\n");
        return;
    }
    printf("***You have chosen insert_at_index!***\n\n");
    
    int pos;
    
    // INDEX INPUT AND VALIDATION
    
	for(;;){
    	 printf("Please enter index : ");
    	 scanf(" %d", &pos);
    	 getchar();
		 if(pos >= MAX_STUDENTS || pos < 0){
		 	printf("Index out of bounds!!!\n\n");
		 }else {
		 	if(cr->studList[pos].age != 0){
		 		printf("Index occupied!!!\nPrinting empty indexes:\n");
		 		int ndx, j;
		 		int open[20];
		 		for(ndx = 0, j = 0; ndx < MAX_STUDENTS; ndx++){
					if(cr->studList[ndx].age != 0){
						open[j++] = ndx;
					}	
				}
				for(;j >= 0; j--){
					printf("%d", open[j]);
					if (j != 0){
						printf(", ");
					}
				}
				printf("\n\n");
			 }else{
			 	break;
			 }	 
		 }
		 printf("\n\n"); 	 
	}
	
	studentInfo newStudent;
    getUserInput(&newStudent, current_year, current_month);
    
	strcpy(cr->studList[pos].name.fName, newStudent.name.fName);
    strcpy(cr->studList[pos].name.lName, newStudent.name.lName);
    cr->studList[pos].birthdate.month = newStudent.birthdate.month;
    cr->studList[pos].birthdate.year = newStudent.birthdate.year;
    cr->studList[pos].idNum = newStudent.idNum;
    cr->studList[pos].age = newStudent.age;
    cr->studCount++;
}

// insert sorted by age
void insert_sorted(classRecord* cr, int current_year, int current_month) {
	
	if (cr->studCount >= MAX_STUDENTS) {
        printf("Class Record is already full!\n");
        return;
    }
	
    // Get user input for the new student
    studentInfo newStudent;
    getUserInput(&newStudent, current_year, current_month);

    // Find the correct position to insert the new student based on age
    int insertIndex = 0;
    while (insertIndex < cr->studCount && cr->studList[insertIndex].age < newStudent.age) {
        insertIndex++;
    }

    // Shift existing students to make space for the new student
    for (int i = cr->studCount; i > insertIndex; i--) {
        cr->studList[i] = cr->studList[i - 1];
    }

    // Insert the new student into the correct position
    cr->studList[insertIndex] = newStudent;

    // Increment the count of students in the class record
    cr->studCount++;

    // Check if the class record is sorted, if not, sort it
    if (!isSorted(cr, cr->studCount)) {
        sortClassRecord(cr, cr->studCount);
    }
}

// Function to check if the class record is sorted by age
int isSorted(classRecord* cr, int n) {
    for (int i = 1; i < n; i++) {
        if (cr->studList[i - 1].age > cr->studList[i].age) {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
}

// Function to sort the class record by age
void sortClassRecord(classRecord* cr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cr->studList[j].age > cr->studList[j + 1].age) {
                // Swap students if they are in the wrong order
                studentInfo temp = cr->studList[j];
                cr->studList[j] = cr->studList[j + 1];
                cr->studList[j + 1] = temp;
            }
        }
    }
}

void delete_front(classRecord* cr) {
    if (cr->studCount <= 0) {
        printf("No students to delete from the front.\n");
        return;
    }

    // Move the last element to the front
    cr->studList[0] = cr->studList[cr->studCount - 1];

    // Reduce the studCount
    cr->studCount--;

    // Mark the moved element as uninitialized
    cr->studList[cr->studCount].age = 0;
}

void delete_rear(classRecord* cr) {
    if (cr->studCount <= 0) {
        printf("No students to delete from the rear.\n");
        return;
    }
	// 
    // Move the second-to-last element to the last position
    cr->studList[cr->studCount - 1] = cr->studList[cr->studCount - 2];
    cr->studCount--;

    // Mark the moved element as uninitialized
    cr->studList[cr->studCount].age = 0;
    
}
void delete_index(classRecord* cr, int index) {
    if (index < 0 || index >= cr->studCount) {
        printf("Invalid index to delete.\n");
        return;
    }

    // Move the next element to replace the current element
    cr->studList[index] = cr->studList[index + 1];

    // Reduce the studCount
    cr->studCount--;

    // Mark the moved element as uninitialized
    cr->studList[cr->studCount].age = 0;
}


void main (){
	int current_year;
	int current_month;
	GET_CURRENT_YEAR_AND_MONTH(current_year, current_month);
	
	
	classRecord cr;
	initClassRecord(&cr);
	int option = 0;
	//printf("Current Year : %d", current_year);
	while(1){
	 	printf("\n\nSelect Operation: \n"
		 "1 - Insert front\n"
		 "2 - Insert rear\n"
		 "3 - Insert at index\n"
		 "4- Insert Sorted\n"
		 "5 - Delete Front\n"
		 "6 - Delete Rear\n" 
		 "7 - Delete at Index\n"
		 "8 - Print class record\n"
		 "9 - Exit\n"
		 "Choose option : ");
		 
		 scanf(" %d", &option);
		 switch(option){
		 	case 1:
		 		insert_front(&cr, current_year, current_month);
		 		break;
			case 2:
				insert_rear(&cr, current_year, current_month);
				break;
			case 3:
				insert_at_index(&cr, current_year, current_month);
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:
				
				break;
			case 7:
				
				break;
			case 9:
				exit(1);
				break;
			default:
				printf("YA");
				
		 }
		 
	}


}
