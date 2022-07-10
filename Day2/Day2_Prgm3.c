//Coded by Eswar Majji
//It was Raj's first day at school. His teacher asked the students to meet every other student in the class and to introduce themselves. The teacher asked them to give handshakes when they meet each other. If there are ‘n’ number of students in the class then find the total number of handshakes made by the students.
#include <stdio.h>

int main()
{
    int no_of_students, num;
    printf("Enter no of students :");
    fflush(stdout);
    scanf("%d", &no_of_students);
    num = no_of_students - 1;
    //sum of n natural numbers
    printf("No of Hand shakes : %d", ((num*(num + 1)) / 2) );

    return 0;
}
